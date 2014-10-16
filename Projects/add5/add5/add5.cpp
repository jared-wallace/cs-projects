/* This program will read a data file, add 5 to each value, and will then 
write the contents to a data file named pa5out.dat.
*/

#include <iostream>
#include <fstream>

using namespace std;

/*
I modified the function to fit the requirements of the assignment
(ie. use the same loop to print to file and screen)
I also shifted the open file command to the function, as it no longer requires
user input to create the file.
*/
void WriteArray (int arg[], int length)
{
	ofstream fout("pa5out.dat");
	for (int n=0; n<length; n++)
	{
		cout << arg[n] << " ";
		fout << arg[n] << " ";
	}
}

int main()
{
	ifstream fin("data.txt");
	int data[10], count(0);

	if (!fin)
	{
		cerr << "Could not open data.txt\n";
		exit(1);
	}

	fin >> data[count];
	for (int i=0; i<10; i++)
	{
		data[count] += 5;
		count++;
		fin >> data[count];
	}

	WriteArray (data, count);
	cout << " Press <enter> to proceed \n\n";
	cin.ignore();//This program only requires one...
}