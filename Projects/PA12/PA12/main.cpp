#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout("dataCase1.dat"), fout2("dataCase2.dat"), fout3("dataCase3.dat"), fout4("dataCase4.dat");
	int a(1), b(2), c(5), *ptr;
	char input;

	
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
		cout << "The value of a is " << a << " and the address of a is " << &a << endl;;
		cout << "The value of b is " << b << " and the address of b is " << ptr << endl;
		cout << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		cout << "The pointer points to " << *ptr << endl;
		fout << "The value of a is " << a << " and the address of a is " << &a << endl;
		fout << "The value of b is " << b << " and the address of b is " << &b << endl;
		fout << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		fout << "The pointer points to " << *ptr << endl;
		break;
	case '2':
		ptr=&b;
		a=*ptr;
		cout << "The value of a is " << a << " and the address of a is " << &a << endl;
		cout << "The value of b is " << b << " and the address of b is " << &b << endl;
		cout << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		cout << "The pointer points to " << *ptr << endl;
		fout2 << "The value of a is " << a << " and the address of a is " << &a << endl;
		fout2 << "The value of b is " << b << " and the address of b is " << &b << endl;
		fout2 << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		fout2 << "The pointer points to " << *ptr << endl;
		break;
	case '3':
		ptr=&c;
		b=*ptr;
		*ptr=a;
		cout << "The value of a is " << a << " and the address of a is " << &a << endl;
		cout << "The value of b is " << b << " and the address of b is " << &b << endl;
		cout << "The value of c is " << c << " and the address of c is " << &c << endl;
		cout << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		cout << "The pointer points to " << *ptr << endl;
		fout3 << "The value of a is " << a << " and the address of a is " << &a << endl;
		fout3 << "The value of b is " << b << " and the address of b is " << &b << endl;
		fout3 << "The value of c is " << c << " and the address of c is " << &c << endl;
		fout3 << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		fout3 << "The pointer points to " << *ptr << endl;
		break;
	case '4':
		ptr=&c;
		c=b;
		a=*ptr;
		cout << "The value of a is " << a << " and the address of a is " << &a << endl;
		cout << "The value of b is " << b << " and the address of b is " << &b << endl;
		cout << "The value of c is " << c << " and the address of c is " << &c << endl;
		cout << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		cout << "The pointer points to " << *ptr << endl;
		fout4 << "The value of a is " << a << " and the address of a is " << &a << endl;
		fout4 << "The value of b is " << b << " and the address of b is " << &b << endl;
		fout4 << "The value of c is " << c << " and the address of c is " << &c << endl;
		fout4 << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << endl;
		fout4 << "The pointer points to " << *ptr << endl;
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