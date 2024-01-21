#pragma once

typedef long double ld;
typedef long long int lli;

#define _TERMS_IN_SUM_ 731
#define _FUNCTION_NAME_ARRAY_SIZE_ 4

class MathFunctions {
public:
	ld const_pi = cal_const_pi();
	ld const_e = cal_const_e();

	/*
	Массивы с именами функций и соотв. им приорететам
	Для удобного использования в "ReversPolishNotaion.h" все данные хранятся в HashMap. (подробнее в "ReversPolishNotaion.h")
	*/

	const string FunctionNames[_FUNCTION_NAME_ARRAY_SIZE_] = { "Add","Sub","Mul","Div" };
	const int FunctionValue[_FUNCTION_NAME_ARRAY_SIZE_] = { 1,1,2,2 };

	//Подсчет-функции
public:
	vec2 Addition(const vec2 num1,const vec2 num2) {
		vec2 Answer;
		Answer.real = num1.real + num2.real;
		Answer.imagine = num1.imagine + num2.imagine;
		return Answer;
	}

	vec2 Subtraction(const vec2 num1, const vec2 num2) {
		vec2 Answer;
		Answer.real = num1.real - num2.real;
		Answer.imagine = num1.imagine - num2.imagine;
		return Answer;
	}

	vec2 Multiplacation(const vec2 num1, const vec2 num2) {
		vec2 Answer;
		Answer.real = num1.real * num2.real - num1.imagine * num2.imagine;
		Answer.imagine = num1.real * num2.real + num1.imagine * num2.imagine;
		return Answer;
	}

	vec2 Division(const vec2 num1, const vec2 num2) {
		vec2 Answer;
		Answer.real = (num1.real * num2.real + num1.imagine * num2.imagine)/(num2.real* num2.real+ num2.imagine * num2.imagine);
		Answer.imagine = (num2.real*num1.imagine-num1.real*num2.imagine)/(num2.real * num2.real + num2.imagine * num2.imagine);
		return Answer;
	}

	/*
	Функции, НЕ работающие с vec2
	Являются вспомогательными
	*/
private:
	lli Fuctorial(lli num) {
		lli Answer = 1;
		while (num-- > 1) {
			Answer *= num;
		}
		return Answer;
	}

	ld cal_const_pi() {
		ld pi = 3.0;
		int sign = 1;

		for (int i = 2; i <= _TERMS_IN_SUM_; i += 2) {

			pi += sign * (ld)4 / (i * (i + 1) * (i + 2));;
			sign *= -1;
		}

		return pi;
	}

	ld cal_const_e() {
		ld e = 1;

		for (int i = 2; i <= _TERMS_IN_SUM_ - 700; i++) {
			e += (ld)1 / Fuctorial(i);
		}
		return e;
	}
};