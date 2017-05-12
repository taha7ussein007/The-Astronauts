#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include "Stack.h"
#include "SpaceShip.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void limchar(char BEGIN, char END, char* Output);
bool unsigned_scanner(unsigned* Unsigned);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	//Set Console Title
	system("Title Space Ship_Rocket-launcher : The Astronauts Team");
	//Set Console Size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 1250, 650, TRUE);
	//Set Console Buffer Size
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD c; c.X = 80; c.Y = 9999;
	SetConsoleScreenBufferSize(hConsole, c);
	//--------------------------------------------------Caution-Message--------------------------------------------------------------
	clog << "\n\n\n\n\t\t\t\t***Caution!***\n\n\t"
		<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t"
		<< ">> Any Character Out of The Choices Will Not Be Allowed <<"
		<< "\n\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
		<< "\n\n\n\n\n\n\n\t";
	for (int i = 0; i<2; i++){
		system("color c0"); _beep(750, 100);
		system("color 90"); _beep(1000, 100);
	}
	system("color 0c");
	system("pause");
	//////////////////////////////////////////////////////Variables Declaration///////////////////////////////////////////////////////////////////
	SpaceShip* Ship = new SpaceShip;
	Rocket*_Rocket = new Rocket;
	long double * final_velocity = new long double;
	long double * final_displacement = new long double;
	static unsigned fix_detach = 0;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (true)
	{
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		system("cls"); system("color f0"); char * switcher = new char;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (Ship->get_NumOfRockets() > 0)
		{
			//List Rockets:
			cout << "\t____________________________________________________" << endl;
			printf("\t| %-10s |    %-12s    |    %-8s    |\n", "Rocket_No.", "Acceleration", "Duration");
			for (int i = Ship->get_NumOfRockets() - 1; i >= 0; i--)
			{
				cout << "\t----------------------------------------------------" << endl;
			 	*_Rocket = Ship->get_rocket_info(i);
				printf("\t| %-10s | %-18s | %-14s |\n", to_string(_Rocket->get_rocket_no()).c_str(),
					to_string(_Rocket->get_acceleration()).c_str(),
					to_string(_Rocket->get_duration()).c_str());
			}
			cout << "\t----------------------------------------------------" << endl;
			//Menu
			cout << "\n\t\3 Please Press a Choice:\n"
				<< "\t**************************\n"
				<< "\t1-Attach Another Rocket.\n"
			    << "\t2-Launch Now!.\n"
				<< "\t3-Detach Rocket.\n"
			    << "\t0-Exit.\n"
				<< "\t**************************" << endl;
			_beep(1000, 500);
			//scan choice
			limchar('0', '3', switcher);
		}
		else
		{
			//Main Menu
			cout << "\n\n\t\t\3 Welcome To Space Ship_Rocket-launcher \3"
				<< "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
				<< "\n\n\t\3 Please Press a Choice:\n"
				<< "\t**************************\n"
				<< "\t1-Attach Rocket.\n";
			cout << "\t0-Exit.\n"
				<< "\t**************************" << endl;
			_beep(1000, 500);
			//scan choice
			limchar('0', '1', switcher);
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		switch (*switcher)
		{
			case'1': //Attach
				cout << "\n\t >> Enter Rocket ("<< Ship->get_NumOfRockets()+1+fix_detach << ") Info Carefully: ";
				do{ cout << "\n\n\t\7 >> Acceleration : "; } while (!_Rocket->set_acceleration());
				do{ cout << "\n\n\t\7 >> Duration : "; } while (!_Rocket->set_duration());
				_Rocket->set_rocket_no(Ship->get_NumOfRockets() + 1 + fix_detach);
				Ship->attach_rocket(_Rocket);
				
				cout << "\n\n\t\t\t >>> Rocket attached :)" << endl; _beep(750, 500);
				break;
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case'2': //Launch
			{
					   system("cls"); system("color 0f");
					   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					   SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					   cout << "\n\t\t\t\t Launching Now..." << endl << endl << endl;
					   Ship->launch_now(); fix_detach = 0; // <== core function
					   Ship->get_final(final_velocity, final_displacement);
					   SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					   //progress bar
					   cout << "=>"; _beep(1000, 1000);
					   for (int j = 78; j > 0; j--) {
						   cout << "\b\b =>"; _sleep(j);
					   }  _beep(750, 100);
					   SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					   cout << "\n\t\t\tWOW! YOU ARE ON MARS NOW xD\t\t\t\t\n\n\n\n";
					   SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					   //tiny table
					   cout << "\t\t_______________________________________________" << endl;
					   printf("\t\t|    %-12s    |    %-12s    |\n", "Final Velocity", "Final Distance");
					   cout << "\t\t-----------------------------------------------" << endl;
					   printf("\t\t| %-20s | %-20s |\n", to_string(*final_velocity).c_str(), to_string(*final_displacement).c_str());
					   cout << "\t\t-----------------------------------------------\n\n\n\n\n\n\n\n\n\t";
					   SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
					   system("pause");
			}
				break;
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case '3': //Detach
			{
					unsigned * index = new unsigned;
					cout << "\n\n\t\7 >> Enter The Rocket (index on the table) Not Rocket Number!\n\t Start Count From (0) Upwards: ";
					if (unsigned_scanner(index))
					{
						if (Ship->detach_rocket(*index)) { cout << "\n\n\t\t\t >>> Rocket detached :)" << endl; _beep(750, 500); fix_detach++; }
						else { cout << "\n\n\t\t\t >>> Wrong Rocket index :(" << endl; _beep(750, 500); _beep(750, 500); _beep(750, 500); }
					}
					else
					{
						cout << "\n\n\t\t\t >>> Wrong Entry!!!" << endl; _beep(750, 500); _beep(750, 500); _beep(750, 500);
					}
					delete index;
			}
				break;
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case '0': //Exit
				system("cls"); system("Color 70");
				clog << "\n\n\n\n\n\n\n\t\t\t Thanks For Using This Program \1\n " << endl; _sleep(1500);
				return 0;
				break;
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}//End_While
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void limchar(char BEGIN, char END, char* Output){
	char hold;
	while (true)
	{
		hold = _getch();
		if ((hold >= BEGIN && hold <= END)){ //Must be a value between (BEGIN - END)
			*Output = hold;
		}
		if ((hold == *Output) && (*Output >= BEGIN && *Output <= END)){
			break;
		}
	} //End Of Loop
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool unsigned_scanner(unsigned*u){
	string *tmp = new string;
	char hold;
	for (int i = 0;;){
		hold = _getch();
		if ((hold >= '0' && hold <= '9')){ //Must be positive integer value
			tmp->push_back(hold);
			clog << hold;
			++i;
		}
		if (hold == '\b' && i >= 1){
			tmp->pop_back();
			clog << "\b \b";  //rub the char behind the cursor	
			--i;
		}
		if (hold == '\r'){
			break;
		}
	} if (!tmp->empty()){
		*u = (unsigned)stol(*tmp);
		return true;
	}
	else{
		return false;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////