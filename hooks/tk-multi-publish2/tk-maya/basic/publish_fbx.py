# This file is based on templates provided and copyrighted by Autodesk, Inc.
# This file has been modified by Epic Games, Inc. and is subject to the license
# file included in this repository.

import os
import maya.cmds as cmds
import maya.mel as mel
import sgtk
from sgtk.util.filesystem import ensure_folder_exists

HookBaseClass = sgtk.get_hook_baseclass()


class MayaFBXPublishPlugin(HookBaseClass):
    """
    Plugin for publishing an open maya session as an exported FBX.

    This hook relies on functionality found in the base file publisher hook in
    the publish2 app and should inherit from it in the configuration. The hook
    setting for this plugin should look something like this:

        hook: "{self}/publish_file.py:{config}/tk-multi-publish2/tk-maya/basic/publish_fbx.py"

    .. note :: Most of this code was copied over from tk-maya publish_session hook
               since it is not possible to derive from it to publish something
               else than a Maya scene, and since it populates properties on the
               publish item rather than using local properties, so it conflicts
               with other plugins acting on the same item.
    """

    # NOTE: The plugin icon and name are defined by the base file plugin.

    @property
    def description(self):
        """
        Verbose, multi-line description of what the plugin does. This can
        contain simple html for formatting.
        """

        return """
        <p>This plugin exports the current Maya session as an FBX file and publishes it.
        The scene will be exported to the path defined by this plugin's configured
        "Publish Template" setting.  The resulting FBX file can then be imported
        into Unreal Engine via the Loader.</p>
        """

    @property
    def icon(self):
        """
        Return the path to this item's icon.

        :returns: Full path to an icon.
        """
        return os.path.join(
            self.disk_location,
            os.path.pardir,
            "icons",
            "fbx.png"
        )

    @property
    def settings(self):
        """
        Dictionary defining the settings that this plugin expects to receive
        through the settings parameter in the accept, validate, publish and
        finalize methods.

        A dictionary on the following form::

            {
                "Settings Name": {
                    "type": "settings_type",
                    "default": "default_value",
                    "description": "One line description of the setting"
            }

        The type string should be one of the data types that toolkit accepts as
        part of its environment configuration.
        """

        # Inherit the settings from the base publish plugin
        base_settings = super(MayaFBXPublishPlugin, self).settings or {}

        # Settings specific to this class
        maya_publish_settings = {
            "Publish Template": {
                "type": "template",
                "default": None,
                "description": "Template path for published work files. Should"
                "correspond to a template defined in "
                "templates.yml.",
            }
        }

        # Update the base settings
        base_settings.update(maya_publish_settings)
        return base_settings

    @property
    def item_filters(self):
        """
        List of item types that this plugin is interested in.

        Only items matching entries in this list will be presented to the
        accept() method. Strings can contain glob patters such as *, for example
        ["maya.*", "file.maya"]

        By accepting a child item from the `maya.session` item we ensure that
        publishes will have a dependency to the main publish for the session.
        """
        return ["maya.session.secondaries"]

    def accept(self, settings, item):
        """
        Method called by the publisher to determine if an item is of any
        interest to this plugin. Only items matching the filters defined via the
        item_filters property will be presented to this method.

        A publish task will be generated for each item accepted here. Returns a
        dictionary with the following booleans:

            - accepted: Indicates if the plugin is interested in this value at
                all. Required.
            - enabled: If True, the plugin will be enabled in the UI, otherwise
                it will be disabled. Optional, True by default.
            - visible: If True, the plugin will be visible in the UI, otherwise
                it will be hidden. Optional, True by default.
            - checked: If True, the plugin will be checked in the UI, otherwise
                it will be unchecked. Optional, True by default.

        :param settings: Dictionary of Settings. The keys are strings, matching
            the keys returned in the settings property. The values are `Setting`
            instances.
        :param item: Item to process

        :returns: dictionary with boolean keys accepted, required and enabled
        """

        accepted = True
        publisher = self.parent

        # Check the publish template if one defined
        # If a publish template is configured, disable context change. This
        # is a temporary measure until the publisher handles context switching
        # natively.
        template_name = settings["Publish Template"].value
        if template_name:
            item.context_change_allowed = False
            publish_template = publisher.get_template_by_name(template_name)
            if not publish_template:
                self.logger.debug(
                    "The valid publish template could not be determined for the "
                    "FBX publish.  Not accepting the item."
                )
                accepted = False

            # We've validated the publish template. add it to the item properties
            # for use in subsequent methods
            item.local_properties["publish_template"] = publish_template

        path = _session_path()
        if not path:
            # the session has not been saved before (no path determined).
            # provide a save button. the session will need to be saved before
            # validation will succeed.
            self.logger.warn(
                "The Maya session has not been saved.", extra=_get_save_as_action()
            )

        if accepted:
            self.logger.info(
                "Maya '%s' plugin accepted the current Maya session." % (self.name,)
            )
        return {"accepted": accepted, "checked": True}

    def validate(self, settings, item):
        """
        Validates the given item to check that it is ok to publish. Returns a
        boolean to indicate validity.

        :param settings: Dictionary of Settings. The keys are strings, matching
            the keys returned in the settings property. The values are `Setting`
            instances.
        :param item: Item to process.
        :returns: ``True`` if item is valid, ``False`` otherwise.
        :raises ValueError: For problems which can't be solved in the current session.
        """

        path = _session_path()

        # ---- ensure the session has been saved

        if not path:
            # the session still requires saving. provide a save button.
            # validation fails.
            error_msg = "The Maya session has not been saved."
            self.logger.error(error_msg, extra=_get_save_as_action())
            return False

        # Ensure we have an updated project root
        project_root = cmds.workspace(q=True, rootDirectory=True)
        # log if no project root could be determined.
        if not project_root:
            self.logger.error(
                "Your session is not part of a Maya project.",
                extra={
                    "action_button": {
                        "label": "Set Project",
                        "tooltip": "Set the Maya project",
                        "callback": lambda: mel.eval('setProject ""'),
                    }
                },
            )
            return False
        item.properties["project_root"] = project_root

        # ---- check the session against any attached work template

        # get the path in a normalized state. no trailing separator,
        # separators are appropriate for current os, no double separators,
        # etc.
        path = sgtk.util.ShotgunPath.normalize(path)
        publish_name = os.path.splitext(os.path.basename(path))[0]
        # if the session item has a known work template, see if the path
        # matches. if not, warn the user and provide a way to save the file to
        # a different path
        work_template = item.properties.get("work_template")
        publish_template = item.local_properties.get("publish_template")
        if work_template and publish_template:
            # Ensure the fields work for the publish template
            # This raises an error if the path does not match the template.
            work_fields = work_template.get_fields(path)
            missing_keys = publish_template.missing_keys(work_fields)
            if missing_keys:
                error_msg = (
                    "Work file '%s' missing keys required for the "
                    "publish template %s: %s" % (path, publish_template, missing_keys)
                )
                self.logger.error(error_msg)
                return False
            # Create the publish path by applying the fields. store it in the item's
            # properties. This is the path we'll create and then publish in the base
            # publish plugin. Also set the publish_path to be explicit.
            # NOTE: local_properties is used here as directed in the publisher
            # docs when there may be more than one plugin operating on the
            # same item in order for each plugin to have it's own values that
            # aren't overwritten by the other.
            item.local_properties["publish_path"] = publish_template.apply_fields(work_fields)

            # use the work file's version number when publishing
            if "version" in work_fields:
                item.properties["publish_version"] = work_fields["version"]
        else:
            # Derive a publish path from the current scene path
            workspace = cmds.workspace(q=True, openWorkspace=True)
            if not workspace:
                self.logger.error(
                    "A Maya workspace must be set when no SG TK templates are provided",
                    extra={
                        "action_button": {
                            "label": "Set Project",
                            "tooltip": "Set the Maya project",
                            # This is a Mel script not available as a Python command.
                            "callback": lambda: mel.eval('setProject ""'),
                        }
                    },
                )
                return False
            fbx_dir = cmds.workspace(fileRuleEntry="FBX") or "data"
            # Append a "publishes" folder and get the full path
            fbx_dir = cmds.workspace(expandName=os.path.join(fbx_dir, "publishes"))

            # Build a name from the Maya scene
            base_name = "%s.fbx" % publish_name
            publish_path = os.path.join(fbx_dir, base_name)
            # NOTE: local_properties is used here as directed in the publisher
            # docs when there may be more than one plugin operating on the
            # same item in order for each plugin to have it's own values that
            # aren't overwritten by the other.
            # Set the publish_path to be explicit.
            item.local_properties["publish_path"] = publish_path

        # Set the session path on the item for use by the base plugin validation
        # step.
        # NOTE: this path could change prior to the publish phase.
        item.properties["path"] = path
        # NOTE: local_properties is used here as directed in the publisher
        # docs when there may be more than one plugin operating on the
        # same item in order for each plugin to have it's own values that
        # aren't overwritten by the other.
        item.local_properties["publish_type"] = "Maya FBX"
        item.local_properties["publish_name"] = publish_name

        return True

    def _copy_to_publish(self, settings, item):
        """
        Override base implementation to do nothing
        since we're not copying a file but exporting
        directly to the publish location.
        """
        pass

    def _copy_local_to_publish(self, settings, item):
        """
        Override base implementation to do nothing
        since we're not copying a file but exporting
        directly to the publish location.
        """
        pass

    def _copy_work_to_publish(self, settings, item):
        """
        Override base implementation to do nothing
        since we're not copying a file but exporting
        directly to the publish location.
        """
        pass

    def publish(self, settings, item):
        """
        Executes the publish logic for the given item and settings.

        :param settings: Dictionary of Settings. The keys are strings, matching
            the keys returned in the settings property. The values are `Setting`
            instances.
        :param item: Item to process
        """

        # Get the path in a normalized state. no trailing separator, separators
        # are appropriate for current os, no double separators, etc.
        path = sgtk.util.ShotgunPath.normalize(_session_path())

        # Ensure the session is saved
        _save_session(path)

        # Update the item with the saved session path
        item.properties["path"] = path

        # Get the path to create and publish
        publish_path = self.get_publish_path(settings, item)

        # ensure the publish folder exists:
        publish_folder = os.path.dirname(publish_path)
        self.parent.ensure_folder_exists(publish_folder)

        # Export scene to FBX
        self.logger.info(
            "Exporting scene %s to FBX %s" % (
                path, publish_path
            )
        )
        cmds.FBXResetExport()
        cmds.FBXExportSmoothingGroups("-v", True)
        # Mel script equivalent: mel.eval('FBXExport -f "fbx_output_path"')
        cmds.FBXExport("-f", publish_path)

        # Store the exported fbx path onto the parent item so other items can
        # retrieve it and use it without having to export themself an fbx.
        item.parent.properties["exported_fbx_path"] = publish_path

        # Let the base class register the publish
        super(MayaFBXPublishPlugin, self).publish(settings, item)
        # Save publish data locally on the item to be able to restore it later
        item.local_properties["sg_publish_data"] = item.properties.sg_publish_data
        # Store the published fbx data onto the parent item so other items can
        # retrieve it and use it without having to export themself an fbx.
        item.parent.properties["sg_fbx_publish_data"] = item.properties.sg_publish_data

    def finalize(self, settings, item):
        """
        Set the global item sg_publish_data property from the local property and
        call base the implementation which needs it.
        """
        item.properties.sg_publish_data = item.local_properties.sg_publish_data
        # do the base class finalization
        super(MayaFBXPublishPlugin, self).finalize(settings, item)


