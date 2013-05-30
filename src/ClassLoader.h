#ifndef _ClassLoader_h_
#define _ClassLoader_h_

#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OISJoyStick.h>

#include <OgreDynLibManager.h>
#include <OgreDynLib.h>
#include <string>

//no volem referencies circulars
class GameSetup;
class Interface;

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#include <macUtils.h>
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "windows.h"
#endif


//subclasses de GameSetup
typedef GameSetup *(*GameSetupLocalProva_mk) (Ogre::Root*, Ogre::RenderWindow*, Ogre::String, Ogre::String);

//subclasses de Interface
typedef Interface *(*KeyboardInterface_mk) (OIS::Keyboard*, std::string);
#define KEYBOARDINTERFACE_CFG "scripts/kbControls"

class ClassLoader
{
private:
	static Ogre::DynLib* loadLibrary(std::string lib_name);
	
//libs
	//subclasses de GameSetup
	static Ogre::DynLib* mGameSetupLocalProva_lib;
	
	//subclasses de Interface
	static Ogre::DynLib* mKeyboardInterface_lib;
	
//makers
	//subclasses de GameSetup
	static GameSetupLocalProva_mk mGameSetupLocalProva_mk;
	
	//subclasses de Interface
	static KeyboardInterface_mk mKeyboardInterface_mk;
	
public:

	static void init(void);
//loaders
	//subclasses de GameSetup
	static GameSetup* makeGameSetupLocalProva(Ogre::Root *__root, Ogre::RenderWindow *__rw, Ogre::String __plnm, Ogre::String __lvnm);
	
	//subclasses de Interface
	static Interface* makeKeyboardInterface(OIS::Keyboard *__kb, std::string __cfgfile=KEYBOARDINTERFACE_CFG);

//unloaders
	//subclasses de GameSetup
	static void unloadGameSetupLocalProva(void);
	
	//subclasses de Interface
	static void unloadKeyboardInterface(void);
};

#endif //_ClassLoader_h_
