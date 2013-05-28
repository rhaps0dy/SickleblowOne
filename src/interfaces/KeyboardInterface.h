#ifndef _KeyboardInterface_h_
#define _KeyboardInterface_h_

#include "../Interface.h"
#include <iostream>
#include <fstream>
#include <OISKeyboard.h>

class KeyboardInterface : public Interface
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
	KeyboardInterface(OIS::Keyboard *kb, std::string cfgfile="scripts/kbControls");
	~KeyboardInterface(void);
	
	bool readConfigFile();
	
	void update(void);
};
#endif //_KeyboardInterface_h_
