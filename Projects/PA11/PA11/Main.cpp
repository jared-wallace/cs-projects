/* 
Student: Jared Wallace
Assignment #: PA 11
Assignment Description: Accept a matrix from a file, and transpose it.
Issue Date: n/a
Due Date: 4-21-2012
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program will prompt for a filename of a file containing a matrix.  It will then prompt for the desired size.  After checking the size to make sure it
within the proper limits, it will transpose the matrix, ajnd print both matrices to screen and specified file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Transpose.h"
#include "Print.h"
#include "ErrorCheck.h"
#include "Global.h"

using namespace std;

int main()
{
	bool status(true);
	int rowsx(0), colsx(0);
	ifstream fin;
	ofstream fout;
	string filename1, filename2;
	char input;
	double matrixA[nrows][ncols]={0}, matrixB[nrows][ncols]={0};

	system("Cls");
	cout << "Please enter the filename of your data file, then press <enter>.\n\n";
	cin >> filename1;
	fin.open(filename1.c_str());
	if (!fin)//tells user why, restarts program
	{
		cerr << "\n\nCould not open the file specified\n\n";
		system("Pause");
		main();
	}

	system("Cls");
	cout << "Please enter the number of rows the matrix contains\n\n";
	cin >> rowsx;
	if (cin.fail())//resets stream fail state and flushes whatever garbage was entered
	{
		cerr << "You need to enter numbers here Einstein.  Try again." << endl;
		system("Pause");
		cin.clear();
		cin.ignore(1024, '\n');
		main();
	}
	cout << "\n\nPlease enter the number of columns the matrix contains\n\n";
	cin >> colsx;
	if (cin.fail())
	{
		cerr << "You need to enter numbers here Einstein.  Try again." << endl;
		system("Pause");
		cin.clear();
		cin.ignore(1024, 'n');
		main();
	}
	system("Cls");

	ErrorCheck(rowsx, colsx, status);
	if (!status)//too big or too small of a matrix specified, starts over
		main();

	for (int i=0; i<rowsx; i++)
		for (int j=0; j<colsx; j++)
			fin >> matrixA[i][j];

	Transpose(matrixA, matrixB, rowsx, colsx);
	cout << "Please enter the filename you wish to use for the output, then press <enter>\n\n";
	cin >> filename2;
	fout.open(filename2.c_str());
	system("Cls");
	Print(matrixA, matrixB, filename2, rowsx, colsx, cout);
	Print(matrixA, matrixB, filename2, rowsx, colsx, fout);

	do
	{
		cout << "Would you like to enter another matrix? [y/n]" << endl;
		cin >> input;
	}
	while( !cin.fail() && input!='y' && input!='n' );

	if (input == 'y')
	{
		system("Cls");
		main();
	}
}


