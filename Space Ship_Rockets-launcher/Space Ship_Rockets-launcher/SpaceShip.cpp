#include "SpaceShip.h"
using namespace std;
/////////////////////////////////////////////////////////////////////
SpaceShip::SpaceShip(){
	this->velocity = 0.0;
	this->displacement = 0.0;
}
/////////////////////////////////////////////////////////////////////
SpaceShip::~SpaceShip(){}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void SpaceShip::attach_rocket(Rocket *pR){
	if (this->Rockets_Container.size() == 0) this->Rockets_Container.push(*pR);
	else if (pR->get_acceleration() > this->Rockets_Container.top().get_acceleration()) this->Rockets_Container.push(*pR);
	else if (this->Rockets_Container.size() == 1) this->Rockets_Container.push(*pR, 0); //size = 1 and less than
	else
	{
		int j = this->Rockets_Container.size() - 2;
		this->Rockets_Container.push(this->Rockets_Container.top());
		while (pR->get_acceleration() <= this->Rockets_Container.at(j).get_acceleration())q
		{
			this->Rockets_Container.assign(this->Rockets_Container.at(j), j + 1);
			j--;
			if (j == -1)
			{
				this->Rockets_Container.assign(*pR, 0);
				return;
			}
		}
		this->Rockets_Container.assign(*pR, j + 1);
	}
}
/////////////////////////////////////////////////////////////////////
bool SpaceShip::detach_rocket(unsigned r_n){
	if ( r_n < this->Rockets_Container.size() ){
		this->Rockets_Container.remove(r_n);
		return true;
	}
	else return false;
}
/////////////////////////////////////////////////////////////////////
void SpaceShip::launch_now(){
	long double prev_displacement = 0.0;
	while (!this->Rockets_Container.empty())
	{
		prev_displacement = this->velocity*this->Rockets_Container.top().get_duration() + 0.5*this->Rockets_Container.top().get_acceleration()*this->Rockets_Container.top().get_duration()*this->Rockets_Container.top().get_duration();
		this->displacement += prev_displacement;
		this->velocity += this->Rockets_Container.top().get_acceleration()*this->Rockets_Container.top().get_duration();
		this->Rockets_Container.pop();
	}
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
Rocket SpaceShip::get_rocket_info(unsigned index){
	return this->Rockets_Container.at(index);
}
/////////////////////////////////////////////////////////////////////
unsigned SpaceShip::get_NumOfRockets(){
	return this->Rockets_Container.size();
}
/////////////////////////////////////////////////////////////////////
void SpaceShip::get_final(long double*v, long double*d){
	*v = this->velocity;
	*d = this->displacement;
	//reset
	this->velocity = 0.0;
	this->displacement = 0.0;
}
/////////////////////////////////////////////////////////////////////