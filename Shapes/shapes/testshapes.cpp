#include "shapes.h"
#include <iostream>
#include "menu.h"
#include <string>

int main()
{
  Menu menu;
  Shape shape;
  std::string compName;
  std::cin >> compName;

  menu.welcome_user(compName);
  return 0;
}