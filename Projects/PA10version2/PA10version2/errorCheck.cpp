//Accepts the row and columns for both matrices, and checks for various potential issues. Returns with
//a value of 1 if the user needs to try gain from the top, and 2 (to flag not square). No errors returns 0.

#include <iostream>
using namespace std;

int errorCheck(int rows1, int cols1, int rows2, int cols2)
{

if (rows1 <= 0 || rows2 <= 0 || cols1 <= 0 || cols2 <= 0)//outside permitted range
	{
		cout << "I don't think you meant to put a negative or zero\nnumber for the size of the array...\nPlease try again.\n\n";
		return(1);
	}
	if (rows1 > 10 || rows2 > 10 || cols1 > 10 || cols2 > 10)//outside permitted range
	{
		cout << "The maximum permitted size of the matrices is 10X10\nPlease try again.\n\n";
		return(1);
	}

	if (cols1 != rows2)//unable to multiply
	{
		cout << "\nMatrices are not compatible.  Please try again.\n\nRemember, the number of columns of the first matrix must match\nthe number of rows of the second matrix\n\n";
		system("Pause");
		return(1);
	}
			
	if (rows1 != rows2 || cols1 != cols2)//this one just flags the fact that BA multiplication will not work
	{
		cout << "\nMatrices are not square.  Only the first multiplication operation will be run.\n\n";
		return(2);
	}

	return(0);
}