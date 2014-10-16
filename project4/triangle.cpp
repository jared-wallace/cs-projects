#include "triangle.h"
#include <iostream>

using namespace std;

/*
  This function accepts two parameters, length and orientation.
  Based on what is passed, it sets Shape's member variables
  appropiately and draws the correct triangle.
*/
void Triangle::draw(int length, bool flipped)
{
    setLength( length);
    setFlipped( flipped);

    int len = 0;

    if (getFlipped())
      len = getLength();                        //first line is widest
    for (int i=0; i<getLength(); i++)
      {
        if (getFlipped())
          cout << string(len, getSymbol());
        else
          cout << string(len+1, getSymbol());
        cout << endl;
        if (getFlipped())
          len--;                                //gets smaller every pass
        else
          len++;                                //gets larger
      }
}
