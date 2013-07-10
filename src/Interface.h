#ifndef _Interface_h_
#define _Interface_h_

#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OISJoyStick.h>

#include <OgrePlatform.h>
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

class SKBLCORE Interface
{
protected:
	char ctlStatus;
	char prevCtlStatus;
	int joyX;
	int joyY;
	int prevJoyX;
	int prevJoyY;
	
public:
	static const char SALT = 0x80;
	static const char ROLL = 0x40;
	static const char AATK = 0x20;
	static const char SATK = 0x10;
	static const char ULTI = 0x08;
	static const char SHLD = 0x04;
	
	static const int MAX_JOY = 0x8000;
	static const int MIN_JOY = -0x8000; 
	static const int JOY_TH = 300; //inclinacio del joy a partir de la qual es considera mogut

	inline char getActualCtlStatus(void)
	{
		return ctlStatus;
	}
	
	inline char getPrevCtlStatus(void)
	{
		return prevCtlStatus;
	}
	
	//retorna els 8 penultims bits amb l'estat anterior
	// i els ultims 8 amb l'estat actual
	inline unsigned int getStatus(void)
	{
		return (prevCtlStatus << 8) + ctlStatus;
	}
	
	inline int getJoyX(void)
	{
		return joyX;
	}
	inline int getJoyY(void)
	{
		return joyY;
	}
	inline int getPrevJoyX(void)
	{
		return prevJoyX;
	}
	inline int getPrevJoyY(void)
	{
		return prevJoyY;
	}

	virtual void update(void)
	{
		prevCtlStatus = ctlStatus;
		prevJoyX = joyX;
		prevJoyY = joyY;
	}
	
	virtual ~Interface(void){;}
};

#endif //_Interface_h_
