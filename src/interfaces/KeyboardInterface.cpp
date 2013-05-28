#include "KeyboardInterface.h"

KeyboardInterface::KeyboardInterface(OIS::Keyboard *kb, std::string cfgfile)
: mKeyboard(kb), mCfgFile(cfgfile)
{
	keyMap = static_cast<OIS::KeyCode*> ( new OIS::KeyCode[10] );
	readConfigFile();
}

KeyboardInterface::~KeyboardInterface(void)
{
	delete keyMap;
}

bool KeyboardInterface::readConfigFile(void)
{
	std::ifstream cfg;
	cfg.open(mCfgFile.c_str());
	if(!cfg.is_open())
		return false;
	register int tecla;
	for(register int i=0; i<10; i++) //10 tecles diferents
	{
		cfg >> tecla;
		keyMap[i] = static_cast<OIS::KeyCode>(tecla);
	}
	cfg.close();
	return true;
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
