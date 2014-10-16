#include <iostream>
#include <fstream>

void PrintArray (int arr[][10], std::ostream& out)
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			if (arr[i][j] < 0 || arr[i][j] > 200)
				arr[i][j] = 0;
			out << arr[i][j] << " ";
		}
		out << std::endl;
	}
	out << std::endl;
}