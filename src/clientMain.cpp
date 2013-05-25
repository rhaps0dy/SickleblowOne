//#include "GameSetup.h"
#include <OgreRoot.h>
#include <OgreException.h>

int main(int argc, char **argv)
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
		
		//Carreguem un octree manager
	    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

		
		
		//Creem un GameSetup --provisional
		
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
