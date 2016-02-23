#include "ofApp.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundColor(ofColor::black);
    videoPath = ofToDataPath("../../../videoTestFile/video1.mp4", true);
    ofLogWarning("setup") << videoPath;
    moduleManager.acceptProviderType<PlayerModuleProvider>();
    moduleManager.addProvider(new GstreamerModuleProvider());
    //load included Modules
    //moduleManager.load("bin/data/.modules/Core/MyModule");
    moduleManager.getProviders(modulesProvider);
    std::vector<PlayerModuleProvider *>::iterator it;
    ofLogWarning("setup()") << "setting up myModule";
    for (it = modulesProvider.begin(); it != modulesProvider.end(); it++)
    {
        myModule = (*it)->create();
    }
    if(myModule != nullptr)
    {
        ofLogWarning("setup()") << "myModule setUp ok";
    }
    else
    {
        ofLogError("setup()") << "myModule setUp failed";
    }
    myModule->setPath(this->videoPath);
    myModule->setup();
    ofSetWindowShape(1280, 720);
    myModule->play();
    this->frameCounter = 0;
}

//--------------------------------------------------------------
void ofApp::update()
{
    //ofLogWarning("update()") << "myModule::update()";
    myModule->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    myModule->draw();
    ofSetColor(ofColor::white);
    ofDrawBitmapString(myModule->getPostion(), 10, 120);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch(key)
    {
    case ' ':
        myModule->togglePlay();
        break;
    case 'p':
        myModule->play();
        break;
    case 's':
        myModule->stop();
        break;
    case 'q':
        ofExit(0);
        break;
    case 'f':
        ofToggleFullscreen();
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{}
