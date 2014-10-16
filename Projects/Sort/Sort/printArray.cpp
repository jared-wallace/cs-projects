/*
Accepts the array and the object to output the stream to (in this case, the file we want written).
Obviously, nothing is returned, and less obviously, nothing is changed.
*/
#include <iostream>
#include <fstream>

void printArray (int arg[], std::ofstream& out)
{
	for (int i=0; i<10; i++)
	{
		std::cout << arg[i] << " ";
		out << arg[i] << " ";
	}
}