def _session_path():
    """
    Return the path to the current session
    :return: A string or ``None``.
    """
    path = cmds.file(query=True, sn=True)
    return path


def _save_session(path):
    """
    Save the current session to the supplied path.
    """

    # Maya can choose the wrong file type so we should set it here
    # explicitly based on the extension
    maya_file_type = None
    if path.lower().endswith(".ma"):
        maya_file_type = "mayaAscii"
    elif path.lower().endswith(".mb"):
        maya_file_type = "mayaBinary"

    # Maya won't ensure that the folder is created when saving, so we must make sure it exists
    folder = os.path.dirname(path)
    ensure_folder_exists(folder)

    cmds.file(rename=path)

    # save the scene:
    if maya_file_type:
        cmds.file(save=True, force=True, type=maya_file_type)
    else:
        cmds.file(save=True, force=True)


# TODO: method duplicated in all the maya hooks
def _get_save_as_action():
    """
    Simple helper for returning a log action dict for saving the session
    """

    engine = sgtk.platform.current_engine()

    # default save callback
    callback = cmds.SaveScene

    # if workfiles2 is configured, use that for file save
    if "tk-multi-workfiles2" in engine.apps:
        app = engine.apps["tk-multi-workfiles2"]
        if hasattr(app, "show_file_save_dlg"):
            callback = app.show_file_save_dlg

    return {
        "action_button": {
            "label": "Save As...",
            "tooltip": "Save the current session",
            "callback": callback,
        }
    }
