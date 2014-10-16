/*
  @author: Jared Wallace
  @date: 10-25-2012

  This program is a basic ascii art generator. It can draw a few basic shapes like lines, squares,
  rectangles, right triangles and a United States flag.

  I realize that normally class declarations would be written in a separate file, but we can only
  upload one file :/
*/
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


class Shape
{
  private:
    bool wide, flipped;
    double width;
    double length;
    char symbol;
  public:
    void setWidth( int);
    void setLength( int);
    void setWide( bool);
    void setFlipped( bool);
    void setSymbol( char);
    void screen() const;
    bool inputValidate( int, int);
    int getLength() const;
    int getWidth() const;
    char getSymbol() const;
    bool getWide() const;
    bool getFlipped() const;


};

class Rectangle : public Shape
{
  public:
    void draw( int, int, bool);
    void hollow() const;
    void flag() const;
};

class Triangle : public Shape
{
  public:
    void draw() const;
};

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

void Shape::screen() const
{
    cout << string(90, '\n');
}


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

void Rectangle::hollow() const
{
  if (getLength())
    {
      for (int i=0; i<getWidth()-2; i++)
      {
        cout << getSymbol() << " ";
        for (int j=0; j<getLength()-2; j++)
          cout << "  ";
        cout << getSymbol();
        cout << endl;
      }
    }
}
/*
  This function draws both types of triangles.
*/
void Triangle::draw() const
{
    int len = 0;

    cout << endl;
    if (getFlipped())
      len = getLength();
    for (int i=0; i<getLength(); i++)
      {
        if (getFlipped())
          cout << string(len, getSymbol());
        else
          cout << string(len+1, getSymbol());
        cout << endl;
        if (getFlipped())
          len--;
        else
          len++;
      }
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

    //uses cin.get so we only grab the first character entered
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
        {
          rect.draw( width, 1, true);
          rect.setWidth( width);
          rect.hollow();
          rect.draw( width, 1, true);
        }
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
        {
          rect.draw(length, 1, true);
          rect.setWidth( width);
          rect.hollow();
          rect.draw( length, 1, true);
        }
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
        {
          rect.draw( length, width, true);
        }
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
        {
          cout << endl;
          tri.setLength( length);
          cout << endl;
          tri.setFlipped( false);
          tri.draw();
        }
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
        {
          cout << endl;
          tri.setLength( length);
          cout << endl;
          tri.setFlipped( true);
          tri.draw();
        }
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
