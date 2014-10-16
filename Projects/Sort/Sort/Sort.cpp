/*
Student: Jared Wallace
Assignment #: PA 8
Assignment Description: Sort an array of numbers from least to greatest.
Issue Date: n/a
Due Date: March 30, 2012
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program will read a set of numbers from a file, store them into an array,
and then use an algorithm to sort them from least to greatest.  The sorted numbers will
then be written to a file.
*/
#include <iostream>
#include <fstream>
#include "prototypes.h"

using namespace std;

void main()
{
	ifstream fin("data.dat");
	ofstream fout("sorted.dat");
	int Arr[10];

	if (!fin)
		{
			cerr << "File can't be opened";
			exit(1);
		}

	for (int i=0; i<10; i++)
		{
			fin >> Arr[i];
		}

	sort (Arr, 10);
	printArray (Arr, fout);

	cout << "Press <enter> to close this window";
	cin.get();
}

