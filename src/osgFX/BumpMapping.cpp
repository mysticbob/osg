#include <osgFX/BumpMapping>
#include <osgFX/Registry>

#include <osg/VertexProgram>
#include <osg/FragmentProgram>
#include <osg/Texture2D>
#include <osg/Depth>
#include <osg/TexEnv>
#include <osg/TexEnvCombine>
#include <osg/BlendFunc>
#include <osg/Geometry>
#include <osg/Notify>

#include <osgUtil/TangentSpaceGenerator>

#include <osgDB/ReadFile>

#include <sstream>

using namespace osgFX;

namespace
{

    using osg::NodeVisitor;
    
     // this is a visitor class that prepares all geometries in a subgraph
    // by calling prepareGeometry() which in turn generates tangent-space
    // basis vectors
    class TsgVisitor: public NodeVisitor {
    public:
        TsgVisitor(BumpMapping *bm): NodeVisitor(NodeVisitor::TRAVERSE_ALL_CHILDREN), bm_(bm) {}
        void apply(osg::Geode &geode)
        {
            for (unsigned i=0; i<geode.getNumDrawables(); ++i) {
                osg::Geometry *geo = dynamic_cast<osg::Geometry *>(geode.getDrawable(i));
                if (geo) {
                    bm_->prepareGeometry(geo);
                }
            }
            NodeVisitor::apply(geode);
        }
    private:
        osg::ref_ptr<BumpMapping> bm_;
    };


    // this visitor generates texture coordinates for all geometries in a
    // subgraph. It is used only for demo purposes.
    class TexCoordGenerator: public osg::NodeVisitor {
    public:
        TexCoordGenerator(int du, int nu): NodeVisitor(NodeVisitor::TRAVERSE_ALL_CHILDREN), du_(du), nu_(nu) {}
        void apply(osg::Geode &geode)
        {
            const osg::BoundingSphere &bsphere = geode.getBound();
            float scale = 10;
            if (bsphere.radius() != 0) {
                scale = 5 / bsphere.radius();
            }
            for (unsigned i=0; i<geode.getNumDrawables(); ++i) {
                osg::Geometry *geo = dynamic_cast<osg::Geometry *>(geode.getDrawable(i));
                if (geo) {
                    osg::ref_ptr<osg::Vec2Array> tc = generate_coords(geo->getVertexArray(), geo->getNormalArray(), scale);
                    geo->setTexCoordArray(du_, tc.get());
                    geo->setTexCoordArray(nu_, tc.get());
                }
            }
            NodeVisitor::apply(geode);
        }

    protected:
        osg::Vec2Array *generate_coords(osg::Array *vx, osg::Array *nx, float scale)
        {
            osg::Vec2Array *v2a = dynamic_cast<osg::Vec2Array *>(vx);
            osg::Vec3Array *v3a = dynamic_cast<osg::Vec3Array *>(vx);
            osg::Vec4Array *v4a = dynamic_cast<osg::Vec4Array *>(vx);
            osg::Vec2Array *n2a = dynamic_cast<osg::Vec2Array *>(nx);
            osg::Vec3Array *n3a = dynamic_cast<osg::Vec3Array *>(nx);
            osg::Vec4Array *n4a = dynamic_cast<osg::Vec4Array *>(nx);

            osg::ref_ptr<osg::Vec2Array> tc = new osg::Vec2Array;
            for (unsigned i=0; i<vx->getNumElements(); ++i) {

                osg::Vec3 P;
                if (v2a) P.set(v2a->at(i).x(), v2a->at(i).y(), 0);
                if (v3a) P.set(v3a->at(i).x(), v3a->at(i).y(), v3a->at(i).z());
                if (v4a) P.set(v4a->at(i).x(), v4a->at(i).y(), v4a->at(i).z());

                osg::Vec3 N(0, 0, 1);
                if (n2a) N.set(n2a->at(i).x(), n2a->at(i).y(), 0);
                if (n3a) N.set(n3a->at(i).x(), n3a->at(i).y(), n3a->at(i).z());
                if (n4a) N.set(n4a->at(i).x(), n4a->at(i).y(), n4a->at(i).z());

                int axis = 0;
                if (N.y() > N.x() && N.y() > N.z()) axis = 1;
                if (-N.y() > N.x() && -N.y() > N.z()) axis = 1;
                if (N.z() > N.x() && N.z() > N.y()) axis = 2;
                if (-N.z() > N.x() && -N.z() > N.y()) axis = 2;

                osg::Vec2 uv;

                switch (axis) {
                    case 0: uv.set(P.y(), P.z()); break;
                    case 1: uv.set(P.x(), P.z()); break;
                    case 2: uv.set(P.x(), P.y()); break;
                    default: ;
                }

                tc->push_back(uv * scale);
            }
            return tc.take();
        }

