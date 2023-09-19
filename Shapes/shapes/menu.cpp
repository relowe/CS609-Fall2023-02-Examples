#include "menu.h"
#include <string>
#include <ostream>
#include <iostream>

Menu::Menu() {}

int Menu::welcome_user(std::string companyName)
{
  // User choice
  int userChoice; 
  std::cout << "Welcome to company::: " << companyName  << std::endl;
  std::cout << "Enter the name to rename company" << std::endl;
  std::cin >> userChoice;
  std::cout << "You have entered : " << userChoice << std::endl;
  return userChoice;
}
