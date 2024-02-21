#pragma once

#include "ofMain.h"
#include "ofxGlobalContext.h"
#include "ofxImGui.h"

class AppContext final : public ofxGlobalContext::Context
{
public:
    AppContext()
    {
        _elapsedTimef = ofGetElapsedTimef();
        _frameRate = ofGetFrameRate();
        _lastFrameTime = ofGetLastFrameTime();
        _frameNum = ofGetFrameNum();
    }

    void update() override
    {
        _elapsedTimef = ofGetElapsedTimef();
        _frameRate = ofGetFrameRate();
        _lastFrameTime = ofGetLastFrameTime();
        _frameNum = ofGetFrameNum();
    }

    void renderGui()
    {
        ImGui::Begin("App Context");
        {
            float fps = getFrameRate();
            ImGui::Text("FPS : %.2f", fps);
        }
        ImGui::End();
    }

    const float getElapsedTimef() const { return _elapsedTimef; }
    const float getFrameRate() const { return _frameRate; }
    const int getFrameNum() const { return _frameNum; }
    const float getLastFrameTime() const { return _lastFrameTime; }

private:
    float _elapsedTimef { 0.0f };
    float _frameRate { 0.0f };
    float _lastFrameTime { 0.0f };
    int _frameNum { 0 };
};
