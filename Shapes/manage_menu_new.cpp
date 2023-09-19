#include <iostream>
#include <string>
#include "menu_item.h"


// Inheritance in C++
class Manage_Menu_New : public Menu_Item
{
public:
    virtual std::string label();
    virtual void selected();
};

int main()
{
    // a menu item pointer
    Menu_Item *mi;
    // manually instantiate mi
    mi = new Manage_Menu_New();
    int user_choice = 0;
    std::cout << (std::stoi)mi -> label() << std::endl;
    mi->selected();
    delete mi;
}


// Implementation of the Test_Item (normally in a separate file)
std::string Manage_Menu_New::label()
{
    std::string any_key;
    std::cout<< "Welcome to the shape adder! You can add a shape, remove it and view it" << std::endl;
    std:: cout << "Choice??" << std::endl;
    std::cin >> any_key; // Get user input from the keyboard
    return any_key;

}


void Manage_Menu_New::selected()
{
    std::cout << "Test item selected." << std::endl;
}