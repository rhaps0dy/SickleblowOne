#include "GameSetup.h"
#include "ClassLoader.h"

#include <OgreRoot.h>
#include <OgreException.h>
#include <OgreConfigFile.h>
#ifndef NO_LOGS
	#include <OgreLogManager.h>
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char **argv)
#endif
{
	try
	{
		//Iniciem el nostre carregador de classes
		ClassLoader::init();
		
		//Iniciem OGRE
		#ifdef NO_LOGS
			Ogre::Root *lRoot = new Ogre::Root("", "", "");
		#else
			Ogre::Root *lRoot = new Ogre::Root("", "", "SickleblowOne.log");
		#endif
		lRoot->loadPlugin("Plugin_OctreeSceneManager");
		
		//provem de carregar els plugins de DirectX o OpenGL
		#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
			try
			{
				lRoot->loadPlugin("RenderSystem_Direct3D9");
			}catch (Ogre::Exception &e)
			{
				MessageBox( NULL, "Get it in our web page",
					"Couldn't find shared library \"RenderSystem_Direct3D9\"\n",
						MB_OK | MB_ICONERROR | MB_TASKMODAL);
			}
		#else //Win32
			try
			{
				lRoot->loadPlugin("RenderSystem_GL");
			}catch (Ogre::Exception &ee)
			{
					std::cerr << "Couldn't find shared library \"RenderSystem_GL\". Get it in our web page\n" << std::endl;
			}
		#endif //Win32
		
		
		//ara seleccionem un render system d'entre els disponibles
		const Ogre::RenderSystemList& lRenderSystemList = lRoot->getAvailableRenderers();
		for(unsigned int i=0; i<lRenderSystemList.size(); i++)
		{
			Ogre::String rsysnm = lRenderSystemList[i]->getName();
			//l'ordre d'ifs es el de preferencia
			if(rsysnm=="Direct3D9 Rendering Subsystem")
			{
				lRoot->setRenderSystem(lRenderSystemList[i]);
				break;
			}
			if(rsysnm=="OpenGL Rendering Subsystem")
			{
				lRoot->setRenderSystem(lRenderSystemList[i]);
				break;
			}
		}
		
		//Inicialitzem Root sense crear finestra
		lRoot->initialise(false);
		
		//TODO: Llegir fitxer de configuracio
		Ogre::RenderWindow *lWindow;
		Ogre::NameValuePairList lParams;
		lParams["vsync"] = "true";
		lWindow = lRoot->createRenderWindow("8====D~~~~O:", 1280, 720, false, &lParams);
		

    // Load resource paths from config file
		Ogre::ConfigFile cf;
    cf.load("configScripts/resources.cfg");

    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
            // OS X does not set the working directory relative to the app,
            // In order to make things portable on OS X we need to provide
            // the loading with it's own bundle path location
            if (!Ogre::StringUtil::startsWith(archName, "/", false)) // only adjust relative dirs
                archName = Ogre::String(Ogre::macBundlePath() + archName);
#endif
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }
		//Creem un GameSetup --provisional
		GameSetup *lGameSetup = ClassLoader::makeGameSetupLocalProva(lRoot, lWindow, "pl_Boxejador", "lvl_Prova");
		delete lGameSetup;
		
		ClassLoader::unloadGameSetupLocalProva();
		
		#ifndef NO_LOGS
			Ogre::LogManager::getSingletonPtr()->logMessage("Fi del programa");
		#endif
		delete lRoot;
	
	}catch(Ogre::Exception &e)
	{
		#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
		#endif
	}
	return 0;
}
