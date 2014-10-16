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


using namespace std;

const int nrows=10, ncols=10;
double matrixA[nrows][ncols]={0}, matrixB[nrows][ncols]={0}, matrixC[nrows][ncols]={0}, matrixD[nrows][ncols]={0};
void multiply(double X[nrows][ncols], int rowsx, int colsx, double Y[nrows][ncols], int rowsy, int colsy, double Z[nrows][ncols], double Z2[nrows][ncols], int square);
void printarray(double X[nrows][ncols], int rowsx, int colsx, double Y[nrows][ncols], int rowsy, int colsy, double Z[nrows][ncols], double Z2[nrows][ncols], ostream& out, int square);

int main()
{
	int cont(0), rows1(0), cols1(0), rows2(0), cols2(0), input(0), square(1);
	string filename1, filename2, filename3;
	ifstream fin1, fin2;
	ofstream fout;

	cout << "Please enter the filename of the first input file and then press <enter>\n\n";
	cin >> filename1;
	fin1.open(filename1.c_str());
	
	if (!fin1)
	{
		cerr << "Could not open file " << filename1;
		exit(1);
	}
		
	cout << "\nPlease enter the number of rows and columns of the first matrix, \npressing <enter> after each value\n\n";
	cin >> rows1 >> cols1;

	for (int i=0; i<rows1; i++)
		{
			for (int j=0; j<cols1; j++)
			{
					fin1 >> matrixA[i][j];
			}
		}
		
	cout << "\nPlease enter the filename of the second input file and then press <enter>\n\n";
	cin >> filename2;
	fin2.open(filename2.c_str());

	if (!fin2)
	{
		cerr << "Could not open file " << filename2;
		exit(1);
	}
			
		cout << "\nPlease enter the number of rows and columns of the second matrix, \npressing <enter> after each value\n\n";
		cin >> rows2 >> cols2;

	/******************************************************************************************************************************************************************************** 
	error checking block
	*/
	if (rows1 <= 0 || rows2 <= 0 || cols1 <= 0 || cols2 <= 0)//outside permitted range
	{
		cout << "I don't think you meant to put a negative or zero\nnumber for the size of the array...\nPlease try again.\n\n";
		main();//to understand recursion, you must first understand recursion...(this only works inside of main btw)
	}
	if (rows1 > 10 || rows2 > 10 || cols1 > 10 || cols2 > 10)//outside permitted range
	{
		cout << "The maximum permitted size of the matrices is 10X10\nPlease try again.\n\n";
		main();
	}

	if (cols1 != rows2)//unable to multiply
	{
		cout << "\nMatrices are not compatible.  Please try again.\n\nRemember, the number of columns of the first matrix must match\nthe number of rows of the second matrix\n\n";
		main();
	}
			
	if (rows1 != rows2 || cols1 != cols2)//this one just flags the fact that BA multiplication will not work
	{
		cout << "\nMatrices are not square.  Only the first multiplication operation will be run.\n\n";
		square = 0;
	}
	/*********************************************************************************************************************************************************************************/
	
	cout << "\nPlease enter the name of the file to be used for the output\n\n";
	cin >> filename3;
	fout.open(filename3.c_str());
	system("CLS");//sigh...yes I'm using SYSTEM *hangs head* The alternative was 80 lines of additional code
				
	for (int i=0; i<rows2; i++)
	{
		for (int j=0; j<cols2; j++)
		{
			fin2 >> matrixB[i][j];
		}
	}
		
	multiply(matrixA, rows1, cols1, matrixB, rows2, cols2, matrixC, matrixD, square);
	printarray(matrixA, rows1, cols1, matrixB, rows2, cols2, matrixC, matrixD, fout, square);

	cout << "\nTo enter two more matrices, press 1. To end this program now press 2\n\n";//finally figured out how to cycle my program o_O
	cin >> input;
	if (input == 2)
	{
		exit(0);
	}
	system("CLS");
	main();
	}
//This function performs the AB (and if applicable) BA multiplication
//This particular function required some serious head scratching. There is probably a more eloquent solution...
void multiply(double X[nrows][ncols], int rowsx, int colsx, double Y[nrows][ncols], int rowsy, int colsy, double Z[nrows][ncols], double Z2[nrows][ncols], int square)
{
	double interim(0);
	for (int i=0; i<rowsx; i++)
	{
		for (int j=0; j<colsy; j++)
		{
			for (int k=0; k<rowsy; k++)
			{
				interim += X[i][k] * Y[k][j];
			}

			Z[i][j] = interim;
			interim = 0;
		}
	}
	
	
	if (square)
	{

	for (int i=0; i<rowsy; i++)
	{
		for (int j=0; j<colsx; j++)
		{
			for (int k=0; k<rowsx; k++)
			{
				interim += Y[i][k] * X[k][j];
			}

			Z2[i][j] = interim;
			interim = 0;
		}
	}
	}
}

void printarray(double X[nrows][ncols], int rowsx, int colsx, double Y[nrows][ncols], int rowsy, int colsy, double Z[nrows][ncols], double Z2[nrows][ncols], ostream& out, int square)
{
	cout << "\nMatrix A looks like:\n\n";
	out << "\nMatrix A looks like:\n\n";
	for (int i=0; i<rowsx; i++)
	{
		for (int j=0; j<colsx; j++)
		{
			cout << X[i][j] << " ";
			out << X[i][j] << " ";
		}
		cout << "\n\n";
		out << "\n\n";
	}

	cout << "\nMatrix B looks like:\n\n";
	out << "\nMatrix B looks like:\n\n";
	for (int i=0; i<rowsy; i++)
	{
		for (int j=0; j<colsy; j++)
		{
				cout << Y[i][j] << " ";
				out << Y[i][j] << " ";
		}
		cout << "\n\n";
		out << "\n\n";
	}

	cout << "\n\nThe first resultant matrix looks like:\n\n";
	out << "\n\nThe first resultant matrix looks like:\n\n";
	for (int i=0; i<rowsx; i++)
	{
		for (int j=0; j<colsy; j++)
		{
			cout << Z[i][j] << " ";
			out << Z[i][j] << " ";
		}
		cout << "\n\n";
		out << "\n\n";
	}

	if (square)
	{
	cout << "\n\nThe second resultant matrix looks like:\n\n";
	out << "\n\nThe second resultant matrix looks like:\n\n";
	for (int i=0; i<rowsy; i++)
	{
		for (int j=0; j<colsx; j++)
		{
			cout << Z2[i][j] << " ";
			out << Z2[i][j] << " ";
		}
		cout << "\n";
		out << "\n";
	}
	}
}