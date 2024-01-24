#pragma once

class Compute
{
private:
	enum compute_cmds { stop = 0, back = 1, this_secetion = 1 };
	commands cmds;

public:
	Compute() : cmds(this_secetion) {}
	void work(bool& st)
	{
		bool back = true;
		bool& bk = back;
		while (st && bk)
		{
			compute_meaning_interface();
			compute(st, bk);
		}
	}

private:
	//meaning iterface
	void compute_meaning_interface() const
	{
		cout << "----------compute interface-------------" << "\n";
		cout << "meanings" << "\n";
		cout << "rules" << "\n";
		cout << "range" << "\n";
		cout << "enter expression to compute:" << "\n";
	}

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
			cout << "----------back-----------" << "\n\n";
			bk = false;
			break;
		default:
			compute_implementation(entered_command);
			break;
		}
	}

	void compute_implementation(string entered_expression)
	{
		cout << "2 + 2 = " << entered_expression << "\n\n";
	}
};

