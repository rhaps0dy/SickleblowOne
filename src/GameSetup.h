#ifndef _GameSetup_h_
#define _GameSetup_h_

//renderitzacio
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>

//events
#include <OgreFrameListener.h>
#include <OgreWindowEventUtilities.h>
#include <OISKeyboard.h>
#include <OISMouse.h>


class GameSetup: public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
protected:
	//construccions basiques de Ogre
	Ogre::Root *mRoot;
    Ogre::Camera *mCamera;
    Ogre::SceneManager *mSceneMgr;
    Ogre::RenderWindow *mWindow;
    
    //construccions basiques de OIS
    OIS::InputManager *mInputManager;
    OIS::Mouse *mMouse;
    OIS::Keyboard *mKeyboard;
    
public:
	GameSetup(Ogre::Root *root, Ogre::Camera *cam, Ogre::SceneManager *mSceneMgr);
	~GameSetup();
};

#endif //_GameSetup_h_
