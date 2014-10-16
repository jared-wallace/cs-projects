//This program will read from three different files and ouput the contents to the screen.

#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	ifstream fin1("data1.dat");
	ifstream fin2("data2.dat");
	ifstream fin3("data3.dat");

	//making sure it opens. I assume if one opens, they all will
	if (fin1. fail())
	{
		cerr << "Could not open data1.dat\n";
		exit(1);
	}

	int value;
	fin1 >> value;
	while (!fin1.eof())
	{
		cout << value << " ";

		fin1 >> value;

	}
	cout << endl;
	fin1.close();

	fin2 >> value;
	while (!fin2.eof())
	{
		cout << value << " ";

		fin2 >> value;
	}
	cout << endl;
	fin2.close();

	fin3 >> value;
	while (!fin3.eof())
	{
		cout << value << " ";

		fin3 >> value;
	}
	cout << endl;
	fin3.close();
	cout << "Press <enter> to continue";
	cin.ignore();
	cin.get();

}