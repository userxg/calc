#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long double ld;
#include "calculator.h"


//all interfaces

//start interfaces

void Calculator::start_interface() const
{
	cout << "---------------------[ interface ]--------------------" << "\n";
	cout << "--[ to choose a section, enter a figure or a title ]--" << "\n";
	cout << "---------------------{ 1 compute }--------------------" << "\n";
	cout << "---------------------{ 2 complex }--------------------" << "\n";
	cout << "---------------------{ 3 matrix  }--------------------" << "\n";
	cout << "------------[ info: '0' or 'stop' for off  ]----------" << "\n";
	cout << "-------------------[ chose section: ]-----------------" << "\n";
	cout << "\n";
}

void Calculator::wrong_cmd() const
{
	cout << "-------------------[ wrong commands ]-----------------" << "\n";
}




/// all compute interfaces
void Compute::compute_meaning_interface() const
{
	cout << "-----------------[ compute interface ]----------------" << "\n";
	cout << "---------------------[ meaning: ]---------------------" << "\n";
	cout << "----{   You can enter a single-line arithmetic   }----" << "\n";
	cout << "----{        expression and get the result       }----" << "\n";
	cout << "---------------------[  rules:  ]---------------------" << "\n";
	cout << "----{ * The divisor cannot be equal to 0;        }----" << "\n";
	cout << "----{ * The value of the square root cannot      }----" << "\n";
	cout << "----{   be negative;                             }----" << "\n";
	cout << "----{ * Logarithm base can only be positive      }----" << "\n";
	cout << "----{   and not equal to 1;                      }----" << "\n";
	cout << "----{ * Sub-logarithmic expression cannot be 0;  }----" << "\n";
	cout << "-------------[ the range of input values: ]-----------" << "\n";
	cout << "-------------{    3.4e-4932..3.4e+4932    }-----------" << "\n";
	cout << "------------[ info: '~' or 'back' for back ]----------" << "\n";
	cout << "------------[       '0' or 'stop' for off  ]----------" << "\n";
	cout << "------------[ enter expression to compute: ]----------" << "\n";
}


//all complex interfaces
// 
//complex start interface
void Complex::complex_interface() const
{
	cout << "-----------------[ complex interface ]----------------" << "\n";
	cout << "---------------------[ meaning: ]---------------------" << "\n";
	cout << "----{     You can enter a single-line complex    }----" << "\n";
	cout << "----{  arithmetic expression and get the result  }----" << "\n";
	cout << "---------------------[ WARNING! ]---------------------" << "\n";
	cout << "--------{ Entering an incorrect string may  }---------" << "\n";
	cout << "--------{    cause the program to crash.    }---------" << "\n";
	cout << "---------------------[  rules: ]----------------------" << "\n";
	cout << "----{ * The divisor cannot be equal to 0;        }----" << "\n";
	cout << "----{ * Logarithm base cannot equal to 1;        }----" << "\n";
	cout << "----{ * Sub-logarithmic expression cannot be 0;  }----" << "\n";
	cout << "-------------[ the range of input values: ]-----------" << "\n";
	cout << "-------------{    3.4e-4932..3.4e+4932    }-----------" << "\n";
	cout << "------------[ info: '~' or 'back' for back ]----------" << "\n";
	cout << "------------[       '0' or 'stop' for off  ]----------" << "\n";
	cout << "------------[ enter expression to compute: ]----------" << "\n";
}

void Complex::wrong_command() const
{
	cout << "-------------------[ wrong commands ]-----------------" << "\n";
}




//commans (located insede calculator)
void Matrix::matrix_interface() const
{
	cout << "-----------------[ matrix interface ]-----------------" << "\n";
	cout << "--[ to choose a section, enter a figure or a title ]--" << "\n";
	cout << "------------{    1 - det - determinant    }-----------" << "\n";
	cout << "------------{      2 - rev - reverse      }-----------" << "\n";
	cout << "------------{     3 - add - addtitoin     }-----------" << "\n";
	cout << "------------{  4 - mult - multiplication  }-----------" << "\n";
	cout << "--------------------[  rules:  ]----------------------" << "\n";
	cout << "----{ * The dimension of the entered matrix      }----" << "\n";
	cout << "----{   cannot be more than 3x3;                 }----" << "\n";
	cout << "----{ * To add matrices, the entered matrices    }----" << "\n";
	cout << "----{   must be of the same dimension;           }----" << "\n";
	cout << "----{ * The determinant can only be found for a  }----" << "\n";
	cout << "----{   square matrix;                           }----" << "\n";
	cout << "----{ * The reverse matrix can only be found for }----" << "\n";
	cout << "----{   a square matrix with a determinant not   }----" << "\n";
	cout << "----{   equal to 0;                              }----" << "\n";
	cout << "----{ * To multiplication matrices, the          }----" << "\n";
	cout << "----{   dimensions of the matrices must have the }----" << "\n";
	cout << "----{   form dim(A)=n x m and dim(B)=m x p;      }----" << "\n";
	cout << "-------------[ the range of input values: ]-----------" << "\n";
	cout << "-------------{    3.4e-4932..3.4e+4932    }-----------" << "\n";
	cout << "------------[ info: '~' or 'back' for back ]----------" << "\n";
	cout << "------------[       '0' or 'stop' for off  ]----------" << "\n";
	cout << "-------------------[ chose section: ]-----------------" << "\n";
}

void Matrix::wrong_command() const
{
	cout << "-------------------[ wrong commands ]-----------------" << "\n";
}