    private:
        int du_;
        int nu_;
    };

}

namespace
{

    const unsigned int NO_VALID_CONTEXT = 0xffffffff;

    // a state attribute class that grabs the initial inverse view matrix
    // and sends it to a VertexProgram.
    // NOTE: due to lack of support for per-context parameters in VertexProgram,
    // this class will send the matrix to the vp only while the first context
    // is being rendered. All subsequent contexts will use the first context's
    // matrix.
    class ViewMatrixExtractor: public osg::StateAttribute {
    public:
    
    
        ViewMatrixExtractor()
        :    osg::StateAttribute(),
            vp_(0),
            param_(0),
            first_context_(NO_VALID_CONTEXT)
        {
        }

        ViewMatrixExtractor(const ViewMatrixExtractor &copy, const osg::CopyOp &copyop)
        :    osg::StateAttribute(copy, copyop),
            vp_(static_cast<osg::VertexProgram *>(copyop(copy.vp_.get()))),
            param_(copy.param_),
            first_context_(NO_VALID_CONTEXT)
        {
        }

        ViewMatrixExtractor(osg::VertexProgram *vp, int param)
        :    osg::StateAttribute(),
            vp_(vp),
            param_(param),
            first_context_(NO_VALID_CONTEXT)
        {
        }

        META_StateAttribute(osgFX, ViewMatrixExtractor, 0x564d4548);

        int compare(const osg::StateAttribute &sa) const
        {
            COMPARE_StateAttribute_Types(ViewMatrixExtractor, sa);
            if (vp_.get() != rhs.vp_.get()) return -1;
            if (param_ < rhs.param_) return -1;
            if (param_ > rhs.param_) return 1;
            return 0;
        }

        void apply(osg::State &state) const
        {
            if (first_context_ == NO_VALID_CONTEXT) {
                first_context_ = state.getContextID();
            }
            if (state.getContextID() == first_context_) {
                if (vp_.valid()) {
                    osg::Matrix M = state.getInitialInverseViewMatrix();
                    for (int i=0; i<4; ++i) {
                        vp_->setProgramLocalParameter(param_+i, osg::Vec4(M(0, i), M(1, i), M(2, i), M(3, i)));
                    }                
                }
            }
        }

    private:
        mutable osg::ref_ptr<osg::VertexProgram> vp_;
        int param_;
        mutable unsigned int first_context_;
    };

}


namespace
{
    // let's register this cool effect! :)
    Registry::Proxy proxy(new BumpMapping);
}


namespace
{

    // "Full ARB" technique uses ARB vertex program and fragment program.
    // Handles ambient, diffuse and specular lighting transparently. A texture
    // for the diffuse component is required as well as a normal map texture.
    class FullArbTechnique: public Technique {
    public:

        FullArbTechnique(int lightnum, int diffuseunit, int normalunit, osg::Texture2D *diffuse_tex, osg::Texture2D *normal_tex)
        :   Technique(),
            lightnum_(lightnum),
            diffuseunit_(diffuseunit),
            normalunit_(normalunit),
            diffuse_tex_(diffuse_tex),
            normal_tex_(normal_tex)
        {
        }

        META_Technique(
            "FullArbTechnique", 
            "Single-pass technique, requires ARB_vertex_program and ARB_fragment_program."
        );

