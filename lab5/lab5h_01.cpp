/*
Name: Jared Wallace
Class: CS 1418.09
Date: 10-01-1011

This program accepts no inputs.
This program has two name constants, ARRAY_SIZE, which is the size of each side of
the world you want to create, and GENERATIONS, which is how many generations you wish to simulate.
This program outputs each generation of the world in turn. Alive cells are represented as *, dead ones are blank.

This is a cool program that plays Conway's Game of Life.
It starts by generating a randomly seeded world of alive and dead cells.
It then steps through a new generation each second until reaching the limit set by GENERATIONS.
There is a limit to the size of the world you can select, which is 35 or so. Anything larger
will look funny. To manually seed the initial world, comment out lines 49-56 and declare the world
as you see fit.
    Ex.
        world[ARRAY_SIZE][ARRAY_SIZE]={1,1,0,1,1,0,0,1 ...etc etc}

The way I have implemented the game is by creating a toroidal array. Cells on the edges
interact with cells on the opposite side.
You may also leave it running as an infinite loop, for screensaver purposes.
    ex.
        set GENERATIONS to something super large
        replace line 82 with:
            for (int i=1; i>0; i++)
        replace the for loop on line 82 with a do...while loop

*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

using namespace std;

const int ARRAY_SIZE = 30;
const int GENERATIONS = 1000;
int checkNeighbors(int l, int m, bool array[ARRAY_SIZE][ARRAY_SIZE]);
void clearScreen();

int main()
{
    bool world[ARRAY_SIZE][ARRAY_SIZE];
    bool world1[ARRAY_SIZE][ARRAY_SIZE];


    srand(time(NULL));
    //initialize world1 with all zeros
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        for (int j=0; j<ARRAY_SIZE; j++)
        {
            world1[i][j] = 0;
        }
    }
    //seed the first array
    for (int i=0; i<(ARRAY_SIZE); i++)
    {
        for (int j=0; j<(ARRAY_SIZE); j++)
        {
            if (rand()%10 < 5)      //gives mostly random alive/dead
                world[i][j]=1;
            else
                world[i][j]=0;
        }
    }
    //print the initial world
    clearScreen();
    cout << "                  ";
    for (int i=0; i<(ARRAY_SIZE); i++)
    {
        for (int j=0; j<(ARRAY_SIZE); j++)
        {
            if (world[i][j])
                cout << " * ";
            else
                cout << "   ";
        }
        cout << endl << "                  ";
    }

    //start the iterations through the generations
    for (int i=0; i<GENERATIONS; i++)
    {
        for (int j=0; j<(ARRAY_SIZE); j++)
        {
            for (int k=0; k<(ARRAY_SIZE); k++)
            {
                switch (checkNeighbors(j, k, world))
                {
                    case 0:
                        if (world[j][k])
                            world1[j][k]=0;
                        break;
                    case 1:
                        if (world[j][k])
                            world1[j][k]=0;
                        break;
                    case 2:
                        break;
                    case 3:
                        if (!world[j][k])
                            world1[j][k]=1;
                        break;
                    case 4:
                        if (world[j][k])
                            world1[j][k]=0;
                        break;
                    case 5:
                        if (world[j][k])
                            world1[j][k]=0;
                        break;
                    case 6:
                        if (world[j][k])
                            world1[j][k]=0;
                        break;
                    case 7:
                        if (world[j][k])
                            world1[j][k]=0;
                        break;
                    case 8:
                        if (world[j][k])
                            world1[j][k]=0;
                        break;
                    default:
                        cout << "You screwed something up idiot.\n";
                }
            }
        }

        //erase the screen and display the new generation
        clearScreen();
        cout << "                  ";
        for (int i=0; i<(ARRAY_SIZE); i++)
        {
            for (int j=0; j<(ARRAY_SIZE); j++)
            {
                if (world1[i][j])
                    cout << " * ";
                else
                    cout << " ";
            }
            cout << endl << "                  ";
        }
        sleep(1);           //time in seconds between iterations

        //copy the contents of world1 to world in preparation for the next iteration
        for (int i=0; i<(ARRAY_SIZE); i++)
        {
            for (int j=0; j<(ARRAY_SIZE); j++)
            {
                world[i][j] = world1[i][j];
            }
        }


    }

}


int checkNeighbors(int l, int m, bool array[ARRAY_SIZE][ARRAY_SIZE])
{
    int nextBottom, nextTop, nextRight, nextLeft;
    /*
        The following if..else statements "stitch" the opposite sides together
    */

    if (l+1>(ARRAY_SIZE-1))
        nextTop = 0;
    else
        nextTop = l+1;
    if (l-1<0)
        nextBottom = (ARRAY_SIZE-1);
    else
        nextBottom = l-1;
    if (m+1>(ARRAY_SIZE-1))
        nextRight = 0;
    else
        nextRight = m+1;
    if (m-1<0)
        nextLeft = (ARRAY_SIZE-1);
    else
        nextLeft = m-1;

    return (array[nextTop][m] + array[nextTop][nextRight] + array[nextTop][nextLeft] + array[l][nextRight]
            + array[l][nextLeft] + array[nextBottom][m] + array[nextBottom][nextRight] + array[nextBottom][nextLeft]);
}

void clearScreen()
{
    cout << string(90, '\n');
}
