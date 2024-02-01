#pragma once
#include "Stack.h"


class Compute_impl
{
public:
	void do_compute(string entered_expression)
	{
		char symbol = 0;

		Stack<Leksema> numbers_st;
		Stack<Leksema> operations_st;


		string expression = entered_expression;
		//getline(cin, expression);


		int expression_length = expression.length();
		int index = 0;

		bool unar_minus = true;
		bool multi_number = false;
		bool wrong_expression = false;
		bool& wr = wrong_expression;
		Leksema elem;

		for (; index < expression_length;)
		{
			if (expression[index] == ' ')
			{
				index++;
				continue;
			}

			//read double numbers
			if (expression[index] >= '0' && expression[index] <= '9' || expression[index] == '.' || (expression[index] == '-' && unar_minus))
			{
				bool dot_error = true;
				int dot_count_error = 0;
				string tmp_number_s = "";
				ld tmp_numb = 0;
				elem.type = '0';

				while (expression[index] >= '0' && expression[index] <= '9' || expression[index] == '.' || (expression[index] == '-' && unar_minus))
				{
					tmp_number_s = tmp_number_s + expression[index];

					if (tmp_number_s[0] == '-' && unar_minus)
					{
						//check  -\n                                   5 + ( - 
						if (index == expression_length - 1)          //0 1 2 3    len = 4
						{
							cout << "error value\n";
							return;
							break;
						}
						else
						{
							if (expression[index + 1] == ' ')
							{
								index++;
								while (expression[index] == ' ' && (index < (expression_length - 1)))
									index++;
							}
							else { index++; }                  //| s s s - 5
							if (index == expression_length - 1 && multi_number)   //5 + ( - s s                        //5 + ( - s s 4               
							{                                                     //0 1 2 3 4 5     len = 6   or      //0 1 2 3 4 5  6
								cout << "error value\n";                          //          i                      //              i 
								return;
								break;
							}
							else
							{
								if (expression[index] >= '0' && expression[index] <= '9' || expression[index] == '.')
								{
									tmp_number_s = tmp_number_s + expression[index];
								}
								else
								{
									cout << "error value\n";
									return;
									break;
								}
							}
						}
					}

					//process dot error
					if (expression[index] != '.' && expression[index] != '-')
						dot_error = false;
					if (expression[index] == '.')
						dot_count_error++;

					index++;
					unar_minus = false;
				}

				//check correct dots in double value like 2.3.4 or just .
				if (dot_error || dot_count_error > 1)
				{
					cout << "error value\n";
					return;
					break;
				}

				//check numbers like  003 
				int num_len = tmp_number_s.length();
				if (num_len > 2 && tmp_number_s[0] == '-' && tmp_number_s[1] == '0' && (tmp_number_s[2] >= '0' && tmp_number_s[2] <= '9')
					|| (num_len > 1 && tmp_number_s[0] == '0' && (tmp_number_s[1] >= '0' && tmp_number_s[1] <= '9')))
				{
					cout << "error value\n";
					return;
					break;

				}



				stringstream convert;  //good way to convert
				convert << tmp_number_s;
				convert >> tmp_numb;

				elem.value = tmp_numb;
				numbers_st.push(elem);
				multi_number = true;
				continue;
				//cout << numbers_st.top().value << "\n";
				//unar_minus = false;
			}

			//simple ops
			if (expression[index] == '+' || expression[index] == '-' || expression[index] == '/' || expression[index] == '*' || expression[index] == '^')
			{
				string tmp_operation = "";
				tmp_operation = tmp_operation + expression[index];

				if (operations_st.isEmpty() || !operations_st.isEmpty() && priority(tmp_operation) > priority(operations_st.top().type))
				{
					elem.type = tmp_operation;
					elem.value = 0;
					operations_st.push(elem);

					index++;
					continue;
				}

				if (!operations_st.isEmpty() && priority(tmp_operation) <= priority(operations_st.top().type))
				{
					bool call_maths = Maths(numbers_st, operations_st, elem);
					if (!call_maths)
					{
						cout << "wrong expression\n";
						return;
					}
					continue;
				}
			}

			//trig
			if (expression[index] == 's' || expression[index] == 'c' || expression[index] == 't')
			{
				string tmp_operation = "";

				for (int i = index; (index < expression_length) && (index < i + 3); index++)
				{
					tmp_operation += expression[index];
				}

				if (tmp_operation == "sin")
				{
					elem.type = tmp_operation;
					elem.value = 0;
					operations_st.push(elem);

					continue;
				}
				if (tmp_operation == "cos")
				{
					elem.type = tmp_operation;
					elem.value = 0;
					operations_st.push(elem);

					continue;
				}
				if (tmp_operation == "tan")
				{
					elem.type = tmp_operation;
					elem.value = 0;
					operations_st.push(elem);

					continue;
				}
				if (tmp_operation == "ctg")
				{
					elem.type = tmp_operation;
					elem.value = 0;
					operations_st.push(elem);

					continue;
				}
				//cout << tmp_operation;
			}

			if (expression[index] == 'p')
			{
				elem.type = "0";
				elem.value = Pi;
				numbers_st.push(elem);
				index++;
				continue;
			}



			//brackets 
			if (expression[index] == '(')
			{
				string tmp_operation = "";
				tmp_operation = tmp_operation + expression[index];
				elem.type = tmp_operation;
				elem.value = 0;
				operations_st.push(elem);

				unar_minus = true;
				index++;
				continue;
			}

			if (expression[index] == ')')
			{

				while (!operations_st.isEmpty() && operations_st.top().type != "(")
				{
					bool call_maths = Maths(numbers_st, operations_st, elem);
					if (!call_maths)//SIMP
					{
						cout << "wrong expression\n";
						return;
					}
					else continue;
				}
				if (operations_st.isEmpty())
				{
					cout << "wrong expression\n";
					return;
				}
				operations_st.pop();
				index++;
				continue;
			}


			cout << "wrong expression\n";
			return;
			break;
		}

		//last elems
		while (!operations_st.isEmpty())
		{
			bool call_maths = Maths(numbers_st, operations_st, elem);
			if (!call_maths)
			{
				cout << "wrong expression\n";
				return;
			}
			else continue;
		}


		if (numbers_st.Size() != 1)
		{
			cout << "wrong expression\n";
			return;
		}
		ld result = numbers_st.top().value;
		cout << "Result: " << result << "\n\n";
	}



