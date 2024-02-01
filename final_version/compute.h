#pragma once

#include "commands.h"
#include "compute_impl.h"

class Compute
{
private:
	enum compute_cmds { stop = 0, back = 1, cls = 2, this_secetion = 1 };
	commands cmds;
	Compute_impl cmp_impl;
	

public:
	Compute() : cmds(this_secetion) {}
	void work(bool& st)
	{
		bool back = true;
		bool& bk = back;
		compute_meaning_interface();
		while (st && bk)
		{
			compute(st, bk);
		}
	}

private:
	//meaning iterface
	void compute(bool& st, bool& bk)
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
			compute_meaning_interface();
			break;
		default:
			compute_implementation(entered_command);
			break;
		}
	}

	void compute_implementation(string entered_expression)
	{
		cmp_impl.do_compute(entered_expression);
	}


	void compute_meaning_interface() const
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
		cout << "----{ * trig: sin cos tan ctg use with p (pi)    }----" << "\n";
		cout << "-------------[ the range of input values: ]-----------" << "\n";
		cout << "-------------{    3.4e-4932..3.4e+4932    }-----------" << "\n";
		cout << "------------[ info: '~' or 'back' for back ]----------" << "\n";
		cout << "------------[       '0' or 'stop' for off  ]----------" << "\n";
		cout << "------------[ enter expression to compute: ]----------" << "\n";
	}
};




