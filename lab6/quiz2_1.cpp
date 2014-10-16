/*
    Jared Wallace
    CS1428, section 9
    10-09-2012

    This program acepts no inputs, and has no constants.
    This program outputs the array of numbers, as well as the sum, average and standard deviation.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int array[100], sum = 0, randNum = 0;
    float average = 0, deviation = 0;

    srand(time(0));

    for (int i=0; i<100; i++)
    {
        randNum = rand()%21;
        if (randNum < 10)
            randNum += 10;
        array[i] = randNum;
    }

    for (int i = 0; i < 100; i++)
    {
        sum += array[i];
        cout << array[i] << " ";
    }

    for (int i = 0; i < 100; i++)
    {
        deviation += pow(array[i]-(sum/100), 2);
    }
    deviation = sqrt(deviation/100);
    cout << endl;
    cout << "The sum of all the numbers equals " << sum << endl;
    cout << "The average of all the numbers equals " << sum/100 << endl;
    cout << "The standard deviation is " << deviation << endl;



}
