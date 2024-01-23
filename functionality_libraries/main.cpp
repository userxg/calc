#include <iostream>

using namespace std;
#include "commands.h"


class calculator
{
public:
	enum cmds_consts { stop = 0, compute = 1, complex = 2, matrix = 3, prime = 4 };

	void work(bool& st)
	{
		//iterface function
		cout << "--------------interface-------------" << "\n";
		cout << "enter figure for chosing section\n"
			<< "1 -------- compute ----------------------\n"
			<< "2 -------- complex----------------------\n"
			<< "3 -------- matrix ----------------------\n"
			<< "4 -------- primes ----------------------\n"
			<< "enter stop to turn off calculator\n"
			<< "\n\n";
		

		//porcess command
		string entered_command = "";
		std::cin >> entered_command;

		for (int i = 0; i < entered_command.length(); ++i)
			entered_command[i] = tolower(entered_command[i]);

		int chosen_command = cmds.identify(entered_command);

		switch (chosen_command)
		{
		case stop:
			cout << "----------stop-----------" << "\n";
			st = 0;
			break;
		case compute:
			cout << "compute" << "\n\n";
			break;
		case complex:
			cout << "complex" << "\n\n";
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
	commands cmds;
};

#define DEBUG


#ifdef DEBUG

int main()
{
	bool stop = 1;
	bool& st = stop;
	calculator calc;

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



