#include "rectangle.h"
#include "shape.h"
#include <iostream>

using namespace std;

/*
  Accepts three parameters representing length, width and spacing of the
  desired rectangle. The function then sets Shape's member variables to
  the values passed to the function. The function then draws the desired
  rectangle.
  */
void Rectangle::draw(int len, int wid, bool wide)
{
  setWidth( wid);
  setLength( len);
  setWide( wide);
  if (getLength())
  {
    for (int i=0; i<getWidth(); i++)
    {
      for (int j=0; j<getLength(); j++)
      {
        cout << getSymbol();
        if (getWide())
        cout << " ";
      }
      cout << endl;
    }
  }
}

/*
  This function is similar to draw, but it draws a hollow shape instead. It
  accepts the same parameters as draw with the exception of spacing. This is
  because we don't ever draw just a line with this function.
*/
void Rectangle::hollow(int len, int wid)
{

  setWidth( wid);
  setLength( len);
  draw( getLength(), 1, true);
  setWidth( wid);
  for (int i=0; i<getWidth()-2; i++)
   {
     cout << getSymbol() << " ";
     for (int j=0; j<getLength()-2; j++)
       cout << "  ";
     cout << getSymbol();
     cout << endl;
   }
  draw( getLength(), 1, true);
}

void Rectangle::flag() const
{
    cout << endl;
    cout << "*   *   *   *   *   *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "  *   *   *   *   *\n";
    cout << "*   *   *   *   *   *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "  *   *   *   *   * \n";
    cout << "*   *   *   *   *   *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "  *   *   *   *   *\n";
    cout << "*   *   *   *   *   *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "  *   *   *   *   *\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << endl;
}
