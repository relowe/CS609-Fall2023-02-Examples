///////////////////////////////////////////////////////////////////////////
// File: quit_menu.h
// Purpose: Implementation of a menu item for quitting.
///////////////////////////////////////////////////////////////////////////
#include "quit_menu.h"

// constructors
Quit_Menu::Quit_Menu(const std::string &_msg) {
  this->_msg = _msg;
  this->_quit = false;
}

Quit_Menu::Quit_Menu() : Quit_Menu("Quit") {
  // nothing to do, this just delegates with a default message.
}

// menu item implementation
std::string Quit_Menu::label() { return _msg; }

void Quit_Menu::selected() { _quit = true; }

// Returns true if the quit function has been selected.
bool Quit_Menu::quit() { return _quit; }