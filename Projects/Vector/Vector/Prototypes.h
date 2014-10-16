#include <fstream>
void WriteValues (int xCoor, int yCoor, double Mag, double Rad, double Deg, std::ostream& out);
void Angle (double Mag, int xCoor, int yCoor, double& rad, double& deg);
double Magnitude (int xCoor, int yCoor);