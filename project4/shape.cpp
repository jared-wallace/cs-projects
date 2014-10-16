#include "shape.h"
#include <iostream>

using namespace std;

//Accessors
int Shape::getLength() const
{
  return length;
}

int Shape::getWidth() const
{
  return width;
}

char Shape::getSymbol() const
{
  return symbol;
}

bool Shape::getWide() const
{
  return wide;
}

bool Shape::getFlipped() const
{
  return flipped;
}

//just clears the screen
void Shape::screen() const
{
    cout << string(90, '\n');
}

//mutators
void Shape::setWide( bool yes)
{
  if (yes)
    wide = true;
  else
    wide = false;
}


void Shape::setFlipped(bool yes)
{
    if (yes)
      flipped = true;
    else
      flipped = false;
}

void Shape::setWidth(int w)
{
  width = w;
}

void Shape::setLength(int l)
{
  length = l;
}

void Shape::setSymbol( char sym)
{
  symbol = sym;
}

/*
  The program only accepts values between 1 and 35 for maximum compatibility.
  This function makes sure both values are valid.
*/
bool Shape::inputValidate( int l, int w)
{
  if (w<1 || w>35)
  {
    cout << "\nWidth value out of range. Please try again using a value between 1 and 35. \n";
    return false;
  }

  if (l<1 || l>35)
  {
    cout << "\nLength value out of range. Please try again using a value between 1 and 35. \n";
    return false;
  }

  return true;
}
