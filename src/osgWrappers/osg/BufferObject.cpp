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

#include <osg/BufferObject>
#include <osg/CopyOp>
#include <osg/Image>
#include <osg/Object>
#include <osg/State>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::BufferObject)
	I_BaseType(osg::Object);
	I_Constructor0(____BufferObject,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::BufferObject &, bo, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____BufferObject__C5_BufferObject_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_Object_P1,
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
	I_Method1(bool, isBufferObjectSupported, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __bool__isBufferObjectSupported__unsigned_int,
	          "",
	          "");
	I_Method1(bool, isPBOSupported, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __bool__isPBOSupported__unsigned_int,
	          "",
	          "");
	I_Method1(GLuint &, buffer, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __GLuint_R1__buffer__unsigned_int,
	          "",
	          "");
	I_Method1(void, bindBuffer, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __void__bindBuffer__unsigned_int,
	          "",
	          "");
	I_Method1(void, unbindBuffer, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __void__unbindBuffer__unsigned_int,
	          "",
	          "");
	I_Method1(bool, needsCompile, IN, unsigned int, contextID,
	          Properties::PURE_VIRTUAL,
	          __bool__needsCompile__unsigned_int,
	          "",
	          "");
	I_Method1(void, compileBuffer, IN, osg::State &, state,
	          Properties::PURE_VIRTUAL,
	          __void__compileBuffer__State_R1,
	          "",
	          "");
	I_Method1(void, releaseBuffer, IN, osg::State *, state,
	          Properties::NON_VIRTUAL,
	          __void__releaseBuffer__State_P1,
	          "",
	          "");
	I_StaticMethod2(void, deleteBufferObject, IN, unsigned int, contextID, IN, GLuint, globj,
	                __void__deleteBufferObject__unsigned_int__GLuint_S,
	                "Use deleteVertexBufferObject instead of glDeleteBuffers to allow OpenGL buffer objects to be cached until they can be deleted by the OpenGL context in which they were created, specified by contextID. ",
	                "");
	I_StaticMethod3(void, flushDeletedBufferObjects, IN, unsigned int, contextID, IN, double, x, IN, double &, availableTime,
	                __void__flushDeletedBufferObjects__unsigned_int__double__double_R1_S,
	                "flush all the cached display list which need to be deleted in the OpenGL context related to contextID. ",
	                "");
	I_StaticMethod2(osg::BufferObject::Extensions *, getExtensions, IN, unsigned int, contextID, IN, bool, createIfNotInitalized,
	                __Extensions_P1__getExtensions__unsigned_int__bool_S,
	                "Function to call to get the extension of a specified context. ",
	                "If the Exentsion object for that context has not yet been created and the 'createIfNotInitalized' flag been set to false then returns NULL. If 'createIfNotInitalized' is true then the Extensions object is automatically created. However, in this case the extension object is only created with the graphics context associated with ContextID.. ");
	I_StaticMethod2(void, setExtensions, IN, unsigned int, contextID, IN, osg::BufferObject::Extensions *, extensions,
	                __void__setExtensions__unsigned_int__Extensions_P1_S,
	                "setExtensions allows users to override the extensions across graphics contexts. ",
	                "typically used when you have different extensions supported across graphics pipes but need to ensure that they all use the same low common denominator extensions. ");
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::BufferObject::BufferEntry)
	I_Constructor0(____BufferEntry,
	               "",
	               "");
	I_Constructor1(IN, const osg::BufferObject::BufferEntry &, be,
	               Properties::NON_EXPLICIT,
	               ____BufferEntry__C5_BufferEntry_R1,
	               "",
	               "");
	I_PublicMemberProperty(osg::buffered_value< unsigned int >, modifiedCount);
	I_PublicMemberProperty(unsigned int, dataSize);
	I_PublicMemberProperty(unsigned int, offset);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::BufferObject::Extensions)
	I_BaseType(osg::Referenced);
	I_Constructor1(IN, unsigned int, contextID,
	               Properties::NON_EXPLICIT,
	               ____Extensions__unsigned_int,
	               "",
	               "");
	I_Constructor1(IN, const osg::BufferObject::Extensions &, rhs,
	               Properties::NON_EXPLICIT,
	               ____Extensions__C5_Extensions_R1,
	               "",
	               "");
	I_Method1(void, lowestCommonDenominator, IN, const osg::BufferObject::Extensions &, rhs,
	          Properties::NON_VIRTUAL,
	          __void__lowestCommonDenominator__C5_Extensions_R1,
	          "",
	          "");
	I_Method1(void, setupGLExtenions, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __void__setupGLExtenions__unsigned_int,
	          "",
	          "");
	I_Method0(bool, isBufferObjectSupported,
	          Properties::NON_VIRTUAL,
	          __bool__isBufferObjectSupported,
	          "",
	          "");
	I_Method0(bool, isPBOSupported,
	          Properties::NON_VIRTUAL,
	          __bool__isPBOSupported,
	          "",
	          "");
	I_Method2(void, glGenBuffers, IN, GLsizei, n, IN, GLuint *, buffers,
	          Properties::NON_VIRTUAL,
	          __void__glGenBuffers__GLsizei__GLuint_P1,
	          "",
	          "");
	I_Method2(void, glBindBuffer, IN, GLenum, target, IN, GLuint, buffer,
	          Properties::NON_VIRTUAL,
	          __void__glBindBuffer__GLenum__GLuint,
	          "",
	          "");
	I_Method4(void, glBufferData, IN, GLenum, target, IN, GLsizeiptrARB, size, IN, const GLvoid *, data, IN, GLenum, usage,
	          Properties::NON_VIRTUAL,
	          __void__glBufferData__GLenum__GLsizeiptrARB__C5_GLvoid_P1__GLenum,
	          "",
	          "");
	I_Method4(void, glBufferSubData, IN, GLenum, target, IN, GLintptrARB, offset, IN, GLsizeiptrARB, size, IN, const GLvoid *, data,
	          Properties::NON_VIRTUAL,
	          __void__glBufferSubData__GLenum__GLintptrARB__GLsizeiptrARB__C5_GLvoid_P1,
	          "",
	          "");
	I_Method2(void, glDeleteBuffers, IN, GLsizei, n, IN, const GLuint *, buffers,
	          Properties::NON_VIRTUAL,
	          __void__glDeleteBuffers__GLsizei__C5_GLuint_P1,
	          "",
	          "");
	I_Method1(GLboolean, glIsBuffer, IN, GLuint, buffer,
	          Properties::NON_VIRTUAL,
	          __GLboolean__glIsBuffer__GLuint,
	          "",
	          "");
	I_Method4(void, glGetBufferSubData, IN, GLenum, target, IN, GLintptrARB, offset, IN, GLsizeiptrARB, size, IN, GLvoid *, data,
	          Properties::NON_VIRTUAL,
	          __void__glGetBufferSubData__GLenum__GLintptrARB__GLsizeiptrARB__GLvoid_P1,
	          "",
	          "");
	I_Method2(GLvoid *, glMapBuffer, IN, GLenum, target, IN, GLenum, access,
	          Properties::NON_VIRTUAL,
	          __GLvoid_P1__glMapBuffer__GLenum__GLenum,
	          "",
	          "");
	I_Method1(GLboolean, glUnmapBuffer, IN, GLenum, target,
	          Properties::NON_VIRTUAL,
	          __GLboolean__glUnmapBuffer__GLenum,
	          "",
	          "");
	I_Method3(void, glGetBufferParameteriv, IN, GLenum, target, IN, GLenum, pname, IN, GLint *, params,
	          Properties::NON_VIRTUAL,
	          __void__glGetBufferParameteriv__GLenum__GLenum__GLint_P1,
	          "",
	          "");
	I_Method3(void, glGetBufferPointerv, IN, GLenum, target, IN, GLenum, pname, IN, GLvoid **, params,
	          Properties::NON_VIRTUAL,
	          __void__glGetBufferPointerv__GLenum__GLenum__GLvoid_P1P1,
	          "",
	          "");










