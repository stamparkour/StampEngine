module;

#include "debug.h"
#include "glm.h"

export module testScene;

import std;
import engine;
import gamerender;
import swm;
import math;

class ControlComponent : public engine::Component {
    math::Vec2f direction{};
    //sync safe
    virtual void Start() {}
    //unsafe
    virtual void Update() {
        math::Vec2f cursor{(float)swm::getCursorDeltaX(), (float)swm::getCursorDeltaY()};
        cursor *= 0.002;
        direction += cursor;
        GameObject()->transform.rotation = math::Quatf::RotationZXY(direction.y, direction.x,0);
        float speed = 5;
        if (swm::isKeyHold(swm::VertKey::W)) {
            GameObject()->transform.position += GameObject()->Forward() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::S)) {
            GameObject()->transform.position += GameObject()->Back() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::D)) {
            GameObject()->transform.position += GameObject()->Right() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::A)) {
            GameObject()->transform.position += GameObject()->Left() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::E)) {
            GameObject()->transform.position += math::Vec3f(0,1,0) * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::Q)) {
            GameObject()->transform.position += math::Vec3f(0, -1, 0) * swm::DeltaTime() * speed;
        }


    }
    //gl context safe
    virtual void Render(int phase) {
        if(phase == 0)
        if (swm::isKeyDown(swm::VertKey::F1)) {
            static bool k = true;
            if (k)
                render::TriangleOutline();
            else
                render::TriangleFill();
            k = !k;
        }
    }
    //sync safe
    virtual void SyncUpdate() {}
    //sync safe
    virtual void OnEnable() {}
    //sync safe
    virtual void OnDisable() {}
    //sync safe
    virtual void OnDestroy() {}
};

class BoatComponent : public engine::Component {
    //sync safe
    virtual void Start() {}
    //unsafe
    virtual void Update() {
        math::Vec2f force{};
        float Torque = 0;
        math::Mat4f rot = math::Mat4f::RotationZ(angle);
        math::Vec2f dragN = (math::Vec2f)(rot * drag);
        dragN.x = abs(dragN.x);
        dragN.y = abs(dragN.y);
        math::Vec2f dragF = dragN * ((wind - velocity) + (current - velocity) * waterResistanceCo);
        force += dragF;
        math::Vec2f k = current - velocity;

        math::Vec2f rudderPos = (math::Vec2f)(rot * math::Vec2f(0,rudderOffset )) + 
            math::Vec2f{ std::sin(rudderAngle + angle), -std::cos(rudderAngle + angle) } *rudderLength / 2;
        math::Vec2f rudderDragV = math::Vec2f{ std::cos(rudderAngle + angle), std::sin(rudderAngle + angle) } * rudderDrag;
        rudderDragV.x = abs(rudderDragV.x);
        rudderDragV.y = abs(rudderDragV.y);
        math::Vec2f rudderForce = rudderDragV * (current - velocity) * waterResistanceCo;

        force += rudderForce;
        Torque -= math::Cross(rudderPos, rudderForce);

        angularVelocity += Torque * swm::DeltaTime() / anglularInertia;
        angularVelocity -= angularVelocity * swm::DeltaTime() * drag.x;
        angle += angularVelocity * swm::DeltaTime();
        velocity += force * swm::DeltaTime() / mass;
        position += velocity * swm::DeltaTime();
        GameObject()->transform.position = math::Vec3f(position.x, 0, position.y);
        GameObject()->transform.rotation = math::Quatf::RotationY(angle);

        static int i = 0;
        if (i++ % 15 == 0) {
            std::cout << "vel x: " << velocity.x << ", z: " << velocity.y << std::endl;
            std::cout << "angVel : " << angularVelocity << std::endl;
            std::cout << std::endl;
        }
    }
    //gl context safe
    virtual void Render(int phase) {
    }
    //sync safe
    virtual void SyncUpdate() {}
    //sync safe
    virtual void OnEnable() {}
    //sync safe
    virtual void OnDisable() {}
    //sync safe
    virtual void OnDestroy() {}
public:
    static inline math::Vec2f wind{ 8,0 };
    static inline math::Vec2f current = wind / 20;
    float mass = 20;
    float anglularInertia = 50;
    math::Vec2f position{};
    math::Vec2f velocity{1,1};
    float angle;
    float angularVelocity;
    float rudderOffset = 1.2;
    float rudderLength = 0.14;
    float rudderDrag = 0.14;
    math::Vec2f drag{ 0.02,0.6 };
    float waterResistanceCo = 12;

