/*
Name: Jared Wallace
CS1428.09
09-18-2012

The program accepts as input any positive integer.
The program uses no constants
The program outputs the sum of the integers between 1 and the integer the client inputs.

This program will compute the sum of all integers between 1 and the number the client selects.
It will then output the sum to a file named lab6_02.txt

*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int sum = 0, endingInteger =0;
    ofstream fout;

    cout << "Please enter a positive integer ";
    cin >> endingInteger;
    if (endingInteger<0)
    {
        cout << "Real cute man...try a positive integer next time.";
        cout << endl << "Press <enter> to end this program";
        cin.get();
        cin.ignore();
    }

    for (int i=1; i<endingInteger+1; i++)
    {
        sum += i;
    }

    fout.open("lab6_02.txt");
    fout << "You entered the number " << endingInteger << endl;
    fout << "The sum of the numbers from 1 to " << endingInteger << " is " << sum;
	return 0;
}

