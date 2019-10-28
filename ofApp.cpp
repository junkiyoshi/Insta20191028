#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofEnableDepthTest();

	this->mesh.addVertex(glm::vec3(0, 50, 0));
	this->mesh.addVertex(glm::vec3(-50, 0, 0));
	this->mesh.addVertex(glm::vec3(0, 0, -50));
	this->mesh.addVertex(glm::vec3(50, 0, 0));
	this->mesh.addVertex(glm::vec3(0, 0, 50));
	this->mesh.addVertex(glm::vec3(0, -50, 0));
	
	this->mesh.addIndex(0);
	this->mesh.addIndex(1);
	this->mesh.addIndex(2);

	this->mesh.addIndex(0);
	this->mesh.addIndex(2);
	this->mesh.addIndex(3);

	this->mesh.addIndex(0);
	this->mesh.addIndex(3);
	this->mesh.addIndex(4);

	this->mesh.addIndex(0);
	this->mesh.addIndex(4);
	this->mesh.addIndex(1);

	this->mesh.addIndex(5);
	this->mesh.addIndex(1);
	this->mesh.addIndex(2);

	this->mesh.addIndex(5);
	this->mesh.addIndex(2);
	this->mesh.addIndex(3);

	this->mesh.addIndex(5);
	this->mesh.addIndex(3);
	this->mesh.addIndex(4);

	this->mesh.addIndex(5);
	this->mesh.addIndex(4);
	this->mesh.addIndex(1);
}

//--------------------------------------------------------------
void ofApp::update() {
	
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofColor color_0, color_1, color_2;
	for (auto x = ofGetWidth() * -0.5; x <= ofGetWidth() * 0.5; x += 120) {

		for (auto y = ofGetHeight() * -0.5; y <= ofGetHeight() * 0.5; y += 120) {

			auto hue = ofMap(y, ofGetHeight() * 0.5, ofGetHeight() * -0.5, 0, 240);
			color_0.setHsb(255, 0, 255);
			color_1.setHsb(hue, 255, 128);
			color_2.setHsb(hue, 255, 230);

			this->mesh.clearColors();
			this->mesh.addColor(color_1);
			for (int i = 0; i < 4; i++) {
			
				this->mesh.addColor(color_2);
			}
			this->mesh.addColor(color_1);

			ofPushMatrix();
			ofTranslate(x, y);
			ofRotateY(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, 0, 360));
			ofRotateX(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, 0, 360));

			this->mesh.drawFaces();
			
			this->mesh.clearColors();
			for (int i = 0; i < 6; i++) {
			
				this->mesh.addColor(color_0);
			}
			this->mesh.drawWireframe();


			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}