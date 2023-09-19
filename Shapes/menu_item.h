///////////////////////////////////////////////////////////////////////////
// File: menu_item.h
// Purpose: Class definition of a pure abstract menu_item class.
//          (C++ equivalent of an interface in java)
///////////////////////////////////////////////////////////////////////////
#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include <string>

class Menu_Item
{
public:
    // return the label for this menu item
    virtual std::string label()=0;

    // perform the selected handler for this item
    virtual void selected()=0;
};

#endif