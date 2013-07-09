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
	delete mLevel;
	delete mLevelRenderer;
	delete mPlayerRenderer;
	GameSetup::destroyAll();
	ClassLoader::unloadKeyboardInterface();
}

void GameSetupLocalProva::createScene(void)
{
	GameSetup::createScene();
	
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
    	light->setPosition(20.0f, 80.0f, 50.0f);
	
	mLevel = new Level();
	mInterface = ClassLoader::makeKeyboardInterface(mKeyboard);
	
	if(mPlayerName == "pl_Boxejador")
	{
		mPlayer = new Player(mInterface);
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
	mLevel->update(evt.timeSinceLastFrame);
	mLevelRenderer->update();
	mPlayer->update(evt.timeSinceLastFrame);
	mPlayerRenderer->update(evt.timeSinceLastFrame);
	mCameraMan->update();

	/*mCameraNode->yaw(Ogre::Radian(mInterface->getJoyX()*CAM_TURNRATE*evt.timeSinceLastFrame));
	mCameraNode->pitch(Ogre::Radian(mInterface->getJoyY()*CAM_TURNRATE*evt.timeSinceLastFrame)); 
	char estat = mInterface->getActualCtlStatus();
	Ogre::Real moviment = evt.timeSinceLastFrame * CAM_SPEED;
	if(estat & Interface::SALT)
		mCameraNode->translate(0.0, 0.0, -CAM_SPEED*evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);	
	if(estat & Interface::SHLD)
		mCameraNode->translate(0.0, 0.0, CAM_SPEED*evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);	
	if(estat & Interface::AATK)
		mCameraNode->translate(-CAM_SPEED*evt.timeSinceLastFrame, 0.0, 0.0, Ogre::Node::TS_LOCAL);	
	if(estat & Interface::SATK)
		mCameraNode->translate(CAM_SPEED*evt.timeSinceLastFrame, 0.0, 0.0, Ogre::Node::TS_LOCAL);	
	Ogre::Quaternion quat = mCameraNode->getOrientation();
	Ogre::Vector3 posicio = mCameraNode->getPosition();
	std::cerr << "rx: " <<  quat.x << " ry: " <<  quat.x << " rz: " <<  quat.x << " rw: " <<  quat.x << std::endl;
	std::cerr << "x: " <<  posicio.x << " y: " <<  posicio.y << " z: " <<  posicio.z << std::endl << std::endl;*/

	return mContinue;
} 

GameSetup* GameSetupLocalProva_maker(Ogre::Root *_root, Ogre::RenderWindow *_rw, Ogre::String _plnm, Ogre::String _lvnm)
{
	return new GameSetupLocalProva(_root, _rw, _plnm, _lvnm);
}
