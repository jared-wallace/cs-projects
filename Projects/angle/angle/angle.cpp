/*
This will return the angle measure in radians and degrees for a given vector, relative to the x-axis.
It first uses the given values to determine in which quadrant the vector lies.
Then, using the absolute values of the coordinates generates a preliminary solution.
After that, depending on the quadrant of the vector, it modifies the original solution.
Jared Wallace
PA1
01/24/2012
*/
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

void main()
{
	double rad, deg, hyp, x, y;
	//This is what threw off my original program...had it initialized at 0,
	//which matched the switch statement for quadrant 2
	int quadrant(5);
	
	
	cout << "Enter the x value of the vector  ";
	cin >> x;
	cout << "Enter the y value of the vector  ";
	cin >> y;
	
	/*
	For legibility purposes, I'm using names to represent integers.
	This makes it instantly clear that when the angle falls into quadrant 2,
	for example, that the program will take the original solution and subtract
	it from 180 degrees (Pi radians).  If I used numbers like 0, 1 or 2,
	it would not be so clear which quadrant the vector falls into.
	*/
	enum quadrant 
	{
		q_second,
		q_third,
		q_fourth,
	};
	
	if (x<0 && y>0)	quadrant = q_second;
	if (x<0 && y<0)	quadrant = q_third;
	if (x>0 && y<0) quadrant = q_fourth;

	x = abs (x);
	y = abs (y);
	
	//initial solution
	hyp = sqrt(x*x+y*y);
	rad = asin(y/hyp);
	deg = (rad*180)/M_PI;
	
	switch (quadrant)
	{
	case q_second:
		rad = M_PI - rad;
		deg = 180 - deg;
		break;
	case q_third:
		rad = rad + M_PI;
		deg = deg + 180;
		break;
	case q_fourth:
		rad = 2*M_PI - rad;
		deg = 360 - deg;
		break;
	}
	
	cout << "\nThe angle is  " << rad << " radians and " << deg << " degrees\n";
	cout << "\nPress <enter> to continue\n";
	//the two commands are needed, there is still a "/n" in the buffer(from pressing enter after the second vector entry)
	//cin.ignore pulls one character from the buffer and discards it.
	cin.ignore();
	//cin.get takes the first character from the input stream, casts it to int, and then returns the result
	//which we don't catch because we don't have any use for it.
	cin.get();
}