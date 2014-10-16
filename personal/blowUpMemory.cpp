#include <iostream>
using namespace std;
int main()
{
    double* ptr;
    ptr = new double[1099999999];
    if (ptr == NULL)
        cout << "\nHa ha you succeeded";
    else
        cout << "\nNo problem here bossman";

    for (int i=0; i<1099999999; i++)
    {
        ptr[i] = i;
    }

    for (int i=0; i<1099999999; i++)
      cout << ptr[i] << endl;
    cout << "\nMemory allcoated starts at" << ptr;
    cin.get();
}
