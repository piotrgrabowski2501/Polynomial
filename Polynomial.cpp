//Piotr Grabowski
#include "Z2.h"
#include "Polynomial.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>

Polynomial::Polynomial()
{
	degree = 0;
	coefficients = new Z2[1];
	coefficients[0] = 0;
}


Polynomial::Polynomial(unsigned int _degree, Z2* _coefficients)
{
	degree = _degree;
	unsigned int i = degree;
	while(_coefficients[i] == 0 && i > 0)
		i--;
	degree = i;
	this -> coefficients = new Z2[degree + 1];
	for(unsigned j = 0; j <= degree; j++)
		coefficients[j] = _coefficients[j];
}

Polynomial& Polynomial::operator=(const Polynomial& a)
{
    this->degree = a.degree;
    delete[]coefficients;
    coefficients = new Z2[a.degree + 1];
    memcpy(coefficients, a.coefficients,(a.degree + 1) * sizeof(Z2));
    return *this;
}

const Z2& Polynomial::operator[](unsigned int i) const
{
	if(i > this-> degree)
	{
		std::cout << "Niepoprawny indeks wielomianu\n";
		return this -> coefficients[0];
	}
	else return this-> coefficients[i];
}

Polynomial& Polynomial::operator+=(const Polynomial& b)
{
	*this = *this + b;
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& c)
{
	*this = *this * c;
	return *this;
}

unsigned int Polynomial::degr() const
{
	return this -> degree;
}

std::string Polynomial::toString(std::string xVar)
{
	std::string output_string;
	std::ostringstream temp_string;
	int pom = -1;

    if(degree == 0 && coefficients[0] == 0)
        output_string = "0";

    if(coefficients[0].x != 0)
	{
        output_string = "1";
        pom = 0;
    }

    for(unsigned int i = 1; i < degree; i++)
	{
        if(coefficients[i].x != 0)
        {
            if(pom == 0)
            {
                temp_string << "+";
                pom = 1;
            }
            temp_string << xVar << "^" << i << "+";
        }
    }

    if(degree > 0)
    {
        if(pom == 0)
            temp_string << "+";
        temp_string << xVar << "^" << degree;
    }

    output_string += temp_string.str();
    return output_string;
}

Polynomial operator+(const Polynomial& a, const Polynomial& b)
{
	Z2* coefficients_temp;
	unsigned int degree_temp = 0;
	if(b.degree >= a.degree)
	{
		degree_temp = b.degree;
		coefficients_temp = new Z2[degree_temp + 1];
		for(unsigned int i = 0; i <= degree_temp; i++)
		{
			if(i <= a.degree) coefficients_temp[i] = a.coefficients[i] + b.coefficients[i];
			else coefficients_temp[i] = b.coefficients[i];
		}
	}
	else
	{
		degree_temp = a.degree;
		coefficients_temp = new Z2[degree_temp + 1];
		for(unsigned int i = 0; i <= degree_temp; i++)
		{
			if(i <= b.degree) coefficients_temp[i] = a.coefficients[i] + b.coefficients[i];
			else coefficients_temp[i] = a.coefficients[i];
		}
	}
	Polynomial gotowy(degree_temp, coefficients_temp);
    delete[]coefficients_temp;
    return gotowy;
}

Polynomial operator*(const Polynomial& a, const Polynomial& b)
{
    unsigned int degree_temp = a.degree + b.degree;
    Z2* coefficients_temp = new Z2[(degree_temp) + 1];
    for(unsigned int i = 0; i <= a.degree; i++)
    {
        for(unsigned int j = 0; j <= b.degree; j++)
            coefficients_temp[i+j] = coefficients_temp[i+j] + (a.coefficients[i] * b.coefficients[j]);
    }
    Polynomial poly_return(degree_temp, coefficients_temp);
    delete[]coefficients_temp;
    return poly_return;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& h)
{
	out << "{";
	for(unsigned int i = 0; i < h.degree; i++)
	{
		out << h.coefficients[i].x << ",";
	}
	out << h.coefficients[h.degree].x << "}";
  	return out;
}
std::istream& operator>>(std::istream& in, Polynomial& g) {
    Z2* coefficients_temp;
    char arr_of_coefs[256];
    in.getline(arr_of_coefs,256);
    coefficients_temp = new Z2[256];
    int counter = 0;
	int i = 0;
    while(arr_of_coefs[i] != '{')
            i++;

    while(arr_of_coefs[i] != '}')
    {
        if(arr_of_coefs[i] == '1' || arr_of_coefs[i] == '0')
        {
            coefficients_temp[counter] = Z2(arr_of_coefs[i]);
            counter++;
        }
        i++;
    }
    g.degree = counter;
    g.coefficients = new Z2[counter + 1];
    for(int i = 0; i <= g.degree; i++)
        g.coefficients[i] = coefficients_temp[i];
    while(g.coefficients[g.degree].x == 0 && g.degree != 0)
        g.degree--;

    delete[]coefficients_temp;
	return in;
}

