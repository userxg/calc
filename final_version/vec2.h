#pragma once
#ifndef _VEC2_
#define _VEC2_

#//include <iostream>

//typedef long double ld;


class vec2 {
public:
	vec2(ld RealPart, ld ImaginaryPart) :r(RealPart), i(ImaginaryPart) {}
	vec2(ld RealPart) :r(RealPart), i(0) {}
	vec2() :r(0), i(0) {}
public:
	ld r;
	ld i;

public:
	//"+"
	const vec2& operator+(const vec2& num)const {
		return vec2(this->r + num.r, this->i + num.i);
	}
	const vec2& operator+(const ld& num)const {
		return vec2(this->r + num, this->i);
	}
	const vec2& operator+()const {
		return *this;
	}
	vec2& operator+=(const vec2& num) {
		this->r += num.r;
		this->i += num.i;
		return *this;
	}
	vec2& operator+=(const ld& num) {
		this->r += num;
		return *this;
	}
	//"-"
	const vec2& operator-(const vec2& num)const {
		return vec2(this->r - num.r, this->i - num.i);
	}
	const vec2& operator-(const ld& num)const {
		return vec2(this->r - num, this->i);
	}
	const vec2& operator-()const {
		return vec2(-this->r, -this->i);
	}
	const vec2& operator-=(const vec2& num) {
		this->r -= num.r;
		this->i -= num.i;
		return *this;
	}
	const vec2& operator-=(const ld& num) {
		this->r -= num;
		return *this;
	}
	//"*"
	const vec2& operator*(const vec2& num)const {
		return vec2(this->r * num.r - this->i * num.i, this->r * num.i + this->i * num.r);
	}
	const vec2& operator*=(const vec2& num) {
		this->r = this->r * num.r - this->i * num.i;
		this->i = this->r * num.i + this->i * num.r;
		return *this;
	}
	const vec2& operator*(const ld& num)const {
		return vec2(this->r * num, this->i * num);
	}
	const vec2& operator*=(const ld& num) {
		this->r = this->r * num;
		this->i = this->i * num;
		return *this;
	}
	// "/"
	const vec2& operator/(const vec2& num)const {
		if (num.i == 0 && num.r == 0) {
			return vec2();
		}
		return vec2((this->r * num.r + this->i * num.i) / (num.r * num.r + num.i * num.i), (num.r * this->i - this->r * num.i) / (num.r * num.r + num.i * num.i));
	}
	const vec2& operator/=(const vec2& num)const {
		if (num.i == 0 && num.r == 0) {
			return vec2();
		}
		return vec2((this->r * num.r + this->i * num.i) / (num.r * num.r + num.i * num.i), (num.r * this->i - this->r * num.i) / (num.r * num.r + num.i * num.i));
	}

	const vec2& operator/(const ld& num)const {
		if (num == (ld)0) {
			return vec2();
		}
		return vec2(this->r / num, this->i / num);
	}
	const vec2& operator/=(const ld& num)const {
		if (num == (ld)0) {
			return vec2();
		}
		return vec2(this->r / num, this->i / num);
	}
	//Other
	const vec2& operator=(const vec2& num) {
		this->r = num.r;
		this->i = num.i;
		return *this;
	}
	const vec2& operator=(const ld& num) {
		this->r = num;
		this->i = 0;
		return *this;
	}
	const vec2& operator|=(const ld& num) {
		this->i = num;
		return *this;
	}
	const vec2& operator!() {
		return vec2(this->r, -1 * this->i);
	}
	const vec2& operator~() {
		return vec2(this->r / (this->r * this->r + this->i * this->i), -this->i / ((this->r * this->r + this->i * this->i)));
	}
	// Bools
	bool operator==(const vec2& num) {
		return this->r == num.r && this->i == num.i;
	}
	bool operator==(const ld& num) {
		return this->r == num;
	}
	bool operator!=(const vec2& num) {
		return !(this->r == num.r && this->i == num.i);
	}
	bool operator!=(const ld& num) {
		return !(this->r == num);
	}
	bool operator>(const vec2& num) {
		return this->r > num.r;
	}
	bool operator>(const ld& num) {
		return this->r > num;
	}
	bool operator<(const vec2& num) {
		return this->r < num.r;
	}
	bool operator<(const ld& num) {
		return this->r < num;
	}
	bool operator>=(const vec2& num) {
		return this->r >= num.r;
	}
	bool operator>=(const ld& num) {
		return this->r >= num;
	}
	bool operator<=(const vec2& num) {
		return this->r <= num.r;
	}
	bool operator<=(const ld& num) {
		return this->r <= num;
	}

	// in/out
	friend std::ostream& operator<<(std::ostream& output, const vec2& num) {
		if (num.i == (ld)0) {
			output << num.r;
			return output;
		}
		if (num.r == (ld)0) {
			output << num.i << 'i';
			return output;
		}
		if (num.i < 0) {
			output << num.r << num.i << "i";
			return output;
		}
		output << num.r << "+" << num.i << "i";
		return output;
	}
};
#endif