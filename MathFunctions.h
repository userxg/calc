#pragma once

#ifndef _MATH_FUNCTIONS_
#define _MATH_FUNCTIONS_

#include "vec2.h"

typedef long double ld;
typedef long long int lli;

#define _APPROXIMATION_ 1e-15
#define _TERMS_IN_SUM_ 31

/*
Fucntions List:

const_e
const_pi

Fuctorial
Double fuctorial
power (Natural)
sqrt
exponent
LambertW

sin, cos, tg, ctg, sec, cosec
arcsin, arccos,arctg,arcctg

sh, ch, th, cth, sch, csch
*/

//General and const

lli fuct_vec2(lli num) {
	lli Answer = num;
	while (num-- > 1) {
		Answer *= num;
	}
	return Answer;
}

lli dfuct_vec2(lli num) {
	lli Answer = 1;
	while (num > 1) {
		Answer *= num;
		num -= 2;
	}
	return Answer;
}

vec2 power_vec2(const vec2& base, lli power) {
	if (power == 0)
		return vec2(1);

	vec2 p = power_vec2(base, power / 2);
	p = p * p;

	return (power % 2 == 0) ? p : base * p;
}

ld const_e() {
	ld e = 1;

	for (int i = 2; i <= _TERMS_IN_SUM_; i++) {
		e += (ld)1 / fuct_vec2(i);
	}
	return e;
}

vec2 exp_vec2(const vec2& num) {
	vec2 res = num + 1;

	int n = 2;
	vec2 term;
	do {
		term = power_vec2(num, n) / fuct_vec2(n);
		res += term;
		n++;
	} while (n < _TERMS_IN_SUM_);

	return res;
}

vec2 ln_vec2(const vec2& num) {
	
	vec2 res = num;

	int sign = -1;
	int n = 2;
	vec2 term;
	do {
		term = power_vec2(num,n)/ n;
		res += term*sign;
		sign *= -1;
		n++;
	} while (n < _TERMS_IN_SUM_);

	return res;
}

ld const_pi() {
	ld pi = 3.0;
	int sign = 1;

	for (int i = 2; i <= _TERMS_IN_SUM_; i += 2) {

		pi += sign * (ld)4 / (i * (i + 1) * (i + 2));;
		sign *= -1;
	}

	return pi;
}

vec2 sqrt_vec2(const vec2& num) {
	vec2 x = num / 2;
	for (int i = 0; i < _TERMS_IN_SUM_; i++) {
		x = (x + num / x);
		x = x * .5;
	}
	return x;
}

vec2 W_vec2(const vec2& num) {
	vec2 res = num-num*num;
	int n = 3;
	int sign = 1;

	vec2 term;
	do {
		term = (power_vec2(-n, n - 1) / fuct_vec2(n))* power_vec2(num, n);
		sign *= -1;
		n++;
	} while (n < _TERMS_IN_SUM_);

	return res;
}

//Trinometry
vec2 sin_vec2(const vec2& num) {
	vec2 res = num;
	int sign = -1;
	int n = 3;

	vec2 term;
	do {
		term = power_vec2(num, n)/fuct_vec2(n);
		res+= term * sign;
		sign *= -1;
		n += 2;
	} while (n< _TERMS_IN_SUM_);

	return res;
}

vec2 cos_vec2(const vec2& num) {
	vec2 res = 1;
	int sign = -1;
	int n = 2;

	vec2 term;
	do {
		term = power_vec2(num, n) / fuct_vec2(n);
		res += term * sign;
		sign *= -1;
		n += 2;
	} while (n < _TERMS_IN_SUM_ );

	return res;
}

vec2 tg_vec2(const vec2& num) {
	return sin_vec2(num) / cos_vec2(num);
}

vec2 ctg_vec2(const vec2& num) {
	return cos_vec2(num) / sin_vec2(num);
}

vec2 sec_vec2(const vec2& num) {
	return vec2(1) / cos_vec2(num);
}

vec2 cosec_vec2(const vec2& num) {
	return vec2(1) / sin_vec2(num);
}

//Revers trigonometry

vec2 arcsin_vec2(const vec2& num) {
	vec2 res = num;
	int n = 3;

	vec2 term;
	do {
		term = (power_vec2(num, n)*dfuct_vec2(n))/(dfuct_vec2(n-1)*n*n);
		res += term;
		n += 2;
	} while (n < _TERMS_IN_SUM_);

	return res;
}

vec2 arccos_vec2(const vec2& num) {
	return -arcsin_vec2(num)+ const_pi() / 2;
}

vec2 arctg_vec2(const vec2& num) {
	vec2 res = num;
	int sign = -1;
	int n = 3;

	vec2 term;
	do {
		term = power_vec2(num, n) / n;
		res += term * sign;
		sign *= -1;
		n += 2;
	} while (n < _TERMS_IN_SUM_);

	return res;
}

vec2 arcctg_vec2(const vec2& num) {
	return -arctg_vec2(num) + const_pi() / 2;
}

//hyperbolic functions
vec2 sh_vec2(const vec2& num) {
	return (exp_vec2(num) - exp_vec2(-num)) / 2;
}
vec2 ch_vec2(const vec2& num) {
	return (exp_vec2(num) + exp_vec2(-num)) / 2;
}

vec2 th_vec2(const vec2& num) {
	return sh_vec2(num) / ch_vec2(num);
}

vec2 cth_vec2(const vec2& num) {
	return ch_vec2(num) / sh_vec2(num);
}

vec2 sch_vec2(const vec2& num) {
	return vec2(2) / (exp_vec2(num) + exp_vec2(-num));
}

vec2 csch_vec2(const vec2& num) {
	return vec2(2) / (exp_vec2(num) - exp_vec2(-num));
}

#endif