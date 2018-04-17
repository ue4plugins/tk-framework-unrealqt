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


#ifndef SBK_QT3DRENDER_PYTHON_H
#define SBK_QT3DRENDER_PYTHON_H

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
#include <qgraphicsapifilter.h>
#include <qshaderprogram.h>
#include <qsortpolicy.h>
#include <qmaterial.h>
#include <qtextureimage.h>
#include <qeffect.h>
#include <qabstractfunctor.h>
#include <qtexturegenerator.h>
#include <qblendequationarguments.h>
#include <qfrustumculling.h>
#include <qbuffer.h>
#include <qpolygonoffset.h>
#include <qtexture.h>
#include <qcomputecommand.h>
#include <qtexturewrapmode.h>
#include <qpickevent.h>
#include <qstenciloperationarguments.h>
#include <qframegraphnodecreatedchange.h>
#include <qabstracttexture.h>
#include <qobjectpicker.h>
#include <qstencilmask.h>
#include <qblendequation.h>
#include <qtextureimagedata.h>
#include <qpaintedtextureimage.h>
#include <qcameralens.h>
#include <qclearbuffers.h>
#include <qrendercapture.h>
#include <qsceneloader.h>
#include <qfrontface.h>
#include <qclipplane.h>
#include <qlevelofdetailswitch.h>
#include <qlayer.h>
#include <qstenciltest.h>
#include <qstenciltestarguments.h>
#include <qpicktriangleevent.h>
#include <qseamlesscubemap.h>
#include <qtextureimagedatagenerator.h>
#include <qcamera.h>
#include <qattribute.h>
#include <qrendersurfaceselector.h>
#include <qscissortest.h>
#include <qrenderstate.h>
#include <qrenderpass.h>
#include <qrendertargetselector.h>
#include <qrendertarget.h>
#include <qpointlight.h>
#include <qtechniquefilter.h>
#include <qabstracttextureimage.h>
#include <qbufferdatagenerator.h>
#include <qnodraw.h>
#include <qtexturedata.h>
#include <qdispatchcompute.h>
#include <qrendersettings.h>
#include <qalphacoverage.h>
#include <qcolormask.h>
#include <qstenciloperation.h>
#include <qrenderstateset.h>
#include <qrenderpassfilter.h>
#include <qcullface.h>
#include <qfilterkey.h>
#include <qgeometry.h>
#include <qlevelofdetailboundingsphere.h>
#include <qshaderdata.h>
#include <qgeometryrenderer.h>
#include <qrenderaspect.h>
#include <qabstractlight.h>
#include <qtechnique.h>
#include <qdithering.h>
#include <qbuffercapture.h>
#include <qdepthtest.h>
#include <qlevelofdetail.h>
#include <qdirectionallight.h>
#include <qalphatest.h>
#include <qcameraselector.h>
#include <qspotlight.h>
#include <qenvironmentlight.h>
#include <qlayerfilter.h>
#include <qpickingsettings.h>
#include <qviewport.h>
#include <qpointsize.h>
#include <qframegraphnode.h>
#include <qparameter.h>
#include <qrendertargetoutput.h>
#include <qmultisampleantialiasing.h>
#include <qmesh.h>
#include <qgeometryfactory.h>
#include <qmemorybarrier.h>
#include <qnodepthmask.h>
// Conversion Includes - Primitive Types
#include <QString>
#include <wtypes.h>
#include <signalmanager.h>
#include <QStringList>
#include <qabstractitemmodel.h>

// Conversion Includes - Container Types
#include <QVector>
#include <QMultiMap>
#include <QPair>
#include <pysideqflags.h>
#include <QSet>
#include <QStack>
#include <QList>
#include <QQueue>
#include <QMap>
#include <QLinkedList>

