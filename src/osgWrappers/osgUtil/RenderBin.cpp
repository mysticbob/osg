// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/CopyOp>
#include <osg/Object>
#include <osg/State>
#include <osgUtil/RenderBin>
#include <osgUtil/RenderLeaf>
#include <osgUtil/RenderStage>
#include <osgUtil/StateGraph>
#include <osgUtil/Statistics>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_VALUE_REFLECTOR(osgUtil::RegisterRenderBinProxy)
	I_Constructor2(IN, const std::string &, binName, IN, osgUtil::RenderBin *, proto);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osgUtil::RenderLeaf * >, osgUtil::RenderBin::RenderLeafList);

TYPE_NAME_ALIAS(std::vector< osgUtil::StateGraph * >, osgUtil::RenderBin::StateGraphList);

TYPE_NAME_ALIAS(std::map< int COMMA  osg::ref_ptr< osgUtil::RenderBin > >, osgUtil::RenderBin::RenderBinList);

BEGIN_ENUM_REFLECTOR(osgUtil::RenderBin::SortMode)
	I_EnumLabel(osgUtil::RenderBin::SORT_BY_STATE);
	I_EnumLabel(osgUtil::RenderBin::SORT_BY_STATE_THEN_FRONT_TO_BACK);
	I_EnumLabel(osgUtil::RenderBin::SORT_FRONT_TO_BACK);
	I_EnumLabel(osgUtil::RenderBin::SORT_BACK_TO_FRONT);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::RenderBin)
	I_BaseType(osg::Object);
	I_Constructor0();
	I_Constructor1(IN, osgUtil::RenderBin::SortMode, mode);
	I_ConstructorWithDefaults2(IN, const osgUtil::RenderBin &, rhs, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(void, reset);
	I_Method0(osgUtil::RenderBin *, getParent);
	I_Method0(const osgUtil::RenderBin *, getParent);
	I_Method0(osgUtil::RenderStage *, getStage);
	I_Method0(const osgUtil::RenderStage *, getStage);
	I_Method0(int, getBinNum);
	I_Method0(osgUtil::RenderBin::StateGraphList &, getStateGraphList);
	I_Method0(const osgUtil::RenderBin::StateGraphList &, getStateGraphList);
	I_Method0(osgUtil::RenderBin::RenderBinList &, getRenderBinList);
	I_Method0(const osgUtil::RenderBin::RenderBinList &, getRenderBinList);
	I_Method0(osgUtil::RenderBin::RenderLeafList &, getRenderLeafList);
	I_Method0(const osgUtil::RenderBin::RenderLeafList &, getRenderLeafList);
	I_Method2(osgUtil::RenderBin *, find_or_insert, IN, int, binNum, IN, const std::string &, binName);
	I_Method1(void, addStateGraph, IN, osgUtil::StateGraph *, rg);
	I_Method0(void, sort);
	I_Method0(void, sortImplementation);
	I_Method1(void, setSortMode, IN, osgUtil::RenderBin::SortMode, mode);
	I_Method0(osgUtil::RenderBin::SortMode, getSortMode);
	I_Method0(void, sortByState);
	I_Method0(void, sortByStateThenFrontToBack);
	I_Method0(void, sortFrontToBack);
	I_Method0(void, sortBackToFront);
	I_Method1(void, setSortCallback, IN, osgUtil::RenderBin::SortCallback *, sortCallback);
	I_Method0(osgUtil::RenderBin::SortCallback *, getSortCallback);
	I_Method0(const osgUtil::RenderBin::SortCallback *, getSortCallback);
	I_Method2(void, draw, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	I_Method2(void, drawImplementation, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	I_Method1(void, setDrawCallback, IN, osgUtil::RenderBin::DrawCallback *, drawCallback);
	I_Method0(osgUtil::RenderBin::DrawCallback *, getDrawCallback);
	I_Method0(const osgUtil::RenderBin::DrawCallback *, getDrawCallback);
	I_Method1(bool, getStats, IN, osgUtil::Statistics &, primStats);
	I_Method0(void, copyLeavesFromStateGraphListToRenderLeafList);
	I_ReadOnlyProperty(int, BinNum);
	I_Property(osgUtil::RenderBin::DrawCallback *, DrawCallback);
	I_ReadOnlyProperty(osgUtil::RenderBin *, Parent);
	I_ReadOnlyProperty(osgUtil::RenderBin::RenderBinList &, RenderBinList);
	I_ReadOnlyProperty(osgUtil::RenderBin::RenderLeafList &, RenderLeafList);
	I_Property(osgUtil::RenderBin::SortCallback *, SortCallback);
	I_Property(osgUtil::RenderBin::SortMode, SortMode);
	I_ReadOnlyProperty(osgUtil::RenderStage *, Stage);
	I_ReadOnlyProperty(osgUtil::RenderBin::StateGraphList &, StateGraphList);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgUtil::RenderBin::DrawCallback)
	I_BaseType(osg::Referenced);
	I_Constructor0();
	I_Method3(void, drawImplementation, IN, osgUtil::RenderBin *, bin, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgUtil::RenderBin::SortCallback)
	I_BaseType(osg::Referenced);
	I_Constructor0();
	I_Method1(void, sortImplementation, IN, osgUtil::RenderBin *, x);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgUtil::RenderBin >)
	I_Constructor0();
	I_Constructor1(IN, osgUtil::RenderBin *, ptr);
	I_Constructor1(IN, const osg::ref_ptr< osgUtil::RenderBin > &, rp);
	I_Method0(osgUtil::RenderBin *, get);
	I_Method0(bool, valid);
	I_Method0(osgUtil::RenderBin *, release);
	I_Method1(void, swap, IN, osg::ref_ptr< osgUtil::RenderBin > &, rp);
	I_ReadOnlyProperty(osgUtil::RenderBin *, );
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< int COMMA  osg::ref_ptr< osgUtil::RenderBin > >);

STD_VECTOR_REFLECTOR(std::vector< osgUtil::RenderLeaf * >);

STD_VECTOR_REFLECTOR(std::vector< osgUtil::StateGraph * >);

