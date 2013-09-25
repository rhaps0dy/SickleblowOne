#include "GameSetupLocalProva.h"

GameSetupLocalProva::GameSetupLocalProva(Ogre::Root *root, Ogre::RenderWindow *rw, Ogre::String plnm, Ogre::String lvnm)
: GameSetup(root, rw), mLevelName(lvnm), mPlayerName(plnm) 
{
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Inicialitzant GameSetupLocalProva");
	#endif
	loadResources();
	createScene();
	mRoot->startRendering();
}

GameSetupLocalProva::~GameSetupLocalProva(void)
{
	delete mPlayer;
	mLevel->unregisterPlayer(mPlayer);
	delete mLevel;
	delete mLevelRenderer;
	delete mPlayerRenderer;
	delete mCameraMan;
	//GameSetup::destroyAll();
	ClassLoader::unloadKeyboardInterface();
}

void GameSetupLocalProva::createScene(void)
{
	GameSetup::createScene();
	
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
    	light->setPosition(20.0f, 80.0f, 50.0f);
	
	mLevel = new PLevel();
	mInterface = ClassLoader::makeKeyboardInterface(mKeyboard);
	
	if(mPlayerName == "pl_Boxejador")
	{
		mPlayer = new PPlayer(mInterface);
	}
	 
	mLevel->registerPlayer(mPlayer);
	
	//renderers
	mLevelRenderer = new LevelRenderer(mLevel, mRoot, mCamera, mSceneMgr);
	mPlayerRenderer = new PlayerRenderer(mPlayer, mSceneMgr, mLevelRenderer->getTerra());
	mCameraMan = new CameraMan(mPlayerRenderer->getPlayerNode(), mCameraNode);
}

void GameSetupLocalProva::loadResources(void)
{
	GameSetup::loadResources();
	Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("Grup_prova");
}

bool GameSetupLocalProva::frameRenderingQueued(const Ogre::FrameEvent &evt)
{
	mContinue = GameSetup::frameRenderingQueued(evt);
	mPlayer->update(evt.timeSinceLastFrame);
	mPlayerRenderer->update(evt.timeSinceLastFrame);
	mLevel->update(evt.timeSinceLastFrame);
	mLevelRenderer->update();
	mCameraMan->update();

	return mContinue;
} 

GameSetup* GameSetupLocalProva_maker(Ogre::Root *_root, Ogre::RenderWindow *_rw, Ogre::String _plnm, Ogre::String _lvnm)
{
	return new GameSetupLocalProva(_root, _rw, _plnm, _lvnm);
}
