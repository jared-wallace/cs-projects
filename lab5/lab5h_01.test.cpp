/*
Name: Jared Wallace
Class: CS 1428.09
Date: 10-02-2012

This program accepts no inputs.
This program has two name constants, ARRAY_SIZE, which is the size of the world you want to create,
and GENERATIONS, which is how many generations you wish to simulate.
This program outputs each generation of the world in turn. Alive cells are represented as *, dead ones are blank.

This is a cool program that plays Conway's Game of Life.
It starts by generating a randomly seeded world of alive and dead cells.
It then steps through a new generation each second until reaching the limit set by GENERATIONS.
There is a limit to the size of the world you can select, which is 35 or so. Anything larger
will look funny. To manually seed the initial world, comment out lines 49-56 and declare the world
as you see fit.
    Ex.
        world[ARRAY_SIZE][ARRAY_SIZE]={1,1,0,1,1,0,0,1 ...etc etc}

The way this particular implementation works is that it creates an initial array
of size given by ARRAY_SIZE and then creates the world as an array 1 row and column
smaller. This allows the program to use a general function for checking neighbors rather
than having to create a different function for every special case (corners and outside rows/columns).

*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>         //change to dos.h for windows systems

using namespace std;

const int ARRAY_SIZE = 30;
const int GENERATIONS = 100;
int checkNeighbors(int l, int m, bool array[ARRAY_SIZE][ARRAY_SIZE]);
void clearScreen();

int main()
{
    bool world[ARRAY_SIZE][ARRAY_SIZE];
    bool world2[ARRAY_SIZE][ARRAY_SIZE];

    //initialize both arrays
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        for (int j=0; j<ARRAY_SIZE; j++)
        {
            world[i][j]=0;
            world2[i][j]=0;

        }
    }

    srand(time(NULL));

    //seed the first array
    for (int i=2; i<(ARRAY_SIZE-2); i++)
    {
        for (int j=2; j<(ARRAY_SIZE-2); j++)
        {
            if (rand()%10 < 5)      //gives mostly random alive/dead
                world[i][j]=1;
        }
    }
    //print the initial world
    clearScreen();
    cout << "                  ";
    for (int i=2; i<(ARRAY_SIZE-2); i++)
    {
        for (int j=2; j<(ARRAY_SIZE-2); j++)
        {
            if (world[i][j])
                cout << " * ";
            else
                cout << " ";
        }
        cout << endl << "                  ";
    }

    //start the iterations through the generations
    for (int i=0; i<GENERATIONS; i++)
    {
        for (int j=2; j<(ARRAY_SIZE-2); j++)
        {
            for (int k=2; k<(ARRAY_SIZE-2); k++)
            {
                switch (checkNeighbors(j, k, world))
                {
                    case 0:
                        if (world[j][k])
                            world2[j][k]=0;
                        break;
                    case 1:
                        if (world[j][k])
                            world2[j][k]=0;
                        break;
                    case 2:
                        break;
                    case 3:
                        if (!world[j][k])
                            world2[j][k]=1;
                        break;
                    case 4:
                        if (world[j][k])
                            world2[j][k]=0;
                        break;
                    case 5:
                        if (world[j][k])
                            world2[j][k]=0;
                        break;
                    case 6:
                        if (world[j][k])
                            world2[j][k]=0;
                        break;
                    case 7:
                        if (world[j][k])
                            world2[j][k]=0;
                        break;
                    case 8:
                        if (world[j][k])
                            world2[j][k]=0;
                        break;
                }
            }
        }

        //erase the screen and display the new generation
        clearScreen();
        cout << "                  ";
        for (int i=2; i<(ARRAY_SIZE-2); i++)
        {
            for (int j=2; j<(ARRAY_SIZE-2); j++)
            {
                if (world2[i][j])
                    cout << " * ";
                else
                    cout << " ";
            }
            cout << endl << "                  ";
        }
        sleep(1);

        //copy the contents of world2 to world in preparation for the next iteration
        for (int i=2; i<(ARRAY_SIZE-2); i++)
        {
            for (int j=2; j<(ARRAY_SIZE-2); j++)
            {
                world[i][j] = world2[i][j];
            }
        }


    }

}


int checkNeighbors(int l, int m, bool array[ARRAY_SIZE][ARRAY_SIZE])
{
    return (array[l+1][m] + array[l+1][m+1] + array[l+1][m-1] + array[l][m+1]
        + array[l][m-1] + array[l-1][m] + array[l-1][m+1] + array[l-1][m-1]);
}

void clearScreen()
{
    cout << string(90, '\n');
}
