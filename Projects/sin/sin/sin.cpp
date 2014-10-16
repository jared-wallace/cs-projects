/*
This will calculate the sin of angles of a given range of degrees, inclusive, by increments of the client's choosing.
The output (sin values) will be printed as they are calculated.
I realize this is quite a bit more capability than requested, but I felt the original program was far too limited
in its usefulness.
Jared Wallace
PA 3 (for loop)
01/24/2012
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

void main ()
{
	double current, temp, duration, increments;
	int initial(0), end;

	cout << "This program will calculate the sin of angles from a range of degrees\n";
	cout << "by increments of your choice (also in degrees)\n";
	cout << "For example, for the sin of angles from 10 to 40 degrees by increments\nof 2 degrees, enter 10, then 40, and finally 2\n";
	cout << "Enter the starting value of the range of angles\n";
	cin >> initial;
	cout << "Enter the ending value of the range of angles\n";
	cin >> end;
	cout << "Enter the increments in degrees\n";
	cin >> increments;

	duration = (end-initial)/increments;
	duration++;

	for (int i=duration; i>0; i--)
	{
		current = sin (initial*M_PI/180);
		//temp = initial*180/M_PI;//converting radians to degrees
		if (current < .0001 && current > -.0001)//to catch sin 180 and sin 360
		{
			current = 0;
			cout << "The sin of " << initial << " degrees is " << current << "\n";
			initial = initial + increments;//(increments*M_PI)/180;
		}
		else
		{
		cout.precision(4);//for legibility, no precision was specified in the assignmnet
		cout << "The sin of " << initial << " degrees is " << current << "\n";
		initial = initial + increments;//(increments*M_PI)/180;
		}
	}
	cout << "Press <enter> to continue\n\n";
	cin.ignore();
	cin.get();
}
