#include <iostream>
#include <string>
using namespace std;
#include "commands.h"
#include "complex.h"
#define DEBUG


#ifdef DEBUG

class Compute
{
private:
	enum compute_cmds { stop = 0, back = 1, this_secetion = 1};
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





class Calculator
{
private:
	enum cmds_consts { stop = 0, compute = 1, complex = 2, matrix = 3, prime = 4 };
	commands cmds;

	//sections
	Compute cmpt;
	Complex cmplx;
	/*Matrix mrx;
	Prime prm;*/

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




int main()
{
	bool stop = true;
	bool& st = stop;
	Calculator calc;

	while (st)
	{
		calc.work(st);
	}
}
#endif // DEBUG



#ifdef TEST


int main()
{

	return 0;
}
#endif // DEBUG



