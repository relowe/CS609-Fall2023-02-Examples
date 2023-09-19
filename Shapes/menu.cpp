#include <iostream>
#include <vector>
#include <string>
#include "menu.h"

// Constructor
Menu::Menu() {}

// Add item to menu
void Menu::add_item(Menu_Item *item) 
{
  _items.push_back(item);  
}

// If present, remove an item from menu
void Menu::remove_item(Menu_Item *item) 
{
  auto itr = std::find(_items.begin(), _items.end(), item);
  if(itr != _items.end()) {
            _items.erase(itr);
        } else {
            std::cout << "Number not found." << std::endl;
        }
}

void Menu::run()
{
  bool done = false;
  int choice;

    while(not done) {
        // Display the menu
        for(int i=0; i<_items.size(); i++) {
            std::cout << i+1 << ".) " << _items[i]->label() << std::endl;
        }

        // Get the user's choice
        std::cout << "Choice? ";
        std::cin >> choice;
        choice--;

        if(choice < 0 or choice >= _items.size()) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        } else {
            done = true;
        }
    }

    // Run the selected choice
    _items[choice]->selected();
}