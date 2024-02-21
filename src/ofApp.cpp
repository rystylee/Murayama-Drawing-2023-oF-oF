#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    //ofSetVerticalSync(false);
    
    ofxGlobalContext::Manager::defaultManager().createContext<AppContext>();
    ofxGlobalContext::Manager::defaultManager().createContext<DataContext>();

    _sceneManager.addScene<SceneA>(_resolution);
    _sceneManager.addScene<SceneB>(_resolution);
    _sceneManager.addScene<SceneC>(_resolution);
    _sceneManager.addScene<SceneD>(_resolution);
    _sceneManager.init();

    _outputFbo.allocate(_resolution.x, _resolution.y, GL_RGBA, 1);

    initGui();

    _exp.setup(_resolution.x, _resolution.y, "png", GL_RGB, 4);
    _exp.setMaxThreads(6);
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofxGlobalContext::Manager::defaultManager().update();
    _sceneManager.update();

    _exp.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    _outputFbo.begin();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _sceneManager.renderScene(glm::vec2(0, 0), _resolution.x, _resolution.y);
    _outputFbo.end();

    _exp.begin();
    _outputFbo.draw(glm::vec2(0, 0), ofGetWindowWidth(), ofGetWindowHeight());
    _exp.end();
    _exp.draw();
    
    if (_isGui) renderGui();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ' ') _isGui = !_isGui;
    if (key == '1') _sceneManager.changeScene(0);
    if (key == '2') _sceneManager.changeScene(1);
    if (key == '3') _sceneManager.changeScene(2);
    if (key == '4') _sceneManager.changeScene(3);
}

//--------------------------------------------------------------
// Private
//--------------------------------------------------------------
void ofApp::initGui()
{
    _gui.setup();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigDockingWithShift = true;
}

//--------------------------------------------------------------
void ofApp::renderGui()
{
    _gui.begin();
    {
        $Context(AppContext)->renderGui();

        ImGui::Begin("Recoring");
        {
            if (ImGui::Button("Start Recording"))
            {
                if(!_exp.isExporting())
                {
                    _exp.setExportDir("export");
                    _exp.startExport(); //this will overwrite - careful!
                }
            }
            if (ImGui::Button("End Recording"))
            {
                if(_exp.isExporting())
                {
                    _exp.stopExport();
                }
            }
        }
        ImGui::End();

        _sceneManager.renderGui();
    }
    _gui.end();
}
