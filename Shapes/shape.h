///////////////////////////////////////////////////////////////////////////
// File: shape.h
// Purpose: Pure abstract class to represent shapes.
///////////////////////////////////////////////////////////////////////////
#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
public:
    virtual int sides()=0;
    virtual double side_length(int i)=0;
    virtual double area()=0;
    virtual double perimeter()=0;
};
#endif