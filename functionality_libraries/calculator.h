#pragma once
class Calculator
{
private:
	enum cmds_consts { stop = 0, compute = 1, complex = 2, matrix = 3, prime = 4 };
	commands cmds;

	//sections
	Compute cmpt;
	Complex cmplx;

public:

	void work(bool& st)
	{
		//iterface function
		start_interface();

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
		case compute:
			cmpt.work(st);
			break;
		case complex:
			cmplx.work(st);
			break;
		case prime:
			cout << "prime" << "\n\n";
			break;
		default:
			cout << "wrong cmd" << "\n\n";
			break;
		}
	}

private:
	void start_interface() const
	{
		cout << "--------------interface-------------" << "\n";
		cout << "enter figure for chosing section\n"
			<< "1 -------- compute ----------------------\n"
			<< "2 -------- complex----------------------\n"
			<< "3 -------- matrix ----------------------\n"
			<< "4 -------- primes ----------------------\n"
			<< "enter stop to turn off calculator\n"
			<< "\n\n";
	}
};