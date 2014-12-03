#include "ofApp.h"
#include "Particle.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    //p.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, ofRandom(-10, 10), ofRandom(-10, 10));
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].resetForce();
        particles[i].addForce(0, 0.1);
        particles[i].addDampingForce();
        particles[i].update();
        
        //画面外に出た際に消去する
//        if (particles[i].outWindow())
//            particles.erase(particles.begin() + i);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//
//    ofDrawBitmapStringHighlight("Everything works!", 20, 20);
//    
//    ofSetColor(0, 0, 0);
//    ofLine(10, 20, 30, 40); //始点x,始点y,終点x,終点y
//    
//    ofCircle(30, 30, 10);
//    
//    ofRect(50, 50, 20, 20);
//    
//    ofTriangle(50, 70, 50, 100, 70, 80);

    ofSetColor(255, 255, 255);
    
    //画面左上にメッセージを表示
    string message = "current particle num = " + ofToString(particles.size(),0);
    ofDrawBitmapString(message, 20, 20);

    ofNoFill();
    ofBeginShape();
    for (int i = 0; i < particles.size(); i++) {
        //p[i].draw();
        particles[i].draw();
        ofCurveVertex(particles[i].pos.x, particles[i].pos.y);
    }
    ofEndShape();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        particles.clear();
    }
    
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Particle newParticle;
    float vx = ofRandom(-3, 3);
    float vy = ofRandom(-3, 3);
    newParticle.setInitialCondition(x, y, vx, vy);
    particles.push_back(newParticle);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < NUM; i++) {
        //p[i].setInitialCondition(x, y, ofRandom(-10, 10), ofRandom(-10, 10));
        Particle newParticle;
        
        float vx = ofRandom(-10, 10);
        float vy = ofRandom(-10, 10);
        newParticle.setInitialCondition(x, y, vx, vy);
        particles.push_back(newParticle);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
