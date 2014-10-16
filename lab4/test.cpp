#include  <iostream>
using namespace std;
int main()
{
    long double prod = 1, base = 0;

    cout << "Enter base";
    cin >> base;
    for (int exp = 1; exp < 33; exp++)
    {
        for (int i = 0; i < exp; i++)
            prod *= base;
        cout << "For base " << base << " # " << exp << " = " << prod << endl;
    }
}
