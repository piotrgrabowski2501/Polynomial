//Piotr Grabowski
#include "Z2.h"
#include <iostream>
#include <sstream>
Z2::Z2()
{
	this -> x = 0;
}

Z2::Z2(short int m)
{
	if(m % 2 == 0) this -> x = 0;
	else this -> x = 1;
}

Z2::operator short int() const
{
	return x;
}

Z2& Z2::operator+=(const Z2& q)
{
    if((this -> x == 1 && q.x == 1) || (this -> x == 0 && q.x == 0)) this -> x = 0;
    else this -> x = 1;
    return *this;
}


Z2& Z2::operator*=(const Z2& w)
{
    if(this -> x == 1 && w.x == 1) this -> x = 1;
    else this -> x = 0;
    return *this;
}

Z2& Z2::operator/=(const Z2& a)
{
    if (this -> x == 1 && a.x == 1) this -> x = 1;
    else if (this -> x == 0 && a.x == 1) this -> x = 0;
	else std::cout << "Dzielenie przez zero\n";
    return *this;
}

Z2 operator+(const Z2& b, const Z2& c)
{
    if ((b.x == 1 && c.x == 1) || (b.x == 0 && c.x == 0)) return Z2(0);
    else return Z2(1);
}

Z2 operator*(const Z2& d, const Z2& e)
{
    if (d.x == 1 && e.x == 1) return Z2(1);
    else return Z2(0);
}

Z2 operator/(const Z2& f, const Z2& g)
{
    if (f.x == 1 && g.x == 1) return Z2(1);
    else if (f.x == 0 && g.x == 1) return Z2(0);
	else{
		std::cout << "Dzielenie przez zero\n";
		return f;
	}
}

std::ostream& operator<<(std::ostream& out, const Z2& h)
{
	out << h.x;
  	return out;
}

