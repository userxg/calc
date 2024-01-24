#include <iostream>
#include <string>

using namespace std;

#include "commands.h"

#include "complex.h"
#include "compute.h"

#include "calculator.h"

#define MAIN


#ifdef MAIN

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
#endif 



#ifdef TEST


int main()
{

	return 0;
}
#endif // DEBUG



