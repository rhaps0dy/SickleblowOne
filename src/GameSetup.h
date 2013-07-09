#ifndef _GameSetup_h_
#define _GameSetup_h_

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#ifdef BUILDING_SKBLCORE
		#define SKBLCORE __declspec(dllexport)
	#else
		#define SKBLCORE __declspec(dllimport)
	#endif
#else
	#define SKBLCORE
#endif

//renderitzacio
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>
#ifndef NO_LOGS
	#include <OgreLogManager.h>
#endif
#include <OgreMath.h>

//events
#include <OgreFrameListener.h>
#include <OgreWindowEventUtilities.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISException.h>

#include "Player.h"
#include "PlayerRenderer.h"
#include "Level.h"
#include "LevelRenderer.h"
#include "Interface.h"
#include "ClassLoader.h"
#include "CameraMan.h"

//crea i destrueix tots els objectes per a un partit concret.

class SKBLCORE GameSetup: public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
protected:
	//construccions basiques de Ogre
	Ogre::Root *mRoot;
	Ogre::Camera *mCamera;
    Ogre::SceneManager *mSceneMgr;
    Ogre::RenderWindow *mWindow;
    
	//auxiliar de moviment de camera
	Ogre::SceneNode *mCameraNode;

    //construccions basiques de OIS
    OIS::InputManager *mInputManager;
    OIS::Mouse *mMouse;
    OIS::Keyboard *mKeyboard;
    OIS::JoyStick *mJoystick;
    
    //continuem renderitzant?
    bool mContinue;
    
    virtual void createScene(void); //crea totes les instancies de classes necessaries per al mode de joc
    virtual void loadResources(void); //Carrega els recursos necessaris
    
    virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
    
    virtual bool windowClosing(Ogre::RenderWindow *rw);
    
    //events per a CEGUI
	virtual bool keyPressed(const OIS::KeyEvent& arg);
	virtual bool keyReleased(const OIS::KeyEvent& arg);
	virtual bool mouseMoved (const OIS::MouseEvent &arg);
	virtual bool mousePressed (const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	virtual bool mouseReleased (const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	//utilitzada per a fer destructors de derivades
	virtual void destroyAll(void);

public:
	GameSetup(Ogre::Root *root, Ogre::RenderWindow *rw);
	//potencial per afegir un altre constructor amb els objectes de OIS ja creats

	~GameSetup(void) { destroyAll(); }
};

#endif //_GameSetup_h_
