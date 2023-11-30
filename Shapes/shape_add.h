///////////////////////////////////////////////////////////////////////////
// File: shape_add.h
// Purpose: Shape add handler.
///////////////////////////////////////////////////////////////////////////
#ifndef SHAPE_ADD_H
#define SHAPE_ADD_H
#include "menu_item.h"

class Shape_Add: public Menu_Item
{
public:
    virtual std::string label();
    virtual void selected();
};
class Square: public shape {
public:
 square(int a = 0, int b = 0):shape(a,b) {}
int area () {
  std::cout << "Square class area :" <<std::endl;
  return (width * hight);
}
};
class Circle:  public shape {
public:
 Circle (int a= 0, int b = 0): shape(a,b) {}
};
class traingle:public shape{
public:
traingle(int a=0,int b=0):shape(a,b){}
int main(){
  std::cout<<"Area of the traingle:"<<std::endl;
  return(base*height)*0.5;
}
class rectangle: public shape{
public;
rectangle(int a=0, int b=0): shape(a,b){}
ini area(){
  std::cout<< "rectangle class area:" <<std::endl:
return(length * breath);
}
};
}
#endif