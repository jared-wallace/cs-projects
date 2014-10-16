#include <cmath>
#include <iostream>
#include <fstream>

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

	//read data file values into Array A and print them to file
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			fin >> ArrayA[i][j];
			outFile1 << ArrayA[i][j] << " ";
		}
		outFile1 << endl;
	}

	//create and populate array B
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<4; j++)
			ArrayB[i][j] = ArrayA[i][j];
	}
	
	//create and populate array C and print to file
	for (int i=4; i<7; i++)
	{
		for (int j=5; j<9; j++)
		{
			ArrayC[i][j] = ArrayA[i][j];
			outFile3 << ArrayC[i][j] << " ";
		}
		outFile3 << endl;
	}
	
	//create and populate array D with sum of Array B and Array C, then print to file
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<4; j++)
		{
			ArrayD[i][j] = ArrayB[i][j] + ArrayC[i+4][j+5];
			outFile4 << ArrayD[i][j] << " ";
		}
		outFile4 << endl;
	}
	
	//Add Array D to Array B starting at position 6,0
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<4; j++)
			ArrayB[i+5][j] = ArrayD[i][j];
	}
	
	//print Array B to file
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			//To fill in the missing values...
			if (ArrayB[i][j] < 0 || ArrayB[i][j] > 150)
				ArrayB[i][j] = 0;
			outFile2 << ArrayB[i][j] << " ";
		}
		outFile2 << endl;
	}


	cout << "Press <enter> to terminate the program";
	cin.get();

}