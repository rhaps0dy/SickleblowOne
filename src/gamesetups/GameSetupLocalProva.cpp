#include "GameSetupLocalProva.h"

GameSetupLocalProva::GameSetupLocalProva(Ogre::Root *root, Ogre::RenderWindow *rw, Ogre::String plnm, Ogre::String lvnm)
: mLevelName(lvnm), mPlayerName(plnm), GameSetup(root, rw)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("Inicialitzant GameSetupLocalProva");
	mRoot->startRendering();
}

GameSetupLocalProva::~GameSetupLocalProva(void)
{
	delete mInterface;
	delete mPlayer;
	delete mLevel;
	GameSetup::destroyAll();
	ClassLoader::unloadKeyboardInterface();
}

void GameSetupLocalProva::createScene(void)
{
	GameSetup::createScene();
	mLevel = new Level();
	mInterface = ClassLoader::makeKeyboardInterface(mKeyboard);
	
	if(mPlayerName == "Sinbad")
	{
		mPlayer = new Player(mInterface);
	}
	 
	mLevel->registerPlayer(mPlayer);
}

bool GameSetupLocalProva::frameRenderingQueued(const Ogre::FrameEvent &evt)
{
	mContinue = GameSetup::frameRenderingQueued(evt);
	mLevel->update(evt.timeSinceLastFrame);
	return mContinue;
}

extern "C"
{
	GameSetup* GameSetupLocalProva_maker(Ogre::Root *_root, Ogre::RenderWindow *_rw, Ogre::String _plnm, Ogre::String _lvnm)
	{
		return new GameSetupLocalProva(_root, _rw, _plnm, _lvnm);
	}
}
