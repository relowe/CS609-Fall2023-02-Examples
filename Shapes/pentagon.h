//////////////////////////////////////////////////////////////
///// file: Pentagon.h

#ifndef PENTAGON_H
#define PENTAGON_H
#include "shape.h"

class pentagon : public Shape{
public:

  virtual std::int sides;
  virtual double side_length(int i);
  virtual double area();
  virtual double perimeter();


};
#endif