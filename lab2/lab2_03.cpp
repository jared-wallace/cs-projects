/*
name: Jared Wallace
CS1428.09
09-11-12

This program asks for 2 inputs, both floats (fruitPrices and vegetablePrice)
This program has one constant, SALES_TAX_RATE, initialized at .07
This program outputs the final bill after accounting for taxes

This program will accept two prices, the amount paid for the fruit and the amount paid for the vegetables.
The program will then output the final bill after accounting for taxes.
*/

#include <iostream>

using namespace std;

int main()
{
    const float SALES_TAX_RATE = .07;
    float fruitPrices = 0, TotalSales = 0, SalesTaxAmount = 0, TotalAmountPaid = 0, vegetablePrice = 0;

    cout << "Please enter the amount paid for the fruits " << endl;
    cin >> fruitPrices;
    cout << "Please enter the amount paid for the vegetable" << endl;
    cin >> vegetablePrice;

    TotalSales = fruitPrices + vegetablePrice;          //simple addition
    SalesTaxAmount = TotalSales * SALES_TAX_RATE;       //a simpler method would have simply multiplied the total by 1.07, thus saving a variable
    TotalAmountPaid = TotalSales + SalesTaxAmount;      //calculating the final bill

    cout << "The total amount paid is: " << TotalAmountPaid << endl;

	return 0;
}

