#pragma once
#include "commands.h"

class Complex
{
private:
	enum complex_cmds { stop = 0, back = 1, cls = 2, this_secetion = 2, add = 101, mult = 102, div = 103, sqrt = 104 };
	commands cmds;

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
		case add:
			addition();
			break;
		case mult:
			multiplication();
			break;
		case div:
			division();
			break;
		case sqrt:
			square();
			break;
		default:
			wrong_command();
			break;
		}
	}

	void addition()
	{
		addition_meaning_interface();
		cout << "vect1 + vect2" << "\n\n";
	}

	void multiplication()
	{
		multiplication_meaning_interface();
		cout << "vect1 * vect2" << "\n\n";

	}

	void division()
	{
		division_meaning_interface();
		cout << "vect1 / vect2" << "\n\n";
	}

	void square()
	{
		square_meaning_interface();
		cout << "vect1" << "\n\n";
	}


	//appearance
private:

	//interfaces
	//complex start interface
	void complex_interface() const;

	//meaning interfaces
	void addition_meaning_interface() const;
	void multiplication_meaning_interface() const;
	void division_meaning_interface() const;
	void square_meaning_interface() const;

	//wrong
	void wrong_command() const;
};