// Type indices
#define SBK_QT3DRENDER_IDX                                           0
#define SBK_QT3DRENDER_QTEXTUREDATA_IDX                              138
#define SBK_QT3DRENDER_PROPERTYREADERINTERFACE_IDX                   1
#define SBK_QT3DRENDER_QFRAMEGRAPHNODECREATEDCHANGEBASE_IDX          51
#define SBK_QT3DRENDER_QTEXTUREIMAGEDATA_IDX                         142
#define SBK_QT3DRENDER_QABSTRACTFUNCTOR_IDX                          2
#define SBK_QT3DRENDER_QTEXTUREIMAGEDATAGENERATOR_IDX                143
#define SBK_QT3DRENDER_QBUFFERDATAGENERATOR_IDX                      29
#define SBK_QT3DRENDER_QGEOMETRYFACTORY_IDX                          56
#define SBK_QT3DRENDER_QTEXTUREGENERATOR_IDX                         139
#define SBK_QT3DRENDER_QLEVELOFDETAILBOUNDINGSPHERE_IDX              66
#define SBK_QT3DRENDER_QPICKEVENT_IDX                                78
#define SBK_QT3DRENDER_QPICKEVENT_BUTTONS_IDX                        79
#define SBK_QT3DRENDER_QPICKEVENT_MODIFIERS_IDX                      80
#define SBK_QT3DRENDER_QPICKTRIANGLEEVENT_IDX                        81
#define SBK_QT3DRENDER_QRENDERCAPTUREREPLY_IDX                       93
#define SBK_QT3DRENDER_QSTENCILTESTARGUMENTS_IDX                     123
#define SBK_QT3DRENDER_QSTENCILTESTARGUMENTS_STENCILFACEMODE_IDX     124
#define SBK_QT3DRENDER_QSTENCILTESTARGUMENTS_STENCILFUNCTION_IDX     125
#define SBK_QT3DRENDER_QSTENCILOPERATIONARGUMENTS_IDX                119
#define SBK_QT3DRENDER_QSTENCILOPERATIONARGUMENTS_FACEMODE_IDX       120
#define SBK_QT3DRENDER_QSTENCILOPERATIONARGUMENTS_OPERATION_IDX      121
#define SBK_QT3DRENDER_QTEXTUREWRAPMODE_IDX                          146
#define SBK_QT3DRENDER_QTEXTUREWRAPMODE_WRAPMODE_IDX                 147
#define SBK_QT3DRENDER_QGRAPHICSAPIFILTER_IDX                        59
#define SBK_QT3DRENDER_QGRAPHICSAPIFILTER_API_IDX                    60
#define SBK_QT3DRENDER_QGRAPHICSAPIFILTER_OPENGLPROFILE_IDX          61
#define SBK_QT3DRENDER_QRENDERASPECT_IDX                             90
#define SBK_QT3DRENDER_QRENDERASPECT_RENDERTYPE_IDX                  91
#define SBK_QT3DRENDER_QEFFECT_IDX                                   47
#define SBK_QT3DRENDER_QFRAMEGRAPHNODE_IDX                           50
#define SBK_QT3DRENDER_QBUFFERCAPTURE_IDX                            28
#define SBK_QT3DRENDER_QRENDERSTATESET_IDX                           99
#define SBK_QT3DRENDER_QDISPATCHCOMPUTE_IDX                          45
#define SBK_QT3DRENDER_QRENDERPASSFILTER_IDX                         95
#define SBK_QT3DRENDER_QNODRAW_IDX                                   74
#define SBK_QT3DRENDER_QFRUSTUMCULLING_IDX                           54
#define SBK_QT3DRENDER_QCAMERASELECTOR_IDX                           34
#define SBK_QT3DRENDER_QRENDERTARGETSELECTOR_IDX                     104
#define SBK_QT3DRENDER_QSORTPOLICY_IDX                               114
#define SBK_QT3DRENDER_QSORTPOLICY_SORTTYPE_IDX                      115
#define SBK_QT3DRENDER_QRENDERSURFACESELECTOR_IDX                    100
#define SBK_QT3DRENDER_QCLEARBUFFERS_IDX                             35
#define SBK_QT3DRENDER_QCLEARBUFFERS_BUFFERTYPE_IDX                  36
#define SBK_QT3DRENDER_QVIEWPORT_IDX                                 148
#define SBK_QT3DRENDER_QLAYERFILTER_IDX                              63
#define SBK_QT3DRENDER_QTECHNIQUEFILTER_IDX                          127
#define SBK_QT3DRENDER_QRENDERCAPTURE_IDX                            92
#define SBK_QT3DRENDER_QMEMORYBARRIER_IDX                            69
#define SBK_QT3DRENDER_QMEMORYBARRIER_OPERATION_IDX                  70
#define SBK_QT3DRENDER_QRENDERSTATE_IDX                              98
#define SBK_QT3DRENDER_QFRONTFACE_IDX                                52
#define SBK_QT3DRENDER_QFRONTFACE_WINDINGDIRECTION_IDX               53
#define SBK_QT3DRENDER_QBLENDEQUATION_IDX                            20
#define SBK_QT3DRENDER_QBLENDEQUATION_BLENDFUNCTION_IDX              21
#define SBK_QT3DRENDER_QALPHATEST_IDX                                15
#define SBK_QT3DRENDER_QALPHATEST_ALPHAFUNCTION_IDX                  16
#define SBK_QT3DRENDER_QALPHACOVERAGE_IDX                            14
#define SBK_QT3DRENDER_QNODEPTHMASK_IDX                              73
#define SBK_QT3DRENDER_QMULTISAMPLEANTIALIASING_IDX                  72
#define SBK_QT3DRENDER_QBLENDEQUATIONARGUMENTS_IDX                   22
#define SBK_QT3DRENDER_QBLENDEQUATIONARGUMENTS_BLENDING_IDX          23
#define SBK_QT3DRENDER_QPOLYGONOFFSET_IDX                            89
#define SBK_QT3DRENDER_QSEAMLESSCUBEMAP_IDX                          109
#define SBK_QT3DRENDER_QCOLORMASK_IDX                                38
#define SBK_QT3DRENDER_QPOINTSIZE_IDX                                87
#define SBK_QT3DRENDER_QPOINTSIZE_SIZEMODE_IDX                       88
#define SBK_QT3DRENDER_QSCISSORTEST_IDX                              108
#define SBK_QT3DRENDER_QCLIPPLANE_IDX                                37
#define SBK_QT3DRENDER_QSTENCILOPERATION_IDX                         118
#define SBK_QT3DRENDER_QSTENCILMASK_IDX                              117
#define SBK_QT3DRENDER_QDEPTHTEST_IDX                                42
#define SBK_QT3DRENDER_QDEPTHTEST_DEPTHFUNCTION_IDX                  43
#define SBK_QT3DRENDER_QCULLFACE_IDX                                 40
#define SBK_QT3DRENDER_QCULLFACE_CULLINGMODE_IDX                     41
#define SBK_QT3DRENDER_QSTENCILTEST_IDX                              122
#define SBK_QT3DRENDER_QDITHERING_IDX                                46
#define SBK_QT3DRENDER_QBUFFER_IDX                                   24
#define SBK_QT3DRENDER_QBUFFER_BUFFERTYPE_IDX                        26
#define SBK_QT3DRENDER_QBUFFER_USAGETYPE_IDX                         27
#define SBK_QT3DRENDER_QBUFFER_ACCESSTYPE_IDX                        25
#define SBK_QT3DRENDER_QABSTRACTTEXTUREIMAGE_IDX                     13
#define SBK_QT3DRENDER_QPAINTEDTEXTUREIMAGE_IDX                      76
#define SBK_QT3DRENDER_QTEXTUREIMAGE_IDX                             140
#define SBK_QT3DRENDER_QTEXTUREIMAGE_STATUS_IDX                      141
#define SBK_QT3DRENDER_QRENDERPASS_IDX                               94
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_IDX                          5
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_STATUS_IDX                   10
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_TARGET_IDX                   11
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_TEXTUREFORMAT_IDX            12
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_FILTER_IDX                   9
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_CUBEMAPFACE_IDX              8
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_COMPARISONFUNCTION_IDX       6
#define SBK_QT3DRENDER_QABSTRACTTEXTURE_COMPARISONMODE_IDX           7
#define SBK_QT3DRENDER_QTEXTURE2DARRAY_IDX                           131
#define SBK_QT3DRENDER_QTEXTURE2D_IDX                                130
#define SBK_QT3DRENDER_QTEXTURE1DARRAY_IDX                           129
#define SBK_QT3DRENDER_QTEXTURE2DMULTISAMPLEARRAY_IDX                133
#define SBK_QT3DRENDER_QTEXTURE2DMULTISAMPLE_IDX                     132
#define SBK_QT3DRENDER_QTEXTURECUBEMAPARRAY_IDX                      137
#define SBK_QT3DRENDER_QTEXTURECUBEMAP_IDX                           136
#define SBK_QT3DRENDER_QTEXTURELOADER_IDX                            144
#define SBK_QT3DRENDER_QTEXTUREBUFFER_IDX                            135
#define SBK_QT3DRENDER_QTEXTURERECTANGLE_IDX                         145
#define SBK_QT3DRENDER_QTEXTURE1D_IDX                                128
#define SBK_QT3DRENDER_QTEXTURE3D_IDX                                134
#define SBK_QT3DRENDER_QPICKINGSETTINGS_IDX                          82
#define SBK_QT3DRENDER_QPICKINGSETTINGS_PICKMETHOD_IDX               84
#define SBK_QT3DRENDER_QPICKINGSETTINGS_PICKRESULTMODE_IDX           85
#define SBK_QT3DRENDER_QPICKINGSETTINGS_FACEORIENTATIONPICKINGMODE_IDX 83
#define SBK_QT3DRENDER_QFILTERKEY_IDX                                49
#define SBK_QT3DRENDER_QSHADERDATA_IDX                               110
#define SBK_QT3DRENDER_QMATERIAL_IDX                                 68
#define SBK_QT3DRENDER_QRENDERSETTINGS_IDX                           96
#define SBK_QT3DRENDER_QRENDERSETTINGS_RENDERPOLICY_IDX              97
#define SBK_QT3DRENDER_QOBJECTPICKER_IDX                             75
#define SBK_QT3DRENDER_QSCENELOADER_IDX                              105
#define SBK_QT3DRENDER_QSCENELOADER_STATUS_IDX                       107
#define SBK_QT3DRENDER_QSCENELOADER_COMPONENTTYPE_IDX                106
#define SBK_QT3DRENDER_QCAMERALENS_IDX                               32
#define SBK_QT3DRENDER_QCAMERALENS_PROJECTIONTYPE_IDX                33
#define SBK_QT3DRENDER_QRENDERTARGET_IDX                             101
#define SBK_QT3DRENDER_QGEOMETRYRENDERER_IDX                         57
#define SBK_QT3DRENDER_QGEOMETRYRENDERER_PRIMITIVETYPE_IDX           58
#define SBK_QT3DRENDER_QMESH_IDX                                     71
#define SBK_QT3DRENDER_QLEVELOFDETAIL_IDX                            64
#define SBK_QT3DRENDER_QLEVELOFDETAIL_THRESHOLDTYPE_IDX              65
#define SBK_QT3DRENDER_QLEVELOFDETAILSWITCH_IDX                      67
#define SBK_QT3DRENDER_QLAYER_IDX                                    62
#define SBK_QT3DRENDER_QCOMPUTECOMMAND_IDX                           39
#define SBK_QT3DRENDER_QABSTRACTLIGHT_IDX                            3
#define SBK_QT3DRENDER_QABSTRACTLIGHT_TYPE_IDX                       4
#define SBK_QT3DRENDER_QSPOTLIGHT_IDX                                116
#define SBK_QT3DRENDER_QPOINTLIGHT_IDX                               86
#define SBK_QT3DRENDER_QDIRECTIONALLIGHT_IDX                         44
#define SBK_QT3DRENDER_QENVIRONMENTLIGHT_IDX                         48
#define SBK_QT3DRENDER_QTECHNIQUE_IDX                                126
#define SBK_QT3DRENDER_QPARAMETER_IDX                                77
#define SBK_QT3DRENDER_QGEOMETRY_IDX                                 55
#define SBK_QT3DRENDER_QCAMERA_IDX                                   30
#define SBK_QT3DRENDER_QCAMERA_CAMERATRANSLATIONOPTION_IDX           31
#define SBK_QT3DRENDER_QRENDERTARGETOUTPUT_IDX                       102
#define SBK_QT3DRENDER_QRENDERTARGETOUTPUT_ATTACHMENTPOINT_IDX       103
#define SBK_QT3DRENDER_QSHADERPROGRAM_IDX                            111
#define SBK_QT3DRENDER_QSHADERPROGRAM_SHADERTYPE_IDX                 112
#define SBK_QT3DRENDER_QSHADERPROGRAM_STATUS_IDX                     113
#define SBK_QT3DRENDER_QATTRIBUTE_IDX                                17
#define SBK_QT3DRENDER_QATTRIBUTE_ATTRIBUTETYPE_IDX                  18
#define SBK_QT3DRENDER_QATTRIBUTE_VERTEXBASETYPE_IDX                 19
#define SBK_Qt3DRender_IDX_COUNT                                     149

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_Qt3DRenderTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_Qt3DRenderTypeConverters;

