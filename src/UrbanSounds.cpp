#include "UrbanSounds.h"

UrbanSound::UrbanSound(std::string name, ofDirectory dir) {

  mName = name;
  mSoundDir = dir;

  mParameters.setName(name);
  mParameters.add(mVolumen.set("volumen", 0.3, 1.0, 0.0));
  mParameters.add(mActive.set("activate"));

  mVolumen = 0.0;

  // load sounds
}

void UrbanSound::addtoMixer(ofxSoundMixer &mixer) {
  if (mSoundDir.size() > 0) {
    for (int i = 0; i < mSoundDir.size(); i++) {
      mPlayer.load(mSoundDir.getPath(i));
      mPlayer.setLoop(true);
      mPlayer.connectTo(mixer);
      mPlayer.play();
    }
  }
}

//----------------------------------------------------------------
UrbanSoundClass::UrbanSoundClass(std::string name) {

  mClassName = name;

  mParameters.setName(name);
  mParameters.add(mVolumen.set("volumen", 0.3, 1.0, 0.0));
  mParameters.add(mActive.set("activate"));
}

void UrbanSoundClass::addSound(UrbanSoundRef &urbansound) {
  mUrbanClass.push_back(urbansound);
}

void UrbanSoundClass::updateVolumen() {}

//----------------------------------------------------------------

SoundScape::SoundScape() {
  mParameters.setName("Master");
  mParameters.add(mVolumen.set("volumen", 0.0, 1.0, 0.0));
  mParameters.add(mActive.set("activate"));
}

void SoundScape::addClass(UrbanSoundClassRef &urbanClass) {
  mUrbanSounds.push_back(urbanClass);
}

void SoundScape::setVolumen(float master) {}
