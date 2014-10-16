/*
This function accepts two matrices, the filename of the output file, rows/columns of the original matrix, and the desired stream  (cout/fout)
It returns nothing, obviously.
*/
#include "Global.h"
#include <string>
#include <fstream>

using namespace std;

void Print(double matrixA[nrows][ncols], double matrixB[nrows][ncols], string &filename2, int rowsx, int colsx, std::ostream &out)
{
	out << "The first matrix looks like:\n\n";

	for (int i=0; i<rowsx; i++)
	{
		for (int j=0; j<colsx; j++)
		{
			out << matrixA[i][j] << " ";
		}
		out << endl;
	}

	out << "The transposed matrix looks like:\n\n";

	for (int i=0; i<colsx; i++)
	{
		for (int j=0; j<rowsx; j++)
		{
			out << matrixB[i][j] << " ";
		}
		out << endl;
	}
}