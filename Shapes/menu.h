 ///////////////////////////////////////////////////////////////////////////
// File: menu.h
// Purpose: Class definition of a menu.
///////////////////////////////////////////////////////////////////////////
#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include "menu_item.h"

class Menu
{
public:
    // constructor
    Menu();

    // Display the menu and execute the user's choice
    virtual void run();

    // Add an item to the menu
    virtual void add_item(Menu_Item *item);

    // Remove an item from the menu
    virtual void remove_item(Menu_Item *item);

protected:
    std::vector<Menu_Item*> _items;
};

#endif