    float rudderAngle;
    struct {
        float angle = 0;
        float drag = 0;
        float offset = 0;
        float activePercent = 0;
    } sails[8];
};

export class InitScene : public engine::Scene {
public:
    InitScene() {}
    virtual void Initialize() {
        using namespace engine;
        using namespace engine::component;

        swm::setCursorVisibility(false);
        swm::setCursorConstraint(swm::CursorConstraintState::Frozen);

        glClearColor(135.0f/255, 206.0f/255, 235.0f/255, 0.0f);
        glClearStencil(0);
        glClearDepth(0);
        glDepthFunc(GL_GEQUAL);
        glEnable(GL_DEPTH_TEST);
        //glEnable(GL_STENCIL_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glStencilMask(0xFF);
        glDepthMask(GL_TRUE);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        
        math::Mat4f matrix = math::Mat4f::Perspective(math::PI / 2, 1, 1, 100);
        math::Vec4f vec = matrix * math::Vec4f(0,0,1, 1);
        std::shared_ptr<render::SolidMaterial> material{ new render::SolidMaterial() };
        std::fstream shaderFile{ "resources\\shader.glsl" };
        material->shader = render::RenderShaderProgram::ParseStream_glsl(shaderFile, { 0 }, { {"test"}});

        std::shared_ptr<GameObject> cameraObj = CreateObject("Camera");
        std::shared_ptr<Camera> camera = cameraObj->AddComponent<Camera>(Camera::CameraType::Main);
        camera->scalePercent = 0.7;
        std::shared_ptr<ControlComponent> controller = cameraObj->AddComponent<ControlComponent>();
        cameraObj->transform.position = { 0,0,-5 };

        std::shared_ptr<GameObject> testObj = CreateObject("TestMesh");
        std::shared_ptr<MeshRenderer> meshRenderer = testObj->AddComponent<MeshRenderer>();
        auto boatController = testObj->AddComponent<BoatComponent>();
        meshRenderer->mesh = std::shared_ptr<render::Mesh>( new render::Mesh() );
        std::fstream meshFile{"resources\\mesh.mesh"};
        math::Mat4f meshTmpTranform = math::Mat4f::RotationY(-math::DEGTORAD * 90);
        meshRenderer->mesh->set(render::PointP3NUC::ParseStream_obj(meshFile, &meshTmpTranform));
        meshRenderer->material = material;

        std::shared_ptr<GameObject> oceanObj = CreateObject("Ocean", testObj);
        std::shared_ptr<OceanRenderer> oceanRenderer2 = oceanObj->AddComponent<OceanRenderer>();
        std::shared_ptr<OceanRenderer> oceanRenderer1 = oceanObj->AddComponent<OceanRenderer>();
        std::fstream oceanShaderFile{ "resources\\oceanShader.glsl" };
        oceanRenderer2->ocean.shader = oceanRenderer1->ocean.shader = render::RenderShaderProgram::ParseStream_glsl(oceanShaderFile, { 0 }, {});
        oceanRenderer2->ocean.scale = 256;
        oceanRenderer2->ocean.width = oceanRenderer2->ocean.height = 6;
        oceanRenderer2->ocean.vertOffset = -0.4;
        engine::Scene::Initialize();
    }
    virtual void Iterate() {
    }
    virtual void PreRender(int phase) {
        if (phase == 0) {
            glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
            //unsigned int clearColor[] = { engine::FloatToUN8(0.6f), engine::FloatToUN8(0.2f), engine::FloatToUN8(0.8f), engine::FloatToUN8(0.0f) };
            //glClearBufferuiv(GL_COLOR,0, clearColor);
            GLSTAMPERROR;
        }
        engine::Scene::PreRender(phase);
    }
    virtual void PostRender(int phase) {
        engine::Scene::PostRender(phase);
    }
    virtual void Resize(long width, long height) {
        engine::Scene::Resize(width, height);
    }
    ~InitScene() {}
}; 