#pragma once

#ifndef _MATH_FUNCTIONS_
#define _MATH_FUNCTIONS_

#include "vec2.h"

typedef long double ld;
typedef long long int lli;

#define _APPROXIMATION_ 1e-15
#define _TERMS_IN_SUM_ 31

// const_e const_pi ceil floor round rad fuct dfuct abs pow sqrt exp ln log W sin cos tg ctg sec cosec arcsin arccos arctg arcctg sh ch th cth sch csch P C

ld const_e();
ld const_pi();

vec2 ceil_vec2(const vec2& num, const ld& approximation);
vec2 floor_vec2(const vec2& num, const ld& approximation);
vec2 round_vec2(const vec2& num, const ld& approximation);

ld rad(const ld& num);
lli fuct_vec2(lli num);
lli dfuct_vec2(lli num);
vec2 abs_vec2(const vec2& num);
ld Pabs_vec2(const ld& num);

vec2 power_vec2(const vec2& base, lli power);
vec2 pow_vec2(const vec2& base, const vec2& power);
vec2 sqrt_vec2(const vec2& num);
vec2 exp_vec2(const vec2& num);
vec2 ln_vec2(const vec2& num);
vec2 log_vec2(const vec2& num, const vec2& num1);
vec2 W_vec2(const vec2& num);

vec2 sin_vec2(const vec2& num);
vec2 cos_vec2(const vec2& num);
vec2 tg_vec2(const vec2& num);
vec2 ctg_vec2(const vec2& num);
vec2 sec_vec2(const vec2& num);
vec2 cosec_vec2(const vec2& num);

vec2 arcsin_vec2(const vec2& num);
vec2 arccos_vec2(const vec2& num);
vec2 arctg_vec2(const vec2& num);
vec2 arcctg_vec2(const vec2& num);

vec2 sh_vec2(const vec2& num);
vec2 ch_vec2(const vec2& num);
vec2 th_vec2(const vec2& num);
vec2 cth_vec2(const vec2& num);
vec2 sch_vec2(const vec2& num);
vec2 csch_vec2(const vec2& num);

lli P_vec2(const lli& n, const lli& k);
lli C_vec2(const lli& n, const lli& k);

//Limits

//l_approximation  l_ln_vec2 l_log_vec2 l_W_vec2 l_arc_vec2 l_P_vec2 l_C_vec2
bool l_approximation(const ld& approximation);
bool l_ln_vec2(const vec2& num);
bool l_log_vec2(const vec2& base, const vec2& num);
bool l_W_vec2(const vec2& num);
bool l_arc_vec2(const vec2& num);
bool l_P_vec2(const lli& n, const lli& k);
bool l_C_vec2(const lli& n, const lli& k);
//General and const

vec2 trunc_vec2(const vec2& num) {
	vec2 res;
	res.r = (lli)num.r;
	res.i = (lli)num.i;
	return res;
}

vec2 rtrunc_vec2(const vec2& num) {
	vec2 res;
	res.r = Pabs_vec2(num.r)-Pabs_vec2((lli)num.r);
	res.i = Pabs_vec2(num.i)-Pabs_vec2((lli)num.i);
	return res;
}

int sign_vec2(const ld& num) {
	if (num > 0) {
		return 1;
	}
	else if (num == 0) {
		return 0;
	}
	return -1;
}

vec2 ceil_vec2(const vec2& num,const ld& approximation) {
	vec2 res(((lli)(num.r / approximation)+1)*approximation, ((lli)(num.i / approximation)+1) * approximation);

	if (num.r < 0 && num.r != res.r) {
		res.r -= approximation;
	}
	if (num.i < 0 && num.i != res.i) {
		res.i -= approximation;
	}

	return res;
}

vec2 round_vec2(const vec2& num, const ld& approximation) {
	return vec2(lli(num.r / approximation + (num.r < 0 ? -0.5 : 0.5)) * approximation, lli(num.i / approximation + (num.i < 0 ? -0.5 : 0.5)) * approximation);
}

vec2 floor_vec2(const vec2& num, const ld& approximation) {
	vec2 res(lli(num.r / approximation) * approximation, lli(num.i / approximation) * approximation);

	if (num.r < 0 && num.r != res.r) {
		res.r -= approximation;
	}
	if (num.i < 0 && num.i != res.i) {
		res.i -= approximation;
	}

	return res;
}


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

ld rad(const ld& num) {
	return (const_pi() * num) / 180;
}

vec2 abs_vec2(const vec2& num) {
	if (num.i != 0) {
		return sqrt_vec2(num.r * num.r + num.i * num.i);
	}
	if (num.r > 0) {
		return num;
	}
	return -num;
}

ld Pabs_vec2(const ld& num) {
	if (num > 0) {
		return num;
	}
	return -num;
}

