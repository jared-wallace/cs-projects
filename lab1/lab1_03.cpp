/*
Jared Wallace
CS1428.09
09-04-12
*/

#include <iostream>

using namespace std;

int main()
{
	//Declare PI as a named constant and assign the value 3.14159 to PI
const double PI = 3.14159;

	//Declare all variables here
int length, width;
char LetterGrade;

	//Assign values to the declared variables
	length = 6;
	width = 7.96;
	LetterGrade = 'B';


	cout << "The value of length is :" << length << endl << endl;
	cout << "The value of width is :" << width << endl << endl;
	cout << "The value of LetterGrade is :" << LetterGrade << endl << endl;
	cout << "The value of the named constant is :" << PI << endl << endl;

	return 0;
}

