#ifndef SHAPES_H  
#define SHAPES_H


class Shape
{

public:
Shape();
void shape_name();
double area_of_the_shape(int length, int breadth);

private:

int _length;
int _breadth;

};

#endif