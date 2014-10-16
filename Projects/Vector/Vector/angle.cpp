/*
Accepts magnitude and coordinates, calculates the angle, and
effects the results in radians and degrees upon the variables rad and deg.
*/
#define _USE_MATH_DEFINES
#include <math.h>

void Angle (double Mag, int xCoor, int yCoor, double& rad, double& deg)
{
	int quadrant(5);

	enum quadrant 
	{
		q_second,
		q_third,
		q_fourth,
	};
	
	if (xCoor<0 && yCoor>0)	quadrant = q_second;
	if (xCoor<0 && yCoor<0)	quadrant = q_third;
	if (xCoor>0 && yCoor<0) quadrant = q_fourth;

	xCoor = abs(xCoor);
	yCoor = abs(yCoor);

	rad = asin(yCoor/Mag);
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
}