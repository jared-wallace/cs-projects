/*

@author: Jared Wallace, A04111604
@date: 09-11-2012

This simple program will compute the tax and various levels of a tip
for a given restaurant bill.

The program will accept as input the amount of the restaurant bill,
and will output the total bill given tip amounts of 15, 20 and 25 percent.

 */

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const float TAX_RATE = 1.0675;

int main()
{
    float amountBill = 0;
    void calculate(float amountBill);

    cout << string(90, '\n');                       //quick and dirty way to clear the screen
    cout << "Please enter the amount your meal cost without the dollar sign: ";
    cin >> amountBill;
    calculate(amountBill);
    cout << endl << "Press <enter> to continue";
    cin.get();
    cin.ignore();
    return 0;
}

/*
This function accepts the amount of the bill as an argument, performs the desired calculations
and outputs to the screen the desired information (cost of the bill with tax and various tips).
I chose printf instead of cout for the text formatting opportunities it offered.
The width values utilized in the printf statements were all picked after trial and error
and were chosen to work with all default console window sizes, both Linux and Windows.
There may very well be a more elegant solution for that.
As a void function, obviously it does not return anything.
 */

void calculate(float amountBill)
{
    cout << string(90, '\n');
    printf ("%70s %#8.2f \n", "Total: $", amountBill);
    printf ("%70s %#8.2f \n", "  Tax:  $", amountBill*TAX_RATE-amountBill);   //generates the tax amount
    printf ("%70s %8s\n", "", "--------");
    printf ("%70s %#8.2f \n", "Grand total: $", amountBill*TAX_RATE);        //performing the calculation inline eliminates a variable
    printf ("%70s %#8.2f \n", "with 15% tip: $", amountBill*TAX_RATE*1.15);
    printf ("%70s %#8.2f \n", "with 20% tip: $", amountBill*TAX_RATE*1.20);
    printf ("%70s %#8.2f \n", "with 25% tip: $", amountBill*TAX_RATE*1.25);
}
