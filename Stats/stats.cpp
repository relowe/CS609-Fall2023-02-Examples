#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include "quit_menu.h"
#include "manage_numbers.h"
#include "show_stats.h"

int main() {
    std::vector<double> numbers;
    
    // build the main menu
    Menu menu;
    Quit_Menu *quit = new Quit_Menu();
    Manage_Numbers *manage = new Manage_Numbers(&numbers);
    Show_Stats *stats = new Show_Stats(&numbers);

    menu.add_item(manage);
    menu.add_item(stats);
    menu.add_item(quit);

    while(not quit->quit()) {
        menu.run();
    }

    // Destroy the menu items
    delete quit;
    delete manage;
    delete stats;
}