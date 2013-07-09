#ifndef _KeyboardInterface_h_
#define _KeyboardInterface_h_

#include "../Interface.h"
#ifndef NO_LOGS
	#include <OgreLogManager.h>
#endif
//#include "../iniparser/iniparser.h"


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#ifdef BUILDING_KEYBOARDINTERFACE
		#define KEYBOARDINTERFACE __declspec(dllexport)
	#else
		#define KEYBOARDINTERFACE __declspec(dllimport)
	#endif
#else
	#define KEYBOARDINTERFACE
#endif
// la macro del fitxer de configuracio per defecte esta a ClassLoader.h

class KEYBOARDINTERFACE KeyboardInterface : public Interface
{
private:
	OIS::Keyboard *mKeyboard;
	
	enum posicionsMap
	{
		ARRPOS_SALT = 0,
		ARRPOS_ROLL = 1,
		ARRPOS_AATK = 2,
		ARRPOS_SATK = 3,
		ARRPOS_ULTI = 4,
		ARRPOS_SHLD = 5,
		ARRPOS_LEFT = 6,
		ARRPOS_RIGHT = 7,
		ARRPOS_UP = 8,
		ARRPOS_DOWN = 9
	};
	
	OIS::KeyCode* keyMap;
	std::string mCfgFile;
	
public:
	KeyboardInterface(OIS::Keyboard *kb);
	~KeyboardInterface(void);
	
	bool readConfigFile();
	
	void update(void);
};

extern "C"
{
	KeyboardInterface* KEYBOARDINTERFACE KeyboardInterface_maker(OIS::Keyboard *_kb);
}
#endif //_KeyboardInterface_h_
