#ifndef _Interface_h_
#define _Interface_h_

//lloc on hi ha les llibreries compartides
//dels tipus d'interficie
#define INTERFACES_DIR "interfaces"

#define MAX_JOY 0x7f
#define MIN_JOY -0x8f

class Interface
{
protected:
	char ctlStatus;
	char prevCtlStatus;
	int joyX;
	int joyY;
	
public:
	static const char SALT = 0x80;
	static const char ROLL = 0x40;
	static const char AATK = 0x20;
	static const char SATK = 0x10;
	static const char ULTI = 0x08;
	static const char SHLD = 0x04;
	
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
	
	virtual void update(void)
	{
		prevCtlStatus = ctlStatus;
	}
};

#endif //_Interface_h_
