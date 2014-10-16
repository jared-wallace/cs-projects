/*
    Jared Wallace
    cs1428 section 9
    10-09-2012

    This program accepts a file as input. The user is prompted for the filename.

    This program has no constants.

    This program can output certain statements, depending on the contents of the input file.

    This is out first foray into writing our own programming language.Pretty damn cool to be honest.
    Gives me a certain appreciation for the people who write real languages ;)
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int loadProgram(string fileName, int program[][4]);
void addition(int arr[512][4], int mem[256], int instruction);
void subtraction(int arr[512][4], int mem[256], int instruction);
void multiplication(int arr[512][4], int mem[256], int instruction);
void division(int arr[512][4], int mem[256], int instruction);
void exponent(int arr[512][4], int mem[256], int instruction);
void storeInput(int arr[512][4], int mem[256], int instruction);
void display(int arr[512][4], int mem[256], int instruction);
void storeFile(int arr[512][4], int mem[256], int instruction);
int jump(int arr[512][4], int instruction);
int jumpConditional(int arr[512][4], int mem[256], int instruction);


int main()
{
    string fileName;
    int program[512][4] = {0}, memory[256] = {0}, loopTime = 0;
    char keepGoing = 'y';

    do
    {

        cout << string(90, '\n');
        cout << "Enter the name of the input file\n\n";
        cin >> fileName;
        loopTime = loadProgram(fileName, program);
        cout << endl << loopTime << " instructions loaded.\n\n";
        cout << "Press <enter> to run the program" << endl;
        cin.get();
        cin.ignore();

        for (int i=0; i<loopTime; i++)
        {

            switch (program[i][0])
            {
                case 0:
                    addition(program, memory, i);
                    break;
                case 1:
                    subtraction(program, memory, i);
                    break;
                case 2:
                    multiplication(program, memory, i);
                    break;
                case 3:
                    division(program, memory, i);
                    break;
                case 4:
                    exponent(program, memory, i);
                    break;
                case 5:
                    storeInput(program, memory, i);
                    break;
                case 6:
                    display(program, memory, i);
                    break;
                case 7:
                    storeFile(program, memory, i);
                    break;
                case 8:
                    i=jump (program, i);
                    break;
                case 9:
                    i=jumpConditional(program, memory, i);
                    break;
                default:
                    cout << "You screwed something up idiot." << endl;
            }
        }
        cout << "\nWould you like to run another program? (y/n)\n\n";
        cin >> keepGoing;

    }while(keepGoing=='y' || keepGoing=='Y');
}

int loadProgram(string fileName, int program[512][4])
{


    int instruction = 0, target = 0, left = 0, right = 0;
    ifstream fin;
    fin.open(fileName.c_str());

    if (!fin)
    {
        cout << "You entered the name of a file that doesn't exist.";
        cout << "\n\nDumbass.\n\n";
        main();     //just for you Asa
    }

    int i = 0;

    while(!fin.eof())
    {
        fin >> instruction >> target >> left >> right;
        program[i][0] = instruction;
        program[i][1] = target;
        program[i][2] = left;
        program[i][3] = right;
        i++;
    }
    fin.close();

    return i;
}

void addition(int arr[512][4], int mem[256], int instruction)
{
    mem[arr[instruction][1]] = mem[arr[instruction][2]] + mem[arr[instruction][3]];
}
void subtraction(int arr[512][4], int mem[256],  int instruction)
{
    mem[arr[instruction][1]] = arr[instruction][2] - arr[instruction][3];
}
void multiplication(int arr[512][4], int mem[256], int instruction)
{
    mem[arr[instruction][1]] = arr[instruction][2] * arr[instruction][3];
}
void division(int arr[512][4], int mem[256], int instruction)
{
    mem[arr[instruction][1]] = mem[arr[instruction][2]] / mem[arr[instruction][3]];
}
void exponent(int arr[512][4], int mem[256], int instruction)
{
    mem[arr[instruction][1]] = pow(mem[arr[instruction][2]], mem[arr[instruction][3]]);
}
void storeInput(int arr[512][4], int mem[256], int instruction)
{
    cout << "\nEnter the value you wish to store ";
    cin >> mem[arr[instruction][1]];
}
void display(int arr[512][4], int mem[256], int instruction)
{
    cout << endl << mem[arr[instruction][1]] << endl;
}
void storeFile(int arr[512][4], int mem[256], int instruction)
{
    mem[arr[instruction][1]] = arr[instruction][2];
}
int jump(int arr[512][4], int instruction)
{
    instruction+=(arr[instruction][1]-1);
    return instruction;
}
int jumpConditional(int arr[512][4], int mem[256], int instruction)
{
    if (mem[arr[instruction][2]]-mem[arr[instruction][3]] == 0)
    {
        instruction+=(arr[instruction][1]-1);
        return instruction;
    }
    return instruction;
}
