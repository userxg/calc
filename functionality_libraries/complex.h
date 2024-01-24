#pragma once
class Complex
{
private:
	enum complex_cmds { stop = 0, back = 1, this_secetion = 2, add = 2, mult = 3, div = 4, sqrt = 5 };
	commands cmds;

public:
	Complex() : cmds(this_secetion) {}
	void work(bool& st)
	{
		bool back = true;
		bool& bk = back;
		while (st && bk)
		{
			complex_interface();
			complex(st, bk);
		}
	}

	//logic
private:

	void complex(bool& st, bool& bk)
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
		case add:
			addition();
			break;
		case mult:
			multiplication();
			break;
		case div:
			division();
		case sqrt:
			square();
			break;
		default:
			wrong_command();
			break;
		}
	}

	void addition()
	{
		addition_meaning_interface();
		cout << "vect1 + vect2" << "\n\n";
	}

	void multiplication()
	{
		multiplication_meaning_interface();
		cout << "vect1 * vect2" << "\n\n";

	}

	void division()
	{
		division_meaning_interface();
		cout << "vect1 / vect2" << "\n\n";
	}

	void square()
	{
		square_meaning_interface();
		cout << "vect1" << "\n\n";
	}


	//appearance
private:
	void complex_interface() const
	{
		cout << "----------complex interface-------------" << "\n";
		cout << "-----------addtitoin--------------------" << "\n";
		cout << "-----------multiplication--------------------" << "\n";
		cout << "-----------division--------------------" << "\n";
		cout << "-----------square--------------------" << "\n";
		cout << "chose section:" << "\n";
	}


	void addition_meaning_interface()
	{
		cout << "----------addition interface-------------" << "\n";
		cout << "meanings" << "\n";
		cout << "rules" << "\n";
		cout << "range" << "\n";
		cout << "enter two complex numbers:" << "\n";
	}
	void multiplication_meaning_interface()
	{
		cout << "----------multiplication interface-------------" << "\n";
		cout << "meanings" << "\n";
		cout << "rules" << "\n";
		cout << "range" << "\n";
		cout << "enter two complex numbers:" << "\n";
	}
	void division_meaning_interface()
	{
		cout << "---------division interface-------------" << "\n";
		cout << "meanings" << "\n";
		cout << "rules" << "\n";
		cout << "range" << "\n";
		cout << "enter two complex numbers:" << "\n";
	}
	void square_meaning_interface()
	{
		cout << "----------square interface-------------" << "\n";
		cout << "meanings" << "\n";
		cout << "rules" << "\n";
		cout << "range" << "\n";
		cout << "enter complex number:" << "\n";
	}



	void wrong_command() const
	{
		cout << "wrong command\n";
	}
};