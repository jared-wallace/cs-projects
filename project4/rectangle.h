#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
  public:
    void draw( int, int, bool);
    void hollow(int, int);
    void flag() const;
};

#endif