// Converter indices
#define SBK_QT3DRENDER_QLIST_QOBJECTPTR_IDX                          0 // const QList<QObject* > &
#define SBK_QT3DRENDER_QLIST_QBYTEARRAY_IDX                          1 // QList<QByteArray >
#define SBK_QT3DRENDER_QVECTOR_QT3DCORE_QNODEPTR_IDX                 2 // QVector<Qt3DCore::QNode* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QFILTERKEYPTR_IDX          3 // QVector<Qt3DRender::QFilterKey* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QPARAMETERPTR_IDX          4 // QVector<Qt3DRender::QParameter* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QRENDERPASSPTR_IDX         5 // QVector<Qt3DRender::QRenderPass* >
#define SBK_QT3DRENDER_QVECTOR_QT3DCORE_QENTITYPTR_IDX               6 // QVector<Qt3DCore::QEntity* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QRENDERTARGETOUTPUTPTR_IDX 7 // QVector<Qt3DRender::QRenderTargetOutput* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QRENDERSTATEPTR_IDX        8 // QVector<Qt3DRender::QRenderState* >
#define SBK_QT3DRENDER_QVECTOR_QREAL_IDX                             9 // const QVector<qreal > &
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QATTRIBUTEPTR_IDX          10 // QVector<Qt3DRender::QAttribute* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QTECHNIQUEPTR_IDX          11 // QVector<Qt3DRender::QTechnique* >
#define SBK_QT3DRENDER_QVECTOR_QT3DCORE_QCOMPONENTPTR_IDX            12 // QVector<Qt3DCore::QComponent* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QLAYERPTR_IDX              13 // QVector<Qt3DRender::QLayer* >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QRENDERTARGETOUTPUT_ATTACHMENTPOINT_IDX 14 // QVector<Qt3DRender::QRenderTargetOutput::AttachmentPoint >
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QSORTPOLICY_SORTTYPE_IDX   15 // const QVector<Qt3DRender::QSortPolicy::SortType > &
#define SBK_QT3DRENDER_QVECTOR_INT_IDX                               16 // const QVector<int > &
#define SBK_QT3DRENDER_QVECTOR_QT3DRENDER_QABSTRACTTEXTUREIMAGEPTR_IDX 17 // QVector<Qt3DRender::QAbstractTextureImage* >
#define SBK_QT3DRENDER_QLIST_QVARIANT_IDX                            18 // QList<QVariant >
#define SBK_QT3DRENDER_QLIST_QSTRING_IDX                             19 // QList<QString >
#define SBK_QT3DRENDER_QMAP_QSTRING_QVARIANT_IDX                     20 // QMap<QString,QVariant >
#define SBK_Qt3DRender_CONVERTERS_IDX_COUNT                          21

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureData >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREDATA_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::PropertyReaderInterface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_PROPERTYREADERINTERFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QFrameGraphNodeCreatedChangeBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QFRAMEGRAPHNODECREATEDCHANGEBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureImageData >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREIMAGEDATA_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractFunctor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTFUNCTOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureImageDataGenerator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREIMAGEDATAGENERATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBufferDataGenerator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBUFFERDATAGENERATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QGeometryFactory >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QGEOMETRYFACTORY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureGenerator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREGENERATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QLevelOfDetailBoundingSphere >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QLEVELOFDETAILBOUNDINGSPHERE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickEvent::Buttons >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKEVENT_BUTTONS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickEvent::Modifiers >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKEVENT_MODIFIERS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickTriangleEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKTRIANGLEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderCaptureReply >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERCAPTUREREPLY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilTestArguments::StencilFaceMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILTESTARGUMENTS_STENCILFACEMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilTestArguments::StencilFunction >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILTESTARGUMENTS_STENCILFUNCTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilTestArguments >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILTESTARGUMENTS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilOperationArguments::FaceMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILOPERATIONARGUMENTS_FACEMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilOperationArguments::Operation >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILOPERATIONARGUMENTS_OPERATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilOperationArguments >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILOPERATIONARGUMENTS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureWrapMode::WrapMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREWRAPMODE_WRAPMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureWrapMode >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREWRAPMODE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QGraphicsApiFilter::Api >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QGRAPHICSAPIFILTER_API_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QGraphicsApiFilter::OpenGLProfile >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QGRAPHICSAPIFILTER_OPENGLPROFILE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QGraphicsApiFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QGRAPHICSAPIFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderAspect::RenderType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERASPECT_RENDERTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderAspect >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERASPECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QEffect >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QEFFECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QFrameGraphNode >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QFRAMEGRAPHNODE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBufferCapture >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBUFFERCAPTURE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderStateSet >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERSTATESET_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QDispatchCompute >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QDISPATCHCOMPUTE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderPassFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERPASSFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QNoDraw >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QNODRAW_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QFrustumCulling >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QFRUSTUMCULLING_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QCameraSelector >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCAMERASELECTOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderTargetSelector >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERTARGETSELECTOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QSortPolicy::SortType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSORTPOLICY_SORTTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QSortPolicy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSORTPOLICY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderSurfaceSelector >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERSURFACESELECTOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QClearBuffers::BufferType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCLEARBUFFERS_BUFFERTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QClearBuffers >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCLEARBUFFERS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QViewport >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QVIEWPORT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QLayerFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QLAYERFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTechniqueFilter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTECHNIQUEFILTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderCapture >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERCAPTURE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QMemoryBarrier::Operation >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QMEMORYBARRIER_OPERATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QMemoryBarrier >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QMEMORYBARRIER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderState >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERSTATE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QFrontFace::WindingDirection >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QFRONTFACE_WINDINGDIRECTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QFrontFace >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QFRONTFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBlendEquation::BlendFunction >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBLENDEQUATION_BLENDFUNCTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBlendEquation >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBLENDEQUATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAlphaTest::AlphaFunction >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QALPHATEST_ALPHAFUNCTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAlphaTest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QALPHATEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAlphaCoverage >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QALPHACOVERAGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QNoDepthMask >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QNODEPTHMASK_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QMultiSampleAntiAliasing >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QMULTISAMPLEANTIALIASING_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBlendEquationArguments::Blending >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBLENDEQUATIONARGUMENTS_BLENDING_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBlendEquationArguments >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBLENDEQUATIONARGUMENTS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPolygonOffset >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPOLYGONOFFSET_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QSeamlessCubemap >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSEAMLESSCUBEMAP_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QColorMask >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCOLORMASK_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPointSize::SizeMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPOINTSIZE_SIZEMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPointSize >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPOINTSIZE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QScissorTest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSCISSORTEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QClipPlane >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCLIPPLANE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilOperation >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILOPERATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilMask >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILMASK_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QDepthTest::DepthFunction >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QDEPTHTEST_DEPTHFUNCTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QDepthTest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QDEPTHTEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QCullFace::CullingMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCULLFACE_CULLINGMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QCullFace >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCULLFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QStencilTest >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSTENCILTEST_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QDithering >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QDITHERING_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBuffer::BufferType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBUFFER_BUFFERTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBuffer::UsageType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBUFFER_USAGETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBuffer::AccessType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBUFFER_ACCESSTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QBuffer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QBUFFER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTextureImage >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTUREIMAGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPaintedTextureImage >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPAINTEDTEXTUREIMAGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureImage::Status >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREIMAGE_STATUS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureImage >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREIMAGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderPass >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERPASS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture::Status >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_STATUS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture::Target >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_TARGET_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture::TextureFormat >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_TEXTUREFORMAT_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture::Filter >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_FILTER_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture::CubeMapFace >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_CUBEMAPFACE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture::ComparisonFunction >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_COMPARISONFUNCTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture::ComparisonMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_COMPARISONMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractTexture >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTTEXTURE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTexture2DArray >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURE2DARRAY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTexture2D >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURE2D_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTexture1DArray >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURE1DARRAY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTexture2DMultisampleArray >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURE2DMULTISAMPLEARRAY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTexture2DMultisample >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURE2DMULTISAMPLE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureCubeMapArray >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURECUBEMAPARRAY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureCubeMap >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURECUBEMAP_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureLoader >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURELOADER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureBuffer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTUREBUFFER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTextureRectangle >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURERECTANGLE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTexture1D >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURE1D_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTexture3D >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTEXTURE3D_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickingSettings::PickMethod >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKINGSETTINGS_PICKMETHOD_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickingSettings::PickResultMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKINGSETTINGS_PICKRESULTMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickingSettings::FaceOrientationPickingMode >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKINGSETTINGS_FACEORIENTATIONPICKINGMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPickingSettings >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPICKINGSETTINGS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QFilterKey >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QFILTERKEY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QShaderData >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSHADERDATA_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QMaterial >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QMATERIAL_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderSettings::RenderPolicy >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERSETTINGS_RENDERPOLICY_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderSettings >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERSETTINGS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QObjectPicker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QOBJECTPICKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QSceneLoader::Status >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSCENELOADER_STATUS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QSceneLoader::ComponentType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSCENELOADER_COMPONENTTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QSceneLoader >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSCENELOADER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QCameraLens::ProjectionType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCAMERALENS_PROJECTIONTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QCameraLens >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCAMERALENS_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderTarget >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERTARGET_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QGeometryRenderer::PrimitiveType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QGEOMETRYRENDERER_PRIMITIVETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QGeometryRenderer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QGEOMETRYRENDERER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QMesh >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QMESH_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QLevelOfDetail::ThresholdType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QLEVELOFDETAIL_THRESHOLDTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QLevelOfDetail >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QLEVELOFDETAIL_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QLevelOfDetailSwitch >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QLEVELOFDETAILSWITCH_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QLayer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QLAYER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QComputeCommand >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCOMPUTECOMMAND_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractLight::Type >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTLIGHT_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAbstractLight >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QABSTRACTLIGHT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QSpotLight >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSPOTLIGHT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QPointLight >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPOINTLIGHT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QDirectionalLight >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QDIRECTIONALLIGHT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QEnvironmentLight >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QENVIRONMENTLIGHT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QTechnique >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QTECHNIQUE_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QParameter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QPARAMETER_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QGeometry >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QGEOMETRY_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QCamera::CameraTranslationOption >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCAMERA_CAMERATRANSLATIONOPTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QCamera >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QCAMERA_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderTargetOutput::AttachmentPoint >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERTARGETOUTPUT_ATTACHMENTPOINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QRenderTargetOutput >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QRENDERTARGETOUTPUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QShaderProgram::ShaderType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSHADERPROGRAM_SHADERTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QShaderProgram::Status >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSHADERPROGRAM_STATUS_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QShaderProgram >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QSHADERPROGRAM_IDX]); }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAttribute::AttributeType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QATTRIBUTE_ATTRIBUTETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAttribute::VertexBaseType >() { return SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QATTRIBUTE_VERTEXBASETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::Qt3DRender::QAttribute >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_Qt3DRenderTypes[SBK_QT3DRENDER_QATTRIBUTE_IDX]); }

} // namespace Shiboken

#endif // SBK_QT3DRENDER_PYTHON_H

