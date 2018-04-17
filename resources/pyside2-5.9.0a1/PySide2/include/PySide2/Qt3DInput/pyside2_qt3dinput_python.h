/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of PySide2.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef SBK_QT3DINPUT_PYTHON_H
#define SBK_QT3DINPUT_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

#include <pysidesignal.h>
// Module Includes
#include <pyside2_qt3dcore_python.h>
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qabstractaxisinput.h>
#include <qaxissetting.h>
#include <qaxis.h>
#include <qinputchord.h>
#include <qkeyboardhandler.h>
#include <qmouseevent.h>
#include <qanalogaxisinput.h>
#include <qbuttonaxisinput.h>
#include <qkeyboarddevice.h>
#include <qinputsettings.h>
#include <qabstractactioninput.h>
#include <qabstractphysicaldevice.h>
#include <qkeyevent.h>
#include <qaxisaccumulator.h>
#include <qmousehandler.h>
#include <qlogicaldevice.h>
#include <qinputaspect.h>
#include <qinputsequence.h>
#include <qactioninput.h>
#include <qaction.h>
#include <qmousedevice.h>
// Conversion Includes - Primitive Types
#include <QString>
#include <QStringList>
#include <wtypes.h>
#include <signalmanager.h>
#include <qabstractitemmodel.h>

// Conversion Includes - Container Types
#include <QVector>
#include <QPair>
#include <pysideqflags.h>
#include <QMultiMap>
#include <QStack>
#include <QSet>
#include <QQueue>
#include <QList>
#include <QLinkedList>
#include <QMap>

// Type indices
#define SBK_QT3DINPUT_IDX                                            0
#define SBK_QT3DINPUT_QINPUTASPECT_IDX                               12
#define SBK_QT3DINPUT_QABSTRACTPHYSICALDEVICE_IDX                    3
#define SBK_QT3DINPUT_QKEYBOARDDEVICE_IDX                            17
#define SBK_QT3DINPUT_QMOUSEDEVICE_IDX                               20
#define SBK_QT3DINPUT_QMOUSEDEVICE_AXIS_IDX                          21
#define SBK_QT3DINPUT_QACTION_IDX                                    4
#define SBK_QT3DINPUT_QINPUTSETTINGS_IDX                             15
#define SBK_QT3DINPUT_QKEYBOARDHANDLER_IDX                           18
#define SBK_QT3DINPUT_QLOGICALDEVICE_IDX                             19
#define SBK_QT3DINPUT_QMOUSEHANDLER_IDX                              25
#define SBK_QT3DINPUT_QAXISACCUMULATOR_IDX                           8
#define SBK_QT3DINPUT_QAXISACCUMULATOR_SOURCEAXISTYPE_IDX            9
#define SBK_QT3DINPUT_QAXIS_IDX                                      7
#define SBK_QT3DINPUT_QAXISSETTING_IDX                               10
#define SBK_QT3DINPUT_QABSTRACTACTIONINPUT_IDX                       1
#define SBK_QT3DINPUT_QACTIONINPUT_IDX                               5
#define SBK_QT3DINPUT_QINPUTSEQUENCE_IDX                             14
#define SBK_QT3DINPUT_QINPUTCHORD_IDX                                13
#define SBK_QT3DINPUT_QABSTRACTAXISINPUT_IDX                         2
#define SBK_QT3DINPUT_QANALOGAXISINPUT_IDX                           6
#define SBK_QT3DINPUT_QBUTTONAXISINPUT_IDX                           11
#define SBK_QT3DINPUT_QKEYEVENT_IDX                                  16
#define SBK_QT3DINPUT_QWHEELEVENT_IDX                                26
#define SBK_QT3DINPUT_QWHEELEVENT_BUTTONS_IDX                        27
#define SBK_QT3DINPUT_QWHEELEVENT_MODIFIERS_IDX                      28
#define SBK_QT3DINPUT_QMOUSEEVENT_IDX                                22
#define SBK_QT3DINPUT_QMOUSEEVENT_BUTTONS_IDX                        23
#define SBK_QT3DINPUT_QMOUSEEVENT_MODIFIERS_IDX                      24
#define SBK_Qt3DInput_IDX_COUNT                                      29

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_Qt3DInputTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_Qt3DInputTypeConverters;

