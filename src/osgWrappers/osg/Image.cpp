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
#include <osg/FrameStamp>
#include <osg/Image>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/Vec2>
#include <osg/Vec3>
#include <osg/Vec4>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< unsigned int >, osg::Image::MipmapDataType)

BEGIN_ENUM_REFLECTOR(osg::Image::WriteHint)
	I_DeclaringFile("osg/Image");
	I_EnumLabel(osg::Image::NO_PREFERENCE);
	I_EnumLabel(osg::Image::STORE_INLINE);
	I_EnumLabel(osg::Image::EXTERNAL_FILE);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Image::AllocationMode)
	I_DeclaringFile("osg/Image");
	I_EnumLabel(osg::Image::NO_DELETE);
	I_EnumLabel(osg::Image::USE_NEW_DELETE);
	I_EnumLabel(osg::Image::USE_MALLOC_FREE);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Image::Origin)
	I_DeclaringFile("osg/Image");
	I_EnumLabel(osg::Image::BOTTOM_LEFT);
	I_EnumLabel(osg::Image::TOP_LEFT);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::Image)
	I_DeclaringFile("osg/Image");
	I_BaseType(osg::Object);
	I_Constructor0(____Image,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::Image &, image, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Image__C5_Image_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __Object_P1__clone__C5_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
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
	I_Method1(int, compare, IN, const osg::Image &, rhs,
	          Properties::VIRTUAL,
	          __int__compare__C5_Image_R1,
	          "Return -1 if *this < *rhs, 0 if *this==*rhs, 1 if *this>*rhs. ",
	          "");
	I_Method1(void, setFileName, IN, const std::string &, fileName,
	          Properties::NON_VIRTUAL,
	          __void__setFileName__C5_std_string_R1,
	          "",
	          "");
	I_Method0(const std::string &, getFileName,
	          Properties::NON_VIRTUAL,
	          __C5_std_string_R1__getFileName,
	          "",
	          "");
	I_Method1(void, setWriteHint, IN, osg::Image::WriteHint, writeHint,
	          Properties::NON_VIRTUAL,
	          __void__setWriteHint__WriteHint,
	          "",
	          "");
	I_Method0(osg::Image::WriteHint, getWriteHint,
	          Properties::NON_VIRTUAL,
	          __WriteHint__getWriteHint,
	          "",
	          "");
	I_Method1(void, setAllocationMode, IN, osg::Image::AllocationMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setAllocationMode__AllocationMode,
	          "Set the method used for deleting data once it goes out of scope. ",
	          "");
	I_Method0(osg::Image::AllocationMode, getAllocationMode,
	          Properties::NON_VIRTUAL,
	          __AllocationMode__getAllocationMode,
	          "Get the method used for deleting data once it goes out of scope. ",
	          "");
	I_MethodWithDefaults6(void, allocateImage, IN, int, s, , IN, int, t, , IN, int, r, , IN, GLenum, pixelFormat, , IN, GLenum, type, , IN, int, packing, 1,
	                      Properties::NON_VIRTUAL,
	                      __void__allocateImage__int__int__int__GLenum__GLenum__int,
	                      "Allocate a pixel block of specified size and type. ",
	                      "");
	I_MethodWithDefaults9(void, setImage, IN, int, s, , IN, int, t, , IN, int, r, , IN, GLint, internalTextureformat, , IN, GLenum, pixelFormat, , IN, GLenum, type, , IN, unsigned char *, data, , IN, osg::Image::AllocationMode, mode, , IN, int, packing, 1,
	                      Properties::NON_VIRTUAL,
	                      __void__setImage__int__int__int__GLint__GLenum__GLenum__unsigned_char_P1__AllocationMode__int,
	                      "Set the image dimensions, format and data. ",
	                      "");
	I_Method6(void, readPixels, IN, int, x, IN, int, y, IN, int, width, IN, int, height, IN, GLenum, pixelFormat, IN, GLenum, type,
	          Properties::NON_VIRTUAL,
	          __void__readPixels__int__int__int__int__GLenum__GLenum,
	          "Read pixels from current frame buffer at specified position and size, using glReadPixels. ",
	          "Create memory for storage if required, reuse existing pixel coords if possible. ");
	I_MethodWithDefaults3(void, readImageFromCurrentTexture, IN, unsigned int, contextID, , IN, bool, copyMipMapsIfAvailable, , IN, GLenum, type, GL_UNSIGNED_BYTE,
	                      Properties::NON_VIRTUAL,
	                      __void__readImageFromCurrentTexture__unsigned_int__bool__GLenum,
	                      "Read the contents of the current bound texture, handling compressed pixelFormats if present. ",
	                      "Create memory for storage if required, reuse existing pixel coords if possible. ");
	I_Method3(void, scaleImage, IN, int, s, IN, int, t, IN, int, r,
	          Properties::NON_VIRTUAL,
	          __void__scaleImage__int__int__int,
	          "Scale image to specified size. ",
	          "");
	I_Method4(void, scaleImage, IN, int, s, IN, int, t, IN, int, r, IN, GLenum, newDataType,
	          Properties::NON_VIRTUAL,
	          __void__scaleImage__int__int__int__GLenum,
	          "Scale image to specified size and with specified data type. ",
	          "");
	I_Method4(void, copySubImage, IN, int, s_offset, IN, int, t_offset, IN, int, r_offset, IN, osg::Image *, source,
	          Properties::NON_VIRTUAL,
	          __void__copySubImage__int__int__int__osg_Image_P1,
	          "Copy a source Image into a subpart of this Image at specified position. ",
	          "Typically used to copy to an already allocated image, such as creating a 3D image from a stack 2D images. If this Image is empty then image data is created to accomodate the source image in its offset position. If source is NULL then no operation happens, this Image is left unchanged. ");
	I_Method1(void, setOrigin, IN, osg::Image::Origin, origin,
	          Properties::NON_VIRTUAL,
	          __void__setOrigin__Origin,
	          "Set the origin of the image. ",
	          "The default value is BOTTOM_LEFT and is consistent with OpenGL. TOP_LEFT is used for imagery that follows standard Imagery convention, such as movies, and hasn't been flipped yet. For such images one much flip the t axis of the tex coords. to handle this origin position. ");
	I_Method0(osg::Image::Origin, getOrigin,
	          Properties::NON_VIRTUAL,
	          __Origin__getOrigin,
	          "Get the origin of the image. ",
	          "");
	I_Method0(int, s,
	          Properties::NON_VIRTUAL,
	          __int__s,
	          "Width of image. ",
	          "");
	I_Method0(int, t,
	          Properties::NON_VIRTUAL,
	          __int__t,
	          "Height of image. ",
	          "");
	I_Method0(int, r,
	          Properties::NON_VIRTUAL,
	          __int__r,
	          "Depth of image. ",
	          "");
	I_Method1(void, setInternalTextureFormat, IN, GLint, internalFormat,
	          Properties::NON_VIRTUAL,
	          __void__setInternalTextureFormat__GLint,
	          "",
	          "");
	I_Method0(GLint, getInternalTextureFormat,
	          Properties::NON_VIRTUAL,
	          __GLint__getInternalTextureFormat,
	          "",
	          "");
	I_Method1(void, setPixelFormat, IN, GLenum, pixelFormat,
	          Properties::NON_VIRTUAL,
	          __void__setPixelFormat__GLenum,
	          "",
	          "");
	I_Method0(GLenum, getPixelFormat,
	          Properties::NON_VIRTUAL,
	          __GLenum__getPixelFormat,
	          "",
	          "");
	I_Method1(void, setDataType, IN, GLenum, dataType,
	          Properties::NON_VIRTUAL,
	          __void__setDataType__GLenum,
	          "",
	          "");
	I_Method0(GLenum, getDataType,
	          Properties::NON_VIRTUAL,
	          __GLenum__getDataType,
	          "",
	          "");
	I_Method1(void, setPacking, IN, unsigned int, packing,
	          Properties::NON_VIRTUAL,
	          __void__setPacking__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getPacking,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getPacking,
	          "",
	          "");
	I_Method0(unsigned int, getPixelSizeInBits,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getPixelSizeInBits,
	          "Return the number of bits required for each pixel. ",
	          "");
	I_Method0(unsigned int, getRowSizeInBytes,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getRowSizeInBytes,
	          "Return the number of bytes each row of pixels occupies once it has been packed. ",
	          "");
	I_Method0(unsigned int, getImageSizeInBytes,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getImageSizeInBytes,
	          "Return the number of bytes each image (_s*_t) of pixels occupies. ",
	          "");
	I_Method0(unsigned int, getTotalSizeInBytes,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getTotalSizeInBytes,
	          "Return the number of bytes the whole row/image/volume of pixels occupies. ",
	          "");
	I_Method0(unsigned int, getTotalSizeInBytesIncludingMipmaps,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getTotalSizeInBytesIncludingMipmaps,
	          "Return the number of bytes the whole row/image/volume of pixels occupies, including all mip maps if included. ",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "Return true if the Image represent a valid and usable imagery. ",
	          "");
	I_Method0(unsigned char *, data,
	          Properties::NON_VIRTUAL,
	          __unsigned_char_P1__data,
	          "Raw image data. ",
	          "");
	I_Method0(const unsigned char *, data,
	          Properties::NON_VIRTUAL,
	          __C5_unsigned_char_P1__data,
	          "Raw const image data. ",
	          "");
	I_MethodWithDefaults3(unsigned char *, data, IN, int, column, , IN, int, row, 0, IN, int, image, 0,
	                      Properties::NON_VIRTUAL,
	                      __unsigned_char_P1__data__int__int__int,
	                      "",
	                      "");
	I_MethodWithDefaults3(const unsigned char *, data, IN, int, column, , IN, int, row, 0, IN, int, image, 0,
	                      Properties::NON_VIRTUAL,
	                      __C5_unsigned_char_P1__data__int__int__int,
	                      "",
	                      "");
	I_MethodWithDefaults3(osg::Vec4, getColor, IN, unsigned int, s, , IN, unsigned, t, 0, IN, unsigned, r, 0,
	                      Properties::NON_VIRTUAL,
	                      __Vec4__getColor__unsigned_int__unsigned__unsigned,
	                      "Get the color value for specified texcoord. ",
	                      "");
	I_Method1(osg::Vec4, getColor, IN, const osg::Vec2 &, texcoord,
	          Properties::NON_VIRTUAL,
	          __Vec4__getColor__C5_Vec2_R1,
	          "Get the color value for specified texcoord. ",
	          "");
	I_Method1(osg::Vec4, getColor, IN, const osg::Vec3 &, texcoord,
	          Properties::NON_VIRTUAL,
	          __Vec4__getColor__C5_Vec3_R1,
	          "Get the color value for specified texcoord. ",
	          "");
	I_Method0(void, flipHorizontal,
	          Properties::NON_VIRTUAL,
	          __void__flipHorizontal,
	          "Flip the image horizontally. ",
	          "");
	I_Method0(void, flipVertical,
	          Properties::NON_VIRTUAL,
	          __void__flipVertical,
	          "Flip the image vertically. ",
	          "");
	I_Method1(void, ensureValidSizeForTexturing, IN, GLint, maxTextureSize,
	          Properties::NON_VIRTUAL,
	          __void__ensureValidSizeForTexturing__GLint,
	          "Ensure image dimensions are a power of two. ",
	          "Mipmapped textures require the image dimensions to be power of two and are within the maxiumum texture size for the host machine. ");
	I_Method0(void, dirty,
	          Properties::NON_VIRTUAL,
	          __void__dirty,
	          "Dirty the image, which increments the modified count, to force osg::Texture to reload the image. ",
	          "");
	I_Method1(void, setModifiedCount, IN, unsigned int, value,
	          Properties::NON_VIRTUAL,
	          __void__setModifiedCount__unsigned_int,
	          "Set the modified count value. ",
	          "Used by osg::Texture when using texture subloading. ");
	I_Method0(unsigned int, getModifiedCount,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getModifiedCount,
	          "Get modified count value. ",
	          "Used by osg::Texture when using texture subloading. ");
	I_Method0(bool, isMipmap,
	          Properties::NON_VIRTUAL,
	          __bool__isMipmap,
	          "",
	          "");
	I_Method0(unsigned int, getNumMipmapLevels,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumMipmapLevels,
	          "",
	          "");
	I_Method1(void, setMipmapLevels, IN, const osg::Image::MipmapDataType &, mipmapDataVector,
	          Properties::NON_VIRTUAL,
	          __void__setMipmapLevels__C5_MipmapDataType_R1,
	          "Send offsets into data. ",
	          "It is assumed that first mipmap offset (index 0) is 0. ");
	I_Method0(const osg::Image::MipmapDataType &, getMipmapLevels,
	          Properties::NON_VIRTUAL,
	          __C5_MipmapDataType_R1__getMipmapLevels,
	          "",
	          "");
	I_Method1(unsigned int, getMipmapOffset, IN, unsigned int, mipmapLevel,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getMipmapOffset__unsigned_int,
	          "",
	          "");
	I_Method1(unsigned char *, getMipmapData, IN, unsigned int, mipmapLevel,
	          Properties::NON_VIRTUAL,
	          __unsigned_char_P1__getMipmapData__unsigned_int,
	          "",
	          "");
	I_Method1(const unsigned char *, getMipmapData, IN, unsigned int, mipmapLevel,
	          Properties::NON_VIRTUAL,
	          __C5_unsigned_char_P1__getMipmapData__unsigned_int,
	          "",
	          "");
	I_Method0(bool, isImageTranslucent,
	          Properties::NON_VIRTUAL,
	          __bool__isImageTranslucent,
	          "Return true if this image is translucent - i.e. ",
	          "it has alpha values that are less 1.0 (when normalized). ");
	I_Method1(void, setPixelBufferObject, IN, osg::PixelBufferObject *, buffer,
	          Properties::NON_VIRTUAL,
	          __void__setPixelBufferObject__PixelBufferObject_P1,
	          "Set the optional PixelBufferObject used to map the image memory efficiently to graphics memory. ",
	          "");
	I_Method0(osg::PixelBufferObject *, getPixelBufferObject,
	          Properties::NON_VIRTUAL,
	          __PixelBufferObject_P1__getPixelBufferObject,
	          "Get the PixelBufferObject. ",
	          "");
	I_Method0(const osg::PixelBufferObject *, getPixelBufferObject,
	          Properties::NON_VIRTUAL,
	          __C5_PixelBufferObject_P1__getPixelBufferObject,
	          "Get the const PixelBufferObject. ",
	          "");
	I_Method1(void, update, IN, osg::NodeVisitor *, nv,
	          Properties::VIRTUAL,
	          __void__update__NodeVisitor_P1,
	          "",
	          "");
	I_Method3(void, sendPointerEvent, IN, int, x, IN, int, y, IN, int, buttonMask,
	          Properties::VIRTUAL,
	          __void__sendPointerEvent__int__int__int,
	          "method for sending pointer events to images that are acting as front ends to interactive surfaces such as a vnc or browser window. ",
	          "");
	I_Method2(void, sendKeyEvent, IN, int, key, IN, bool, keyDown,
	          Properties::VIRTUAL,
	          __void__sendKeyEvent__int__bool,
	          "method for sending key events to images that are acting as front ends to interactive surfaces such as a vnc or browser window. ",
	          "");
	I_Method1(void, setFrameLastRendered, IN, const osg::FrameStamp *, frameStamp,
	          Properties::VIRTUAL,
	          __void__setFrameLastRendered__C5_osg_FrameStamp_P1,
	          "method for passing frame information to the custom Image classes, to be called only when objects associated with imagery are not culled. ",
	          "");
	I_StaticMethod1(bool, isPackedType, IN, GLenum, type,
	                __bool__isPackedType__GLenum_S,
	                "",
	                "");
	I_StaticMethod1(GLenum, computePixelFormat, IN, GLenum, pixelFormat,
	                __GLenum__computePixelFormat__GLenum_S,
	                "",
	                "");
	I_StaticMethod1(unsigned int, computeNumComponents, IN, GLenum, pixelFormat,
	                __unsigned_int__computeNumComponents__GLenum_S,
	                "",
	                "");
	I_StaticMethod2(unsigned int, computePixelSizeInBits, IN, GLenum, pixelFormat, IN, GLenum, type,
	                __unsigned_int__computePixelSizeInBits__GLenum__GLenum_S,
	                "",
	                "");
	I_StaticMethod4(unsigned int, computeRowWidthInBytes, IN, int, width, IN, GLenum, pixelFormat, IN, GLenum, type, IN, int, packing,
	                __unsigned_int__computeRowWidthInBytes__int__GLenum__GLenum__int_S,
	                "",
	                "");
	I_StaticMethodWithDefaults2(int, computeNearestPowerOfTwo, IN, int, s, , IN, float, bias, 0.5f,
	                            __int__computeNearestPowerOfTwo__int__float_S,
	                            "",
	                            "");
	I_StaticMethodWithDefaults3(int, computeNumberOfMipmapLevels, IN, int, s, , IN, int, t, 1, IN, int, r, 1,
	                            __int__computeNumberOfMipmapLevels__int__int__int_S,
	                            "",
	                            "");
	I_ProtectedMethod0(void, deallocateData,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__deallocateData,
	                   "",
	                   "");
	I_ProtectedMethod2(void, setData, IN, unsigned char *, data, IN, osg::Image::AllocationMode, allocationMode,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setData__unsigned_char_P1__AllocationMode,
	                   "",
	                   "");
	I_SimpleProperty(osg::Image::AllocationMode, AllocationMode, 
	                 __AllocationMode__getAllocationMode, 
	                 __void__setAllocationMode__AllocationMode);
	I_SimpleProperty(GLenum, DataType, 
	                 __GLenum__getDataType, 
	                 __void__setDataType__GLenum);
	I_SimpleProperty(const std::string &, FileName, 
	                 __C5_std_string_R1__getFileName, 
	                 __void__setFileName__C5_std_string_R1);
	I_SimpleProperty(const osg::FrameStamp *, FrameLastRendered, 
	                 0, 
	                 __void__setFrameLastRendered__C5_osg_FrameStamp_P1);
	I_SimpleProperty(unsigned int, ImageSizeInBytes, 
	                 __unsigned_int__getImageSizeInBytes, 
	                 0);
	I_SimpleProperty(GLint, InternalTextureFormat, 
	                 __GLint__getInternalTextureFormat, 
	                 __void__setInternalTextureFormat__GLint);
	I_SimpleProperty(const osg::Image::MipmapDataType &, MipmapLevels, 
	                 __C5_MipmapDataType_R1__getMipmapLevels, 
	                 __void__setMipmapLevels__C5_MipmapDataType_R1);
	I_SimpleProperty(unsigned int, ModifiedCount, 
	                 __unsigned_int__getModifiedCount, 
	                 __void__setModifiedCount__unsigned_int);
	I_SimpleProperty(osg::Image::Origin, Origin, 
	                 __Origin__getOrigin, 
	                 __void__setOrigin__Origin);
	I_SimpleProperty(unsigned int, Packing, 
	                 __unsigned_int__getPacking, 
	                 __void__setPacking__unsigned_int);
	I_SimpleProperty(osg::PixelBufferObject *, PixelBufferObject, 
	                 __PixelBufferObject_P1__getPixelBufferObject, 
	                 __void__setPixelBufferObject__PixelBufferObject_P1);
	I_SimpleProperty(GLenum, PixelFormat, 
	                 __GLenum__getPixelFormat, 
	                 __void__setPixelFormat__GLenum);
	I_SimpleProperty(unsigned int, PixelSizeInBits, 
	                 __unsigned_int__getPixelSizeInBits, 
	                 0);
	I_SimpleProperty(unsigned int, RowSizeInBytes, 
	                 __unsigned_int__getRowSizeInBytes, 
	                 0);
	I_SimpleProperty(unsigned int, TotalSizeInBytes, 
	                 __unsigned_int__getTotalSizeInBytes, 
	                 0);
	I_SimpleProperty(unsigned int, TotalSizeInBytesIncludingMipmaps, 
	                 __unsigned_int__getTotalSizeInBytesIncludingMipmaps, 
	                 0);
	I_SimpleProperty(osg::Image::WriteHint, WriteHint, 
	                 __WriteHint__getWriteHint, 
	                 __void__setWriteHint__WriteHint);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< unsigned int >)

