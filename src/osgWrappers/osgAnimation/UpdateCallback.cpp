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

#include <osg/CopyOp>
#include <osg/Material>
#include <osg/MatrixTransform>
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/PositionAttitudeTransform>
#include <osg/StateAttribute>
#include <osgAnimation/Animation>
#include <osgAnimation/AnimationManagerBase>
#include <osgAnimation/Channel>
#include <osgAnimation/Target>
#include <osgAnimation/UpdateCallback>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgAnimation::AnimationUpdateCallbackBase)
	I_DeclaringFile("osgAnimation/UpdateCallback");
	I_Constructor0(____AnimationUpdateCallbackBase,
	               "",
	               "");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::PURE_VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "",
	          "");
	I_Method0(osgAnimation::AnimationManagerBase *, getAnimationManager,
	          Properties::PURE_VIRTUAL,
	          __AnimationManagerBase_P1__getAnimationManager,
	          "",
	          "");
	I_Method0(bool, needLink,
	          Properties::PURE_VIRTUAL,
	          __bool__needLink,
	          "",
	          "");
	I_Method1(bool, link, IN, osgAnimation::Channel *, channel,
	          Properties::PURE_VIRTUAL,
	          __bool__link__osgAnimation_Channel_P1,
	          "",
	          "");
	I_Method1(int, link, IN, osgAnimation::Animation *, animation,
	          Properties::PURE_VIRTUAL,
	          __int__link__osgAnimation_Animation_P1,
	          "",
	          "");
	I_Method0(void, updateLink,
	          Properties::PURE_VIRTUAL,
	          __void__updateLink,
	          "",
	          "");
	I_Method0(const std::string &, getName,
	          Properties::PURE_VIRTUAL,
	          __C5_std_string_R1__getName,
	          "",
	          "");
	I_SimpleProperty(osgAnimation::AnimationManagerBase *, AnimationManager, 
	                 __AnimationManagerBase_P1__getAnimationManager, 
	                 0);
	I_SimpleProperty(const std::string &, Name, 
	                 __C5_std_string_R1__getName, 
	                 0);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgAnimation::UpdateMaterial)
	I_DeclaringFile("osgAnimation/UpdateCallback");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
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
	I_ConstructorWithDefaults1(IN, const std::string &, name, "",
	                           Properties::NON_EXPLICIT,
	                           ____UpdateMaterial__C5_std_string_R1,
	                           "",
	                           "");
	I_Constructor2(IN, const osgAnimation::UpdateMaterial &, apc, IN, const osg::CopyOp &, copyop,
	               ____UpdateMaterial__C5_UpdateMaterial_R1__C5_osg_CopyOp_R1,
	               "",
	               "");
	I_Method1(void, update, IN, osg::Material &, material,
	          Properties::NON_VIRTUAL,
	          __void__update__osg_Material_R1,
	          "",
	          "");
	I_Method0(bool, needLink,
	          Properties::VIRTUAL,
	          __bool__needLink,
	          "",
	          "");
	I_Method1(bool, link, IN, osgAnimation::Channel *, channel,
	          Properties::VIRTUAL,
	          __bool__link__osgAnimation_Channel_P1,
	          "",
	          "");
	I_Method0(osgAnimation::Vec4Target *, getDiffuse,
	          Properties::NON_VIRTUAL,
	          __osgAnimation_Vec4Target_P1__getDiffuse,
	          "",
	          "");
	I_SimpleProperty(osgAnimation::Vec4Target *, Diffuse, 
	                 __osgAnimation_Vec4Target_P1__getDiffuse, 
	                 0);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgAnimation::UpdateTransform)
	I_DeclaringFile("osgAnimation/UpdateCallback");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
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
	I_ConstructorWithDefaults1(IN, const std::string &, name, "",
	                           Properties::NON_EXPLICIT,
	                           ____UpdateTransform__C5_std_string_R1,
	                           "",
	                           "");
	I_Constructor2(IN, const osgAnimation::UpdateTransform &, apc, IN, const osg::CopyOp &, copyop,
	               ____UpdateTransform__C5_UpdateTransform_R1__C5_osg_CopyOp_R1,
	               "",
	               "");
	I_Method1(void, update, IN, osg::MatrixTransform &, mat,
	          Properties::NON_VIRTUAL,
	          __void__update__osg_MatrixTransform_R1,
	          "",
	          "");
	I_Method1(void, update, IN, osg::PositionAttitudeTransform &, pat,
	          Properties::NON_VIRTUAL,
	          __void__update__osg_PositionAttitudeTransform_R1,
	          "",
	          "");
	I_Method0(bool, needLink,
	          Properties::VIRTUAL,
	          __bool__needLink,
	          "",
	          "");
	I_Method1(bool, link, IN, osgAnimation::Channel *, channel,
	          Properties::VIRTUAL,
	          __bool__link__osgAnimation_Channel_P1,
	          "",
	          "");
	I_Method0(osgAnimation::Vec3Target *, getEuler,
	          Properties::NON_VIRTUAL,
	          __osgAnimation_Vec3Target_P1__getEuler,
	          "",
	          "");
	I_Method0(osgAnimation::Vec3Target *, getPosition,
	          Properties::NON_VIRTUAL,
	          __osgAnimation_Vec3Target_P1__getPosition,
	          "",
	          "");
	I_Method0(osgAnimation::Vec3Target *, getScale,
	          Properties::NON_VIRTUAL,
	          __osgAnimation_Vec3Target_P1__getScale,
	          "",
	          "");
	I_SimpleProperty(osgAnimation::Vec3Target *, Euler, 
	                 __osgAnimation_Vec3Target_P1__getEuler, 
	                 0);
	I_SimpleProperty(osgAnimation::Vec3Target *, Position, 
	                 __osgAnimation_Vec3Target_P1__getPosition, 
	                 0);
	I_SimpleProperty(osgAnimation::Vec3Target *, Scale, 
	                 __osgAnimation_Vec3Target_P1__getScale, 
	                 0);
END_REFLECTOR

