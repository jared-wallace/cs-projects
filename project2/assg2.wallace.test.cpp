/*
@name Jared Wallace, A04111604
@date 09-18-12

This program accepts an operator as the first input, with relevant
error checking, and then depending on the operator chosen, accepts one
or two operands.

This program has no constants.

This program outputs in a nice format the answer to the requested operation.

This is a fairly simplistic polish notation calculator.

*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void clearScreen();
int factorial(int integer);

int main()
{

    char desiredOperator = '+', keepGoing = 'y';                                        //keepGoing is used for deciding whether to continue the program or exit
    long int operand1 = 0, operand2 = 0, result = 1;                        // Using long int for (hopefully) extended functionality in the factorial function
    clearScreen();

    do
    {

        printf ("%70s", "******Jared's Polish Notation Calculator.******\n\n\n");
        printf ("%70s", "\nValid operators include the following: \n");
        printf ("%70s", "\n+(addition),\n-(subtraction),\n*(multiplication),");
        printf ("%70s", "\n/(division),\n%(modulus),\nr(reciprocal),\n^(exponent),");
        printf ("%70s", "\nf(factorial)\n");
        printf ("%70s", "\nEnter the desired operator now: ");
        cin >> desiredOperator;

        switch (desiredOperator)
        {
            case '+':           //addition
                cout << "Enter the two numbers you wish to add, one at a time " << endl;
                cin >> operand1 >> operand2;
                clearScreen();
                cout << "The result of " << operand1 << " plus " << operand2 << " is: " << operand1 + operand2 << endl;
                break;
            case '-':           //subtraction
                cout << "Enter the two numbers you wish to subtract, one at a time " << endl;
                cin >> operand1 >> operand2;
                clearScreen();
                cout << "The result of " << operand1 << " minus " << operand2 << " is " << operand1 - operand2 << endl;
                break;
            case '*':           //multiplication
                cout << "Enter the two numbers you wish to multiply, one at a time " << endl;
                cin >> operand1 >> operand2;
                clearScreen();
                cout << "The result of  " << operand1 << " multiplied by " << operand2 << " is " << operand1 * operand2 << endl;
                break;
            case '/':           //integer division
                clearScreen();
                cout << "Enter the two numbers you wish to divide, one at a time " << endl;
                cin >> operand1 >> operand2;
                //this is to catch 'division by zero' issues
                if (operand2 == 0)
                {
                    cout << "\nDividing by zero is generally a bad idea.\n";
                    break;
                }
                clearScreen();
                cout << "The result of " << operand1 << " divided by " << operand2
                    << " is " << operand1 / operand2 << " with a remainder of " << operand1 % operand2 << endl;
                break;
            case '%':           //modulus (remainder)
                cout << "Please enter the two numbers you wish to find the remainder for " << endl;
                cin >> operand1 >> operand2;
                clearScreen();
                cout << "The remainder of " << operand1 << " divided by " << operand2 << " is " << operand1 % operand2 << endl;
                break;
            case 'r':           //reciprocal
                cout << "Please enter the number you wish to find the reciprocal for " << endl;
                cin >> operand1;
                clearScreen();
                if (operand1 == 0)
                {
                    cout << "The reciprocal of 0 is still 0.\n";
                    break;
                }
                cout << "The reciprocal of " << operand1 << " is 1/" << operand1 << endl;
                break;
            case '^':           //exponential
                cout << "Enter the number, followed by the power you wish to raise it to " << endl;
                cin >> operand1 >> operand2;
                clearScreen();
                //catches 0 to the power of whatever
                if (operand1 == 0)
                {
                    cout << operand1 << " raised to the power of " << operand2 << " is " << operand1 << ".\n";
                    break;
                }
                //catches whatever to the power of 0
                if (operand2 == 0)
                {
                    cout << operand1 << " raised to the power of " << operand2 << " is 1.\n";
                    break;
                }
                for (int i=1; i<operand2; i++)
                    {
                        result = operand1;
                        result *= result;
                    }
                cout << operand1 << " raised to the power of " << operand2 << " is " << result << endl;
                break;
            case 'f':           //factorial
                cout << "Enter the number for which you want the factorial " << endl;
                cin >> operand1;
                clearScreen();
                //warns of potential pitfall
                if (operand1>12)
                {
                    cout << "That number might be too big for this calculator to handle.";
                    cout << "\nBe sure to double check your result.\n\n";
                }
                //catches input of 0
                if (operand1 == 0)
                {
                    cout << operand1 << " factorial is " << operand1 << ".\n";
                    break;
                }
                cout << operand1 << " factorial is ";
                cout << factorial(operand1) << endl;
                break;
            default:            //this catches any strange/unexpected input values
                cout << "You did not enter a valid operator.\n";
    }

    cout << "Would you like to perform another operation? (y/n) ";
    cin >> keepGoing;
    clearScreen();
    }while(keepGoing == 'y' || keepGoing == 'Y');
    clearScreen();
    cout << "******Live long and Prosper******\n\n\n\n";
    return 0;
}



/*
    This function simply clears the screen without too much drama
*/
void clearScreen()
{
    cout << string(90, '\n');
}

/*
This function finds the factorial of whatever integer is passed to it.
It then returns the answer.
*/
int factorial(int integer)
{
    if (integer == 1)
        return 1;
    return integer*factorial(integer-1);

}
