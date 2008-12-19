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

#include <OpenThreads/Mutex>
#include <osg/Geode>
#include <osg/Node>
#include <osg/StateSet>
#include <osgDB/SharedStateManager>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgDB::SharedStateManager::ShareMode)
	I_DeclaringFile("osgDB/SharedStateManager");
	I_EnumLabel(osgDB::SharedStateManager::SHARE_NONE);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_STATIC_TEXTURES);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_UNSPECIFIED_TEXTURES);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_DYNAMIC_TEXTURES);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_STATIC_STATESETS);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_UNSPECIFIED_STATESETS);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_DYNAMIC_STATESETS);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_TEXTURES);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_STATESETS);
	I_EnumLabel(osgDB::SharedStateManager::SHARE_ALL);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgDB::SharedStateManager)
	I_DeclaringFile("osgDB/SharedStateManager");
	I_BaseType(osg::NodeVisitor);
	I_ConstructorWithDefaults1(IN, unsigned int, mode, osgDB::SharedStateManager::SHARE_ALL,
	                           Properties::NON_EXPLICIT,
	                           ____SharedStateManager__unsigned_int,
	                           "",
	                           "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the library name/namespapce of the visitor's. ",
	          "Should be defined by derived classes. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the visitor's class type. ",
	          "Should be defined by derived classes. ");
	I_Method1(void, setShareMode, IN, unsigned int, mode,
	          Properties::NON_VIRTUAL,
	          __void__setShareMode__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getShareMode,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getShareMode,
	          "",
	          "");
	I_Method0(void, prune,
	          Properties::NON_VIRTUAL,
	          __void__prune,
	          "",
	          "");
	I_MethodWithDefaults2(void, share, IN, osg::Node *, node, , IN, OpenThreads::Mutex *, mt, 0,
	                      Properties::NON_VIRTUAL,
	                      __void__share__osg_Node_P1__OpenThreads_Mutex_P1,
	                      "",
	                      "");
	I_Method1(void, apply, IN, osg::Node &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Node_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Geode &, geode,
	          Properties::VIRTUAL,
	          __void__apply__osg_Geode_R1,
	          "",
	          "");
	I_Method1(bool, isShared, IN, osg::StateSet *, stateSet,
	          Properties::NON_VIRTUAL,
	          __bool__isShared__osg_StateSet_P1,
	          "",
	          "");
	I_ProtectedMethod1(bool, shareTexture, IN, osg::Object::DataVariance, variance,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__shareTexture__osg_Object_DataVariance,
	                   "",
	                   "");
	I_ProtectedMethod1(bool, shareStateSet, IN, osg::Object::DataVariance, variance,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__shareStateSet__osg_Object_DataVariance,
	                   "",
	                   "");
	I_ProtectedMethod2(void, process, IN, osg::StateSet *, ss, IN, osg::Object *, parent,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__process__osg_StateSet_P1__osg_Object_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(osg::StateAttribute *, find, IN, osg::StateAttribute *, sa,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_StateAttribute_P1__find__osg_StateAttribute_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(osg::StateSet *, find, IN, osg::StateSet *, ss,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_StateSet_P1__find__osg_StateSet_P1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, setStateSet, IN, osg::StateSet *, ss, IN, osg::Object *, object,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setStateSet__osg_StateSet_P1__osg_Object_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, shareTextures, IN, osg::StateSet *, ss,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__shareTextures__osg_StateSet_P1,
	                   "",
	                   "");
	I_SimpleProperty(unsigned int, ShareMode, 
	                 __unsigned_int__getShareMode, 
	                 __void__setShareMode__unsigned_int);
END_REFLECTOR

