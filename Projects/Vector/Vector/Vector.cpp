/*
Student: Jared Wallace
Assignment #: PA 6
Assignment Description: Write a program that reads x and y coordinates from a file,
	calculates vector lengths and positive radian and degree angles, and writes the 
	data to a file which includes the x, y points plus the calculated data.
Issue Date: n/a
Due Date: 3-9-2012
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program will read (x,y) coordinates from a file specified by the client
and calculate both the magnitude and the angle (relative to the x-axis) of the relevant vector.
The program will then write the original coordinates, along with the calculated values,
both to the screen and to a file specified by the client.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "prototypes.h"

using namespace std;

void main()
{

	double Mag, Rad, Deg;
	string filename;
	int data[24], count(0), xCoor, yCoor;
	ifstream fin;
	ofstream fout;

	cout << "Please enter the filename of the input file and then press <enter>\n\n";
	cin >> filename;
	fin.open(filename.c_str());

	if (!fin)
	{
		cerr << "Could not open file " << filename;
		exit(1);
	}

	cout << "Please enter the filename for the output\n";
	cin >> filename;
	fout.open(filename.c_str());
	
	
	/*----------------------------------------------------------------------------------------------*/
	/*     pulls each set of coordinates and stores them consecutively in the array data[]          */
	for (int i=0; i<12; i++)
	{
		fin >> data[count];
		fin.ignore();//commas...
		count++;
		fin >> data[count];
		count++;
	}
	/*----------------------------------------------------------------------------------------------*/
	
	count = 0;
	/*----------------------------------------------------------------------------------------------*/
	/*                          handles one set of coordinates at a time                            */
	for (int i=0; i<12; i++)
	{
		xCoor = data[count];
		count++;
		yCoor = data[count];
		count++;
		Mag = Magnitude (xCoor, yCoor);
		Angle (Mag, xCoor, yCoor, Rad, Deg);
		WriteValues (xCoor, yCoor, Mag, Rad, Deg, cout);
		WriteValues (xCoor, yCoor, Mag, Rad, Deg, fout);
	}
	/*----------------------------------------------------------------------------------------------*/
	cout << "Press <enter> to close this window";
	cin.get();
	cin.ignore();
}
