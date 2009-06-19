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

#include <osg/Array>
#include <osg/CopyOp>
#include <osg/Drawable>
#include <osg/Image>
#include <osg/Node>
#include <osg/NodeCallback>
#include <osg/Object>
#include <osg/PrimitiveSet>
#include <osg/Referenced>
#include <osg/Shape>
#include <osg/StateAttribute>
#include <osg/StateSet>
#include <osg/Texture>
#include <osg/Uniform>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osg::CopyOp::Options)
	I_DeclaringFile("osg/CopyOp");
	I_EnumLabel(osg::CopyOp::SHALLOW_COPY);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_OBJECTS);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_NODES);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_DRAWABLES);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_STATESETS);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_STATEATTRIBUTES);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_TEXTURES);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_IMAGES);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_ARRAYS);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_PRIMITIVES);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_SHAPES);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_UNIFORMS);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_NODECALLBACKS);
	I_EnumLabel(osg::CopyOp::DEEP_COPY_ALL);
END_REFLECTOR

TYPE_NAME_ALIAS(unsigned int, osg::CopyOp::CopyFlags)

BEGIN_VALUE_REFLECTOR(osg::CopyOp)
	I_DeclaringFile("osg/CopyOp");
	I_ConstructorWithDefaults1(IN, osg::CopyOp::CopyFlags, flags, osg::CopyOp::SHALLOW_COPY,
	                           Properties::NON_EXPLICIT,
	                           ____CopyOp__CopyFlags,
	                           "",
	                           "");
END_REFLECTOR

