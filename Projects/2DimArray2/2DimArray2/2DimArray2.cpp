/*
Student: Jared Wallace
Assignment #: PA 9
Assignment Description: Create, manipulate, and print 2 dimensional arrays.
Issue Date: n/a
Due Date: 4-17-2012
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program will create the original 10X10 array from a data file (pa9input.dat) and then extract certain values that will be placed in arrays B and C.
The arrays B and C will be added together (matrix addition style) and placed into array D.  Finally, the contents of array D will be appended to array B.
All four resultant arrays will be printed to a seperate file (styled array*.dat, where * is the letter).

*note* The arrays will all be printed as 10X10, with zeros used as placeholders.
*/
#include <iostream>
#include <fstream>
#include "prototypes.h"

using namespace std;

void main()
{
	int ArrayA[10][10], ArrayB[10][10], ArrayC[10][10], ArrayD[10][10];

	ifstream fin("pa9input.dat");
	ofstream outFile1("arrayA.dat"), outFile2("arrayB.dat"), outFile3("arrayC.dat"), outFile4("arrayD.dat");

	if (!fin)
	{
		cerr << "Could not open input data file pa9input.dat";
		exit(1);
	}

	//read data file values into Array A
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			fin >> ArrayA[i][j];
		}
	}
	
	CreateB (ArrayA, ArrayB);
	CreateC (ArrayA, ArrayC);
	CreateD (ArrayB, ArrayC, ArrayD);
	AddArray (ArrayB, ArrayD);
	PrintArray (ArrayA, outFile1);
	PrintArray (ArrayB, outFile2);
	PrintArray (ArrayC, outFile3);
	PrintArray (ArrayD, outFile4);
	
	cout << "Press <enter> to terminate the program";
	cin.get();
}