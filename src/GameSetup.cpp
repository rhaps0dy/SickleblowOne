#include "GameSetup.h"

GameSetup::GameSetup(Ogre::Root *root, Ogre::RenderWindow *rw) :
mRoot(root), mWindow(rw), mCamera(0), mSceneMgr(0),
mInputManager(0), mJoystick(0), mMouse(0), mKeyboard(0),
mContinue(true)
{	
	//Creem un octree scene manager
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
    mCamera = mSceneMgr->createCamera("GeneralCamera");
    
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
	
	mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
	
	mCamera->setProjectionType(Ogre::PT_PERSPECTIVE);
	mCamera->setFOVy(Ogre::Degree(40.));
	
	loadResources();
	createScene();
	
	Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
	
	mRoot->addFrameListener(this);
	mRoot->startRendering();
}
GameSetup::~GameSetup(void)
{
	Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
}


void GameSetup::destroyEverything(void)
{
	
	if(mCamera)
	{
		mSceneMgr->destroyCamera(mCamera);
		mCamera = 0;
	}
	
	mWindow->removeAllViewports();
	
	if(mSceneMgr)
	{
		mRoot->destroySceneManager(mSceneMgr);
		mSceneMgr = 0;
	}
	/*if( mInputManager )
	{
		mInputManager->destroyInputObject(mMouse);
		mInputManager->destroyInputObject(mKeyboard);
		if(mJoystick) mInputManager->destroyInputObject(mJoystick);
		OIS::InputManager::destroyInputSystem(mInputManager);
		mInputManager = 0;
	
	}*/
	mContinue = false;	
}

void GameSetup::createScene(void)
{
	std::cerr << "creant escena\n";
}

void GameSetup::loadResources(void)
{
	std::cerr << "Carregant recursos";
}

bool GameSetup::frameRenderingQueued(const Ogre::FrameEvent &evt)
{
	return mContinue;
}
bool GameSetup::windowClosing(Ogre::RenderWindow *rw)
{
	if(rw==mWindow)
	{
		destroyEverything();
		return true;
	}
	return false;
}
