__all__ = list("Qt" + body for body in
    "Core;Gui;Widgets;PrintSupport;Sql;Network;Test;Concurrent;WinExtras;Xml;XmlPatterns;Help;Multimedia;MultimediaWidgets;OpenGL;Qml;Quick;QuickWidgets;TextToSpeech;Charts;Svg;DataVisualization;UiTools;AxContainer;WebChannel;WebEngineWidgets;WebSockets;3DCore;3DRender;3DInput;3DLogic;3DAnimation;3DExtras"
    .split(";"))
__version__ = "5.9.0a1"
__version_info__ = (5, 9, 0, "a", 1)

__build_date__ = '2018-04-04T05:54:37+00:00'




# Timestamp used for snapshot build, which is part of snapshot package version.
__setup_py_package_timestamp__ = ''

def _setupQtDirectories():
    import sys
    import os

    pyside_package_dir =  os.path.abspath(os.path.dirname(__file__))
    # Used by signature module.
    os.environ["PYSIDE_PACKAGE_DIR"] = pyside_package_dir

    # On Windows add the PySide2\openssl folder (if it exists) to the
    # PATH so that the SSL DLLs can be found when Qt tries to dynamically
    # load them. Tell Qt to load them and then reset the PATH.
    if sys.platform == 'win32':
        openssl_dir = os.path.join(pyside_package_dir, 'openssl')
        if os.path.exists(openssl_dir):
            path = os.environ['PATH']
            try:
                os.environ['PATH'] = os.path.join(openssl_dir, path)
                try:
                    from . import QtNetwork
                except ImportError:
                    pass
                else:
                    QtNetwork.QSslSocket.supportsSsl()
            finally:
                os.environ['PATH'] = path

_setupQtDirectories()
