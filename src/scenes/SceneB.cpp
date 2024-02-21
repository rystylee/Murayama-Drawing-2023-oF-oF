#include "SceneB.h"

//--------------------------------------------------------------
// Public
//--------------------------------------------------------------
SceneB::SceneB(const glm::vec2& resolution)
    : BaseScene(resolution)
{
}

void SceneB::init()
{
}

void SceneB::start()
{
}

void SceneB::stop()
{
}

void SceneB::update()
{
    _time = ofGetElapsedTimef();
    
}

void SceneB::renderScene(const glm::vec2& p, const float w, const float h)
{
}

void SceneB::renderGui()
{
    ImGui::Begin("SceneB Control");
    {
    }
    ImGui::End();
}

//--------------------------------------------------------------
// Private
//--------------------------------------------------------------
