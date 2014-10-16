// Trying to print all integers between 1 and n that are divisable by 5
#include <iostream>
using namespace std;
int main ()
{
	int n, b;

	//Get initial value from client
	cout << "Enter a non negative number   ";
	cin >> n;
	//In case the initial value is divisable by 5
	n--;
	//To serve as a counter
	b = n;
	//start printing the relevant numbers
	for (int i=1; i<b; ++i)
	{
		if (n%5);
		else cout << endl << n << endl;
		n--;
	}
	system("pause");
	
}