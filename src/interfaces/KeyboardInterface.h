#ifndef _KeyboardInterface_h_
#define _KeyboardInterface_h_

#include "Interface.h"
//include strings 
#include <OISKeyboard.h>

class KeyboardInterface : public Interface
{
private:
	OIS::Keyboard *mKeyboard;
	
	enum posicionsMap
	{
		ARRPOS_SALT = 0
public:
	KeyboardInterface(OIS::Keyboard *kb, Ogre::String configFile);
	
	void update(void);
}
#endif //_KeyboardInterface_h_
