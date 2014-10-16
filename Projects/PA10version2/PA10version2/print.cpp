#include <iostream>
#include "global.h"

using namespace std;

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