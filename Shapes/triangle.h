
#ifndef TRAINGLE_H
#define TRAINGLE_H
#include "shape.h"
#include "shape_add.h"

class triangle : public Shape {
public:
  virtual double height(int i) = 0;
  virtual double base() = 0;
  virtual double area() = 0;
  
};



#endif