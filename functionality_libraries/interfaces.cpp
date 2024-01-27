#include <iostream>
#include <string>
using namespace std;
#include "calculator.h"


//all interfaces

//start interfaces

void Calculator::start_interface() const
{
	cout << "----------------[ interface ]----------------" << "\n";
	cout << "----[ enter figure for chosing section ]-----\n"
		<< "----------------{ 1 compute }----------------\n"
		<< "----------------{ 2 complex }----------------\n"
		<< "----------------{ 3 matrix  }----------------\n"
		<< "----[ enter stop to turn off calculator ]----\n"
		<< "\n\n";
}

void Calculator::wrong_cmd() const
{
	cout << "-------------[ wrong commands ]--------------" << "\n";
}




/// all compute interfaces
void Compute::compute_meaning_interface() const
{
	cout << "------------[ compute interface ]------------" << "\n";
	cout << "----------------{ meanings }-----------------" << "\n";
	cout << "----------------{  rules   }-----------------" << "\n";
	cout << "----------------{  range   }-----------------" << "\n";
	cout << "------[ enter expression to compute: ]-------" << "\n";

}


//all complex interfaces
// 
//complex start interface
void Complex::complex_interface() const
{
	cout << "------------[ complex interface ]------------" << "\n";
	cout << "---------{    1 add - addtitoin    }---------" << "\n";
	cout << "---------{ 2 mult - multiplication }---------" << "\n";
	cout << "---------{    3 div - division     }---------" << "\n";
	cout << "---------{    4  sqrt - square     }---------" << "\n";
	cout << "-----------[ somerules and info ]------------" << "\n";
	cout << "-------------[ chose section: ]--------------" << "\n";
}

void Complex::wrong_command() const
{
	cout << "-------------[ wrong commands ]--------------" << "\n";
}




//commans (located insede calculator)
void Matrix::matrix_interface() const
{
	cout << "------------[ matrix interface ]-------------" << "\n";
	cout << "-------{    1 - det - determinant    }-------" << "\n";
	cout << "-------{      2 - rev - reverse      }-------" << "\n";
	cout << "-------{     3 - add - addtitoin     }-------" << "\n";
	cout << "-------{  4 - mult - multiplication  }-------" << "\n";
	cout << "-----------[ somerules and info ]------------" << "\n";
	cout << "--------------[ chose section: ]-------------" << "\n";
}

void Matrix::wrong_command() const
{
	cout << "-------------[ wrong commands ]--------------" << "\n";
}