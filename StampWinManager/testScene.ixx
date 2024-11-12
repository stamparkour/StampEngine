export module testScene;

import "glm.h";
import render;
import swm;
import math;

export class InitScene : public swm::SceneBase {
    virtual void Start(double time) {
        glClearColor(0.6f, 0.2f, 0.8f, 1.0f);
        glClearStencil(0);
        glClearDepth(1);
        glDepthFunc(GL_LEQUAL);
        //glEnable(GL_STENCIL_TEST);
        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    virtual void End(double time) {}
    virtual void Update(double time) {}
    virtual void SyncUpdate(double time) {}
    virtual void Render(double time) {}
    virtual void Resize(double time, long width, long height) {}
};