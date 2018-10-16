#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "ofxSoundPlayerObject.h"
#include "ofxSoundObjects.h"

#include "NoiseGenerator.h"
#include "LowPassFilter.h"
#include "DigitalDelay.h"


#include "UrbanSounds.h"

#define NUM_MSG_STRINGS 30

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//sound mixer
        ofxSoundInput  input;
        ofxSoundOutput output;
        ofSoundStream  stream;

        ofxSoundMixer mixer;
        ofxSoundMixer inputVol;

        ofTrueTypeFont font;

        //Filters
        NoiseGenerator  mNoise;
        LowPassFilter   mFilter;
        DigitalDelay    mDelayFilter;

		//GUI
		ofxPanel gui;
		ofParameterGroup parameters;

        //GUI
        ofParameterGroup 		volumeGroup;
        ofxFloatSlider   		volumeInput;
        ofxFloatSlider   		mFilterCutoff;
        ofxFloatSlider   		mDelayFeedback;
        ofxFloatSlider   		maxOut;
		ofxFloatSlider   		mDensitySlider;

		//listeners GUI
		void densityCalculator(float & val);
        void updateVolumeClass(ofAbstractParameter& p);
        void updateVolumeInput(ofAbstractParameter& p);
        void updateDelay( float & val );

		//Urban sounds
		SoundScapeRef 			mSoundScape;

		bool playSound(std::string className, float value);

		void createSoundDatabase();



};
