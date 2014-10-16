/*
  @author: Jared Wallace
  @date: 10-25-2012

  This program is a basic ascii art generator. It can draw a few basic shapes like lines, squares,
  rectangles, right triangles and a United States flag.

*/
#include <iostream>
#include <string>
#include <stdio.h>
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

int main ()
{
  int width = 0, length = 0, choice = 0;
  char symbol = ' ';

  do
  {
    Shape clear;
    clear.screen();
    cout << "What would you like to draw?" << endl << endl;
    cout << "1) Vertical line\n";
    cout << "2) Horizontal line\n";
    cout << "3) Wide spaced horizontal line\n";
    cout << "4) Hollow square\n";
    cout << "5) Solid square\n";
    cout << "6) Hollow rectangle\n";
    cout << "7) Solid rectangle\n";
    cout << "8) Regular triangle\n";
    cout << "9) Upside down triangle\n";
    cout << "0) Flag\n";
    cout << "11) Quit\n";
    cout << "\nEnter choice: ";
    cin >> choice;
    clear.screen();

    if (choice == 11)
    {
        cout << "\n\nLive long and prosper\n\n";
        return 0;
    }

    if (choice)
    {
      cout << "\nWhat symbol would you like to use? ";
      cin.ignore();
      symbol = getchar();
      cin.clear();
      cin.ignore(9999, '\n');
    }

    Rectangle rect;
    Triangle tri;

    rect.setSymbol( symbol);
    tri.setSymbol( symbol);

    switch (choice)
    {
      case 1:
        cout << "\nHow tall do you want the line? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> width;
        length = width;
        if (rect.inputValidate( length, width))
          rect.draw( 1, width, false);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 2:
        cout << "\nHow wide do you want the line? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> width;
        length = width;
        if (rect.inputValidate( length, width))
            rect.draw( width, 1, false);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 3:
        cout << "\nHow wide do you want the line? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> width;
        length = width;
        Rectangle wide;
        if (rect.inputValidate( length, width))
          rect.draw( width, 1, true);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 4:
        cout << "\nHow long do you want each side? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> width;
        length = width;
        if (rect.inputValidate( length, width))
          rect.hollow( length, width);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 5:
        cout << "\nHow long do you want each side? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> width;
        length = width;
        if (rect.inputValidate( length, width))
          rect.draw(length, width, true);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 6:
        cout << "\nHow long do you want the rectangle? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> length;
        cout << "How wide do you want the rectangle? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> width;
        if (rect.inputValidate( length, width))
          rect.hollow( length, width);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 7:
        cout << "\nHow long do you want the rectangle? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> length;
        cout << "How wide do you want the rectangle? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> width;
        if (rect.inputValidate( length, width))
          rect.draw( length, width, true);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 8:
        cout << "\nHow wide do you want the base of the triangle? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> length;
        width = length;
        if (tri.inputValidate( length, width))
          tri.draw(length, false);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 9:
        cout << "\nHow wide do you want the base of the triangle? ";
        cout << "The value given must be between 1 and 35. ";
        cin >> length;
        width = length;
        if (tri.inputValidate( length, width))
          tri.draw( length, true);
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      case 0:
        rect.flag();
        cout << "\nPress <enter> to return to the main menu. ";
        cin.get();
        cin.ignore();
        break;
      default:
        cout << "You screwed the pooch this time...error in switch statement";
    }

  }while(true);

}
