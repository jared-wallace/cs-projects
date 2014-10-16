/*
name: Jared Wallace
cs1428.09
09-11-12

The program asks for and accepts two inputs of type float, name price_item1 and price_item2 respectively.
There are no constants in this program
The program outputs a prompt and the final total of the two items added together.

s program asks for two prices, and adds them together before outputting the total.
*/

#include <iostream>

using namespace std;

int main()
{
	float price_item1;
    float price_item2;

	cout << "Enter the price for the first item: " << endl;
	cin >> price_item1;

	cout << "Enter the price for the second item: " << endl;
	cin >> price_item2;

	cout << "The total price is " << price_item1 + price_item2 << endl;

	return 0;
}
