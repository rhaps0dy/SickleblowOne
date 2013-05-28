#include "GameSetupLocalProva.h"

GameSetupLocalProva::GameSetupLocalProva(Ogre::Root *root, Ogre::RenderWindow *rw, Ogre::String plnm, Ogre::String lvnm)
: mLevelName(lvnm), mPlayerName(plnm), GameSetup(root, rw)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("Inicialitzant GameSetupLocalProva");
	mRoot->startRendering();
}

void GameSetupLocalProva::createScene(void)
{
	mLevel = new Level();
	 if(mPlayerName == "pl_Sinbad")
	 {
		 mPlayer = new Player(mLevel, );
	 }
}

extern "C"
{
	GameSetup* GameSetupLocalProva_maker(Ogre::Root *_root, Ogre::RenderWindow *_rw, Ogre::String _plnm, Ogre::String _lvnm)
	{
		return new GameSetupLocalProva(_root, _rw, _plnm, _lvnm);
	}
}
