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
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osgFX/Effect>
#include <osgFX/Technique>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgFX::Effect::TechniqueSelection)
	I_EnumLabel(osgFX::Effect::AUTO_DETECT);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgFX::Effect)
	I_BaseType(osg::Group);
	I_Constructor0(____Effect,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgFX::Effect &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Effect__C5_Effect_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the node's library. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the node's class type. ",
	          "");
	I_Method0(const char *, effectName,
	          Properties::PURE_VIRTUAL,
	          __C5_char_P1__effectName,
	          "get the name of this Effect ",
	          "");
	I_Method0(const char *, effectDescription,
	          Properties::PURE_VIRTUAL,
	          __C5_char_P1__effectDescription,
	          "get a brief description of this Effect ",
	          "");
	I_Method0(const char *, effectAuthor,
	          Properties::PURE_VIRTUAL,
	          __C5_char_P1__effectAuthor,
	          "get the effect author's name ",
	          "");
	I_Method0(bool, getEnabled,
	          Properties::NON_VIRTUAL,
	          __bool__getEnabled,
	          "get whether the effect is enabled or not ",
	          "");
	I_Method1(void, setEnabled, IN, bool, v,
	          Properties::NON_VIRTUAL,
	          __void__setEnabled__bool,
	          "set whether the effect is enabled or not ",
	          "");
	I_Method0(void, setUpDemo,
	          Properties::VIRTUAL,
	          __void__setUpDemo,
	          "optional: set effect parameters to produce a visually significant result to be used in demo applications like osgfxbrowser. ",
	          "Default is to do nothing.");
	I_Method0(int, getNumTechniques,
	          Properties::NON_VIRTUAL,
	          __int__getNumTechniques,
	          "get the number of techniques defined for this Effect ",
	          "");
	I_Method1(osgFX::Technique *, getTechnique, IN, int, i,
	          Properties::NON_VIRTUAL,
	          __Technique_P1__getTechnique__int,
	          "get the i-th Technique ",
	          "");
	I_Method1(const osgFX::Technique *, getTechnique, IN, int, i,
	          Properties::NON_VIRTUAL,
	          __C5_Technique_P1__getTechnique__int,
	          "get the i-th const Technique ",
	          "");
	I_Method0(int, getSelectedTechnique,
	          Properties::NON_VIRTUAL,
	          __int__getSelectedTechnique,
	          "get the index of the currently selected Technique ",
	          "");
	I_MethodWithDefaults1(void, selectTechnique, IN, int, i, osgFX::Effect::AUTO_DETECT,
	                      Properties::NON_VIRTUAL,
	                      __void__selectTechnique__int,
	                      "select a technique or enable automatic detection ",
	                      "");
	I_Method1(void, traverse, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__traverse__osg_NodeVisitor_R1,
	          "custom traversal ",
	          "");
	I_Method1(void, inherited_traverse, IN, osg::NodeVisitor &, nv,
	          Properties::NON_VIRTUAL,
	          __void__inherited_traverse__osg_NodeVisitor_R1,
	          "default traversal ",
	          "");
	I_ProtectedMethod0(void, dirtyTechniques,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__dirtyTechniques,
	                   "force rebuilding of techniques on next traversal ",
	                   "");
	I_ProtectedMethod1(void, addTechnique, IN, osgFX::Technique *, tech,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__addTechnique__Technique_P1,
	                   "add a technique to the Effect ",
	                   "");
	I_ProtectedMethod0(bool, define_techniques,
	                   Properties::PURE_VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__define_techniques,
	                   "abstract method to be implemented in derived classes; its purpose if to create the techniques that can be used for obtaining the desired effect. ",
	                   "You will usually call addTechnique() inside this method.");
	I_SimpleProperty(bool, Enabled, 
	                 __bool__getEnabled, 
	                 __void__setEnabled__bool);
	I_SimpleProperty(int, SelectedTechnique, 
	                 __int__getSelectedTechnique, 
	                 0);
	I_ArrayProperty(osgFX::Technique *, Technique, 
	                __Technique_P1__getTechnique__int, 
	                0, 
	                __int__getNumTechniques, 
	                0, 
	                0, 
	                0);
END_REFLECTOR

