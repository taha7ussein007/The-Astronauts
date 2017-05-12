#include <string>
#include <iostream>
#include <conio.h> // _getch
#include "Rocket.h"
using namespace std;
/////////////////////////////////////////////////////////////////////
Rocket::Rocket(){}
/////////////////////////////////////////////////////////////////////
Rocket::~Rocket(){}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void Rocket::set_rocket_no(unsigned n){
	this->rocket_no = n;
}
/////////////////////////////////////////////////////////////////////
bool Rocket::set_acceleration() {
	string *tmp = new string;
	char hold;
	for (int i = 0;;){
		hold = _getch();
		if ((hold >= '0' && hold <= '9') || (hold == '.')) //Must be positive double value
		{
			tmp->push_back(hold);
			clog << hold;
			++i;
		}
		else if (hold == '\b' && i >= 1)
		{
			tmp->pop_back();
			clog << "\b \b";  //rub the char behind the cursor	
			--i;
		}
		else if (hold == '\r')
		{
			break;
		}
	}
	if (!tmp->empty() && tmp->back() != '.' && tmp->front() != '.')
	{
		string dummy = *tmp;
		int counter = 0;
		while (!dummy.empty()){
			if (dummy.back() == '.') counter++;
			dummy.pop_back();
		}
		if (counter > 1) return false;
		else
		{
			this->acceleration = stold(*tmp);
			return true;
		}
	}
	else
	{
		return false;
	}
}
/////////////////////////////////////////////////////////////////////
bool Rocket::set_duration() {
	string *tmp = new string;
	char hold;
	for (int i = 0;;){
		hold = _getch();
		if ((hold >= '0' && hold <= '9') || (hold == '.')) //Must be positive double value
		{
			tmp->push_back(hold);
			clog << hold;
			++i;
		}
		else if (hold == '\b' && i >= 1)
		{
			tmp->pop_back();
			clog << "\b \b";  //rub the char behind the cursor	
			--i;
		}
		else if (hold == '\r')
		{
			break;
		}
	}
	if (!tmp->empty() && tmp->back() != '.' && tmp->front() != '.')
	{
		string dummy = *tmp;
		int counter = 0;
		while (!dummy.empty()){
			if (dummy.back() == '.') counter++;
			dummy.pop_back();
		}
		if (counter > 1) return false;
		else
		{
			this->duration = stold(*tmp);
			return true;
		}
	}
	else
	{
		return false;
	}
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
unsigned Rocket::get_rocket_no(){
	return this->rocket_no;
}
/////////////////////////////////////////////////////////////////////
long double Rocket::get_acceleration() {
	return this->acceleration;
}
/////////////////////////////////////////////////////////////////////
long double Rocket::get_duration() {
	return this->duration;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
			//Operators
/////////////////////////////////////////////////////////////////////
void Rocket::operator=(Rocket _Rocket){
	this->rocket_no = _Rocket.get_rocket_no();
	this->acceleration = _Rocket.get_acceleration();
	this->duration = _Rocket.get_duration();
}
/////////////////////////////////////////////////////////////////////