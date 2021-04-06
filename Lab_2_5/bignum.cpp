#include "bignum.h"

BigInt::BigInt(int a)
{
	sign = (a < 0) ? false : true;
	a = abs(a);
	int l = 1;
	int t = a;
	while (t >= 10) { l++; t /= 10; }
	cifr = new Array(l,a); // создаем массив нужного размера
	for (int i = cifr->length() - 1; i >= 0; --i) { //cifr->length(), потому что cifr - указатель
		(*cifr)[i] = a % 10; //(*cifr)[i], потому что cifr - указатель
		a /= 10;
	}
}

BigInt::BigInt(std::string s)
{
	sign = (s[0] == '-') ? false : true;

	if (sign) {
		cifr = new Array(s.length());
		for (int i = 0; i < cifr->length(); ++i) {
			(*this)[i] = s[i] - 48;
		}
	}
	else {
		cifr = new Array(s.length() - 1);
		for (int i = 0; i < cifr->length(); ++i) {
			(*cifr)[i] = s[i + 1] - 48;
		}
	}
}

BigInt::BigInt(const BigInt& other)
{
	sign = other.sign;
	cifr = new Array(*(other.cifr));  // TODO:
}

int BigInt::gcd(const BigInt& other) const
{
	int l(static_cast<int>(*this));
	int r(static_cast<int>(other));
	while (l != 0 && r != 0) {
		if (l > r)
			l = l % r;
		else
			r = r % l;
	}
	return l + r;
}

bool BigInt::is_prime() const
{
	int num = static_cast<int>(*this);
	int d(2);
	while (d * d <= num && num % d != 0)
		++d;
	return d * d > num;
}

BigInt::operator int() const
{
	int num(0);
	for (int i = 0; i < this->length(); ++i) {
		num += (*this)[i];
		num *= 10;
	}
	num /= 10;

	return (this->sign) ? num : -num;
}

BigInt::operator std::string() const
{
	std::string s;

	s = (this->sign) ? "" : "-";
	for (int i = 0; i < this->length(); ++i) {
		s += std::to_string((*this)[i]);
	}

	return s;
}

BigInt& BigInt::operator=(const BigInt& other)
{
	if (this != &other) {
		sign = other.sign;
		cifr = new Array(*(other.cifr));
	}

	return *this;
}

bool BigInt::operator==(const BigInt& other)
{
	if (sign != other.sign)
		return false;
	if (this->length() != other.length())
		return false;
	for (int i = other.length() - 1; i >= 0; --i) {
		if ((*this)[i] != other[i])
			return false;
	}

	return true;
}

bool BigInt::operator!=(const BigInt& other)
{
	return !(*this == other);
}

bool BigInt::operator>(const BigInt& other)
{
	return static_cast<int>(*this) > static_cast<int>(other);
}

bool BigInt::operator>=(const BigInt& other)
{
	return !(*this < other);
}

bool BigInt::operator<(const BigInt& other)
{
	return static_cast<int>(*this) < static_cast<int>(other);
}

bool BigInt::operator<=(const BigInt& other)
{
	return !(*this > other);
}

BigInt BigInt::operator+(const BigInt& other)
{
	int temp(static_cast<int>(*this) + static_cast<int>(other));
	BigInt res(temp);
	return res;
}

BigInt BigInt::operator+=(const BigInt& other)
{
	(*this) = ((*this) + other);
	return *this;
}

BigInt& BigInt::operator-()
{
	sign = !sign;
	return *this;
}

BigInt BigInt::operator-(const BigInt& other)
{
	int temp(static_cast<int>(*this) - static_cast<int>(other));
	BigInt res(temp);
	return res;
}

BigInt BigInt::operator-=(const BigInt& other)
{
	(*this) = ((*this) - other);
	return *this;
}

BigInt BigInt::operator*(const BigInt& other)
{
	int temp(static_cast<int>(*this) * static_cast<int>(other));
	BigInt res(temp);
	return res;
}

BigInt BigInt::operator*=(const BigInt& other)
{
	(*this) = ((*this) * other);
	return *this;
}

BigInt BigInt::operator/(const BigInt& other)
{
	int temp(static_cast<int>(*this) / static_cast<int>(other));
	BigInt res(temp);
	return res;
}

BigInt BigInt::operator/=(const BigInt& other)
{
	(*this) = ((*this) / other);
	return *this;
}

BigInt BigInt::operator%(const BigInt& other)
{
	int temp(static_cast<int>(*this) % static_cast<int>(other));
	BigInt res(temp);
	return res;
}

BigInt BigInt::operator%=(const BigInt& other)
{
	(*this) = ((*this) % other);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const BigInt& bignum)
{
	if (bignum.mark() == '-')
		out << '-';

	for (int i = 0; i < bignum.length(); ++i) {
		out << bignum[i];
	}
	
	return out;
}

std::istream& operator>>(std::istream& in, BigInt& bignum)
{
	std::string s;
	in >> s;
	
	bignum.sign = (s[0] == '-') ? false : true;
	if (bignum.sign) {
		bignum.cifr = new Array(s.length());
		for (int i = 0; i < bignum.length(); ++i) {
			bignum[i] = s[i] - 48;
		}
	}
	else {
		bignum.cifr = new Array(s.length() - 1);
		for (int i = 0; i < bignum.length(); ++i) {
			bignum[i] = s[i + 1] - 48;
		}
	}
	return in;
}

int gcd(const BigInt& first, const BigInt& second)
{
	int l(static_cast<int>(first));
	int r(static_cast<int>(second));
	while (l != 0 && r != 0) {
		if (l > r)
			l = l % r;
		else
			r = r % l;
	}
	return l + r;
}
