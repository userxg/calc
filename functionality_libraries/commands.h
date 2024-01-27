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
	enum sizes { compute_size = 2, start_size = 5, prime_size = 5, matrix_size = 5, complex_size = 6};
	enum cmds { stop = 0, back = 1, cls = 2, go = 3};
	
	//dictionaries
	cmd_dict* start_dict;
	cmd_dict* compute_dict;
	cmd_dict* complex_dict;
	cmd_dict* matrix_dict;
	cmd_dict* prime_dict;

	//constructor - destructor control
	int active_section;
	enum sections { start = 0, compute = 1, complex = 2, matrix = 3, inside_matrix = 103};


public:
	commands()
	{
		start_dict = new cmd_dict[start_size];
		active_section = start;
		//create start commands
		start_dict[0] = { "stop",     0 };
		start_dict[1] = { "compute",  101 };
		start_dict[2] = { "complex",  102 };
		start_dict[3] = { "matrix",   103 };
		start_dict[4] = { "primes",   104 };
	}

	commands(int section)
	{


		//create target dictionary
		switch (section)
		{
		case compute:
		{
			active_section = compute;
			break;
		}
		case complex:
		{
			active_section = complex;

			complex_dict = new cmd_dict[complex_size];
			complex_dict[0] = { "stop", 0 };
			complex_dict[1] = { "add", 101 };
			complex_dict[2] = { "mult", 102 };
			complex_dict[3] = { "div", 103 };
			complex_dict[4] = { "sqrt", 104 };
			break;
		}
		case matrix:
		{
			active_section = matrix;

			matrix_dict = new cmd_dict[matrix_size];
			matrix_dict[0] = { "stop", 0 };
			matrix_dict[1] = { "det", 101 };
			matrix_dict[2] = { "rev",  102 };
			matrix_dict[3] = { "add",  103 };
			matrix_dict[4] = { "mult",  104 };
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
				if (entered_command == start_dict[i].key || entered_command == to_string((start_dict[i].value) % 10))
					return start_dict[i].value;
			}
			if (entered_command == "cls") return cls;
			return -1;
			break;
		}
		case compute:
		{
			if (entered_command == "0" || entered_command == "stop") return stop;
			if (entered_command == "~" || entered_command == "back") return back;
			if (entered_command == "cls") return cls;
			return -1;
			break;
		}
		case complex:
		{
			for (int i = 0; i < complex_size; ++i)
			{

				if (entered_command == complex_dict[i].key || entered_command == to_string((complex_dict[i].value) % 10))
					return complex_dict[i].value;
			}
			if (entered_command == "~" || entered_command == "back") return back;
			if (entered_command == "cls") return cls;
			return -1;
			break;
		}

		case matrix:
		{
			for (int i = 0; i < matrix_size; ++i)
			{
				if (entered_command == matrix_dict[i].key || entered_command == to_string((matrix_dict[i].value) % 10))
					return matrix_dict[i].value;
			}

			if (entered_command == "~" || entered_command == "back") return back;
			if (entered_command == "cls") return cls;
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
		case start:
			delete[] start_dict;
		case complex:
			delete[] compute_dict;
			break;
		case matrix:
			delete[] matrix_dict;
			break;
		/*case prime:
			delete[] prime_dict;
			break;*/
		}
	}
};