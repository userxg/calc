#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long double ld;

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
}
#endif 