// Converter indices
#define SBK_QT3DINPUT_QVECTOR_QT3DCORE_QNODEPTR_IDX                  0 // QVector<Qt3DCore::QNode* >
#define SBK_QT3DINPUT_QLIST_QOBJECTPTR_IDX                           1 // const QList<QObject* > &
#define SBK_QT3DINPUT_QLIST_QBYTEARRAY_IDX                           2 // QList<QByteArray >
#define SBK_QT3DINPUT_QVECTOR_QT3DCORE_QENTITYPTR_IDX                3 // QVector<Qt3DCore::QEntity* >
#define SBK_QT3DINPUT_QVECTOR_QT3DINPUT_QACTIONPTR_IDX               4 // QVector<Qt3DInput::QAction* >
#define SBK_QT3DINPUT_QVECTOR_QT3DINPUT_QAXISPTR_IDX                 5 // QVector<Qt3DInput::QAxis* >
#define SBK_QT3DINPUT_QVECTOR_INT_IDX                                6 // QVector<int >
#define SBK_QT3DINPUT_QVECTOR_QT3DINPUT_QABSTRACTAXISINPUTPTR_IDX    7 // QVector<Qt3DInput::QAbstractAxisInput* >
#define SBK_QT3DINPUT_QVECTOR_QT3DINPUT_QABSTRACTACTIONINPUTPTR_IDX  8 // QVector<Qt3DInput::QAbstractActionInput* >
#define SBK_QT3DINPUT_QVECTOR_QT3DINPUT_QAXISSETTINGPTR_IDX          9 // QVector<Qt3DInput::QAxisSetting* >
#define SBK_QT3DINPUT_QLIST_QVARIANT_IDX                             10 // QList<QVariant >
#define SBK_QT3DINPUT_QLIST_QSTRING_IDX                              11 // QList<QString >
#define SBK_QT3DINPUT_QMAP_QSTRING_QVARIANT_IDX                      12 // QMap<QString,QVariant >
#define SBK_Qt3DInput_CONVERTERS_IDX_COUNT                           13

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QInputAspect >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QINPUTASPECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAbstractPhysicalDevice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QABSTRACTPHYSICALDEVICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QKeyboardDevice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QKEYBOARDDEVICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QMouseDevice::Axis >() { return SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QMOUSEDEVICE_AXIS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QMouseDevice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QMOUSEDEVICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAction >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QACTION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QInputSettings >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QINPUTSETTINGS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QKeyboardHandler >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QKEYBOARDHANDLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QLogicalDevice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QLOGICALDEVICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QMouseHandler >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QMOUSEHANDLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAxisAccumulator::SourceAxisType >() { return SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QAXISACCUMULATOR_SOURCEAXISTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAxisAccumulator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QAXISACCUMULATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAxisSetting >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QAXISSETTING_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAbstractActionInput >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QABSTRACTACTIONINPUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QActionInput >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QACTIONINPUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QInputSequence >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QINPUTSEQUENCE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QInputChord >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QINPUTCHORD_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAbstractAxisInput >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QABSTRACTAXISINPUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QAnalogAxisInput >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QANALOGAXISINPUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QButtonAxisInput >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QBUTTONAXISINPUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QKeyEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QKEYEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QWheelEvent::Buttons >() { return SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QWHEELEVENT_BUTTONS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QWheelEvent::Modifiers >() { return SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QWHEELEVENT_MODIFIERS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QWheelEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QWHEELEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QMouseEvent::Buttons >() { return SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QMOUSEEVENT_BUTTONS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QMouseEvent::Modifiers >() { return SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QMOUSEEVENT_MODIFIERS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DInput::QMouseEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DInputTypes[SBK_QT3DINPUT_QMOUSEEVENT_IDX]); }

} // namespace Shiboken

#endif // SBK_QT3DINPUT_PYTHON_H

