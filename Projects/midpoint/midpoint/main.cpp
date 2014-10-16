#include <iostream>
#include <cmath>

using namespace std;

void main()
{
	double n(0), a(0), b(0), c(0), side1(0), side2(0), distance(0);
	double  CurrentX(0), ChangeX(0), NextX(0), Result(0);
	char input;
	double function(double value);

	system("Cls");
	cout << "Enter the number of midpoints to use" << endl;
	cin >> n;
	if (cin.fail())
	{
		cerr << "You need to enter numbers here Einstein.  Try again.\n" << endl;
		system("Pause");
		cin.clear();
		cin.ignore(1024, '\n');
		main();
	}
	cout << "Enter the starting point" << endl;
	cin >> a;
	if (cin.fail())
	{
		cerr << "You need to enter numbers here Einstein.  Try again.\n" << endl;
		system("Pause");
		cin.clear();
		cin.ignore(1024, '\n');
		main();
	}
	cout << "Enter the ending point" << endl;
	cin >> b;
	if (cin.fail())
	{
		cerr << "You need to enter numbers here Einstein.  Try again.\n" << endl;
		system("Pause");
		cin.clear();
		cin.ignore(1024, '\n');
		main();
	}

	ChangeX = ((b - a)/n);
	CurrentX = (2 * a + ChangeX)/2;
	NextX = CurrentX + ChangeX;
	
	while (CurrentX < b)
	{
		side1 = NextX-CurrentX;
		side2 = function(NextX)-function(CurrentX);
		distance = sqrt(side1*side1 + side2*side2);
		Result += distance;
		CurrentX += ChangeX;
		NextX += ChangeX;
	}

	system("Cls");
	cout << "The approximation is " << Result << endl;
	do
	{
		cout << "Would you like to find another arc length? [y/n]" << endl;
		cin >> input;
	}
	while (!cin.fail() && input!='y' && input!='n' );

	if (input == 'y')
	{
		main();
	}

}

double function(double value)
{
	double intermediate;
	intermediate = pow (value, 2);
	return (intermediate);
}