// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/ApplicationUsage>
#include <osg/Camera>
#include <osg/CopyOp>
#include <osg/Drawable>
#include <osg/Image>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/RenderInfo>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgViewer/ViewerEventHandlers>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgViewer::HelpHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_ConstructorWithDefaults1(IN, osg::ApplicationUsage *, au, 0,
	                           Properties::NON_EXPLICIT,
	                           ____HelpHandler__osg_ApplicationUsage_P1,
	                           "",
	                           "");
	I_Method1(void, setApplicationUsage, IN, osg::ApplicationUsage *, au,
	          Properties::NON_VIRTUAL,
	          __void__setApplicationUsage__osg_ApplicationUsage_P1,
	          "",
	          "");
	I_Method0(osg::ApplicationUsage *, getApplicationUsage,
	          Properties::NON_VIRTUAL,
	          __osg_ApplicationUsage_P1__getApplicationUsage,
	          "",
	          "");
	I_Method0(const osg::ApplicationUsage *, getApplicationUsage,
	          Properties::NON_VIRTUAL,
	          __C5_osg_ApplicationUsage_P1__getApplicationUsage,
	          "",
	          "");
	I_Method1(void, setKeyEventTogglesOnScreenHelp, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventTogglesOnScreenHelp__int,
	          "",
	          "");
	I_Method0(int, getKeyEventTogglesOnScreenHelp,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventTogglesOnScreenHelp,
	          "",
	          "");
	I_Method0(void, reset,
	          Properties::NON_VIRTUAL,
	          __void__reset,
	          "",
	          "");
	I_Method0(osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method0(const osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Deprecated, Handle events, return true if handled, false otherwise. ",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_ProtectedMethod1(void, setUpHUDCamera, IN, osgViewer::ViewerBase *, viewer,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setUpHUDCamera__osgViewer_ViewerBase_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, setUpScene, IN, osgViewer::ViewerBase *, viewer,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setUpScene__osgViewer_ViewerBase_P1,
	                   "",
	                   "");
	I_SimpleProperty(osg::ApplicationUsage *, ApplicationUsage, 
	                 __osg_ApplicationUsage_P1__getApplicationUsage, 
	                 __void__setApplicationUsage__osg_ApplicationUsage_P1);
	I_SimpleProperty(osg::Camera *, Camera, 
	                 __osg_Camera_P1__getCamera, 
	                 0);
	I_SimpleProperty(int, KeyEventTogglesOnScreenHelp, 
	                 __int__getKeyEventTogglesOnScreenHelp, 
	                 __void__setKeyEventTogglesOnScreenHelp__int);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::InteractiveImageHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_BaseType(osg::Drawable::CullCallback);
	I_Constructor1(IN, osg::Image *, image,
	               Properties::NON_EXPLICIT,
	               ____InteractiveImageHandler__osg_Image_P1,
	               "",
	               "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method4(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa, IN, osg::Object *, x, IN, osg::NodeVisitor *, nv,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1__osg_Object_P1__osg_NodeVisitor_P1,
	          "Handle events, return true if handled, false otherwise. ",
	          "");
	I_Method3(bool, cull, IN, osg::NodeVisitor *, nv, IN, osg::Drawable *, drawable, IN, osg::RenderInfo *, renderInfo,
	          Properties::VIRTUAL,
	          __bool__cull__osg_NodeVisitor_P1__osg_Drawable_P1__osg_RenderInfo_P1,
	          "do customized cull code, return true if drawable should be culled. ",
	          "");
	I_ProtectedConstructor0(____InteractiveImageHandler,
	                        "",
	                        "");
	I_ProtectedConstructorWithDefaults2(IN, const osgViewer::InteractiveImageHandler &, rhs, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                                    ____InteractiveImageHandler__C5_InteractiveImageHandler_R1__C5_osg_CopyOp_R1,
	                                    "",
	                                    "");
	I_ProtectedMethod5(bool, mousePosition, IN, osgViewer::View *, view, IN, osg::NodeVisitor *, nv, IN, const osgGA::GUIEventAdapter &, ea, IN, int &, x, IN, int &, y,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __bool__mousePosition__osgViewer_View_P1__osg_NodeVisitor_P1__C5_osgGA_GUIEventAdapter_R1__int_R1__int_R1,
	                   "",
	                   "");
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::LODScaleHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_Constructor0(____LODScaleHandler,
	               "",
	               "");
	I_Method1(void, setKeyEventIncreaseLODScale, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventIncreaseLODScale__int,
	          "",
	          "");
	I_Method0(int, getKeyEventIncreaseLODScale,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventIncreaseLODScale,
	          "",
	          "");
	I_Method1(void, setKeyEventDecreaseLODScale, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventDecreaseLODScale__int,
	          "",
	          "");
	I_Method0(int, getKeyEventDecreaseLODScale,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventDecreaseLODScale,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Deprecated, Handle events, return true if handled, false otherwise. ",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_SimpleProperty(int, KeyEventDecreaseLODScale, 
	                 __int__getKeyEventDecreaseLODScale, 
	                 __void__setKeyEventDecreaseLODScale__int);
	I_SimpleProperty(int, KeyEventIncreaseLODScale, 
	                 __int__getKeyEventIncreaseLODScale, 
	                 __void__setKeyEventIncreaseLODScale__int);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::RecordCameraPathHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_ConstructorWithDefaults2(IN, const std::string &, filename, "saved_animation.path", IN, float, fps, 25.0f,
	                           ____RecordCameraPathHandler__C5_std_string_R1__float,
	                           "",
	                           "");
	I_Method1(void, setKeyEventToggleRecord, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventToggleRecord__int,
	          "",
	          "");
	I_Method0(int, getKeyEventToggleRecord,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventToggleRecord,
	          "",
	          "");
	I_Method1(void, setKeyEventTogglePlayback, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventTogglePlayback__int,
	          "",
	          "");
	I_Method0(int, getKeyEventTogglePlayback,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventTogglePlayback,
	          "",
	          "");
	I_MethodWithDefaults1(void, setAutoIncrementFilename, IN, bool, autoinc, true,
	                      Properties::NON_VIRTUAL,
	                      __void__setAutoIncrementFilename__bool,
	                      "",
	                      "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Deprecated, Handle events, return true if handled, false otherwise. ",
	          "");
	I_SimpleProperty(bool, AutoIncrementFilename, 
	                 0, 
	                 __void__setAutoIncrementFilename__bool);
	I_SimpleProperty(int, KeyEventTogglePlayback, 
	                 __int__getKeyEventTogglePlayback, 
	                 __void__setKeyEventTogglePlayback__int);
	I_SimpleProperty(int, KeyEventToggleRecord, 
	                 __int__getKeyEventToggleRecord, 
	                 __void__setKeyEventToggleRecord__int);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::ScreenCaptureHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_ConstructorWithDefaults1(IN, osgViewer::ScreenCaptureHandler::CaptureOperation *, defaultOperation, 0,
	                           Properties::NON_EXPLICIT,
	                           ____ScreenCaptureHandler__CaptureOperation_P1,
	                           "",
	                           "");
	I_Method1(void, setKeyEventTakeScreenShot, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventTakeScreenShot__int,
	          "",
	          "");
	I_Method0(int, getKeyEventTakeScreenShot,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventTakeScreenShot,
	          "",
	          "");
	I_Method1(void, setCaptureOperation, IN, osgViewer::ScreenCaptureHandler::CaptureOperation *, operation,
	          Properties::NON_VIRTUAL,
	          __void__setCaptureOperation__CaptureOperation_P1,
	          "",
	          "");
	I_Method0(osgViewer::ScreenCaptureHandler::CaptureOperation *, getCaptureOperation,
	          Properties::NON_VIRTUAL,
	          __CaptureOperation_P1__getCaptureOperation,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Deprecated, Handle events, return true if handled, false otherwise. ",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_ProtectedMethod1(void, addCallbackToViewer, IN, osgViewer::ViewerBase &, viewer,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__addCallbackToViewer__osgViewer_ViewerBase_R1,
	                   "",
	                   "");
	I_SimpleProperty(osgViewer::ScreenCaptureHandler::CaptureOperation *, CaptureOperation, 
	                 __CaptureOperation_P1__getCaptureOperation, 
	                 __void__setCaptureOperation__CaptureOperation_P1);
	I_SimpleProperty(int, KeyEventTakeScreenShot, 
	                 __int__getKeyEventTakeScreenShot, 
	                 __void__setKeyEventTakeScreenShot__int);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgViewer::ScreenCaptureHandler::CaptureOperation)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osg::Referenced);
	I_Constructor0(____CaptureOperation,
	               "",
	               "");
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgViewer::ScreenCaptureHandler::WriteToFile::SavePolicy)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_EnumLabel(osgViewer::ScreenCaptureHandler::WriteToFile::OVERWRITE);
	I_EnumLabel(osgViewer::ScreenCaptureHandler::WriteToFile::SEQUENTIAL_NUMBER);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::ScreenCaptureHandler::WriteToFile)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgViewer::ScreenCaptureHandler::CaptureOperation);
	I_ConstructorWithDefaults3(IN, const std::string &, filename, , IN, const std::string &, extension, , IN, osgViewer::ScreenCaptureHandler::WriteToFile::SavePolicy, savePolicy, osgViewer::ScreenCaptureHandler::WriteToFile::OVERWRITE,
	                           ____WriteToFile__C5_std_string_R1__C5_std_string_R1__SavePolicy,
	                           "",
	                           "");
	I_Method1(void, setSavePolicy, IN, osgViewer::ScreenCaptureHandler::WriteToFile::SavePolicy, savePolicy,
	          Properties::NON_VIRTUAL,
	          __void__setSavePolicy__SavePolicy,
	          "",
	          "");
	I_Method0(osgViewer::ScreenCaptureHandler::WriteToFile::SavePolicy, getSavePolicy,
	          Properties::NON_VIRTUAL,
	          __SavePolicy__getSavePolicy,
	          "",
	          "");
	I_SimpleProperty(osgViewer::ScreenCaptureHandler::WriteToFile::SavePolicy, SavePolicy, 
	                 __SavePolicy__getSavePolicy, 
	                 __void__setSavePolicy__SavePolicy);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgViewer::StatsHandler::StatsType)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_EnumLabel(osgViewer::StatsHandler::NO_STATS);
	I_EnumLabel(osgViewer::StatsHandler::FRAME_RATE);
	I_EnumLabel(osgViewer::StatsHandler::VIEWER_STATS);
	I_EnumLabel(osgViewer::StatsHandler::CAMERA_SCENE_STATS);
	I_EnumLabel(osgViewer::StatsHandler::VIEWER_SCENE_STATS);
	I_EnumLabel(osgViewer::StatsHandler::LAST);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::StatsHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_Constructor0(____StatsHandler,
	               "",
	               "");
	I_Method1(void, setKeyEventTogglesOnScreenStats, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventTogglesOnScreenStats__int,
	          "",
	          "");
	I_Method0(int, getKeyEventTogglesOnScreenStats,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventTogglesOnScreenStats,
	          "",
	          "");
	I_Method1(void, setKeyEventPrintsOutStats, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventPrintsOutStats__int,
	          "",
	          "");
	I_Method0(int, getKeyEventPrintsOutStats,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventPrintsOutStats,
	          "",
	          "");
	I_Method0(double, getBlockMultiplier,
	          Properties::NON_VIRTUAL,
	          __double__getBlockMultiplier,
	          "",
	          "");
	I_Method0(void, reset,
	          Properties::NON_VIRTUAL,
	          __void__reset,
	          "",
	          "");
	I_Method0(osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method0(const osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Deprecated, Handle events, return true if handled, false otherwise. ",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_ProtectedMethod1(void, setUpHUDCamera, IN, osgViewer::ViewerBase *, viewer,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setUpHUDCamera__osgViewer_ViewerBase_P1,
	                   "",
	                   "");
	I_ProtectedMethod4(osg::Geometry *, createBackgroundRectangle, IN, const osg::Vec3 &, pos, IN, const float, width, IN, const float, height, IN, osg::Vec4 &, color,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Geometry_P1__createBackgroundRectangle__C5_osg_Vec3_R1__C5_float__C5_float__osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod4(osg::Geometry *, createGeometry, IN, const osg::Vec3 &, pos, IN, float, height, IN, const osg::Vec4 &, colour, IN, unsigned int, numBlocks,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Geometry_P1__createGeometry__C5_osg_Vec3_R1__float__C5_osg_Vec4_R1__unsigned_int,
	                   "",
	                   "");
	I_ProtectedMethod4(osg::Geometry *, createFrameMarkers, IN, const osg::Vec3 &, pos, IN, float, height, IN, const osg::Vec4 &, colour, IN, unsigned int, numBlocks,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Geometry_P1__createFrameMarkers__C5_osg_Vec3_R1__float__C5_osg_Vec4_R1__unsigned_int,
	                   "",
	                   "");
	I_ProtectedMethod4(osg::Geometry *, createTick, IN, const osg::Vec3 &, pos, IN, float, height, IN, const osg::Vec4 &, colour, IN, unsigned int, numTicks,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Geometry_P1__createTick__C5_osg_Vec3_R1__float__C5_osg_Vec4_R1__unsigned_int,
	                   "",
	                   "");
	I_ProtectedMethod7(osg::Node *, createCameraTimeStats, IN, const std::string &, font, IN, osg::Vec3 &, pos, IN, float, startBlocks, IN, bool, acquireGPUStats, IN, float, characterSize, IN, osg::Stats *, viewerStats, IN, osg::Camera *, camera,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Node_P1__createCameraTimeStats__C5_std_string_R1__osg_Vec3_R1__float__bool__float__osg_Stats_P1__osg_Camera_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, setUpScene, IN, osgViewer::ViewerBase *, viewer,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setUpScene__osgViewer_ViewerBase_P1,
	                   "",
	                   "");
	I_ProtectedMethod0(void, updateThreadingModelText,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__updateThreadingModelText,
	                   "",
	                   "");
	I_SimpleProperty(double, BlockMultiplier, 
	                 __double__getBlockMultiplier, 
	                 0);
	I_SimpleProperty(osg::Camera *, Camera, 
	                 __osg_Camera_P1__getCamera, 
	                 0);
	I_SimpleProperty(int, KeyEventPrintsOutStats, 
	                 __int__getKeyEventPrintsOutStats, 
	                 __void__setKeyEventPrintsOutStats__int);
	I_SimpleProperty(int, KeyEventTogglesOnScreenStats, 
	                 __int__getKeyEventTogglesOnScreenStats, 
	                 __void__setKeyEventTogglesOnScreenStats__int);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::ThreadingHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_Constructor0(____ThreadingHandler,
	               "",
	               "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_Method1(void, setKeyEventChangeThreadingModel, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventChangeThreadingModel__int,
	          "",
	          "");
	I_Method0(int, getKeyEventChangeThreadingModel,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventChangeThreadingModel,
	          "",
	          "");
	I_Method1(void, setChangeThreadingModel, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setChangeThreadingModel__bool,
	          "",
	          "");
	I_Method0(bool, getChangeThreadingModel,
	          Properties::NON_VIRTUAL,
	          __bool__getChangeThreadingModel,
	          "",
	          "");
	I_Method1(void, setKeyEventChangeEndBarrierPosition, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventChangeEndBarrierPosition__int,
	          "",
	          "");
	I_Method0(int, getKeyEventChangeEndBarrierPosition,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventChangeEndBarrierPosition,
	          "",
	          "");
	I_Method1(void, setChangeEndBarrierPosition, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setChangeEndBarrierPosition__bool,
	          "",
	          "");
	I_Method0(bool, getChangeEndBarrierPosition,
	          Properties::NON_VIRTUAL,
	          __bool__getChangeEndBarrierPosition,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Deprecated, Handle events, return true if handled, false otherwise. ",
	          "");
	I_SimpleProperty(bool, ChangeEndBarrierPosition, 
	                 __bool__getChangeEndBarrierPosition, 
	                 __void__setChangeEndBarrierPosition__bool);
	I_SimpleProperty(bool, ChangeThreadingModel, 
	                 __bool__getChangeThreadingModel, 
	                 __void__setChangeThreadingModel__bool);
	I_SimpleProperty(int, KeyEventChangeEndBarrierPosition, 
	                 __int__getKeyEventChangeEndBarrierPosition, 
	                 __void__setKeyEventChangeEndBarrierPosition__int);
	I_SimpleProperty(int, KeyEventChangeThreadingModel, 
	                 __int__getKeyEventChangeThreadingModel, 
	                 __void__setKeyEventChangeThreadingModel__int);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::WindowSizeHandler)
	I_DeclaringFile("osgViewer/ViewerEventHandlers");
	I_BaseType(osgGA::GUIEventHandler);
	I_Constructor0(____WindowSizeHandler,
	               "",
	               "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_Method1(void, setKeyEventToggleFullscreen, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventToggleFullscreen__int,
	          "",
	          "");
	I_Method0(int, getKeyEventToggleFullscreen,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventToggleFullscreen,
	          "",
	          "");
	I_Method1(void, setToggleFullscreen, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setToggleFullscreen__bool,
	          "",
	          "");
	I_Method0(bool, getToggleFullscreen,
	          Properties::NON_VIRTUAL,
	          __bool__getToggleFullscreen,
	          "",
	          "");
	I_Method1(void, setKeyEventWindowedResolutionUp, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventWindowedResolutionUp__int,
	          "",
	          "");
	I_Method0(int, getKeyEventWindowedResolutionUp,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventWindowedResolutionUp,
	          "",
	          "");
	I_Method1(void, setKeyEventWindowedResolutionDown, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventWindowedResolutionDown__int,
	          "",
	          "");
	I_Method0(int, getKeyEventWindowedResolutionDown,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventWindowedResolutionDown,
	          "",
	          "");
	I_Method1(void, setChangeWindowedResolution, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setChangeWindowedResolution__bool,
	          "",
	          "");
	I_Method0(bool, getChangeWindowedResolution,
	          Properties::NON_VIRTUAL,
	          __bool__getChangeWindowedResolution,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __bool__handle__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Deprecated, Handle events, return true if handled, false otherwise. ",
	          "");
	I_ProtectedMethod1(void, toggleFullscreen, IN, osgViewer::GraphicsWindow *, window,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__toggleFullscreen__osgViewer_GraphicsWindow_P1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, changeWindowedResolution, IN, osgViewer::GraphicsWindow *, window, IN, bool, increase,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__changeWindowedResolution__osgViewer_GraphicsWindow_P1__bool,
	                   "",
	                   "");
	I_ProtectedMethod4(unsigned int, getNearestResolution, IN, int, screenWidth, IN, int, screenHeight, IN, int, width, IN, int, height,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __unsigned_int__getNearestResolution__int__int__int__int,
	                   "",
	                   "");
	I_SimpleProperty(bool, ChangeWindowedResolution, 
	                 __bool__getChangeWindowedResolution, 
	                 __void__setChangeWindowedResolution__bool);
	I_SimpleProperty(int, KeyEventToggleFullscreen, 
	                 __int__getKeyEventToggleFullscreen, 
	                 __void__setKeyEventToggleFullscreen__int);
	I_SimpleProperty(int, KeyEventWindowedResolutionDown, 
	                 __int__getKeyEventWindowedResolutionDown, 
	                 __void__setKeyEventWindowedResolutionDown__int);
	I_SimpleProperty(int, KeyEventWindowedResolutionUp, 
	                 __int__getKeyEventWindowedResolutionUp, 
	                 __void__setKeyEventWindowedResolutionUp__int);
	I_SimpleProperty(bool, ToggleFullscreen, 
	                 __bool__getToggleFullscreen, 
	                 __void__setToggleFullscreen__bool);
END_REFLECTOR

