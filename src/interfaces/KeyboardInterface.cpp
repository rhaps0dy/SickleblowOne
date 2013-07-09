#include "KeyboardInterface.h"

KeyboardInterface::KeyboardInterface(OIS::Keyboard *kb)
: mKeyboard(kb), mCfgFile("configScripts/kbControls")
{	
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Creant KeyboardInterface");
	#endif
	keyMap =  new OIS::KeyCode[10];
	readConfigFile();
}

KeyboardInterface::~KeyboardInterface(void)
{
	delete keyMap;
}

bool KeyboardInterface::readConfigFile(void)
{
	keyMap[ARRPOS_SALT] = OIS::KC_SPACE;
	keyMap[ARRPOS_ROLL] = OIS::KC_E;
	keyMap[ARRPOS_AATK] = OIS::KC_Q;
	keyMap[ARRPOS_SATK] = OIS::KC_W;
	keyMap[ARRPOS_ULTI] = OIS::KC_R;
	keyMap[ARRPOS_SHLD] = OIS::KC_LSHIFT;
	keyMap[ARRPOS_DOWN] = OIS::KC_DOWN;
	keyMap[ARRPOS_LEFT] = OIS::KC_LEFT;
	keyMap[ARRPOS_UP] = OIS::KC_UP;
	keyMap[ARRPOS_RIGHT] = OIS::KC_RIGHT;
	return true;
	
	#ifndef NO_LOGS
		for(int i=0; i<10; i++)
			std::cerr << "Tecla num " << keyMap[i] << std::endl;
	#endif
}
	
void KeyboardInterface::update(void)
{
	Interface::update();
	//assumim que el teclat esta capturat
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_SALT]))
		ctlStatus |= SALT;
	else
		ctlStatus &= ~SALT;
		
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_ROLL]))
		ctlStatus |= ROLL;
	else
		ctlStatus &= ~ROLL;
		
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_AATK]))
		ctlStatus |= AATK;
	else
		ctlStatus &= ~AATK;
		
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_SATK]))
		ctlStatus |= SATK;
	else
		ctlStatus &= ~SATK;
		
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_ULTI]))
		ctlStatus |= ULTI;
	else
		ctlStatus &= ~ULTI;
		
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_SHLD]))
		ctlStatus |= SHLD;
	else
		ctlStatus &= ~SHLD;
		
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_DOWN]))
		joyY = MIN_JOY;
	else if(mKeyboard->isKeyDown(keyMap[ARRPOS_UP]))
		joyY = MAX_JOY;
	else
		joyY = 0;
		
	if(mKeyboard->isKeyDown(keyMap[ARRPOS_LEFT]))
		joyX = MIN_JOY;
	else if(mKeyboard->isKeyDown(keyMap[ARRPOS_RIGHT]))
		joyX = MAX_JOY;
	else
		joyX = 0;
}

KeyboardInterface* KeyboardInterface_maker(OIS::Keyboard *_kb)
{
	return new KeyboardInterface(_kb);
}

