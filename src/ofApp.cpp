#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //setup UI elements
    gui.setup();

    //setup each gui element: args = name, default, min, max
    gui.add(wavelength.setup( "wavelength", 0.125, 0.05, 0.2 ));
    gui.add(amplitude.setup( "amplitude", 0, 0, 50 ));
    gui.add(noiseScale.setup( "noiseScale", 0, 0, 10 ));
    gui.add(distortion.setup( "distortion", 0, 0, 50 ));
    gui.add(ySpeed.setup( "ySpeed", 0, 0, 10 ));

    image1.load("data/chip.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    image2 = wave(image1);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::gray);

    ofSetColor(255, 255, 255);
    image2.draw(0, 0);

    gui.draw();
}

//--------------------------------------------------------------
ofImage ofApp::wave(ofImage sourceImage){
    ofImage newImg;
    newImg.clone(sourceImage);

    float time = ofGetElapsedTimef();

    for (int x=0; x<image1.getHeight(); x++){
        for (int y=0; y<image1.getWidth(); y++){
            float noise = ofNoise(time + y * 0.001) * noiseScale;
            float noiseAmp = noise * amplitude;
            float waveform = sin((y * wavelength) + time * ySpeed);
            float wave = (waveform + distortion) * noiseAmp;

            int xWave = x + wave;

            ofColor color = sourceImage.getColor(xWave, y);
            newImg.setColor(x, y, color);
        }
    }

    newImg.update();
    return newImg;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

