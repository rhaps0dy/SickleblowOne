#ifndef _GameSetupLocalProva_h_
#define _GameSetupLocalProva_h_

#include "../GameSetup.h"

class GameSetupLocalProva : public GameSetup
{
private:
	Ogre::String mLevelName;
	Ogre::String mPlayerName;
	
	Player *mPlayer;
	Level *mLevel;
	Interface *mInterface;
	
	void createScene(void);
	bool frameRenderingQueued(const Ogre::FrameEvent &evt);
	
public:
	GameSetupLocalProva(Ogre::Root *root, Ogre::RenderWindow *rw, Ogre::String plnm, Ogre::String lvnm);
	~GameSetupLocalProva(void);
};

#endif //_GameSetupLocalProva_h_
