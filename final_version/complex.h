#pragma once
#include "ReversPolishNotation.h"
#include "commands.h"

class Complex
{
private:
	enum complex_cmds { stop = 0, back = 1, cls = 2, this_secetion = 2};
	commands cmds;
	calculator cmpt;

public:
	Complex() : cmds(this_secetion) {}
	void work(bool& st)
	{
		bool back = true;
		bool& bk = back;
		complex_interface();
		while (st && bk)
		{
			complex(st, bk);
		}
	}

	//logic
private:

	void complex(bool& st, bool& bk)
	{
		string entered_command = "";
		getline(cin, entered_command);


		for (int i = 0; i < entered_command.length(); ++i)
			entered_command[i] = tolower(entered_command[i]);

		int chosen_command = cmds.identify(entered_command);

		switch (chosen_command)
		{
		case stop:
			cout << "----------stop-----------" << "\n";
			st = false;
			break;
		case back:
			system("cls");
			bk = false;
			break;
		case cls:
			system("cls");
			complex_interface();
			break;
		default:
			complex_implementation(entered_command);
			break;
		}
	}

//implementations
private:
	void complex_implementation(string entered_expression)
	{
		cout << "Result: " << cmpt.Solve(entered_expression) << "\n\n";
	}


private:

	//interfaces
	//complex start interface
	void complex_interface() const
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

	//void wrong_command() const;

	//wrong
	void wrong_command() const
	{
		cout << "-------------------[ wrong commands ]-----------------" << "\n";
	}
};