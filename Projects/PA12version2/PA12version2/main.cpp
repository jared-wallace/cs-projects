/* 
Student: Jared Wallace
Assignment #: PA 12
Assignment Description: Fun with pointers!.
Issue Date: n/a
Due Date: 4-28-2012
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program just plays around with pointers.  It ouputs relevant values to screen and file for each case.
*/
#include <iostream>
#include <fstream>
#include "print.h"

using namespace std;

int main()
{
	ofstream fout("dataCase1.dat"), fout2("dataCase2.dat"), fout3("dataCase3.dat"), fout4("dataCase4.dat");
	int a(1), b(2), c(5), *ptr;
	char input;

	system("Cls");
	cout << "The 4 different cases are as follows:\n\n";
	cout << "Case 1 assigns ptr the address of b.\n\n";
	cout << "Case 2 also assigns ptr the address of b, and then assigns a the value\n	ptr points to.\n\n";
	cout << "Case 3 assigns ptr the address of c, b the value ptr points to\n	and then assigns the value ptr points to the value of a.\n\n";
	cout << "Case 4 assigns ptr the address of c, sets b and c equal to each other\n	and then assigns a the value ptr points to.\n\n";
	cout << "\n\nWhich case would you like to test? [1,2,3 or 4]\n\n";
	cin >> input;

	switch (input)
	{
	case '1':
		ptr = &b;
		print(a, b, c, ptr, cout);
		print(a, b, c, ptr, fout);
		break;
	case '2':
		ptr=&b;
		a=*ptr;
		print(a, b, c, ptr, cout);
		print(a, b, c, ptr, fout2);
		break;
	case '3':
		ptr=&c;
		b=*ptr;
		*ptr=a;
		print(a, b, c, ptr, cout);
		print(a, b, c, ptr, fout3);
		break;
	case '4':
		ptr=&c;
		c=b;
		a=*ptr;
		print(a, b, c, ptr, cout);
		print(a, b, c, ptr, fout4);
		break;
	}

	do
	{
		cout << "\n\nDo you wish to run the program again? [y/n]\n\n";
		cin >> input;
		if (input == 'y')
			main();
	}
	while (!cin.fail() && input!='y' && input!='n');
}