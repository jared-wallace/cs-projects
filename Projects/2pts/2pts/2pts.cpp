/*--------------------------------------------------------------------------*/
/* Program chapter 1_1 */
/*																			*/
/* This program computes the distance between two points */
#include <iostream> // required for cout. endl
#include <cmath> // Required for sqrt()
#include <Windows.h> //for the sleep command, because I can't read very quickly :)

using namespace std;

int main()
{
		//	Declare and initialize objects
	double x1(1), y1(5), x2(4), y2(7), side1, side2, distance;

		// Let's make this more interesting by asking for the client to input the relevant points
		cout << "Input two sets of points (x,y) (x,y)" << endl << endl << "one value at a time, pressing <Enter> after each value has been entered" << endl << endl;
		cout << "First X value   ";
		cin >> x1; 
		cout << endl << "First Y value   ";
		cin >> y1;
		cout << endl << "Second X value   ";
		cin >> x2;
		cout << endl << "Second Y value   ";
		cin >> y2;


		// Compute the sides of a right triangle with Pythagorens theorem
		side1 = x2 - x1;
		side2 = y2 - y1;
		distance = sqrt(side1*side1 + side2*side2);

		//  Print distance
		cout << "The distance between the given points is "
			<< distance << endl;
		system("pause");
		
		//  Exit program
		return 0;
}
