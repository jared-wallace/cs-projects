/*---------------------------------------------------------------------------------------------
Student: Jared Wallace
Assignment #: PA 7
Assignment Description: In essence, show dexterity with the manipulation of arrays.
Issue Date: n/a
Due Date: listed as 2-23-12 (typo?)
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program takes an initial array of 10 values, drawn from an input file,
and performs several operations on the values.  All operations are contained within the relevant
functions.  The initial values, and the resultant values, are printed to the screen
as well as several different files.
----------------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "prototypes.h"

using namespace std;

void main()
{
	ifstream fin("pa7input.dat");
	ofstream outFile1("arrayOut.dat"), outFile2("sub1Out.dat"),
		outFile3("sub2Out"), outFile4("addArray.dat"), outFile5("multArray.dat");
	int initArray[10], subArray1[5], subArray2[5], subArray3[5], subArray4[5];

	if (!fin)
	{
		cerr << "Problem opening data file\n";
		exit(1);
	}

	for (int i=0; i<10; i++)
	{
		fin >> initArray[i];
	}

	splitArray (initArray, subArray1, subArray2);
	writeArray (initArray, 10, outFile1);
	writeArray (subArray1, 5, outFile2);
	writeArray (subArray2, 5, outFile3);

	addArray (subArray1, subArray2, subArray3);
	writeArray (subArray3, 5, outFile4);

	multArray (subArray1, subArray2, subArray4);
	writeArray (subArray4, 5, outFile5);

	cout << "\nPress <enter> to close this window";
	cin.get();
}
