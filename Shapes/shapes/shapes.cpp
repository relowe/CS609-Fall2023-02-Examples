#include "shapes.h"
#include <string>
#include <ostream>
#include <iostream>

Shape::Shape() {}

void Shape::shape_name()
{
  std::cout << "You have triggered shape class methods" << std::endl;
}

double Shape::area_of_the_shape(int length, int breadth)
{
  return length*breadth;
}