///////////////////////////////////////////////////////////////////////////
// File: menu.cpp
// Purpose: Implementation of the menu class
///////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <iostream>
#include "menu.h"
#include "menu_item.h"

// Constructor
Menu::Menu()
{
    // nothing to do (for now)
}

// Add an item to the menu
void Menu::add_item(Menu_Item *item)
{
    _items.push_back(item);
}

// Remove an item from the menu
void Menu::remove_item(Menu_Item *item)
{
    // TODO 
}

// Run the menu
void Menu::run()
{
    bool done = false;
    int choice;

    while(not done) {
        //display the menu
        for(int i=0; i<_items.size(); i++) {
            std::cout << i+1 << ".) " << _items[i]->label() << std::endl;
        }

        //get the user choice
        std::cout << "Choice? ";
        std::cin >> choice;
        choice--;

        if(choice < 0 or choice >= _items.size()) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        } else {
            done = true;
        }
    }

    // run the selected choice
    _items[choice]->selected();
}
