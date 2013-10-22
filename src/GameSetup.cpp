#include "GameSetup.h"

GameSetup::GameSetup(Ogre::Root *root, Ogre::RenderWindow *rw) :
mRoot(root), mWindow(rw), mCamera(0), mSceneMgr(0),
mInputManager(0), mJoystick(0), mMouse(0), mKeyboard(0),
mContinue(true)
{	
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Inicialitzant GameSetup");
	#endif
	
	//Creem un octree scene manager
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
    mCamera = mSceneMgr->createCamera("GeneralCamera");
    
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(Ogre::ColourValue(1,0,0));
	
	mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
	
	mCamera->setProjectionType(Ogre::PT_PERSPECTIVE);
	mCamera->setFOVy(Ogre::Degree(40.));
	mCamera->setNearClipDistance(1.0);
	mCamera->setFarClipDistance(100000.0);
	mCameraNode = mSceneMgr->createSceneNode("CameraNode");
	mCameraNode->attachObject(mCamera);

	Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
	mRoot->addFrameListener(this);
	
	//inicialitzem OIS en aquesta finestra
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Inicialitzant OIS...");
	#endif
	
	OIS::ParamList paramList;
	size_t windowHnd;
	std::ostringstream windowHndStr;
	mWindow->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	paramList.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
#if defined OIS_WIN32_PLATFORM
	paramList.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
	paramList.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
	paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
	paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
#elif defined OIS_LINUX_PLATFORM
	paramList.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
	paramList.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
	paramList.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
	paramList.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
#endif
    
			mInputManager = OIS::InputManager::createInputSystem( paramList );

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
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Destruint GameSetup");
	#endif
	Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
	if(mCamera)
	{
		mSceneMgr->destroyCamera(mCamera);
		mCamera = 0;
	}
	
	mWindow->removeAllViewports();
	
	std::cerr << "segfault incoming 1" << std::endl;
	if(mSceneMgr)
	{
		mRoot->destroySceneManager(mSceneMgr);
	std::cerr << "segfault incoming 1" << std::endl;
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

void GameSetup::createScene(void)
{
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Creant escena");
	#endif
}
void GameSetup::loadResources(void)
{	
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Carregant recursos");
	#endif
}
