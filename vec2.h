#pragma once
#ifndef _VEC2_
#define _VEC2_

typedef long double ld;

class vec2 {
public:
	vec2(ld RealPart, ld ImaginaryPart):real(RealPart),imagine(ImaginaryPart){}
	vec2(ld RealPart) :real(RealPart), imagine(0) {}
	vec2() :real(0), imagine(0) {}
public:
	ld real;
	ld imagine;
public:
	const vec2& operator+(const vec2& num)const {
		return vec2(this->real + num.real, this->imagine + num.imagine);
	}
	vec2& operator+=(const vec2& num) {
		this->real += num.real;
		this->imagine += num.imagine;
		return *this;
	}
	vec2& operator-=(const vec2& num) {
		this->real -= num.real;
		this->imagine -= num.imagine;
		return *this;
	}
	const vec2& operator-(const vec2& num)const {
		return vec2(this->real - num.real, this->imagine - num.imagine);
	}
	const vec2& operator*(const vec2& num)const {
		return vec2(this->real * num.real - this->imagine * num.imagine, this->real * num.imagine + this->imagine * num.real);
	}
	const vec2& operator/(const vec2& num)const {
		if (num.imagine == 0 && num.real == 0) {
			return vec2();
		}
		return vec2((this->real * num.real + this->imagine * num.imagine) / (num.real * num.real + num.imagine * num.imagine), (num.real * this->imagine - this->real * num.imagine) / (num.real * num.real + num.imagine * num.imagine));
	}
	bool operator==(const vec2& num) {	
		return this->real == num.real && this->imagine == num.imagine;
	}
	bool operator!=(const vec2& num) {
		return !(this->real == num.real && this->imagine == num.imagine);
	}
};
#endif