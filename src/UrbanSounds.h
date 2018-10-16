#pragma once

#include "ofMain.h"
#include "ofParameter.h"
#include "ofParameterGroup.h"

#include "ofxSoundPlayerObject.h"
#include "ofxSoundObjects.h"

#include "DigitalDelay.h"
#include "LowPassFilter.h"
#include "NoiseGenerator.h"

// class

class UrbanSound;
typedef std::shared_ptr<UrbanSound> UrbanSoundRef;

class UrbanSoundClass;
typedef std::shared_ptr<UrbanSoundClass> UrbanSoundClassRef;

class SoundScape;
typedef std::shared_ptr<SoundScape> SoundScapeRef;

//-----------------------------------------------------------------------
class UrbanSound {

public:
  UrbanSound(std::string name, ofDirectory dir);

  static UrbanSoundRef create(std::string name, ofDirectory dir) {
    return std::make_shared<UrbanSound>(name, dir);
  }

  ofParameterGroup &getParameter() { return mParameters; }

  std::string getName() { return mName; }

  void addtoMixer(ofxSoundMixer &mixer);

  ofParameter<float> &getParamVolumen() { return mVolumen; }

private:
  ofxSoundPlayerObject mPlayer;

  std::string mName;
  ofDirectory mSoundDir;

  ofParameterGroup mParameters;
  ofParameter<float> mVolumen;
  ofParameter<bool> mActive;
};

//---------------------------------------------------------------------
class UrbanSoundClass {
public:
  UrbanSoundClass(std::string name);

  static UrbanSoundClassRef create(std::string name) {
    return std::make_shared<UrbanSoundClass>(name);
  }

  void addSound(UrbanSoundRef &urbansound);
  void addParameter(ofParameterGroup param) { mParameters.add(param); }
  ofParameterGroup &getParameter() { return mParameters; }

  std::string getName() { return mClassName; }

  UrbanSoundRef getUrbanSounds(int index) { return mUrbanClass.at(index); }

  std::vector<UrbanSoundRef> getVector() { return mUrbanClass; }

  void updateVolumen();

private:
  std::vector<UrbanSoundRef> mUrbanClass;
  ofColor mColorClass;
  std::string mClassName;

  ofParameterGroup mParameters;
  ofParameter<float> mVolumen;
  ofParameter<bool> mActive;
};

//----------------------------------------------------------------------
class SoundScape {

public:
  SoundScape();

  static SoundScapeRef create() { return std::make_shared<SoundScape>(); }

  void addClass(UrbanSoundClassRef &urbanClass);

  void setVolumen(float master);

  std::vector<UrbanSoundClassRef> getVector() { return mUrbanSounds; }

private:
  std::vector<UrbanSoundClassRef> mUrbanSounds;

  ofParameterGroup mParameters;
  ofParameter<float> mVolumen;
  ofParameter<bool> mActive;
};
