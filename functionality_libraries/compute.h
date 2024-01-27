#pragma once
#include "commands.h"

class Compute
{
private:
	enum compute_cmds { stop = 0, back = 1, cls = 2, this_secetion = 1 };
	commands cmds;

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
	void compute_meaning_interface() const;
	

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

		cout << entered_expression << " = something ûגאûגא" <<"\n";
		//cout << "press any key to go on" << "\n";
	}
};




