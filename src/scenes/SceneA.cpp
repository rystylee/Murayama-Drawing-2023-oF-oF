#include "SceneA.h"

//--------------------------------------------------------------
// Public
//--------------------------------------------------------------
SceneA::SceneA(const glm::vec2& resolution)
    : BaseScene(resolution)
{
    _shader.load("shaders/shader.vert", "shaders/shader.frag");
}

void SceneA::init()
{
}

void SceneA::start()
{
}

void SceneA::stop()
{
}

void SceneA::update()
{
    _time = ofGetElapsedTimef();

    //updatePhaseAlphas();
    updateIndex();
}

void SceneA::renderScene(const glm::vec2& p, const float w, const float h)
{
    const auto& images = $Context(DataContext)->getImages();

    const int numW = 24; // 1080 / 24 = 45
    const int numH = 25; // 1920 / 25 = 76.8

    float width = _resolution.x / static_cast<float>(numW);
    float height = _resolution.y / static_cast<float>(numH);

    _shader.begin();
    _shader.setUniform1i("_IsBorder", 1);
    for (int y = 0; y < numH; y++)
    {
        for (int x = 0; x < numW; x++)
        {
            int idx = y * numW + x;

            int phase = getPhase(idx);
            //float alpha = _phaseAlphas[phase - 1].getValue();
            //cout << "phase: " << phase << ", " << "alpha: " << alpha << endl;
            float alpha = (idx == _currentIndex) ? 1.0 : 0.2;

            _shader.setUniformTexture("_Texture", images[idx].getTexture(), 0);
            _shader.setUniform1f("_Alpha", alpha);
            _quad.render(glm::vec2(x * width, y * height), width, height);
        }
    }

    _shader.setUniformTexture("_Texture", images[_currentIndex].getTexture(), 0);
    _shader.setUniform1f("_Alpha", 1.0);
    _shader.setUniform1i("_IsBorder", 0);
    _quad.renderCenter(glm::vec2(540, 960), width * 14, height * 13);

    _shader.end();

}

void SceneA::renderGui()
{
    ImGui::Begin("SceneA Control");
    {
        ImGui::SliderInt("Update Index Speed", &_updateIndexSpeed, 1, 20);
        ImGui::SliderInt("Current Index", &_currentIndex, 0, 600);
    }
    ImGui::End();
}

//--------------------------------------------------------------
// Private
//--------------------------------------------------------------
//void SceneA::updatePhaseAlphas()
//{
//    for (int i = 0; i < _phaseAlphas.size(); i++)
//    {
//        _phaseAlphas[i].update();
//        //cout << "_phaseAlpha index: " << ofToString(i) << ", " << _phaseAlphas[i].getValue() << endl;
//    }
//}

void SceneA::updateIndex()
{
    if (($Context(AppContext)->getFrameNum() + 1) % _updateIndexSpeed == 0)
    {
        _currentIndex++;
    }

    if (_currentIndex > 600) _currentIndex = 0;
}

void SceneA::animateAlpha(const int phase)
{

}

const int SceneA::getPhase(const int index)
{
    const auto& phaseIndices = $Context(DataContext)->getPhaseIndices();

    int phase = 0;
    for (int i = 0; i < phaseIndices.size(); i++)
    {
        bool isFound = std::find(phaseIndices[i].cbegin(), phaseIndices[i].cend(), index + 1) != phaseIndices[i].cend();

        if (isFound)
        {
            phase = i + 1;
            break;
        }
    }
    assert(phase != 0);

    return phase;
}
