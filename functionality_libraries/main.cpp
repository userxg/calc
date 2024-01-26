#include <iostream>
#include <string>

using namespace std;

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



#ifdef TEST


int main()
{

	return 0;
}
#endif // DEBUG



