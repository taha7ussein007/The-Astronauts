#pragma once
#include "Stack.h"

class Rocket
{
private:
	/////////////////////////////////////////////////////////////////////
	unsigned rocket_no;
	long double acceleration;
	long double duration;
	/////////////////////////////////////////////////////////////////////
public:
	/////////////////////////////////////////////////////////////////////
	Rocket();
	~Rocket();
	/////////////////////////////////////////////////////////////////////
	void set_rocket_no(unsigned Rocket_Number);
	bool set_acceleration();
	bool set_duration();
	/////////////////////////////////////////////////////////////////////
	unsigned get_rocket_no();
	long double get_acceleration();
	long double get_duration();
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	//Operators
	/////////////////////////////////////////////////////////////////////
	void operator=(Rocket _Rocket);
	/////////////////////////////////////////////////////////////////////
};

