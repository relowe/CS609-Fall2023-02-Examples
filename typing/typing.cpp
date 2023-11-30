#include <iostream>

int main()
{
  double x;
  int y;
  char c;

  x = 1.5;
  y = x;

  std::cout << y << std::endl;

  y = 1;
  x = y;

  std::cout << x << std::endl;

  x = 65;
  c = x;
  std:: cout << c << std::endl;
}