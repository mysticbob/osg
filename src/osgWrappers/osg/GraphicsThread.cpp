// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/GraphicsContext>
#include <osg/GraphicsThread>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osg::BarrierOperation::PreBlockOp)
	I_EnumLabel(osg::BarrierOperation::NO_OPERATION);
	I_EnumLabel(osg::BarrierOperation::GL_FLUSH);
	I_EnumLabel(osg::BarrierOperation::GL_FINISH);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::BarrierOperation)
	I_BaseType(osg::GraphicsThread::Operation);
	I_ConstructorWithDefaults2(IN, int, numThreads, , IN, osg::BarrierOperation::PreBlockOp, op, osg::BarrierOperation::NO_OPERATION);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::Block)
	I_VirtualBaseType(osg::Referenced);
	I_Constructor0();
	I_Method0(void, block);
	I_Method0(void, release);
	I_Method0(void, reset);
	I_Method1(void, set, IN, bool, doRelease);
	I_WriteOnlyProperty(bool, );
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::GraphicsThread)
	I_BaseType(osg::Referenced);
	I_Constructor0();
	I_MethodWithDefaults2(void, add, IN, osg::GraphicsThread::Operation *, operation, , IN, bool, waitForCompletion, false);
	I_Method0(void, run);
	I_Method0(int, cancel);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::GraphicsThread::Operation)
	I_VirtualBaseType(osg::Referenced);
	I_Constructor2(IN, const std::string &, name, IN, bool, keep);
	I_Method1(void, setName, IN, const std::string &, name);
	I_Method0(const std::string &, getName);
	I_Method1(void, setKeep, IN, bool, keep);
	I_Method0(bool, getKeep);
	I_Property(bool, Keep);
	I_Property(const std::string &, Name);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::ReleaseContext_Block_MakeCurrentOperation)
	I_BaseType(osg::GraphicsThread::Operation);
	I_BaseType(osg::Block);
	I_Constructor0();
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::SwapBuffersOperation)
	I_BaseType(osg::GraphicsThread::Operation);
	I_Constructor0();
END_REFLECTOR

