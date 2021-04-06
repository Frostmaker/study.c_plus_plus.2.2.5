#include "array.h"

int& Array::operator[](int i) { return values[i]; }

int Array::operator[](int i) const { return values[i]; }

int Array::length() const { return n; }

bool Array::find(int x)
{
	for (int i{ 0 }; i < n; ++i) {
		if ((*this)[i] == x)
			return true;
	}

	return false;
}

Array& Array::extend(int _n)
{
	if (n < _n) {
		int* _values = new int[_n];
		int i{ 0 };
		for (i; i < n; ++i)
			_values[i] = this->values[i];
		for (i; i < _n; ++i)
			_values[i] = 0;
		delete[] values;
		values = _values;
		n = _n;
	}
	return *this;
}

Array& Array::add(int x)
{
	int _n = n + 1;
	int* _values = new int[_n];
	for (int i{ 0 }; i < n; ++i)
		_values[i] = values[i];
	_values[n] = x;
	delete[] values;
	values = _values;
	n = _n;

	return *this;
}

Array& Array::insert(int x, int pos)
{
	int _n = n + 1;
	int* _values = new int[_n];
	
	for (int i{ 0 }; i < pos; ++i)
		_values[i] = values[i];

	_values[pos] = x;

	for (int i{ pos + 1 }; i < _n; ++i)
		_values[i] = values[i - 1];

	delete[] values;
	values = _values;
	n = _n;

	return *this;
}

Array& Array::remove(int pos)
{
	int _n = n - 1;
	int* _values = new int[_n];

	for (int i{ 0 }; i < pos; ++i)
		_values[i] = values[i];

	for (int i{ pos }; i < _n; ++i)
		_values[i] = values[i + 1];

	delete[] values;
	values = _values;
	n = _n;

	return *this;
}

Array::Array()
{
	n = 1;
	values = new int[n] { 0 };
}

Array::Array(int _n, int x)
{
	n = _n;
	values = new int[n];
	for (int i{ 0 }; i < n; ++i) {
		values[i] = x;
	}
}

Array::Array(int _n, int* _values)
{
	n = _n;
	values = new int[n];
	for (int i = 0; i < n; ++i) {
		values[i] = _values[i];
	}
}

Array::Array(const Array& other)
{
	n = other.n;
	values = new int[n];
	for (int i{ 0 }; i < n; ++i) {
		values[i] = other.values[i];
	}
}

Array::~Array()
{
	delete[] values;
}

Array Array::operator+(const Array& arr)
{
	if (n != arr.n)
		throw (1);
	else {
		Array new_one(n);
		for (int i{ 0 }; i < n; ++i) {
			new_one.values[i] = this->values[i] + arr.values[i];
		}

		return new_one;
	}
}

Array Array::operator+= (const Array& arr)
{
	for (int i = 0; i < n; ++i)
		values[i] = values[i] + arr[i];
	return *this;
}

Array Array::operator+(const int x)
{
	Array new_one(n);
	for (int i{ 0 }; i < n; ++i)
		new_one[i] = (*this)[i] + x;

	return new_one;
}

Array& Array::operator=(const Array& arr)
{
	if (this != &arr) {
		delete[] values;
		n = arr.n;
		values = new int[n];
		for (int i{ 0 }; i < n; ++i)
			(*this)[i] = arr[i];
	}

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
	out << "[";
	for (int i{ 0 }; i < (arr.n - 1); ++i)
		out << arr[i] << ", ";
	out << arr[arr.n - 1] << "]";
	return out;
}

std::istream& operator>>(std::istream& in, Array& arr)
{
	in >> arr.n;
	for (int i{ 0 }; i < arr.n; ++i)
		in >> arr[i];

	return in;
}
