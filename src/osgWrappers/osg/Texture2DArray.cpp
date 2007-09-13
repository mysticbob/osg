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
#include <osg/Image>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/Texture2DArray>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::Texture2DArray)
	I_DeclaringFile("osg/Texture2DArray");
	I_BaseType(osg::Texture);
	I_Constructor0(____Texture2DArray,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::Texture2DArray &, cm, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Texture2DArray__C5_Texture2DArray_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "Return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "Return the name of the attribute's library. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "Return the name of the attribute's class type. ",
	          "");
	I_Method0(osg::StateAttribute::Type, getType,
	          Properties::VIRTUAL,
	          __Type__getType,
	          "Return the Type identifier of the attribute's class type. ",
	          "");
	I_Method1(int, compare, IN, const osg::StateAttribute &, rhs,
	          Properties::VIRTUAL,
	          __int__compare__C5_StateAttribute_R1,
	          "Return -1 if *this < *rhs, 0 if *this==*rhs, 1 if *this>*rhs. ",
	          "");
	I_Method0(GLenum, getTextureTarget,
	          Properties::VIRTUAL,
	          __GLenum__getTextureTarget,
	          "",
	          "");
	I_Method2(void, setImage, IN, unsigned int, layer, IN, osg::Image *, image,
	          Properties::VIRTUAL,
	          __void__setImage__unsigned_int__Image_P1,
	          "Set the texture image for specified layer. ",
	          "");
	I_Method1(osg::Image *, getImage, IN, unsigned int, layer,
	          Properties::VIRTUAL,
	          __Image_P1__getImage__unsigned_int,
	          "Get the texture image for specified layer. ",
	          "");
	I_Method1(const osg::Image *, getImage, IN, unsigned int, layer,
	          Properties::VIRTUAL,
	          __C5_Image_P1__getImage__unsigned_int,
	          "Get the const texture image for specified layer. ",
	          "");
	I_Method0(unsigned int, getNumImages,
	          Properties::VIRTUAL,
	          __unsigned_int__getNumImages,
	          "Get the number of images that are assigned to the Texture. ",
	          "The number is equal to the texture depth. To get the maximum possible image/layer count, you have to use the extension subclass, since it provides graphic context dependent information. ");
	I_Method2(unsigned int &, getModifiedCount, IN, unsigned int, layer, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __unsigned_int_R1__getModifiedCount__unsigned_int__unsigned_int,
	          "Check how often was a certain layer in the given context modified. ",
	          "");
	I_Method3(void, setTextureSize, IN, int, width, IN, int, height, IN, int, depth,
	          Properties::NON_VIRTUAL,
	          __void__setTextureSize__int__int__int,
	          "Set the texture width and height. ",
	          "If width or height are zero then the repsective size value is calculated from the source image sizes. Depth parameter specifies the number of layers to be used. ");
	I_Method1(void, setTextureWidth, IN, int, width,
	          Properties::NON_VIRTUAL,
	          __void__setTextureWidth__int,
	          "",
	          "");
	I_Method1(void, setTextureHeight, IN, int, height,
	          Properties::NON_VIRTUAL,
	          __void__setTextureHeight__int,
	          "",
	          "");
	I_Method1(void, setTextureDepth, IN, int, depth,
	          Properties::NON_VIRTUAL,
	          __void__setTextureDepth__int,
	          "",
	          "");
	I_Method0(int, getTextureWidth,
	          Properties::VIRTUAL,
	          __int__getTextureWidth,
	          "",
	          "");
	I_Method0(int, getTextureHeight,
	          Properties::VIRTUAL,
	          __int__getTextureHeight,
	          "",
	          "");
	I_Method0(int, getTextureDepth,
	          Properties::VIRTUAL,
	          __int__getTextureDepth,
	          "",
	          "");
	I_Method1(void, setSubloadCallback, IN, osg::Texture2DArray::SubloadCallback *, cb,
	          Properties::NON_VIRTUAL,
	          __void__setSubloadCallback__SubloadCallback_P1,
	          "",
	          "");
	I_Method0(osg::Texture2DArray::SubloadCallback *, getSubloadCallback,
	          Properties::NON_VIRTUAL,
	          __SubloadCallback_P1__getSubloadCallback,
	          "",
	          "");
	I_Method0(const osg::Texture2DArray::SubloadCallback *, getSubloadCallback,
	          Properties::NON_VIRTUAL,
	          __C5_SubloadCallback_P1__getSubloadCallback,
	          "",
	          "");
	I_Method1(void, setNumMipmapLevels, IN, unsigned int, num,
	          Properties::NON_VIRTUAL,
	          __void__setNumMipmapLevels__unsigned_int,
	          "Set the number of mip map levels the the texture has been created with. ",
	          "Should only be called within an osg::Texuture::apply() and custom OpenGL texture load. ");
	I_Method0(unsigned int, getNumMipmapLevels,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumMipmapLevels,
	          "Get the number of mip map levels the the texture has been created with. ",
	          "");
	I_Method8(void, copyTexSubImage2DArray, IN, osg::State &, state, IN, int, xoffset, IN, int, yoffset, IN, int, zoffset, IN, int, x, IN, int, y, IN, int, width, IN, int, height,
	          Properties::NON_VIRTUAL,
	          __void__copyTexSubImage2DArray__State_R1__int__int__int__int__int__int__int,
	          "Copies a two-dimensional texture subimage, as per glCopyTexSubImage3D. ",
	          "Updates a portion of an existing OpenGL texture object from the current OpenGL background framebuffer contents at position x, y with width width and height height. Loads framebuffer data into the texture using offsets xoffset and yoffset. zoffset specifies the layer of the texture array to which the result is copied. ");
	I_Method1(void, apply, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__apply__State_R1,
	          "Bind the texture if already compiled. ",
	          "Otherwise recompile. ");
	I_StaticMethod2(osg::Texture2DArray::Extensions *, getExtensions, IN, unsigned int, contextID, IN, bool, createIfNotInitalized,
	                __Extensions_P1__getExtensions__unsigned_int__bool_S,
	                "Function to call to get the extension of a specified context. ",
	                "If the Exentsion object for that context has not yet been created and the 'createIfNotInitalized' flag been set to false then returns NULL. If 'createIfNotInitalized' is true then the Extensions object is automatically created. However, in this case the extension object will only be created with the graphics context associated with ContextID. ");
	I_StaticMethod2(void, setExtensions, IN, unsigned int, contextID, IN, osg::Texture2DArray::Extensions *, extensions,
	                __void__setExtensions__unsigned_int__Extensions_P1_S,
	                "The setExtensions method allows users to override the extensions across graphics contexts. ",
	                "Typically used when you have different extensions supported across graphics pipes but need to ensure that they all use the same low common denominator extensions. ");
	I_ProtectedMethod0(bool, imagesValid,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __bool__imagesValid,
	                   "",
	                   "");
	I_ProtectedMethod0(void, computeInternalFormat,
	                   Properties::VIRTUAL,
	                   Properties::CONST,
	                   __void__computeInternalFormat,
	                   "",
	                   "");
	I_ProtectedMethod1(void, allocateMipmap, IN, osg::State &, state,
	                   Properties::VIRTUAL,
	                   Properties::CONST,
	                   __void__allocateMipmap__State_R1,
	                   "Allocate mipmap levels of the texture by subsequent calling of glTexImage* function. ",
	                   "");
	I_ProtectedMethod6(void, applyTexImage2DArray_subload, IN, osg::State &, state, IN, osg::Image *, image, IN, GLsizei &, inwidth, IN, GLsizei &, inheight, IN, GLsizei &, indepth, IN, GLsizei &, numMipmapLevels,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__applyTexImage2DArray_subload__State_R1__Image_P1__GLsizei_R1__GLsizei_R1__GLsizei_R1__GLsizei_R1,
	                   "",
	                   "");
	I_ArrayProperty(osg::Image *, Image, 
	                __Image_P1__getImage__unsigned_int, 
	                __void__setImage__unsigned_int__Image_P1, 
	                __unsigned_int__getNumImages, 
	                0, 
	                0, 
	                0);
	I_SimpleProperty(unsigned int, NumMipmapLevels, 
	                 0, 
	                 __void__setNumMipmapLevels__unsigned_int);
	I_SimpleProperty(osg::Texture2DArray::SubloadCallback *, SubloadCallback, 
	                 __SubloadCallback_P1__getSubloadCallback, 
	                 __void__setSubloadCallback__SubloadCallback_P1);
	I_SimpleProperty(int, TextureDepth, 
	                 __int__getTextureDepth, 
	                 __void__setTextureDepth__int);
	I_SimpleProperty(int, TextureHeight, 
	                 __int__getTextureHeight, 
	                 __void__setTextureHeight__int);
	I_SimpleProperty(GLenum, TextureTarget, 
	                 __GLenum__getTextureTarget, 
	                 0);
	I_SimpleProperty(int, TextureWidth, 
	                 __int__getTextureWidth, 
	                 __void__setTextureWidth__int);
	I_SimpleProperty(osg::StateAttribute::Type, Type, 
	                 __Type__getType, 
	                 0);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::Texture2DArray::Extensions)
	I_DeclaringFile("osg/Texture2DArray");
	I_BaseType(osg::Referenced);
	I_Constructor1(IN, unsigned int, contextID,
	               Properties::NON_EXPLICIT,
	               ____Extensions__unsigned_int,
	               "",
	               "");
	I_Constructor1(IN, const osg::Texture2DArray::Extensions &, rhs,
	               Properties::NON_EXPLICIT,
	               ____Extensions__C5_Extensions_R1,
	               "",
	               "");
	I_Method1(void, lowestCommonDenominator, IN, const osg::Texture2DArray::Extensions &, rhs,
	          Properties::NON_VIRTUAL,
	          __void__lowestCommonDenominator__C5_Extensions_R1,
	          "",
	          "");
	I_Method1(void, setupGLExtensions, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __void__setupGLExtensions__unsigned_int,
	          "",
	          "");
	I_Method1(void, setTexture2DArraySupported, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setTexture2DArraySupported__bool,
	          "",
	          "");
	I_Method0(bool, isTexture2DArraySupported,
	          Properties::NON_VIRTUAL,
	          __bool__isTexture2DArraySupported,
	          "",
	          "");
	I_Method1(void, setTexture3DSupported, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setTexture3DSupported__bool,
	          "",
	          "");
	I_Method0(bool, isTexture3DSupported,
	          Properties::NON_VIRTUAL,
	          __bool__isTexture3DSupported,
	          "",
	          "");
	I_Method1(void, setMaxLayerCount, IN, GLint, count,
	          Properties::NON_VIRTUAL,
	          __void__setMaxLayerCount__GLint,
	          "",
	          "");
	I_Method0(GLint, maxLayerCount,
	          Properties::NON_VIRTUAL,
	          __GLint__maxLayerCount,
	          "",
	          "");
	I_Method1(void, setMax2DSize, IN, GLint, size,
	          Properties::NON_VIRTUAL,
	          __void__setMax2DSize__GLint,
	          "",
	          "");
	I_Method0(GLint, max2DSize,
	          Properties::NON_VIRTUAL,
	          __GLint__max2DSize,
	          "",
	          "");
	I_Method10(void, glTexImage3D, IN, GLenum, target, IN, GLint, level, IN, GLenum, internalFormat, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLint, border, IN, GLenum, format, IN, GLenum, type, IN, const GLvoid *, pixels,
	           Properties::NON_VIRTUAL,
	           __void__glTexImage3D__GLenum__GLint__GLenum__GLsizei__GLsizei__GLsizei__GLint__GLenum__GLenum__C5_GLvoid_P1,
	           "",
	           "");
	I_Method11(void, glTexSubImage3D, IN, GLenum, target, IN, GLint, level, IN, GLint, xoffset, IN, GLint, yoffset, IN, GLint, zoffset, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLenum, format, IN, GLenum, type, IN, const GLvoid *, pixels,
	           Properties::NON_VIRTUAL,
	           __void__glTexSubImage3D__GLenum__GLint__GLint__GLint__GLint__GLsizei__GLsizei__GLsizei__GLenum__GLenum__C5_GLvoid_P1,
	           "",
	           "");
	I_Method9(void, glCopyTexSubImage3D, IN, GLenum, target, IN, GLint, level, IN, GLint, xoffset, IN, GLint, yoffset, IN, GLint, zoffset, IN, GLint, x, IN, GLint, y, IN, GLsizei, width, IN, GLsizei, height,
	          Properties::NON_VIRTUAL,
	          __void__glCopyTexSubImage3D__GLenum__GLint__GLint__GLint__GLint__GLint__GLint__GLsizei__GLsizei,
	          "",
	          "");
	I_Method0(bool, isCompressedTexImage3DSupported,
	          Properties::NON_VIRTUAL,
	          __bool__isCompressedTexImage3DSupported,
	          "",
	          "");
	I_Method9(void, glCompressedTexImage3D, IN, GLenum, target, IN, GLint, level, IN, GLenum, internalformat, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLint, border, IN, GLsizei, imageSize, IN, const GLvoid *, data,
	          Properties::NON_VIRTUAL,
	          __void__glCompressedTexImage3D__GLenum__GLint__GLenum__GLsizei__GLsizei__GLsizei__GLint__GLsizei__C5_GLvoid_P1,
	          "",
	          "");
	I_Method0(bool, isCompressedTexSubImage3DSupported,
	          Properties::NON_VIRTUAL,
	          __bool__isCompressedTexSubImage3DSupported,
	          "",
	          "");
	I_Method11(void, glCompressedTexSubImage3D, IN, GLenum, target, IN, GLint, level, IN, GLint, xoffset, IN, GLint, yoffset, IN, GLint, zoffset, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLenum, format, IN, GLsizei, imageSize, IN, const GLvoid *, data,
	           Properties::NON_VIRTUAL,
	           __void__glCompressedTexSubImage3D__GLenum__GLint__GLint__GLint__GLint__GLsizei__GLsizei__GLsizei__GLenum__GLsizei__C5_GLvoid_P1,
	           "",
	           "");





	I_SimpleProperty(GLint, Max2DSize, 
	                 0, 
	                 __void__setMax2DSize__GLint);
	I_SimpleProperty(GLint, MaxLayerCount, 
	                 0, 
	                 __void__setMaxLayerCount__GLint);
	I_SimpleProperty(bool, Texture2DArraySupported, 
	                 0, 
	                 __void__setTexture2DArraySupported__bool);
	I_SimpleProperty(bool, Texture3DSupported, 
	                 0, 
	                 __void__setTexture3DSupported__bool);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::Texture2DArray::SubloadCallback)
	I_DeclaringFile("osg/Texture2DArray");
	I_BaseType(osg::Referenced);
	I_Constructor0(____SubloadCallback,
	               "",
	               "");
	I_Method2(void, load, IN, const osg::Texture2DArray &, texture, IN, osg::State &, state,
	          Properties::PURE_VIRTUAL,
	          __void__load__C5_Texture2DArray_R1__State_R1,
	          "",
	          "");
	I_Method2(void, subload, IN, const osg::Texture2DArray &, texture, IN, osg::State &, state,
	          Properties::PURE_VIRTUAL,
	          __void__subload__C5_Texture2DArray_R1__State_R1,
	          "",
	          "");
END_REFLECTOR

