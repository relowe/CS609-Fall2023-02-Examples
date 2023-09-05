///////////////////////////////////////////////////////////////////////////
// File: menu.h
// Purpose: Class definition of a menu.
///////////////////////////////////////////////////////////////////////////
#ifndef MENU_H
#define MENU_H
#include <vector>
#include "menu_item.h"

class Menu
{
public:
    // Constructor
    Menu();

    // Add an item to the menu
    virtual void add_item(Menu_Item *item);

    // Remove an item from the menu
    virtual void remove_item(Menu_Item *item);

    // Run the menu
    virtual void run();

protected:
    std::vector<Menu_Item*> _items;
};

#endif