#include "SceneD.h"

//--------------------------------------------------------------
// Public
//--------------------------------------------------------------
SceneD::SceneD(const glm::vec2& resolution)
    : BaseScene(resolution)
{
}

void SceneD::init()
{
}

void SceneD::start()
{
}

void SceneD::stop()
{
}

void SceneD::update()
{
    _time = ofGetElapsedTimef();
    
}

void SceneD::renderScene(const glm::vec2& p, const float w, const float h)
{
}

void SceneD::renderGui()
{
    ImGui::Begin("SceneD Control");
    {
    }
    ImGui::End();
}

//--------------------------------------------------------------
// Private
//--------------------------------------------------------------
