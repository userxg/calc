#pragma once
#ifndef _HASH_MAP_
#define _HASH_MAP_

#include <iostream>
#include "vec2.h"

#define _CAPACITY_ 50
#define _PRIME_FOR_HASH_ 11

typedef long long int lli;

class HashMap {
	class HashNode {
	public:
		HashNode(std::string Name, char Value, void* FuncPointer, void* LimitPointer, std::string DataType, char NumInputs,vec2 FunctionEval) :Key(Name), FunctionValue(Value), FunctionPointer(FuncPointer), FunctionLimitPointer(LimitPointer), DataType(DataType), FunctionsNumInputs(NumInputs), FunctionEval(FunctionEval), state(false) {}
		HashNode(std::string Name, char Value, void* FuncPointer,void* LimitPointer) :Key(Name), FunctionValue(Value), FunctionPointer(FuncPointer), FunctionLimitPointer(LimitPointer), DataType("ld"), FunctionsNumInputs(0), FunctionEval(0), state(false) {}
		HashNode(std::string Name, char Value, void* FuncPointer) :Key(Name), FunctionValue(Value), FunctionPointer(FuncPointer), FunctionLimitPointer(nullptr), FunctionsNumInputs(0), FunctionEval(0), state(false) {}
		HashNode(std::string Name,char Value) :Key(Name), FunctionValue(Value), FunctionPointer(nullptr), FunctionLimitPointer(nullptr), DataType("ld"), FunctionsNumInputs(0), FunctionEval(0), state(false) {}
		HashNode(std::string Name) :Key(Name), FunctionValue(0), FunctionPointer(nullptr), FunctionLimitPointer(nullptr), DataType("ld"), FunctionsNumInputs(0), FunctionEval(0), state(false) {}
		HashNode() :Key(""), FunctionValue(0), FunctionPointer(nullptr), FunctionLimitPointer(nullptr), DataType("ld"), FunctionsNumInputs(0), FunctionEval(0), state(false) {}

		std::string Key;

		char FunctionValue;
		void* FunctionPointer;
		void* FunctionLimitPointer;
		std::string DataType;
		char FunctionsNumInputs;
		vec2 FunctionEval;

		bool state;
	public:
		bool operator==(const HashNode& node) {
			return this->Key == node.Key && this->FunctionValue == node.FunctionValue;
		}
	};


private:
	HashNode HashArr[_CAPACITY_];

public:
	void put(const std::string& key, const char FunctionValue,void* FunctionPointer, void* FunctionLimitPointer, const std::string& DataType, const char& NumInputs, const vec2& FunctionEval) {
		if (key == "") {
			return;
		}
		
		lli hash = CalculateHash(key);

		if (HashArr[hash].state == false) {
			HashArr[hash].Key = key;
			HashArr[hash].FunctionValue = FunctionValue;
			HashArr[hash].FunctionPointer = FunctionPointer;
			HashArr[hash].FunctionLimitPointer = FunctionLimitPointer;
			HashArr[hash].DataType = DataType;
			HashArr[hash].FunctionsNumInputs = NumInputs;
			HashArr[hash].FunctionEval = FunctionEval;
			HashArr[hash].state = true;
			return;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				HashArr[i].Key = key;
				HashArr[i].FunctionValue = FunctionValue;
				HashArr[i].FunctionPointer = FunctionPointer;
				HashArr[i].FunctionLimitPointer = FunctionLimitPointer;
				HashArr[i].DataType = DataType;
				HashArr[i].FunctionsNumInputs = NumInputs;
				HashArr[i].FunctionEval = FunctionEval;
				HashArr[i].state = true;
				return;
			}
		}
	}

	char getV(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key==key) {
			return HashArr[hash].FunctionValue;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return NULL;
			}

			if (HashArr[i].Key == key) {
				return HashArr[i].FunctionValue;
			}
		}
		return NULL;
	}

	void* getP(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key == key) {
			return HashArr[hash].FunctionPointer;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return NULL;
			}

			if (HashArr[i].Key == key) {
				return HashArr[i].FunctionPointer;
			}
		}
		return NULL;
	}

	void* getLP(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key == key) {
			return HashArr[hash].FunctionLimitPointer;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return NULL;
			}

			if (HashArr[i].Key == key) {
				return HashArr[i].FunctionLimitPointer;
			}
		}
		return NULL;
	}

	std::string getDt(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key == key) {
			return HashArr[hash].DataType;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return NULL;
			}

			if (HashArr[i].Key == key) {
				return HashArr[i].DataType;
			}
		}
		return NULL;
	}

	char getNInp(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key == key) {
			return HashArr[hash].FunctionsNumInputs;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return NULL;
			}

			if (HashArr[i].Key == key) {
				return HashArr[i].FunctionsNumInputs;
			}
		}
		return NULL;
	}

	vec2 getEv(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key == key) {
			return HashArr[hash].FunctionEval;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return NULL;
			}

			if (HashArr[i].Key == key) {
				return HashArr[i].FunctionEval;
			}
		}
		return NULL;
	}

	bool inmap(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key == key) {
			return true;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return false;
			}

			if (HashArr[i].Key == key) {
				return true;
			}
		}
		return false;
	}

private:
	lli CalculateHash(const std::string& key) {
		lli hash=0;
		lli p_pow = 1;
		for (char c : key) {
			if (IsLow(c)) {
				hash = (hash + (c - 'a' + 1) * p_pow) % _CAPACITY_;
				p_pow = (p_pow * _PRIME_FOR_HASH_) % _CAPACITY_;
			}
			else if (IsUpper(c)) {
				hash = (hash + (c - 'A'+('a'-'A') + 1) * p_pow) % _CAPACITY_;
				p_pow = (p_pow * _PRIME_FOR_HASH_) % _CAPACITY_;
			}
		}
		return hash;
	}
	
	bool IsUpper(const char c) {
		return 'A' <= c && c <= 'Z';
	}

	bool IsLow(const char c) {
		return 'a' <= c && c <= 'z';
	}
};
#endif