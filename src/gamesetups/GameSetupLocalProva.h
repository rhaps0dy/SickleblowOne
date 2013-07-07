#ifndef _GameSetupLocalProva_h_
#define _GameSetupLocalProva_h_

#include "../GameSetup.h"

#define CAM_TURNRATE 0.000047938362584151635
#define CAM_SPEED 70.0

//game setup que inclou el personatge de prova i el camp de prova

class GameSetupLocalProva : public GameSetup
{
private:
	Ogre::String mLevelName;
	Ogre::String mPlayerName;
	
	Player *mPlayer;
	PlayerRenderer *mPlayerRenderer;
	Level *mLevel;
	LevelRenderer *mLevelRenderer;
	Interface *mInterface;
	CameraMan *mCameraMan;
	
	void createScene(void);
	void loadResources(void);
	bool frameRenderingQueued(const Ogre::FrameEvent &evt);
	
public:
	GameSetupLocalProva(Ogre::Root *root, Ogre::RenderWindow *rw, Ogre::String plnm, Ogre::String lvnm);
	~GameSetupLocalProva(void);
};

#endif //_GameSetupLocalProva_h_
