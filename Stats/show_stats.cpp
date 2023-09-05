///////////////////////////////////////////////////////////////////////////
// File: show_stats.cpp
// Purpose: Definition of the number management menu item
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <numeric>
#include "show_stats.h"

//constructor
Show_Stats::Show_Stats(std::vector<double> *_numbers)
{
    this->_numbers = _numbers;    
}

//implementation of Menu_Item
std::string Show_Stats::label()
{
    return "Show Statistics";    
}

void Show_Stats::selected()
{
    int n;
    double sum;
    double avg;

    // get the statistics
    n = _numbers->size();
    sum = std::accumulate(_numbers->begin(), _numbers->end(), 0.0);
    avg = sum / n;

    // print data
    std::cout << "N=" << n << std::endl
              << "Sum=" << sum << std::endl
              << "Average=" << avg << std::endl;
}
