#include<iostream>

using namespace std;

int main()
{
    int array1[3][3]={1,2,3,4,5,6,7,8,9};
    int array2[3][3]={9,8,7,6,5,4,3,2,1};
    int array3[3][3]={};

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            for (int k=0; k<3; k++)
            {
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << array3[i][j] << " ";
        }
        cout << endl;
    }
}
