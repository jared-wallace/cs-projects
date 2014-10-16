#include <fstream>

void CreateC (int arr1[][10], int arr2[][10])
{

	for (int i=4; i<7; i++)
		{
			for (int j=5; j<9; j++)
			{
				arr2[i][j] = arr1[i][j];
			}
		}
}