void AddArray (int arr1[][10], int arr2[][10])
{

	for (int i=0; i<3; i++)
		{
			for (int j=0; j<4; j++)
				arr1[i+5][j] = arr2[i][j];
		}
}