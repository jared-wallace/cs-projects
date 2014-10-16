#include <iostream>
#include <fstream>
#include <string>
#include "global.h"

using namespace std;

int inputBlock(double matrixX[nrows][ncols], double matrixY[nrows][ncols], int &rows1, int &cols1, int &rows2, int &cols2, string &filename3, bool &cont)
{
	string filename1, filename2;
	ifstream fin1, fin2;

	cout << "Please enter the filename of the first input file and then press <enter>\n\n";
	cin >> filename1;
	fin1.open(filename1.c_str());
	
	if (!fin1)
	{
		cerr << "Could not open file " << filename1 << "\n\nPlease try again.\n\n";
		system ("Pause");
		system ("Cls");
		cont = false;
		return(1);
	}
		
	cout << "\nPlease enter the number of rows and columns of the first matrix, \npressing <enter> after each value\n\n";
	cin >> rows1 >> cols1;

	for (int i=0; i<rows1; i++)
		{
			for (int j=0; j<cols1; j++)
			{
					fin1 >> matrixX[i][j];
			}
		}
		
	cout << "\nPlease enter the filename of the second input file and then press <enter>\n\n";
	cin >> filename2;
	fin2.open(filename2.c_str());

	if (!fin2)
	{
		cerr << "Could not open file " << filename2 << "\n\nPlease try again.\n\n";
		system ("Pause");
		system ("Cls");
		cont = false;
		return(1);
	}
			
	cout << "\nPlease enter the number of rows and columns of the second matrix, \npressing <enter> after each value\n\n";
	cin >> rows2 >> cols2;

	
	cout << "\nPlease enter the name of the file to be used for the output\n\n";
	cin >> filename3;
	system("CLS");//sigh...yes I'm using SYSTEM *hangs head* The alternative was 80 lines of additional code
				
	for (int i=0; i<rows2; i++)
	{
		for (int j=0; j<cols2; j++)
		{
			fin2 >> matrixY[i][j];
		}
	}
	cont = false;
	return(0);
}