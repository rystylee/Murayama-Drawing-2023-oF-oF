#pragma once

#include "ofMain.h"
#include "BaseScene.h"

#include "../contexts/AppContext.h"
#include "../contexts/DataContext.h"
#include "../utils/Quad.h"
#include "../utils/ValueMotion.h"

#include "ofxImGui.h"
#include "ofxShaderOnTheFly.h"

class SceneA : public BaseScene
{
public:
    SceneA(const glm::vec2& resolution);
    void init() override;
    void start() override;
    void stop() override;
    void update() override;
    void renderScene(const glm::vec2& p, const float w, const float h) override;
    void renderGui() override;

private:
    void updatePhaseAlphas();
    void updateIndex();
    void animateAlpha(const int phase);
    const int getPhase(const int index);

    std::map<std::string, ValueMotion<float>> _phaseAlphas;

    Quad _quad;
    ofxShaderOnTheFly _shader;

    int _updateIndexSpeed { 12 };
    int _currentIndex { 0 };
};
