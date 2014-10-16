#include <fstream>
#include <iostream>

void print(int &a, int &b, int &c, int *ptr, std::ostream &out)
{
	out << "The value of a is " << a << " and the address of a is " << &a << std::endl;
	out << "The value of b is " << b << " and the address of b is " << &b << std::endl;
	out << "The value of c is " << c << " and the address of c is " << &c << std::endl;
	out << "The value of ptr is " << ptr << " and the address of ptr is " << &ptr << std::endl;
	out << "The pointer points to " << *ptr << std::endl;
}