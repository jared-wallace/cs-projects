//This function performs the AB (and if applicable) BA multiplication
//This particular function required some serious head scratching. There is probably a more eloquent solution...

#include "global.h"

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