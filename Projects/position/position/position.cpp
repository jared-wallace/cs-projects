#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double time(0), position;

	cout << "Enter time value  ";
	cin >> time;

	position = (3.12*time);
	position = position - (4.36*pow (time, 2));
	position = position + (1.04*pow (time, 3));
	cout << "Position is  " << position << endl;
	cout << "\n\nPress <enter> to exit  ";
	cin.ignore();
	cin.get();

}