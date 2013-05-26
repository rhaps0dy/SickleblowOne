#ifndef _GameSetup_h_
#define _GameSetup_h_

//renderitzacio
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>

#include <OgreMath.h>

//events
#include <OgreFrameListener.h>
#include <OgreWindowEventUtilities.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

class GameSetup: public Ogre::FrameListener, public Ogre::WindowEventListener//, public OIS::KeyListener, public OIS::MouseListener
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
    OIS::JoyStick *mJoystick;
    
    //continuem renderitzant?
    bool mContinue;
    
    void destroyEverything(void); //destrueix scenemanager, camara... etc deixant nomes Root i RenderWindow
    virtual void createScene(void); //crea totes les instancies de classes necessaries per al mode de joc
    virtual void loadResources(void); //Carrega els recursos necessaris
    
    virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
    
    virtual bool windowClosing(Ogre::RenderWindow *rw);   
public:
	GameSetup(Ogre::Root *root, Ogre::RenderWindow *rw);
	~GameSetup(void);
};

#endif //_GameSetup_h_
