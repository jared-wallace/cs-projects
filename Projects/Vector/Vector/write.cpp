/*
Accepts the coordinates, magnitude, angle (both radians and degrees),
and the desired output, screen or file, then writes to the specified device.  
*/
#include <fstream>

void WriteValues (int xCoor, int yCoor, double Mag, double Rad, double Deg, std::ostream& out)
{
    out << "The coordinates (" << xCoor << "," << yCoor << ")";
	out << " give a vector with a magnitude of " << Mag << " and an angle\nof " << Deg << " degrees (or " << Rad << " radians).\n";
	out << std::endl;
}