void CreateD (int arr1[][10], int arr2[][10], int arr3[][10])
{
	for (int i=0; i<3; i++)
		{
			for (int j=0; j<4; j++)
			{
				arr3[i][j] = arr1[i][j] + arr2[i+4][j+5];
			}
		}
}