#include "ClassLoader.h"

//definim els estatics a fora una vegada
//libs
	//subclasses de GameSetup
	Ogre::DynLib* ClassLoader::mGameSetupLocalProva_lib;
	
	//subclasses de Interface
	Ogre::DynLib* ClassLoader::mKeyboardInterface_lib;
	
//makers
	//subclasses de GameSetup
	GameSetupLocalProva_mk ClassLoader::mGameSetupLocalProva_mk;
	
	//subclasses de Interface
	KeyboardInterface_mk ClassLoader::mKeyboardInterface_mk;



void ClassLoader::init(void)
{
	mGameSetupLocalProva_lib = 0;
	mGameSetupLocalProva_mk = 0;
	
	mKeyboardInterface_lib = 0;
	mKeyboardInterface_mk = 0;
}

inline
Ogre::DynLib* ClassLoader::loadLibrary(std::string lib_name)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
		Ogre::DynLib *dlib = Ogre::DynLibManager::getSingleton().load(Ogre::String(Ogre::macBundlePath()+lib_name));
#else
		Ogre::DynLib *dlib = Ogre::DynLibManager::getSingleton().load(lib_name);
#endif 
}

//subclasses de GameSetup
GameSetup* ClassLoader::makeGameSetupLocalProva(Ogre::Root *__root, Ogre::RenderWindow *__rw, Ogre::String __plnm, Ogre::String __lvnm)
{
	if(!mGameSetupLocalProva_lib)
	{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		mGameSetupLocalProva_lib = loadLibrary("gamesetups/libGameSetupLocalProva.dll");
#else 
		mGameSetupLocalProva_lib = loadLibrary("gamesetups/libGameSetupLocalProva.so");
#endif
		mGameSetupLocalProva_mk = reinterpret_cast<GameSetupLocalProva_mk>(mGameSetupLocalProva_lib->getSymbol("GameSetupLocalProva_maker"));
	}
	return (*mGameSetupLocalProva_mk)(__root, __rw, __plnm, __lvnm);
}

void ClassLoader::unloadGameSetupLocalProva(void)
{
	if(mGameSetupLocalProva_lib)
	{
		Ogre::DynLibManager::getSingleton().unload(mGameSetupLocalProva_lib);
		mGameSetupLocalProva_lib = 0;
		mGameSetupLocalProva_mk = 0;
	}
}

//subclasses de Interface
Interface* ClassLoader::makeKeyboardInterface(OIS::Keyboard *__kb)
{
	if(!mKeyboardInterface_lib)
	{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		mKeyboardInterface_lib = loadLibrary("interfaces/libKeyboardInterface.dll");
#else
		mKeyboardInterface_lib = loadLibrary("interfaces/libKeyboardInterface.so");
#endif
		mKeyboardInterface_mk = reinterpret_cast<KeyboardInterface_mk>(mKeyboardInterface_lib->getSymbol("KeyboardInterface_maker"));
	}
	return (*mKeyboardInterface_mk)(__kb);
}

void ClassLoader::unloadKeyboardInterface(void)
{
	if(mKeyboardInterface_lib)
	{
		Ogre::DynLibManager::getSingleton().unload(mKeyboardInterface_lib);
		mKeyboardInterface_lib = 0;
		mKeyboardInterface_mk = 0;
	}
}
