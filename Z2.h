//Piotr Grabowski
#pragma once
#include <iostream>
#include <sstream>
class Z2
{
public:
	short int x;

	Z2();
	Z2(short int m);
	operator short int() const;
	Z2& operator+=(const Z2& q);
	Z2& operator*=(const Z2& w);
	Z2& operator/=(const Z2& a);
};

Z2 operator+(const Z2& b, const Z2& c);
Z2 operator*(const Z2& d, const Z2& e);
Z2 operator/(const Z2& f, const Z2& g);
std::ostream& operator<<(std::ostream& out, const Z2& h);

