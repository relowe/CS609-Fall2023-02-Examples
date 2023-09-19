///////////////////////////////////////////////////////////////////////////
// File: shape_manager.h
// Purpose: Shape manager handler.
///////////////////////////////////////////////////////////////////////////
#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H
#include "menu_item.h"
#include "shape.h"

class Shape_Manager: public Menu_Item
{
public:
    Shape_Manager(Shape *_shape);

    virtual std::string label();
    virtual void selected();

    //return the shape we are managing
    virtual Shape *shape();
private:
    Shape *_shape;
}

#endif