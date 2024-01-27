#pragma once
#include "commands.h"
#include <iostream>
#include <vector>
#include <matrix_func.h>
using namespace std;




class Matrix
{
private:
	enum complex_cmds { stop = 0, back = 1, cls = 2, this_secetion = 3, det = 101, rev = 102, add = 103, mult = 104 };
	commands cmds;

public:
	Matrix() : cmds(this_secetion) {}
	void work(bool& st)
	{
		bool back = true;
		bool& bk = back;
		matrix_interface();
		while (st && bk)
		{
			matrix(st, bk);
		}
	}

private:

	void matrix(bool& st, bool& bk)
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
			system("cls");
			bk = false;
			break;
		case cls:
			system("cls");
			matrix_interface();
			break;
		case det:
			determinant();
			break;
		case rev:
			reverse();
			break;
		case add:
			addition();
			break;
		case mult:
			multiplication();
			break;
		default:
			wrong_command();
			break;
		}
	}


	void determinant()
	{
		double determinant(const vector<vector<double>>& matrix);

		cout << "determinant implementation" << "\n\n";
	}

	void reverse()
	{
		vector<vector<double>> inverseMatrix(const vector<vector<double>>& matrix);
		cout << "reverse matrix implementation" << "\n\n";
	}

	void addition()
	{
		vector<vector<double>> addMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
		cout << "mat + mat implementation" << "\n\n";
	}

	void multiplication()
	{
		vector<vector<double>> multiplyMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {

		cout << "mat * mat implementation" << "\n\n";

	}


private:

	//interfaces
	//complex start interface
	void matrix_interface() const;

	//wrong
	void wrong_command() const;
};