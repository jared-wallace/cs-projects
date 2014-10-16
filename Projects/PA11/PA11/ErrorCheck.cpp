#include <iostream>
#include "Global.h"

using namespace std;

void ErrorCheck(int rowsx, int colsx, bool &status)
{
	if (rowsx <= 0 || colsx <= 0)
	{
		status = 0;
		cerr << "You sure about those row and column sizes?\n\nHint: zeros or negative values won't fly (neither will letters)\nLet's try again...\n" << endl;
		system("Pause");
	}

	if (rowsx > nrows || colsx > ncols)
	{
		status = 0;
		cerr << "You sure about those row and column sizes?\n\nHint: The values given ( " << rowsx;
		cerr << " rows and " << colsx << " columns) exceed the maximum \npermitted";
		cerr << " (" << nrows << " rows and " << ncols << " columns)\n\nLet's try again...\n\n";
		system("Pause");
	}
}