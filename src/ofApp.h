#pragma once

#include "ofMain.h"
#include "ofxGlobalContext.h"
#include "ofxImGui.h"

#include "contexts/AppContext.h"
#include "contexts/DataContext.h"

#include "SceneManager.h"
#include "scenes/SceneA.h"
#include "scenes/SceneB.h"
#include "scenes/SceneC.h"
#include "scenes/SceneD.h"

#include "ofxImageSequenceExport.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofFbo _outputFbo;

private:
    void initGui();
    void renderGui();

    glm::vec2 _resolution { 1080.0f, 1920.0f };

    SceneManager _sceneManager;

    ofxImGui::Gui _gui;
    bool _isGui { true };

    ofxImageSequenceExport _exp;

};
