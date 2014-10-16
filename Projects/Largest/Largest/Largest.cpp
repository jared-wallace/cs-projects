//This file will read a series of values from a data file, and then will output the largest value
//as well as its position in the range of values to the screen.  It will then ask for a filename and write the numbers to a new file.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
The WriteArray function accepts three parameters, the first of which is an array of undetermined length.  That requires the second parameter,
telling it how long the array that was passed to it is.  The third parameter tells the function where to send the output (cout or fout in this case).
*/
void WriteArray (int arg[], int length, ostream& out)
{
  for (int n=0; n<length; n++)
    out << arg[n] << " ";
	out << "\n";
}

int main()
{
	ifstream fin("data.txt");
	ofstream fout;
	int data [10]; //I'm using an 10 value one dimensional array to hold the data
	int count(0), max(0);
	string filename;


	if (!fin) 
	{
		cerr << "Could not open data.txt\n";
		exit(1);
	}

	fin >> data[count];//pulls the first value
	for (int i=0; i<10; i++)//only loops it 9 times(already pulled first value).  Prevents writing outside the array.
	{
		if (data[count] > data[max])
		{
			max = count;
		}
		count++;
		fin >> data[count];
	}
	cout << "\n\nThe largest value discovered in the file was " << data[max]
		<< " which was number " << max << " in the list \nof numbers.\n\n";
	cout << "The numbers read from the file include  \n\n";
	WriteArray (data, count, cout);//sending my array "data", length of the array, and the desired location of the output to the function WriteArray
	cout << "Please enter a filename to write the numbers to: \n\n";
	cin >> filename;
	fout.open(filename.c_str());
	WriteArray (data, count, fout);//This time I tell WriteArray to send it to the file
	cout << "\n\nPress <enter> to continue";
	cin.get();
	cin.ignore();
}
