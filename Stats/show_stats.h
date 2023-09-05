///////////////////////////////////////////////////////////////////////////
// File: show_stats.h
// Purpose: Definition of the number management menu item
///////////////////////////////////////////////////////////////////////////
#ifndef SHOW_STATS_H
#define SHOW_STATS_H
#include <vector>
#include "menu_item.h"

class Show_Stats : public Menu_Item
{
public:
    //constructor
    Show_Stats(std::vector<double> *_numbers);

    //implementation of Menu_Item
    virtual std::string label();
    virtual void selected();
private:
    std::vector<double> *_numbers;
};
#endif