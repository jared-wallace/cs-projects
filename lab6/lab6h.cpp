/*
    Jared Wallace
    cs1428 section 9
    10-09-2012

    This program accepts a file as input. The user is prompted for the filename.

    This program has no constants.

    This program can output certain statements, depending on the contents of the input file.

    This is out first foray into writing our own programming language.Pretty damn cool to be honest.
    Gives me a certain appreciation for the people who write real languages ;)
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    string fileName;
    int array[256] = {}, instruction = 0, target = 0, left = 0, right = 0;
    ifstream fin;

    cout << "Enter the name of the input file ";
    cin >> fileName;

    fin.open(fileName.c_str());

    if (!fin)
    {
        cout << "You entered the name of a file that doesn't exist.";
        cout << "\n\nDumbass.\n\n";
        main();     //just for you Asa
    }

    do
    {
        instruction = target = left = right = 0;
        fin >> instruction >> target >> left >> right;
        switch (instruction)
        {
            case 0:
                array[target] = array[left] + array[right];
                break;
            case 1:
                array[target] = array[left] - array[right];
                break;
            case 2:
                array[target] = array[left] * array[right];
                break;
            case 3:
                array[target] = array[left] / array[right];
                break;
            case 4:
                array[target] = pow(array[left], array[right]);
                break;
            case 5:
                cout << "\nEnter the value you wish to store ";
                cin >> array[target];
                break;
            case 6:
                cout << endl << array[target] << endl;
                break;
            case 7:
                array[target] = left;
                break;
            default:
                cout << "You screwed something up idiot." << endl;
        }
    }while (!fin.eof());

    fin.close();
}
