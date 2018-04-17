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


#ifndef SBK_QT3DANIMATION_PYTHON_H
#define SBK_QT3DANIMATION_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

#include <pysidesignal.h>
// Module Includes
#include <pyside2_qt3drender_python.h>
#include <pyside2_qt3dcore_python.h>
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qvertexblendanimation.h>
#include <qanimationcontroller.h>
#include <qadditiveclipblend.h>
#include <qclipanimator.h>
#include <qanimationaspect.h>
#include <qmorphinganimation.h>
#include <qblendedclipanimator.h>
#include <qkeyframeanimation.h>
#include <qabstractanimation.h>
#include <qabstractclipblendnode.h>
#include <qanimationgroup.h>
#include <qmorphtarget.h>
#include <qlerpclipblend.h>
#include <qabstractanimationclip.h>
#include <qabstractclipanimator.h>
// Conversion Includes - Primitive Types
#include <qabstractitemmodel.h>
#include <QString>
#include <wtypes.h>
#include <QStringList>
#include <signalmanager.h>

// Conversion Includes - Container Types
#include <QPair>
#include <pysideqflags.h>
#include <QMap>
#include <QStack>
#include <QMultiMap>
#include <QVector>
#include <QQueue>
#include <QList>
#include <QLinkedList>
#include <QSet>

// Type indices
#define SBK_QT3DANIMATION_IDX                                        0
#define SBK_QT3DANIMATION_QABSTRACTANIMATION_IDX                     1
#define SBK_QT3DANIMATION_QABSTRACTANIMATION_ANIMATIONTYPE_IDX       2
#define SBK_QT3DANIMATION_QKEYFRAMEANIMATION_IDX                     13
#define SBK_QT3DANIMATION_QKEYFRAMEANIMATION_REPEATMODE_IDX          14
#define SBK_QT3DANIMATION_QMORPHINGANIMATION_IDX                     17
#define SBK_QT3DANIMATION_QMORPHINGANIMATION_METHOD_IDX              18
#define SBK_QT3DANIMATION_QVERTEXBLENDANIMATION_IDX                  19
#define SBK_QT3DANIMATION_QMORPHTARGET_IDX                           16
#define SBK_QT3DANIMATION_QANIMATIONCONTROLLER_IDX                   9
#define SBK_QT3DANIMATION_QABSTRACTANIMATIONCLIP_IDX                 3
#define SBK_QT3DANIMATION_QABSTRACTCLIPBLENDNODE_IDX                 6
#define SBK_QT3DANIMATION_QLERPCLIPBLEND_IDX                         15
#define SBK_QT3DANIMATION_QADDITIVECLIPBLEND_IDX                     7
#define SBK_QT3DANIMATION_QABSTRACTCLIPANIMATOR_IDX                  4
#define SBK_QT3DANIMATION_QABSTRACTCLIPANIMATOR_LOOPS_IDX            5
#define SBK_QT3DANIMATION_QBLENDEDCLIPANIMATOR_IDX                   11
#define SBK_QT3DANIMATION_QCLIPANIMATOR_IDX                          12
#define SBK_QT3DANIMATION_QANIMATIONASPECT_IDX                       8
#define SBK_QT3DANIMATION_QANIMATIONGROUP_IDX                        10
#define SBK_Qt3DAnimation_IDX_COUNT                                  20

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_Qt3DAnimationTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_Qt3DAnimationTypeConverters;

// Converter indices
#define SBK_QT3DANIMATION_QVECTOR_QT3DRENDER_QATTRIBUTEPTR_IDX       0 // QVector<Qt3DRender::QAttribute* >
#define SBK_QT3DANIMATION_QLIST_QOBJECTPTR_IDX                       1 // const QList<QObject* > &
#define SBK_QT3DANIMATION_QLIST_QBYTEARRAY_IDX                       2 // QList<QByteArray >
#define SBK_QT3DANIMATION_QVECTOR_QT3DANIMATION_QANIMATIONGROUPPTR_IDX 3 // QVector<Qt3DAnimation::QAnimationGroup* >
#define SBK_QT3DANIMATION_QVECTOR_QT3DANIMATION_QABSTRACTANIMATIONPTR_IDX 4 // QVector<Qt3DAnimation::QAbstractAnimation* >
#define SBK_QT3DANIMATION_QVECTOR_QT3DCORE_QNODEPTR_IDX              5 // QVector<Qt3DCore::QNode* >
#define SBK_QT3DANIMATION_QVECTOR_QT3DCORE_QENTITYPTR_IDX            6 // QVector<Qt3DCore::QEntity* >
#define SBK_QT3DANIMATION_QVECTOR_QT3DANIMATION_QMORPHTARGETPTR_IDX  7 // QVector<Qt3DAnimation::QMorphTarget* >
#define SBK_QT3DANIMATION_QVECTOR_FLOAT_IDX                          8 // const QVector<float > &
#define SBK_QT3DANIMATION_QVECTOR_QT3DCORE_QTRANSFORMPTR_IDX         9 // QVector<Qt3DCore::QTransform* >
#define SBK_QT3DANIMATION_QLIST_QVARIANT_IDX                         10 // QList<QVariant >
#define SBK_QT3DANIMATION_QLIST_QSTRING_IDX                          11 // QList<QString >
#define SBK_QT3DANIMATION_QMAP_QSTRING_QVARIANT_IDX                  12 // QMap<QString,QVariant >
#define SBK_Qt3DAnimation_CONVERTERS_IDX_COUNT                       13

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAbstractAnimation::AnimationType >() { return SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QABSTRACTANIMATION_ANIMATIONTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAbstractAnimation >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QABSTRACTANIMATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QKeyframeAnimation::RepeatMode >() { return SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QKEYFRAMEANIMATION_REPEATMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QKeyframeAnimation >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QKEYFRAMEANIMATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QMorphingAnimation::Method >() { return SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QMORPHINGANIMATION_METHOD_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QMorphingAnimation >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QMORPHINGANIMATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QVertexBlendAnimation >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QVERTEXBLENDANIMATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QMorphTarget >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QMORPHTARGET_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAnimationController >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QANIMATIONCONTROLLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAbstractAnimationClip >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QABSTRACTANIMATIONCLIP_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAbstractClipBlendNode >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QABSTRACTCLIPBLENDNODE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QLerpClipBlend >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QLERPCLIPBLEND_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAdditiveClipBlend >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QADDITIVECLIPBLEND_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAbstractClipAnimator::Loops >() { return SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QABSTRACTCLIPANIMATOR_LOOPS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAbstractClipAnimator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QABSTRACTCLIPANIMATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QBlendedClipAnimator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QBLENDEDCLIPANIMATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QClipAnimator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QCLIPANIMATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAnimationAspect >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QANIMATIONASPECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DAnimation::QAnimationGroup >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DAnimationTypes[SBK_QT3DANIMATION_QANIMATIONGROUP_IDX]); }

} // namespace Shiboken

#endif // SBK_QT3DANIMATION_PYTHON_H

