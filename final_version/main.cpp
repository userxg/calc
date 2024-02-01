#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
typedef long double ld;
typedef long long int lli;
#include "ReversPolishNotation.h"

#include "calculator.h"

#define MAIN


#ifdef MAIN

int main()
{
	bool stop = true;
	bool& st = stop;
	Calculator calc;

	

	calc.start_interface();
	while (st)
	{
		calc.work(st);
	}
	/*calculator cmpt;
	string test1 = "ser";
	while (test1 != "stop")
	{
		getline(cin, test1);
		cout <<"Result: " << cmpt.Solve(test1) << "\n\n";
	}*/
}
#endif 