	//additional functions
private:
	struct Leksema
	{
		string type;   //zero for numbers,
		ld value;
	};

	enum opers { operatinos_size = 9, add = 100, sub, mult, divi, power, sine, cosine, tang, ctang };
	const ld Pi = acosl(-1);


	bool Maths(Stack<Leksema>& number_st, Stack<Leksema>& operation_st, Leksema& elem)
	{
		if (number_st.isEmpty()) return false;//check
		if (operation_st.isEmpty() || operation_st.top().type == "(") return false;//check

		ld num2 = number_st.top().value;
		number_st.pop();
		ld num1 = 0;
		ld result = 0;

		string op_str = operation_st.top().type;
		int operation = find_operation(op_str);
		switch (operation)
		{
		case add:
			if (number_st.isEmpty()) return false;
			num1 = number_st.top().value;
			number_st.pop();
			result = num1 + num2;
			break;
		case sub:
			if (number_st.isEmpty()) return false;
			num1 = number_st.top().value;
			number_st.pop();
			result = num1 - num2;
			break;
		case divi:
			if (number_st.isEmpty()) return false;
			if (!num2)
			{
				cerr << "Cannot divide by zero\n";
				return false;
			}
			num1 = number_st.top().value;
			number_st.pop();
			result = num1 / num2;
			break;
		case mult:
			if (number_st.isEmpty()) return false;
			num1 = number_st.top().value;
			number_st.pop();
			result = num1 * num2;
			break;

		case power:
			if (number_st.isEmpty()) return false;
			num1 = number_st.top().value;
			number_st.pop();
			result = pow(num1, num2);
			break;

		case sine:
			result = Sin(num2);
			break;
		case cosine:
			result = Cos(num2);
			break;
		case tang:
			if (Cos(num2) == 0)
			{
				cout << "tang doesn't exist\n";//tan rewrite
				return false;
			}
			result = Tan(num2);
			break;
		case ctang:
			if (Sin(num2) == 0)
			{
				cout << "ctang doesn't exist\n";//tan rewrite
				return false;
			}
			result = Ctg(num2);
			break;
		}

		elem.value = result;
		elem.type = '0';
		number_st.push(elem);
		operation_st.pop();
		return true;
	}

	int priority(const string& op) const
	{
		if (op == "+" || op == "-") return 1;
		if (op == "*" || op == "/") return 2;
		if (op == "^") return 3;
		if (op == "sin" || op == "cos" || op == "tan" || op == "ctg") return 4;
		else return 0;
	}



	int find_operation(const string& op) const
	{

		string ops[] = { "+", "-", "*", "/", "^", "sin", "cos", "tan", "ctg" };
		for (int i = 0; i < operatinos_size; ++i)
		{
			if (op == ops[i])
				return i + 100;
		}
	}


	ld Sin(const ld x) const
	{
		return (round(sinl(x) * 1000000000) / 1000000000);//round
	}

	ld Cos(const ld x) const
	{
		return (round(cosl(x) * 1000000000) / 1000000000);
	}

	ld Tan(const ld x) const
	{
		return (round(Sin(x) / Cos(x) * 1000000000) / 1000000000);
	}
	ld Ctg(const ld x) const
	{
		return (round(Cos(x) / Sin(x) * 10000000) / 10000000);
	}
};