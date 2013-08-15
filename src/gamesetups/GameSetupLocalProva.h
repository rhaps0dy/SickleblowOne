#ifndef _GameSetupLocalProva_h_
#define _GameSetupLocalProva_h_

#include "../GameSetup.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#ifdef BUILDING_GAMESETUPLOCALPROVA
		#define GAMESETUPLOCALPROVA __declspec(dllexport)
	#else
		#define GAMESETUPLOCALPROVA __declspec(dllimport)
	#endif 
#else
	#define GAMESETUPLOCALPROVA
#endif

#define CAM_TURNRATE 0.000047938362584151635
#define CAM_SPEED 70.0

//game setup que inclou el personatge de prova i el camp de prova

class GAMESETUPLOCALPROVA GameSetupLocalProva : public GameSetup
{
private:
	Ogre::String mLevelName;
	Ogre::String mPlayerName;
	
	PPlayer *mPlayer;
	PlayerRenderer *mPlayerRenderer;
	PLevel *mLevel;
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

extern "C"
{
	GameSetup* GAMESETUPLOCALPROVA GameSetupLocalProva_maker(Ogre::Root *_root, Ogre::RenderWindow *_rw, Ogre::String _plnm, Ogre::String _lvnm);
}

#endif //_GameSetupLocalProva_h_
