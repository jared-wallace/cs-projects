/*
This function accepts both matrices and the rows/columns of the original matrix.
It returns nothing, but does change the values of matrix B
*/
#include "Global.h"

void Transpose(double matrixA[nrows][ncols], double matrixB[nrows][ncols], int rowsx, int colsx)
{
	for (int i=0; i<rowsx; i++)
		for (int j=0; j<colsx; j++)
		{
			matrixB[j][i] = matrixA[i][j];
		}
}