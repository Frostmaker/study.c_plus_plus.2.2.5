#pragma once
#include "array.h"
#include <string>

class BigInt {
private:
	bool sign;
	Array* cifr;
public:
	BigInt() {
		sign = true;
		cifr = new Array();
	}
	BigInt(int a);
	BigInt(std::string s);
	BigInt(const BigInt& other);
	int length() const { return cifr->length(); };
	char mark() const { return (sign) ? '+' : '-'; };
	~BigInt() {
		delete cifr;
	}

	int gcd(const BigInt& other) const;
	bool is_prime() const;

	operator int() const;
	operator std::string() const;
	int& operator[] (int i) { return (*cifr)[i]; };
	int operator[] (int i) const { return (*cifr)[i]; };
	BigInt& operator= (const BigInt& other);
	bool operator== (const BigInt& other);
	bool operator!= (const BigInt & other);
	bool operator> (const BigInt& other);
	bool operator>= (const BigInt& other);
	bool operator< (const BigInt& other);
	bool operator<= (const BigInt& other);
	

	BigInt operator+ (const BigInt& other);
	BigInt operator+= (const BigInt & other);
	BigInt& operator- ();
	BigInt operator- (const BigInt& other);
	BigInt operator-= (const BigInt& other);
	BigInt operator* (const BigInt& other);
	BigInt operator*= (const BigInt& other);
	BigInt operator/ (const BigInt& other);
	BigInt operator/= (const BigInt& other);
	BigInt operator% (const BigInt& other);
	BigInt operator%= (const BigInt& other);
	friend std::ostream& operator<< (std::ostream& out, const BigInt& bignum);
	friend std::istream& operator>> (std::istream& in, BigInt& bignum);
	friend int gcd(const BigInt& first, const BigInt& second);
};