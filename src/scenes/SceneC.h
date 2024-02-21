#pragma once

#include "ofMain.h"
#include "BaseScene.h"

#include "ofxImGui.h"


class SceneC : public BaseScene
{
public:
    SceneC(const glm::vec2& resolution);
    void init() override;
    void start() override;
    void stop() override;
    void update() override;
    void renderScene(const glm::vec2& p, const float w, const float h) override;
    void renderGui() override;

private:

};
