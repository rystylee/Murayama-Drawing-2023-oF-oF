#pragma once

#include "ofMain.h"

class BaseScene
{
public:
    BaseScene(const glm::vec2& resolution)
        : _resolution(resolution)
    {}

    virtual ~BaseScene() {};
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void update() = 0;
    virtual void renderScene(const glm::vec2& p, const float w, const float h) = 0;
    virtual void renderGui() = 0;

protected:
    glm::vec2 _resolution;
    float _time { 0.0f };

};
