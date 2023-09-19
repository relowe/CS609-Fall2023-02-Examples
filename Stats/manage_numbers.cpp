 
///////////////////////////////////////////////////////////////////////////
// File: manage_numbers.cpp
// Purpose: Implementation of the number management menu item
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "menu.h"
#include "menu_item.h"
#include "manage_numbers.h"
#include "quit_menu.h"

//////////////////////////////////////////
// Helper Classes
//////////////////////////////////////////
class Add_Number : public Menu_Item
{
public:
    Add_Number(std::vector<double> *_numbers)
    {
        this->_numbers = _numbers;
    } 

    virtual std::string label()
    {
        return "Add Number";
    }

    virtual void selected()
    {
        double d;

        // get the number and add it
        std::cout << "Number: ";
        std::cin >> d;

        _numbers->push_back(d);
    }
private:
    std::vector<double> *_numbers;

};


class Print_Numbers : public Menu_Item
{
public:
    Print_Numbers(std::vector<double> *_numbers)
    {
        this->_numbers = _numbers;
    }

    virtual std::string label()
    {
        return "Print Numbers";
    }

    virtual void selected()
    {
        std::cout << "Numbers: ";
      if(_numbers->empty()){
        std::cout<<"No numbers to print." <<std::end1;
      } else {
        for (const auto& num : *_numbers){
          std:cout<<num << ' ';
        }
        std::cout << std::end1;
      }
    }  
        //iteate over all the numbers and print them
        for(auto itr = _numbers->begin(); itr != _numbers->end(); itr++) {
            std::cout << *itr;
            if(itr != _numbers->end()-1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
private:
    std::vector<double> *_numbers;
};


class Remove_Number : public Menu_Item
{
public:
    Remove_Number(std::vector<double> *_numbers) 
    {
        this->_numbers = _numbers;
    }

    virtual std::string label()
    {
        return "Remove a Number";
    }

    virtual void selected()
    {
        // get the number
        double number;
        std::cout << "Number: ";
        std::cin >> number;
         
        // remove the number from the vector (if it is there)
        auto itr = std::find(_numbers->begin(), _numbers->end(), number);
        if(itr != _numbers->end()) {
            _numbers->erase(itr);
        } else {
            std::cout << "Number not found." << std::endl;
        }
    }
private:
    std::vector<double> *_numbers;
};
 

//////////////////////////////////////////
// Manage Numbers Implementation
//////////////////////////////////////////

//constructor
Manage_Numbers::Manage_Numbers(std::vector<double> *_numbers)
{
    this->_numbers = _numbers;
}

//implementation of Menu_Item
std::string Manage_Numbers::label()
{
    return "Manage Numbers";
}

void Manage_Numbers::selected()
{
    //build the menu
    Menu menu;
    Quit_Menu *quit = new Quit_Menu("Previous Menu");
    Add_Number *add = new Add_Number(_numbers);
    Print_Numbers *print = new Print_Numbers(_numbers);
    Remove_Number *remove = new Remove_Number(_numbers);

    menu.add_item(print);
    menu.add_item(add);
    menu.add_item(remove);
    menu.add_item(quit);

    //perform the menu loop
    while(not quit->quit()) {
        menu.run();        
    }

    //destroy the menu items
    delete quit;
    delete add;
    delete print;
}

void 