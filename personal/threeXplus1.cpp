#include <iostream>
#include <gmp.h>

using namespace std;
mpz_t value;
int calculate(mpz_t value);
int count = 0;

int main()
{
    char keepGoing = 'y';
    mpz_init (value);

    do
    {
    cout << string(90, '\n');
    cout << "Enter the value you wish to test\n";
    cin >> value;
    cout << endl << "The value given arrived at 1 and it took " <<  calculate(value) << " iterations." << endl;
    cout << "Do you wish to enter another number? (y/n) ";
    cin >> keepGoing;
    count = 0;
    cout << endl;
    }while(keepGoing != 'n' && keepGoing != 'N');
    return 0;
}

int calculate(mpz_t value)
{
    mpz_t base = 1;
    if (!mpz_cmp (value, base))
        return (count);
    if (value%2)
    {
        value *= 3;
        value++;
        count++;
        calculate(value);
    }
    else
    {
        value /= 2;
        count++;
        calculate(value);
    }
}
