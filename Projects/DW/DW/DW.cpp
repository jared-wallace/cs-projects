/*
This is gonna create a do/while loop that increments a variable "Sum" by 10
each time through the loop, and will ask the user for the number of times it should execute
the trip through the loop
Jared Wallace
PA #2
*/

#include <iostream>

using namespace std;

void main()

{
	
	int Duration, Sum(0), Count(0);
	
	cout << "Enter the number of times you want the loop to execute\n\n";//removed redundant aside about whole numbers
	cin >> Duration;

	do
	{
		Sum += 10;
		//cout << Sum << endl;
		Count++;
	}while (Count < Duration );

	cout << "The value of the variable Sum is  " << Sum << endl;
	cout << "Press <enter> to continue";
	cin.get();
	cin.ignore();


}