END_REFLECTOR

TYPE_NAME_ALIAS(std::pair< osg::BufferObject::BufferEntry COMMA  osg::Image * >, osg::PixelBufferObject::BufferEntryImagePair);

BEGIN_OBJECT_REFLECTOR(osg::PixelBufferObject)
	I_BaseType(osg::BufferObject);
	I_ConstructorWithDefaults1(IN, osg::Image *, image, 0,
	                           Properties::NON_EXPLICIT,
	                           ____PixelBufferObject__osg_Image_P1,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osg::PixelBufferObject &, pbo, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____PixelBufferObject__C5_PixelBufferObject_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
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
	I_Method1(void, setImage, IN, osg::Image *, image,
	          Properties::NON_VIRTUAL,
	          __void__setImage__osg_Image_P1,
	          "",
	          "");
	I_Method0(osg::Image *, getImage,
	          Properties::NON_VIRTUAL,
	          __Image_P1__getImage,
	          "",
	          "");
	I_Method0(const osg::Image *, getImage,
	          Properties::NON_VIRTUAL,
	          __C5_Image_P1__getImage,
	          "",
	          "");
	I_Method0(unsigned int, offset,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__offset,
	          "",
	          "");
	I_Method1(bool, needsCompile, IN, unsigned int, contextID,
	          Properties::VIRTUAL,
	          __bool__needsCompile__unsigned_int,
	          "",
	          "");
	I_Method1(void, compileBuffer, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__compileBuffer__State_R1,
	          "",
	          "");
	I_SimpleProperty(osg::Image *, Image, 
	                 __Image_P1__getImage, 
	                 __void__setImage__osg_Image_P1);
END_REFLECTOR

STD_PAIR_REFLECTOR(std::pair< osg::BufferObject::BufferEntry COMMA  osg::Image * >);

