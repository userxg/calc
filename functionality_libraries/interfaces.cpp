#include <iostream>
#include <string>
using namespace std;
#include "calculator.h"


//all interfaces

//start interfaces

void Calculator::start_interface() const
{
	cout << "--------------interface-------------" << "\n";
	cout << "enter figure for chosing section\n"
		<< "1 -------- compute ----------------------\n"
		<< "2 -------- complex----------------------\n"
		<< "3 -------- matrix ----------------------\n"
		<< "enter stop to turn off calculator\n"
		<< "\n\n";
}




/// all compute interfaces
void Compute::compute_meaning_interface() const
{
	cout << "----------compute interface-------------" << "\n";
	cout << "meanings" << "\n";
	cout << "rules" << "\n";
	cout << "range" << "\n";
	cout << "enter expression to compute:" << "\n";
}


//all complex interfaces
// 
//complex start interface
void Complex::complex_interface() const
{
	cout << "----------complex interface-------------" << "\n";
	cout << "-----------addtitoin--------------------" << "\n";
	cout << "-----------multiplication--------------------" << "\n";
	cout << "-----------division--------------------" << "\n";
	cout << "-----------square--------------------" << "\n";
	cout << "chose section:" << "\n";
}


void Complex::addition_meaning_interface() const
{
	cout << "----------addition interface-------------" << "\n";
	cout << "meanings" << "\n";
	cout << "rules" << "\n";
	cout << "range" << "\n";
	cout << "enter two complex numbers:" << "\n";
}
void Complex::multiplication_meaning_interface() const
{
	cout << "----------multiplication interface-------------" << "\n";
	cout << "meanings" << "\n";
	cout << "rules" << "\n";
	cout << "range" << "\n";
	cout << "enter two complex numbers:" << "\n";
}
void Complex::division_meaning_interface() const
{
	cout << "---------division interface-------------" << "\n";
	cout << "meanings" << "\n";
	cout << "rules" << "\n";
	cout << "range" << "\n";
	cout << "enter two complex numbers:" << "\n";
}
void Complex::square_meaning_interface() const
{
	cout << "----------square interface-------------" << "\n";
	cout << "meanings" << "\n";
	cout << "rules" << "\n";
	cout << "range" << "\n";
	cout << "enter complex number:" << "\n";
}



void Complex::wrong_command() const
{
	cout << "wrong command\n";
}

void commands::wrong_cmd() const
{
	cout << "wrong command" << "\n";
}