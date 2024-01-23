#pragma once
#ifndef _HASH_MAP_
#define _HASH_MAP_

#include <iostream>

#define _CAPACITY_ 30
#define _PRIME_FOR_HASH_ 11

template <class ValueType>
class HashMap {
	class HashNode {
	public:
		HashNode() :Key(""), Value(NULL), state(false) {}

		std::string Key;
		ValueType Value;
		bool state;
	public:
		bool operator==(const HashNode& node) {
			return this->Key == node.Key && this->Value == node.Value;
		}
	};


private:
	HashNode HashArr[_CAPACITY_];

public:
	void put(const std::string& key, const ValueType& Value) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].state == false) {
			HashArr[hash].Key = key;
			HashArr[hash].Value = Value;
			HashArr[hash].state = true;
			return;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				HashArr[hash].Key = key;
				HashArr[hash].Value = Value;
				HashArr[hash].state = true;
				return;
			}
		}
	}

	ValueType get(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key==key) {
			return HashArr[hash].Value;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return NULL;
			}

			if (HashArr[i].Key == key) {
				return HashArr[hash].Value;
			}
		}
		return NULL;
	}

	void del(const std::string& key) {
		lli hash = CalculateHash(key);

		if (HashArr[hash].Key == key) {
			HashArr[hash].Key = "";
			HashArr[hash].Value = NULL;
			return;
		}

		for (int i = (hash + 1) % _CAPACITY_; i != hash; i = (i + 1) % _CAPACITY_) {
			if (HashArr[i].state == false) {
				return;
			}

			if (HashArr[i].Key == key) {
				HashArr[hash].Key = "";
				HashArr[hash].Value = NULL;
				return;
			}
		}
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