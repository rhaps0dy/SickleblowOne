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

#ifndef SKBLCORE
	#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		#ifdef BUILDING_SKBLCORE
			#define SKBLCORE __declspec(dllexport)
		#else
			#define SKBLCORE __declspec(dllimport)
		#endif
	#else
		#define SKBLCORE
	#endif
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#include <macUtils.h>
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "windows.h"
#endif


//subclasses de GameSetup
typedef GameSetup *(*GameSetupLocalProva_mk) (Ogre::Root*, Ogre::RenderWindow*, Ogre::String, Ogre::String);

//subclasses de Interface
typedef Interface *(*KeyboardInterface_mk) (OIS::Keyboard*);

class SKBLCORE ClassLoader
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
	static Interface* makeKeyboardInterface(OIS::Keyboard *__kb);

//unloaders
	//subclasses de GameSetup
	static void unloadGameSetupLocalProva(void);
	
	//subclasses de Interface
	static void unloadKeyboardInterface(void);
};

#endif //_ClassLoader_h_
