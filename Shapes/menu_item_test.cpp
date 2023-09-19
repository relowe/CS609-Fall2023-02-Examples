#include <iostream>
#include <string>
#include "menu_item.h"

// Inheritance in C++
class Test_Item : public Menu_Item
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
    mi = new Test_Item();

    std::cout << mi->label() << std::endl;
    mi->selected();

    delete mi;
}


// Implementation of the Test_Item (normally in a separate file)
std::string Test_Item::label()
{
    return "Test Item";
}


void Test_Item::selected()
{
    std::cout << "Test item selected." << std::endl;
}