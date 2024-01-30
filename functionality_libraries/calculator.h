#pragma once
#include "commands.h"

#include "compute.h"
#include "complex.h"
#include "matrix.h"

class Calculator
{
private:
	enum cmds_consts { stop = 0, cls = 2, compute = 101, complex = 102, matrix = 103 }; //prime = 104
	commands cmds;

	//sections
	Compute cmpt;
	Complex cmplx;
	Matrix mrx;
public:

	void work(bool& st)
	{
		//porcess command
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
		case cls:
			system("cls");
			start_interface();
			break;
		case compute:
			system("cls");
			cmpt.work(st);
			start_interface();
			break;
		case complex:
			system("cls");
			cmplx.work(st);
			start_interface();
			break;
		case matrix:
			system("cls");
			mrx.work(st);
			start_interface();
			break;
		//case matrix:

		/*case prime:
			cout << "prime" << "\n\n";
			break;*/
		default:
			system("cls");
			start_interface();
			wrong_cmd();
			break;
		}
	}

public:
	void start_interface() const;

private:
	void wrong_cmd() const;
	
};

