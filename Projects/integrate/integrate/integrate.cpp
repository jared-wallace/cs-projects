#include <iostream>
#include <cmath>

using namespace std;

void main()
{
	double n(0), a(0), b(0), c(0);
	double  initialX(0), currentX(0), ChangeX(0), Result(0), intermediate(0);
	double function(double value);

	cout << "Enter n " << endl;
	cin >> n;
	cout << "Enter a " << endl;
	cin >> a;
	cout << "Enter b " << endl;
	cin >> b;

	ChangeX = ((b - a)/n);
	c = a + ChangeX;
	initialX = (a + c)/2;
	currentX = initialX;
	
	while (currentX < b)
	{
		intermediate += function(currentX);
		currentX += ChangeX;
	}

	Result = (ChangeX * intermediate);

	cout << "The approximation is " << Result << endl;
	cin.get();
	cin.ignore();
}

double function(double value)
{
	double intermediate;
	intermediate = sqrt(pow (value, 3) + 1);
	return (intermediate);
}