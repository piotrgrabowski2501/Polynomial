//Piotr Grabowski
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
class Polynomial
{
public:
	unsigned int degree;
	Z2* coefficients;

	Polynomial();
	Polynomial(unsigned int, Z2*);
	Polynomial& operator=(const Polynomial&);
	const Z2& operator[](unsigned int) const;
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	unsigned int degr() const;
	std::string toString(std::string);
};

Polynomial operator+(const Polynomial&, const Polynomial&);
Polynomial operator*(const Polynomial&, const Polynomial&);
std::ostream& operator<<(std::ostream&, const Polynomial&);
std::istream& operator>>(std::istream&, Polynomial&);
