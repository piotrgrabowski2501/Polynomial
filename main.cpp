//Piotr Grabowski
#include "Z2.cpp"
#include "Polynomial.cpp"
#include <iostream>
#include <sstream>
using namespace std;
#define LOGGER(x) std::cout << (#x) << "=" << x << std::endl;

int main(){
  Z2 x(11), y(24);

  LOGGER(x);
  LOGGER(y);
  LOGGER(x+y);
  LOGGER(x*y);

  std::istringstream in("strstr{1,0,1}numbers");
  Polynomial w;
  in >> w;
  cout  << w << endl;
  cout << w.toString("x") << endl;

  const int size1 = 11;
  const int size2 = 4;
  Z2 d1[size1+1] = {Z2(1),Z2(0),Z2(5),Z2(0),Z2(1),Z2(1),Z2(1),Z2(1),Z2(1)};
  Z2 d2[size2+1] = {Z2(0),Z2(0),Z2(1),Z2(1), Z2(1)};
  d1[size1] = 1;
  Polynomial u(size1,d1), v(size2,d2);
  LOGGER(u);

  cout << u.toString("x") << endl;
  cout << v.toString("x") << endl;
  u += v;

  cout << u.toString("x") << endl;
  cout << u + w << endl;
  u *= w;

  cout << u.toString("x");
}
