#include <iostream>
#include <string>

using namespace std;

int bezout(int, int, int, int, int, int, int, int, int);
void clearScreen();

int main()
{
    int d1 = 0, d2 = 0, swap = 0, d3 = 0, x1 = 1, x2 = 0, y1 = 0, y2 = 1, k = 0, choice = 0;
    char keepGoing = 'y';

    do
    {
      clearScreen();
      cout << "Enter the two numbers now.\n\n";
      cin >> d1 >> d2;
      if (d1 < d2)
      {
        swap = d1;
        d1 = d2;
        d2 = swap;
      }

      bezout(d1, d2, x1, x2, y1, y2, k, d1, d2);
      cout << "Do you wish to enter another set of numbers? (y/n)";
      cin >> keepGoing;

    }while(keepGoing == 'y' || keepGoing == 'Y');


    return 0;
}

int bezout(int d1, int d2, int x1, int x2, int y1, int y2, int k, int origD1, int origD2)
{

    int d3 = 0, x3 = 0, y3 = 0;

    k = d1/d2;
    d3 = d1%d2;

    x3 = x1-x2*k;
    y3 = y1-y2*k;

    x1 = x2;
    y1 = y2;
    x2 = x3;
    y2 = y3;
    d1 = d2;
    d2 = d3;

    if (d3 == 0)
    {
        cout << "The equation is " << origD1 << "(" << x1 << ")" << " + " << origD2 << "(" << y1 << ") = " << d1 << ".\n\n";
        if (d1 == 1)
        {
            if (x1<0)
                x1 = x1 + origD2;
            if (y1<0)
                y1 = y1 + origD1;
            cout << "In addition, the multiplicative inverse of " << origD1 << " is " << x1;
            cout << " and the multiplicative inverse of " << origD2 << " is " << y1 << endl << endl;
        }
        return 0;
    }

    bezout(d1, d2, x1, x2, y1, y2, k, origD1, origD2);
}

void clearScreen()
{
    cout << string(90, '\n');
}
