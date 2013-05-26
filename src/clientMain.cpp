#include "GameSetup.h"

#include <OgreRoot.h>
#include <OgreException.h>
#include <OgreLogManager.h>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "windows.h"
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char **argv)
#endif
{
	try
	{
		//Iniciem OGRE
		Ogre::Root *lRoot = new Ogre::Root("", "", "ogre.log");
		
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
		for(int i=0; i<lRenderSystemList.size(); i++)
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
		lWindow = lRoot->createRenderWindow("Client for SickleblowOne", 1280, 720, false, &lParams);
		
		//TODO: Llistem tots els llocs on hi ha recursos
		
		
		
		
		
		//Creem un GameSetup --provisional
		GameSetup *lGameSetup = new GameSetup(lRoot, lWindow);
		
		delete lGameSetup;
		delete lRoot;
		
		Ogre::LogManager::getSingletonPtr()->logMessage("Fi del programa");
		
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
