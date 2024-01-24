#pragma once


class commands
{
private:
	//commands dictionary
	struct cmd_dict
	{
		string key;
		int value;
	};
	enum consts { compute_size = 2, start_size = 5, prime_size = 5, matrix_size = 5, complex_size = 6};

	//dictionaries
	cmd_dict start_dict[start_size];
	cmd_dict* compute_dict;
	cmd_dict* complex_dict;
	cmd_dict* matrix_dict;
	cmd_dict* prime_dict;

	//constructor - destructor control
	int active_section;
	enum sections { start = 0, compute = 1, complex = 2, matrix = 3, prime = 4 };

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
		case compute:
		{
			active_section = compute;

			compute_dict = new cmd_dict[compute_size];
			compute_dict[0] = { "stop", 0 };
			compute_dict[1] = { "back", 1 };
			break;
		}
		case complex:
		{
			active_section = complex;

			complex_dict = new cmd_dict[complex_size];
			complex_dict[0] = { "stop", 0 };
			complex_dict[1] = { "back", 1 };
			complex_dict[2] = { "add", 2 };
			complex_dict[3] = { "mult", 3 };
			complex_dict[4] = { "div", 4 };
			complex_dict[5] = { "sqrt", 5 };
			break;
		}
		case matrix:
		{
			active_section = matrix;

			matrix_dict = new cmd_dict[matrix_size];
			matrix_dict[0] = { "stop", 0 };
			matrix_dict[1] = { "back", 1 };
			matrix_dict[2] = { "mult", 2 };
			matrix_dict[3] = { "det",  3 };
			matrix_dict[4] = { "rev",  4 };
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
			break;
		}
		}
	}



	//functions
public:
	int identify(string entered_command)//identify command
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
			return -1;
			break;
		}
		case compute:
		{
			for (int i = 0; i < compute_size; ++i)
			{
				if (entered_command == compute_dict[i].key)
					return compute_dict[i].value;
			}
			return -1;
			break;
		}
		case complex:
		{
			for (int i = 0; i < complex_size; ++i)
			{
				if (entered_command == complex_dict[i].key)
					return complex_dict[i].value;
			}
			return -1;
			break;
		}
		
		case matrix:
		{
			for (int i = 0; i < matrix_size; ++i)
			{
				if (entered_command == matrix_dict[i].key)
					return matrix_dict[i].value;
			}
			return -1;
			break;
		}
		case prime:
		{
			for (int i = 0; i < prime_size; ++i)
			{
				if (entered_command == prime_dict[i].key)
					return prime_dict[i].value;
			}
			return -1;
			break;
		}
		}
	}



public:

	~commands()
	{
		//free memory
		switch (active_section)
		{
		case compute:
			delete[] compute_dict;
			break;
		case complex:
			delete[] compute_dict;
			break;
		case matrix:
			delete[] matrix_dict;
			break;
		case prime:
			delete[] prime_dict;
			break;
		}
	}
};