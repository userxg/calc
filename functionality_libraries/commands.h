#pragma once
//#include <iostream>


class commands
{
private:
	//commands dictionary
	struct cmd_dict
	{
		string key;
		int value;
	};
	enum consts { start_size = 5, prime_size = 5, matrix_size = 5 };

	//dictionaries
	cmd_dict start_dict[start_size];
	cmd_dict* matrix_dict;
	cmd_dict* prime_dict;

	//constructor - destructor control
	int active_section;
	enum sections { start = 0, matrix = 3, prime = 4 };

public:
	commands()
	{
		active_section = start;
		//create start commands
		start_dict[0] = { "stop",     0 };
		start_dict[1] = { "compute",  1 };
		start_dict[2] = { "complex",  2 };
		start_dict[3] = { "matrix",   3 };
		start_dict[4] = { "primes",   4 };
	}

	commands(int section)
	{

		//create start commands
		start_dict[0] = { "stop",     0 };
		start_dict[1] = { "compute",  1 };
		start_dict[2] = { "complex",  2 };
		start_dict[3] = { "matrix",   3 };
		start_dict[4] = { "primes",   4 };

		//create target dictionary
		switch (section)
		{
		case matrix:
		{
			active_section = matrix;

			matrix_dict = new cmd_dict[matrix_size];
			matrix_dict[0] = { "stop", 0 };
			matrix_dict[1] = { "back", 1 };
			matrix_dict[2] = { "mult", 2 };
			matrix_dict[3] = { "det",  3 };
			matrix_dict[4] = { "rev",  4 };
			cout << "matrix\n";
			break;
		}
		case prime:
		{
			active_section = prime;

			prime_dict = new cmd_dict[prime_size];
			prime_dict[0] = { "stop",   0 };
			prime_dict[1] = { "back",   1 };
			prime_dict[2] = { "gcd",    2 };
			prime_dict[3] = { "lcm",    3 };
			prime_dict[4] = { "rabin",  4 };
			cout << "prime\n";
			break;
		}
		}
	}



	//functions
public:
	int identify(string entered_command)
	{
		switch (active_section)
		{
		case start:
		{
			for (int i = 0; i < start_size; ++i)
			{
				if (entered_command == start_dict[i].key)
					return start_dict[i].value;
			}
		}
		case matrix:
		{
			for (int i = 0; i < matrix_size; ++i)
			{
				if (entered_command == matrix_dict[i].key)
					return matrix_dict[i].value;
			}
		}
		case prime:
		{
			for (int i = 0; i < prime_size; ++i)
			{
				if (entered_command == prime_dict[i].key)
					return prime_dict[i].value;
			}
		}
		default:
			return -1;
		}
	}



public:

	~commands()
	{
		//free memory
		switch (active_section)
		{
		case matrix:
			delete[] matrix_dict;
			break;
		case prime:
			delete[] prime_dict;
			break;
		}
	}
};