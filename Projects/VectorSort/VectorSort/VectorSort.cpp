#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void main()
{
	vector<int> vector (10);
	ifstream fin("data.dat");
	ofstream fout("sorted.dat");
	
	if (!fin)
	{
		cerr << "Could not open file";
		exit(1);
	}

	for (int i=0; i< vector.size(); i++)
		fin >> vector[i];

	sort (vector.begin(), vector.end());

	for (int i=0; i<vector.size(); i++)
	{
		cout << vector[i] << " ";
		fout << vector[i] << " ";
	}

	cout << "\n\nPress <enter> to continue";
	cin.get();
}

