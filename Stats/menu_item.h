///////////////////////////////////////////////////////////////////////////
// File: menu_item.h
// Purpose: This is a class definition of a menu item.
///////////////////////////////////////////////////////////////////////////
#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include <string>

class Menu_Item
{
public:
    // get the text to display for the menu item
    virtual std::string label()=0;

    // function to execute when this item is selected
    virtual void selected()=0;
};
#endif