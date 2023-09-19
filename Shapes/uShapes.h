///////////////////////////////////////////////////////////////////////////
// File: shape.h
// Purpose: Pure abstract class to represent shapes.
///////////////////////////////////////////////////////////////////////////
#ifndef USHAPES_H
#define USHAPES_H

// Logic

/*
First I will create a menu to display the users. 
*/
int welcome_user(){return 0};
// The welcome user will ask for thge input from the user store it in the variable integer
// and pass it to other function called manage menu
void manage_menu(0){
  /*  It will make use of switch cases and will redirect the users to the selected menu

  while not false it will run the program
  Case 1:
    add_shapes();
  Case 2:
    view_shapes();
  Case 3:
    view_shapes();
    delete_shapes();
  */
}




class Shapes
{
public:
    virtual int display_menu();
    virtual void add_shapes();
    virtual void view_shapes();
    virtual void delete_shapes();

private:
    int _menu_option;
};
#endif