# This file is based on templates provided and copyrighted by Autodesk, Inc.
# This file has been modified by Epic Games, Inc. and is subject to the license 
# file included in this repository.

"""
Framework containing PySide2 distributions for the Unreal engine

Because Unreal does not include PySide2/Qt distributions but does use its own
version of Python, we have to distribute full versions for the engine to function.
"""

import sgtk
import sys
import os

class UnrealQtFramework(sgtk.platform.Framework):

    ##########################################################################################
    # init and destroy
            
    def init_framework(self):
        self.log_debug("%s: Initializing UnrealQtFramework..." % self)
        
        # Supporting Windows only for now
        pyside_root = None            
        if sys.platform == "win32":
            if sys.version_info[0] >= 3:
                pyside_root = os.path.join(self.disk_location, "resources", "pyside2-5.15.2")
            else:
                pyside_root = os.path.join(self.disk_location, "resources", "pyside2-5.9.0a1")

        if pyside_root:
            # Add PySide2 path to PYTHONPATH
            if pyside_root not in sys.path:
                sys.path.append(pyside_root)

            try:
                self.log_debug("Attempting to import PySide2 from %s" % pyside_root)
                from PySide2 import QtCore, QtGui, QtWidgets
                import PySide2
                
                self.log_debug("Successfully initialized PySide2 '%s' located in %s." 
                               % (PySide2.__version__, PySide2.__file__))
            except ImportError as e:
                self.log_warning("Error importing PySide2: %s" % e)        
            except Exception as e:
                self.log_warning("Error setting up PySide2. Pyside2-based UI support will not "
                                 "be available: %s" % e)        

    def destroy_framework(self):
        self.log_debug("%s: Destroying UnrealQtFramework..." % self)
