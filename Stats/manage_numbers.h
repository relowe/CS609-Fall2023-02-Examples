ls///////////////////////////////////////////////////////////////////////////
// File: manage_numbers.h
// Purpose: Definition of the number management menu item
///////////////////////////////////////////////////////////////////////////
#ifndef MANAGE_NUMBERS_H
#define MANAGE_NUMBERS_H
#include <vector>
#include "menu_item.h"

class Manage_Numbers : public Menu_Item
{
public:
    //constructor
    Manage_Numbers(std::vector<double> *_numbers);

    //implementation of Menu_Item
    virtual std::string label();
    virtual void selected();
private:
    std::vector<double> *_numbers;
};
#endif