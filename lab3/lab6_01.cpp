/*
Name: Jared Wallace
CS1428.09
09-18-2012

There are no inputs for this program.
There are no constants either.
The program will output two diamonds formed by stars

This program will use stars to form two pretty diamonds with a maximum width of 21 stars.
]
*/

#include <iostream>

using namespace std;

int main()
{

    for (int i=0; i<11; i++)
    {
        for (int j=0; j<10-i; j++)
        {
            cout << " ";
        }
        for (int j=0; j<i*2+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i=10; i>0; i--)
    {

        for (int j=0; j<11-i; j++)
        {
            cout << " ";
        }
        for (int j=2; j<i*2+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i=0; i<11; i++)
    {
        for (int j=0; j<10-i; j++)
        {
            cout << " ";
        }
        for (int j=0; j<i*2+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i=10; i>0; i--)
    {

        for (int j=0; j<11-i; j++)
        {
            cout << " ";
        }
        for (int j=2; j<i*2+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