vec2 power_vec2(const vec2& base, lli power) {
	if (power == 0)
		return vec2(1);

	vec2 p = power_vec2(base, power / 2);
	p = p * p;

	return (power % 2 == 0) ? p : base * p;
}

vec2 pow_vec2(const vec2& base, const vec2& power) {
	vec2 res = ln_vec2(base);
	res = res* power;
	res = exp_vec2(res);
	return res;
}

vec2 sqrt_vec2(const vec2& num) {
	vec2 x = num / 2;
	for (int i = 0; i < _TERMS_IN_SUM_; i++) {
		x = (x + num / x);
		x = x * .5;
	}
	return x;
}

ld const_e() {
	ld e = 1;

	int n = 1;
	ld term;
	do {
		term = (ld)1 / fuct_vec2(n++);
		e += term;
	} while (term > _APPROXIMATION_);

	return e;
}

ld const_pi() {
	ld pi = 3.0;

	int sign = 1;
	int n = 2;
	ld term;
	do {
		term = (ld) 4 / (n * (n + 1) * (n + 2));
		pi += sign * term;
		sign *= -1;
		n += 2;
	} while (term > _APPROXIMATION_);

	return pi;
}

vec2 exp_vec2(const vec2& num) {
	vec2 res = num + 1;

	int n = 2;
	vec2 term;
	do {
		term = power_vec2(num, n) / fuct_vec2(n);
		res += term;
		n++;
	} while (n<_TERMS_IN_SUM_);

	return res;
}

vec2 ln_vec2(const vec2& num) {

	if (num.r < 0) {
		return ln_vec2(vec2(-num.r,num.i)) + vec2(0, const_pi());
	}

	if (abs_vec2(num).r > 1) {
		return -ln_vec2(vec2(1) / num);
	}

	vec2 numb = num - 1;
	vec2 res = numb;

	int sign = -1;
	int n = 2;
	vec2 term;
	do {
		term = power_vec2(numb, n) / n;
		res += term * sign;
		sign *= -1;
		n++;
	} while (term.r>_APPROXIMATION_ || term.r<-_APPROXIMATION_);

	return res;
}

vec2 log_vec2(const vec2& base, const vec2& num) {
	return ln_vec2(num) / ln_vec2(base);
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
	} while (term.r>_APPROXIMATION_ || term.r < -_APPROXIMATION_);

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
	} while (n<_TERMS_IN_SUM_);

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
	vec2 res = num;

	int n = 3;
	vec2 term;
	do {
		term = power_vec2(num, n) / fuct_vec2(n);
		res += term;
		n += 2;
	} while (term.r > _APPROXIMATION_);

	return res;
}

vec2 ch_vec2(const vec2& num) {
	vec2 res = 1;

	int n = 2;
	vec2 term;
	do {
		term = power_vec2(num, n) / fuct_vec2(n);
		res += term;
		n += 2;
	} while (term.r > _APPROXIMATION_);

	return res;
}

vec2 th_vec2(const vec2& num) {
	return sh_vec2(num) / ch_vec2(num);
}

vec2 cth_vec2(const vec2& num) {
	return ch_vec2(num) / sh_vec2(num);
}

vec2 sch_vec2(const vec2& num) {
	return vec2(2) / (exp_vec2(num) + exp_vec2(vec2(-num.r, -num.i)));
}

vec2 csch_vec2(const vec2& num) {
	return vec2(2) / (exp_vec2(num) - exp_vec2(vec2(-num.r, -num.i)));
}

//Combinatories

lli P_vec2(const lli& n, const lli& k) {
	return fuct_vec2(n) / fuct_vec2(n - k);
}

lli C_vec2(const lli& n, const lli& k) {
	return fuct_vec2(n) /(fuct_vec2(k) * fuct_vec2(n - k));
}

//Limits for functions
bool l_approximation(const ld& approximation) {
	return approximation > 0;
}

bool l_ln_vec2(const vec2& num) {
	return (num.r ==0) || (num.r<0 && num.i==0);
}

bool l_log_vec2(const vec2& base, const vec2& num) {
	return l_ln_vec2(base) && l_ln_vec2(num) && base!=vec2(1);
}

bool l_W_vec2(const vec2& num) {
	return abs_vec2(num.r)<=(ld)1/const_e() && abs_vec2(num.i) <= (ld)1 / const_e();
}

bool l_arc_vec2(const vec2& num) {
	return num.i==0 && abs_vec2(num.r)<=1;
}

bool l_P_vec2(const lli& n, const lli& k) {
	return n >= 0 && k >= 0 && n>=k;
}
bool l_C_vec2(const lli& n, const lli& k) {
	return n >= 0 && k >= 0 && n >= k;
}
#endif