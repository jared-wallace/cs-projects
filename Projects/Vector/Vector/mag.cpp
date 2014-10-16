/*
Accepts the coordinates, and returns the magnitude.
*/
#include <cmath>

double Magnitude (int xCoor, int yCoor)
{
	double Mag;
	Mag = sqrt((double)yCoor*yCoor + xCoor*xCoor);
	return(Mag);
}
