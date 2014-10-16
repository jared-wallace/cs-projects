/*
Accepts an array of undetermined length, the length of said array, and the
relevant ofstream object.  It writes to the screen and the associated file
and then closes without changing any data.
*/

#include <fstream>
#include <iostream>

void writeArray (int arg[], int length, std::ofstream& out)
{
	for (int n=0; n<length; n++)
	{
		std::cout << arg[n] << " ";
		out << arg[n] << " ";
	}
	std::cout << std::endl;
}
