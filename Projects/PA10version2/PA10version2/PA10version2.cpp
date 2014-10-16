/* 
Student: Jared Wallace
Assignment #: PA 10
Assignment Description: Accept 2 matrices of variable size, up to 10X10, from file specified by instructor and manipulate, then print.
Issue Date: n/a
Due Date: 4-21-2012
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program will prompt for two data file names, as well as the desired size of each matrix.  The program will check for compatibility in size between the two matrices,
and then will multiply them AB and BA style.  After each multiplication, the result will be displayed to screen and written to a data file specified by the user.  The program
will also anaylze the reults to discover whether they are ientical, with the answer being outputted to screen only.  After this, the program will prompt the user
to choose to terminate he program or start over with a new set of matrices.

Note: I left both functions in the main file just because I'm too lazy-er-time pressed to throw them out into separate files.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Prototypes.h"

using namespace std;

int main()
{
	bool cont(false);
	int rows1(0), cols1(0), rows2(0), cols2(0), input(0), square(1);
	string filename1, filename2, filename3;
	ifstream fin1, fin2;
	ofstream fout;
	
	while (!cont)
	{
	
	inputBlock(matrixA, matrixB, rows1, cols1, rows2, cols2, filename3, cont);
	if (!cont)
		inputBlock(matrixA, matrixB, rows1, cols1, rows2, cols2, filename3, cont);
	switch (errorCheck(rows1, cols1, rows2, cols2))
	{
	case 1:
		inputBlock(matrixA, matrixB, rows1, cols1, rows2, cols2, filename3, cont);
		break;
	case 2:
		square = 0;
		break;
	default:
		cout << "WTF?";
	}
	fout.open(filename3.c_str());
	multiply(matrixA, rows1, cols1, matrixB, rows2, cols2, matrixC, matrixD, square);
	printarray(matrixA, rows1, cols1, matrixB, rows2, cols2, matrixC, matrixD, fout, square);

	cout << "\nTo enter two more matrices, press 1. To end this program now press 2\n\n";//finally figured out how to cycle my program o_O
	cin >> input;
	if (input == 2)
	{
		exit(1);
	}
	system("CLS");
	}
}