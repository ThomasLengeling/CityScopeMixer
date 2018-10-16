#include "ofApp.h"

//-----------------------------------------------------------------------------------
void ofApp::setup() {

  // ofSetLogLevel(OF_LOG_VERBOSE);

  // Audio stream
  std::cout<<"loading audio"<<std::endl;
  stream.setup(2, 0, 44100, 256, 4); // 256

  // GUI
  std::cout<<"loading gui"<<std::endl;
  gui.setup();

  std::cout<<"loading sounds"<<std::endl;
  createSoundDatabase();

  std::cout<<"loading mixer"<<std::endl;
  stream.setOutput(mixer);
  gui.add(mDensitySlider.setup("density", 0.0, 1.0, 0.0));
  mDensitySlider.addListener(this, &ofApp::densityCalculator);

  // fill with sounds that have to do with humans

  // get HTTP
  // paseJSONFromHTTP();
  //
  std::cout << "num channels: " << mixer.getNumChannels() << std::endl;
}

void ofApp::createSoundDatabase() {
  // load sounds to the  ScapeScape class
  mSoundScape = SoundScape::create();

  // Humans
  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("Voice");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("movement");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("Nature");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("construction");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans =
        UrbanSoundClass::create("non-motorized transport");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("social signals");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("private transport");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("public transport");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("emergency transport");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("air transport");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout << dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }

  {
    UrbanSoundClassRef mTrans = UrbanSoundClass::create("music");
    // fill mTrans with sounds that are relative to transportation

    std::string path = "Sounds/";
    std::string sounds[] = {"Car", "Taxi", "Subway"};
    int soundLen = sizeof(sounds) / sizeof(sounds[0]);

    for (int i = 0; i < soundLen; i++) {
      ofDirectory dir;
      dir.allowExt("mp3");
      dir.allowExt("wav");
      std::string dirloc = path + sounds[i];
      std::cout << dirloc << std::endl;
      dir.listDir(dirloc);
      std::cout << dir.getAbsolutePath() << std::endl;

      for (int j = 0; j < dir.size(); j++) {
        std::cout <<"path:"<< dir.getPath(j) << std::endl;

        UrbanSoundRef uSound = UrbanSound::create(sounds[i], dir);

        uSound->addtoMixer(mixer);
        mTrans->addSound(uSound);

        mTrans->addParameter(uSound->getParameter());
      }

      // playersDirectory.push_back(dir);
    }

    ofAddListener(mTrans->getParameter().parameterChangedE(), this,
                  &ofApp::updateVolumeClass);

    gui.add(mTrans->getParameter());
    mSoundScape->addClass(mTrans);
    gui.getGroup(mTrans->getName()).minimize();
  }
}

void ofApp::densityCalculator(float &val) {

  if (val > 0 && val < 0.2) {
  }
}

//--------------------------------------------------------------
void ofApp::updateVolumeClass(ofAbstractParameter &p) {

  for (auto const &urit : mSoundScape->getVector()) {
    int i = 0;
    for (auto const &cit : urit->getVector()) {
      mixer.setChannelVolume(i, cit->getParamVolumen());
      i++;
    }
  }
}

void ofApp::updateVolumeInput(ofAbstractParameter &p) {}

void ofApp::updateDelay(float &val) {
  mDelayFilter.setFeedback(val);
  std::cout << "change dealy" << std::endl;
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(0);

  gui.draw();
}


bool ofApp::playSound(std::string className, float changeVolumen) {
  return true;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