        void getRequiredExtensions(std::vector<std::string> &extensions) const
        {
            extensions.push_back("GL_ARB_vertex_program");
            extensions.push_back("GL_ARB_fragment_program");
        }

    protected:

        void define_passes()
        {
            // vertex program
            std::ostringstream vp_oss;
            vp_oss <<
                "!!ARBvp1.0\n"
                "OPTION ARB_position_invariant;"
                "PARAM c4 = { 0, 0, 0, 1 };"
                "PARAM c5 = { 0.5, 4, 0, 0 };"
                "TEMP R0, R1, R2, R3, R4, R5, R6, R7, R8;"
                "ATTRIB v5 = vertex.attrib[15];"
                "ATTRIB v4 = vertex.attrib[7];"
                "ATTRIB v3 = vertex.attrib[6];"
                "ATTRIB v25 = vertex.texcoord[1];"
                "ATTRIB v24 = vertex.texcoord[0];"
                "ATTRIB v18 = vertex.normal;"
                "ATTRIB v16 = vertex.position;"
                "PARAM s259[4] = { state.matrix.mvp };"
                "PARAM s18 = state.light[0].position;"
                "PARAM s77 = state.lightprod[0].specular;"
                "PARAM s4 = state.material.shininess;"
                "PARAM s75 = state.lightprod[0].ambient;"
                "PARAM s223[4] = { state.matrix.modelview[0] };"
                "PARAM c0[4] = { program.local[0..3] };"
                "    MOV result.texcoord[2].xyz, s75.xyzx;"
                "    MOV result.texcoord[2].w, s4.x;"
                "    MOV result.texcoord[0].zw, s77.xyxy;"
                "    MOV result.texcoord[0].xy, v24;"
                "    MOV result.texcoord[1].zw, s77.zwzw;"
                "    MOV result.texcoord[1].xy, v25;"
                "    MOV R5, c0[0];"
                "    MUL R0, R5.y, s223[1];"
                "    MAD R0, R5.x, s223[0], R0;"
                "    MAD R0, R5.z, s223[2], R0;"
                "    MAD R0, R5.w, s223[3], R0;"
                "    DP4 R1.x, R0, v16;"
                "    MOV R4, c0[1];"
                "    MUL R2, R4.y, s223[1];"
                "    MAD R2, R4.x, s223[0], R2;"
                "    MAD R2, R4.z, s223[2], R2;"
                "    MAD R7, R4.w, s223[3], R2;"
                "    DP4 R1.y, R7, v16;"
                "    MOV R3, c0[2];"
                "    MUL R2, R3.y, s223[1];"
                "    MAD R2, R3.x, s223[0], R2;"
                "    MAD R2, R3.z, s223[2], R2;"
                "    MAD R6, R3.w, s223[3], R2;"
                "    DP4 R1.z, R6, v16;"
                "    MOV R2, c0[3];"
                "    MUL R8, R2.y, s223[1];"
                "    MAD R8, R2.x, s223[0], R8;"
                "    MAD R8, R2.z, s223[2], R8;"
                "    MAD R8, R2.w, s223[3], R8;"
                "    MOV R8.x, R5.w;"
                "    MOV R8.y, R4.w;"
                "    MOV R8.z, R3.w;"
                "    ADD R1.yzw, R8.xxyz, -R1.xxyz;"
                "    DP3 R1.x, R1.yzwy, R1.yzwy;"
                "    RSQ R1.x, R1.x;"
                "    DP4 R5.x, R5, s18;"
                "    DP4 R5.y, R4, s18;"
                "    DP4 R5.z, R3, s18;"
                "    DP3 R2.x, R5.xyzx, R5.xyzx;"
                "    RSQ R2.x, R2.x;"
                "    MUL R5.xyz, R2.x, R5.xyzx;"
                "    MAD R1.yzw, R1.x, R1.yyzw, R5.xxyz;"
                "    DP3 R1.x, R1.yzwy, R1.yzwy;"
                "    RSQ R1.x, R1.x;"
                "    MUL R4.xyz, R1.x, R1.yzwy;"
                "    DP3 R3.x, R0.xyzx, v3.xyzx;"
                "    DP3 R3.y, R7.xyzx, v3.xyzx;"
                "    DP3 R3.z, R6.xyzx, v3.xyzx;"
                "    DP3 R8.x, R3.xyzx, R4.xyzx;"
                "    DP3 R2.x, R0.xyzx, v4.xyzx;"
                "    DP3 R2.y, R7.xyzx, v4.xyzx;"
                "    DP3 R2.z, R6.xyzx, v4.xyzx;"
                "    DP3 R8.y, R2.xyzx, R4.xyzx;"
                "    DP3 R1.x, R0.xyzx, v5.xyzx;"
                "    DP3 R1.y, R7.xyzx, v5.xyzx;"
                "    DP3 R1.z, R6.xyzx, v5.xyzx;"
                "    DP3 R8.z, R1.xyzx, R4.xyzx;"
                "    MAD result.color.front.secondary.xyz, c5.x, R8.xyzx, c5.x;"
                "    DP3 R0.y, R0.xyzx, v18.xyzx;"
                "    DP3 R0.z, R7.xyzx, v18.xyzx;"
                "    DP3 R0.w, R6.xyzx, v18.xyzx;"
                "    DP3 R0.x, R0.yzwy, R0.yzwy;"
                "    RSQ R0.x, R0.x;"
                "    MUL R6.xyz, R0.x, R0.yzwy;"
                "    DP3 R0.x, R6.xyzx, R4.xyzx;"
                "    MUL result.color.front.secondary.w, c5.y, R0.x;"
                "    DP3 R0.x, R3.xyzx, R5.xyzx;"
                "    DP3 R0.y, R2.xyzx, R5.xyzx;"
                "    DP3 R0.z, R1.xyzx, R5.xyzx;"
                "    MAD result.color.front.primary.xyz, c5.x, R0.xyzx, c5.x;"
                "    DP3 R0.x, R6.xyzx, R5.xyzx;"
                "    MUL result.color.front.primary.w, c5.y, R0.x;"
                "END\n";
         
            // fragment program
            std::ostringstream fp_oss;
            fp_oss <<
                "!!ARBfp1.0\n"
                "PARAM c0 = {1, 2, 0.5, 0};"
                "PARAM c1 = {0, 0, 0, 1};"
                "TEMP R0;"
                "TEMP R1;"
                "TEMP R2;"
                "TEX R0, fragment.texcoord[0], texture[0], 2D;"
                "TEX R1, fragment.texcoord[1], texture[1], 2D;"
                "ADD R0, R0, -c0.z;"
                "MUL R0.xyz, c0.y, R0;"
                "ADD R2.xyz, fragment.color.primary, -c0.z;"
                "MUL R2.xyz, c0.y, R2;"
                "DP3_SAT R0.w, R0, R2;"
                "ADD R2, fragment.color.secondary, -c0.z;"
                "MUL R2.xyz, c0.y, R2;"
                "DP3_SAT R0.x, R0, R2;"
                "POW R0.x, R0.x, fragment.texcoord[2].w;"
                "MOV R2.xyz, fragment.texcoord[2].xyyx;"
                "MOV R2.w, c1.w;"
                "MOV_SAT R0.y, fragment.color.primary.w;"
                "MUL R0.w, R0.y, R0.w;"
                "ADD R2, R2, R0.w;"
                "MUL R1.xyz, R1, R2;"
                "MOV_SAT R0.y, fragment.color.secondary.w;"
                "MUL R0.xyz, R0.y, R0.x;"
                "MOV R2.xy, fragment.texcoord[1].zwzz;"
                "MOV R2.z, fragment.texcoord[0].z;"
                "MUL R2.xyz, R0, R2;"
                "ADD R2.xyz, R1, R2;"
                "MOV result.color.xyz, R2;"
                "MOV result.color.w, c0.x;"
                "END\n";            

            osg::ref_ptr<osg::StateSet> ss = new osg::StateSet;

            osg::ref_ptr<osg::VertexProgram> vp = new osg::VertexProgram;
            vp->setVertexProgram(vp_oss.str());
            ss->setAttributeAndModes(vp.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

            osg::ref_ptr<osg::FragmentProgram> fp = new osg::FragmentProgram;
            fp->setFragmentProgram(fp_oss.str());
            ss->setAttributeAndModes(fp.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

            ss->setAttributeAndModes(new ViewMatrixExtractor(vp.get(), 0), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

            if (diffuse_tex_.valid()) {
                ss->setTextureAttributeAndModes(diffuseunit_, diffuse_tex_.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);
            }

            if (normal_tex_.valid()) {
                ss->setTextureAttributeAndModes(normalunit_, normal_tex_.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);
            }

            addPass(ss.get());
        }

    private:
        int lightnum_;
        int diffuseunit_;
        int normalunit_;
        osg::ref_ptr<osg::Texture2D> diffuse_tex_;
        osg::ref_ptr<osg::Texture2D> normal_tex_;
    };

}

namespace
{

    // "ARB Vp" technique uses ARB vertex program and DOT3 texture environment.
    // Ambient and specular components are not handled. A texture for the diffuse 
    // component is required as well as a normal map texture.
    class ArbVpTechnique: public Technique {
    public:
        ArbVpTechnique(int lightnum, int diffuseunit, int normalunit, osg::Texture2D *diffuse_tex, osg::Texture2D *normal_tex)
        :   Technique(),
            lightnum_(lightnum),
            diffuseunit_(diffuseunit),
            normalunit_(normalunit),
            diffuse_tex_(diffuse_tex),
            normal_tex_(normal_tex)
        {
        }

        META_Technique(
            "ArbVpTechnique",
            "Two-passes technique, requires ARB_vertex_program and ARB_texture_env_dot3."
            "Only diffuse lighting, no ambient, no specularity."
        );

        void getRequiredExtensions(std::vector<std::string> &extensions) const
        {
            extensions.push_back("GL_ARB_vertex_program");
            extensions.push_back("GL_ARB_texture_env_dot3");
        }

        void define_passes()
        {
            if (diffuseunit_ != (normalunit_ + 1)) {
                osg::notify(osg::WARN) << "Warning: osgFX::BumpMapping: this technique (ArbVpTechnique) requires that diffuse_unit == (normal_unit + 1). Effect may not show up properly.\n";
            }

            // first pass, diffuse bump
            {
                std::ostringstream vp_oss;
                vp_oss <<
                    "!!ARBvp1.0\n"
                    "OPTION ARB_position_invariant;"
                    "PARAM c0 = { 0.5, 1, 0, 0 };"
                    "TEMP R0, R1, R2;"
                    "ATTRIB v5 = vertex.attrib[15];"
                    "ATTRIB v4 = vertex.attrib[7];"
                    "ATTRIB v3 = vertex.attrib[6];"
                    "ATTRIB v24 = vertex.texcoord[" << normalunit_ << "];"
                    "ATTRIB v25 = vertex.texcoord[" << diffuseunit_ << "];"
                    "ATTRIB v18 = vertex.normal;"
                    "ATTRIB v16 = vertex.position;"
                    "PARAM s259[4] = { state.matrix.mvp };"
                    "PARAM s18 = state.light[" << lightnum_ << "].position;"
                    "PARAM s223[4] = { state.matrix.modelview[0] };"
                    "    MOV result.texcoord[" << diffuseunit_ << "].xy, v25;"
                    "    MOV result.texcoord[" << normalunit_ << "].xy, v24;"
                    "    DP3 R0.y, s223[0].xyzx, v3.xyzx;"
                    "    DP3 R0.z, s223[1].xyzx, v3.xyzx;"
                    "    DP3 R0.w, s223[2].xyzx, v3.xyzx;"
                    "    DP3 R0.x, s18.xyzx, s18.xyzx;"
                    "    RSQ R0.x, R0.x;"
                    "    MUL R2.xyz, R0.x, s18.xyzx;"
                    "    DP3 R1.x, R0.yzwy, R2.xyzx;"
                    "    DP3 R0.x, s223[0].xyzx, v4.xyzx;"
                    "    DP3 R0.y, s223[1].xyzx, v4.xyzx;"
                    "    DP3 R0.z, s223[2].xyzx, v4.xyzx;"
                    "    DP3 R1.y, R0.xyzx, R2.xyzx;"
                    "    DP3 R0.x, s223[0].xyzx, v5.xyzx;"
                    "    DP3 R0.y, s223[1].xyzx, v5.xyzx;"
                    "    DP3 R0.z, s223[2].xyzx, v5.xyzx;"
                    "    DP3 R1.z, R0.xyzx, R2.xyzx;"
                    "    MAD result.color.front.primary.xyz, c0.x, R1.xyzx, c0.x;"
                    "    MOV result.color.front.primary.w, c0.y;"
                    "END\n";

                osg::ref_ptr<osg::StateSet> ss = new osg::StateSet;

                osg::ref_ptr<osg::VertexProgram> vp = new osg::VertexProgram;
                vp->setVertexProgram(vp_oss.str());
                ss->setAttributeAndModes(vp.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

                if (diffuse_tex_.valid()) {
                    ss->setTextureAttributeAndModes(diffuseunit_, diffuse_tex_.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);
                }

                if (normal_tex_.valid()) {
                    ss->setTextureAttributeAndModes(normalunit_, normal_tex_.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);
                }

                osg::ref_ptr<osg::TexEnvCombine> tec = new osg::TexEnvCombine;
                tec->setCombine_RGB(osg::TexEnvCombine::DOT3_RGB);
                tec->setSource0_RGB(osg::TexEnvCombine::PRIMARY_COLOR);
                tec->setSource1_RGB(osg::TexEnvCombine::TEXTURE);
                ss->setTextureAttributeAndModes(normalunit_, tec.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

                osg::ref_ptr<osg::TexEnv> te = new osg::TexEnv;
                te->setMode(osg::TexEnv::MODULATE);
                ss->setTextureAttributeAndModes(diffuseunit_, te.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

                addPass(ss.get());
            }

            // second pass, self-shadowing
            {
                std::ostringstream vp_oss;
                vp_oss <<
                    "!!ARBvp1.0\n"
                    "OPTION ARB_position_invariant;"
                    "PARAM c0 = { 8, 0, 1, 0 };"
                    "TEMP R0;"
                    "ATTRIB v18 = vertex.normal;"
                    "ATTRIB v16 = vertex.position;"
                    "PARAM s259[4] = { state.matrix.mvp };"
                    "PARAM s18 = state.light[" << lightnum_ << "].position;"
                    "PARAM s631[4] = { state.matrix.modelview[0].invtrans };"
                    "    DP4 R0.x, s631[0], v18;"
                    "    DP4 R0.y, s631[1], v18;"
                    "    DP4 R0.z, s631[2], v18;"
                    "    DP3 R0.x, R0.xyzx, s18.xyzx;"
                    "    MAX R0.x, R0.x, c0.y;"
                    "    MUL R0.x, c0.x, R0.x;"
                    "    MIN result.color.front.primary.xyz, R0.x, c0.z;"
                    "    MOV result.color.front.primary.w, c0.z;"
                    "END\n";

                osg::ref_ptr<osg::StateSet> ss = new osg::StateSet;

                osg::ref_ptr<osg::Depth> depth = new osg::Depth;
                depth->setFunction(osg::Depth::EQUAL);
                ss->setAttributeAndModes(depth.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

                osg::ref_ptr<osg::VertexProgram> vp = new osg::VertexProgram;
                vp->setVertexProgram(vp_oss.str());
                ss->setAttributeAndModes(vp.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

                osg::ref_ptr<osg::BlendFunc> bf = new osg::BlendFunc;
                bf->setFunction(osg::BlendFunc::DST_COLOR, osg::BlendFunc::ZERO);                
                ss->setAttributeAndModes(bf.get(), osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);

                ss->setTextureMode(diffuseunit_, GL_TEXTURE_2D, osg::StateAttribute::OVERRIDE|osg::StateAttribute::OFF);
                ss->setTextureMode(normalunit_, GL_TEXTURE_2D, osg::StateAttribute::OVERRIDE|osg::StateAttribute::OFF);

                addPass(ss.get());
            }

        }

    protected:
        int lightnum_;
        int diffuseunit_;
        int normalunit_;
        osg::ref_ptr<osg::Texture2D> diffuse_tex_;
        osg::ref_ptr<osg::Texture2D> normal_tex_;
    };

}


BumpMapping::BumpMapping()
:   Effect(),
    lightnum_(0),
    diffuseunit_(1),
    normalunit_(0)
{
}

BumpMapping::BumpMapping(const BumpMapping &copy, const osg::CopyOp &copyop)
:   Effect(copy, copyop),
    lightnum_(copy.lightnum_),
    diffuseunit_(copy.diffuseunit_),
    normalunit_(copy.normalunit_),
    diffuse_tex_(static_cast<osg::Texture2D *>(copyop(copy.diffuse_tex_.get()))),
    normal_tex_(static_cast<osg::Texture2D *>(copyop(copy.normal_tex_.get())))
{
}

bool BumpMapping::define_techniques()
{
    addTechnique(new FullArbTechnique(lightnum_, diffuseunit_, normalunit_, diffuse_tex_.get(), normal_tex_.get()));
    addTechnique(new ArbVpTechnique(lightnum_, diffuseunit_, normalunit_, diffuse_tex_.get(), normal_tex_.get()));
    return true;
}

void BumpMapping::prepareGeometry(osg::Geometry *geo)
{
    osg::ref_ptr<osgUtil::TangentSpaceGenerator> tsg = new osgUtil::TangentSpaceGenerator;
    tsg->generate(geo, normalunit_);
    if (!geo->getVertexAttribArray(6))
        geo->setVertexAttribData(6, osg::Geometry::ArrayData(tsg->getTangentArray(), osg::Geometry::BIND_PER_VERTEX,GL_TRUE));
    if (!geo->getVertexAttribArray(7))
        geo->setVertexAttribData(7, osg::Geometry::ArrayData(tsg->getBinormalArray(), osg::Geometry::BIND_PER_VERTEX, GL_TRUE));
    if (!geo->getVertexAttribArray(15))
        geo->setVertexAttribData(15, osg::Geometry::ArrayData(tsg->getNormalArray(), osg::Geometry::BIND_PER_VERTEX, GL_TRUE));
}

void BumpMapping::prepareNode(osg::Node *node)
{
    TsgVisitor tv(this);
    node->accept(tv);
}

void BumpMapping::prepareChildren()
{
	for (unsigned i=0; i<getNumChildren(); ++i)
		prepareNode(getChild(i));
}

void BumpMapping::setUpDemo()
{
    // generate texture coordinates
    TexCoordGenerator tcg(diffuseunit_, normalunit_);
    for (unsigned i=0; i<getNumChildren(); ++i)
		getChild(i)->accept(tcg);

    // set up diffuse texture
    if (!diffuse_tex_.valid()) {
        diffuse_tex_ = new osg::Texture2D;
        diffuse_tex_->setImage(osgDB::readImageFile("Images/whitemetal_diffuse.jpg"));
        diffuse_tex_->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR_MIPMAP_LINEAR);
        diffuse_tex_->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
        diffuse_tex_->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
        diffuse_tex_->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
        diffuse_tex_->setMaxAnisotropy(8);
    }

    // set up normal map texture
    if (!normal_tex_.valid()) {
        normal_tex_ = new osg::Texture2D;
        normal_tex_->setImage(osgDB::readImageFile("Images/whitemetal_normal.jpg"));
        normal_tex_->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR_MIPMAP_LINEAR);
        normal_tex_->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
        normal_tex_->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
        normal_tex_->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
        normal_tex_->setMaxAnisotropy(8);
    }

    // generate tangent-space basis vector
    prepareChildren();

    // recreate techniques on next step
    dirtyTechniques();
}
