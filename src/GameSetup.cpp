#include "GameSetup.h"

GameSetup::GameSetup(Ogre::Root *root, Ogre::RenderWindow *rw) :
mRoot(root), mWindow(rw), mCamera(0), mSceneMgr(0),
mInputManager(0), mJoystick(0), mMouse(0), mKeyboard(0),
mContinue(true)
{	
	Ogre::LogManager::getSingletonPtr()->logMessage("Inicialitzant GameSetup");
	
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
	
	//inicialitzem OIS en aquesta finestra
	Ogre::LogManager::getSingletonPtr()->logMessage("Inicialitzant OIS...");
    size_t windowHnd;
    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    
    mInputManager = OIS::InputManager::createInputSystem( windowHnd );

    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));
    
    try
    {
		mJoystick = static_cast<OIS::JoyStick*>(mInputManager->createInputObject(OIS::OISJoyStick, false));
	}catch(OIS::Exception &e)
	{
		#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.eText, "No joystick found.", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		#else
            std::cerr << "No joystick found.\n" << e.eText << std::endl;
		#endif
	}

    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);
}
void GameSetup::destroyAll(void)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("Destruint GameSetup");
	Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
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
	if( mInputManager )
	{
		mInputManager->destroyInputObject(mMouse);
		mInputManager->destroyInputObject(mKeyboard);
		if(mJoystick) mInputManager->destroyInputObject(mJoystick);
		OIS::InputManager::destroyInputSystem(mInputManager);
		mInputManager = 0;
	
	}
}

void GameSetup::createScene(void)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("Creant escena\n");
}

void GameSetup::loadResources(void)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("Carregant recursos\n");
}

bool GameSetup::frameRenderingQueued(const Ogre::FrameEvent &evt)
{
	mMouse->capture();
	mKeyboard->capture();
	return mContinue;
}

bool GameSetup::windowClosing(Ogre::RenderWindow *rw)
{
	if(rw==mWindow)
	{
		mContinue = false;
		return true;
	}
	return false;
}


//Events per a CEGUI. TODO: fer que cridin events de CEGUI
bool GameSetup::keyPressed(const OIS::KeyEvent &arg)
{
	if(arg.key==OIS::KC_ESCAPE) mContinue = false;
	return true;
}
bool GameSetup::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}
bool GameSetup::mouseMoved (const OIS::MouseEvent &arg)
{
	return true;
}
bool GameSetup::mousePressed (const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return true;
}
bool GameSetup::mouseReleased (const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return true;
}
