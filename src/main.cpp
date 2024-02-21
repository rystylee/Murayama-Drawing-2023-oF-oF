#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
    ofGLWindowSettings s;
    s.setGLVersion(4, 5);
    s.setSize(1080, 1920);
    ofCreateWindow(s);

    ofRunApp(new ofApp());
}