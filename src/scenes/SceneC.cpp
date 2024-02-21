#include "SceneC.h"

//--------------------------------------------------------------
// Public
//--------------------------------------------------------------
SceneC::SceneC(const glm::vec2& resolution)
    : BaseScene(resolution)
{
}

void SceneC::init()
{
}

void SceneC::start()
{
}

void SceneC::stop()
{
}

void SceneC::update()
{
    _time = ofGetElapsedTimef();
    
}

void SceneC::renderScene(const glm::vec2& p, const float w, const float h)
{
}

void SceneC::renderGui()
{
    ImGui::Begin("SceneC Control");
    {
    }
    ImGui::End();
}

//--------------------------------------------------------------
// Private
//--------------------------------------------------------------
