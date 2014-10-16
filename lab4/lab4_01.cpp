/*
    @author: Jared Wallace, A04111604
    @date: 09-25-2012

    This program has only answers to the questions as inputs, along with the option to
    quit after each question.

    This program has no constants.

    This program outputs the immediate result of the answer (correct/incorrect) and
    at the end of the program calculates your score.

    This little program would actually work fairly well for a real chem student as
    a study guide.
*/
#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

string names[]={
	"Acetate",
	"Bromate",
	"Bromide",
	"Chlorate",
	"Chloride",
	"Chlorite",
	"Cyanide",
	"Dihydrogen Phosphate",
	"Flouride",
	"Hydrogen Carbonate (Bicarbonate)",
	"Hydrogen Oxalate",
	"Hydrogen Sulfate (Bisulfate)",
	"Hydrogen Sulfide",
	"Hydrogen Sulfite (Bisulfite)",
	"Hydroxide",
	"Hypochlorite",
	"Iodide",
	"Nitrate",
	"Nitrite",
	"Perchlorate",
	"Permanganate",
	"Thiocyanate",
	"Carbonate",
	"Chromate",
	"Dichromate",
	"Hydrogen Phosphate (Biphosphate)",
	"Oxalate",
	"Oxide",
	"Peroxide",
	"Sulfate",
	"Sulfide",
	"Sulfite",
	"Silicate",
	"Thiosulfate",
	"Arsenate",
	"Borate",
	"Nitride",
	"Phosphate",
	"Phosphite",
	"Phosphide",
	"Ammonium"
	};

string values[]={
	"C2H3O2-1",
	"BrO3-1",
	"Br-1",
	"ClO3-1",
	"ClO3-1",
	"ClO2-1",
	"CN-1",
	"H2PO4-1",
	"F-1",
	"HCO3-1",
	"HC2O4-1",
	"HSO4-1",
	"HS-1",
	"HSO3-1",
	"OH-1",
	"ClO-1",
	"I-1",
	"NO3-1",
	"NO2-1",
	"ClO4-1",
	"MnO4-1",
	"SCN-1",
	"CO3-2",
	"CrO4-2",
	"Cr2O7-2",
	"HPO4-2",
	"C2O4-2",
	"O-2",
	"O2-2",
	"SO4-2",
	"S-2",
	"SO3-2",
	"SiO3-2",
	"S2O3-2",
	"AsO4-3",
	"BO3-3",
	"N-3",
	"PO4-3",
	"PO3-3",
	"P-3",
	"NH4+1"
	};

int randomNumber = 0, answer = 0, i = 0, score = 0;
void firstOption(int randomNumber);
void secondOption(int randomNumber);
void thirdOption(int randomNumber);
void fourthOption(int randomNumber);
void clearScreen();

int main()
{

    int guess = 0, nextRandomNumber = 0;
    char keepGoing = 'y';

    for ( ; i < 50; i++)
    {
        srand ( time(NULL) );                           //ensures a more random number
        randomNumber = rand()%40;                       //gives a number between 1-40
        clearScreen();
        cout <<  names[randomNumber] << endl << endl;
        nextRandomNumber = rand()%3;                    //gives us our random function
        switch (nextRandomNumber)
        {
            case 0:
                firstOption(randomNumber);
                break;
            case 1:
                secondOption(randomNumber);
                break;
            case 2:
                thirdOption(randomNumber);
                break;
            case 3:
                fourthOption(randomNumber);
                break;
            default:
                cout << "What the hell are you doing?";
        }
        cout << "Continue (y/n)? ";
        cin >> keepGoing;
        if (keepGoing == 'n' || keepGoing == 'N')
            break;
        clearScreen();

    }
    printf ("%s %#2.0f \n", "Your score is ", ((double)score/(i + 1)) * 100);
	return 0;
}

/*
    All four of the following functions are essentially identical, save for the placement of
    the correct answer. There probably is a more elegant solution, but I'm exhausted and it
    works as is.
*/
void firstOption(int randomNumber)
{
    cout << "1) " << values[randomNumber%1];
    cout << endl;
    cout << "2) " << values[randomNumber%2];
    cout << endl;
    cout << "3) " << values[randomNumber%3];
    cout << endl;
    cout << "4) " << values[randomNumber];
    cout << endl;

    cout << "\n\nEnter your answer (1, 2, 3 or 4) ";
    cin >> answer;
    clearScreen();
    if (answer == 4)
    {
        cout << "Correct!!\n\n";
        score++;
    }
    else
    {
        cout << "\nWrong answer idiot.\n\n";
        cout << "The actual answer was " << values[randomNumber] << endl;   //I know this wasn't asked for, but it's helpful
    }
}

void secondOption(int randomNumber)
{
    cout << "1) " << values[randomNumber%1];
    cout << endl;
    cout << "2) " << values[randomNumber%2];
    cout << endl;
    cout << "3) " << values[randomNumber];
    cout << endl;
    cout << "4) " << values[randomNumber%3];
    cout << endl;

    cout << "\n\nEnter your answer (1, 2, 3 or 4) ";
    cin >> answer;
    clearScreen();
    if (answer == 3)
    {
        cout << "Correct!!\n\n";
        score++;
    }
    else
    {
        cout << "\nWrong answer idiot.\n\n";
        cout << "The actual answer was " << values[randomNumber] << endl;
    }
}
void thirdOption(int randomNumber)
{
    cout << "1) " << values[randomNumber%1];
    cout << endl;
    cout << "2) " << values[randomNumber];
    cout << endl;
    cout << "3) " << values[randomNumber%2];
    cout << endl;
    cout << "4) " << values[randomNumber%3];
    cout << endl;

    cout << "\n\nEnter your answer (1, 2, 3 or 4) ";
    cin >> answer;
    clearScreen();
    if (answer == 2)
    {
        cout << "Correct!!\n\n";
        score++;
    }
    else
    {
        cout << "\nWrong answer idiot.\n\n";
        cout << "The actual answer was " << values[randomNumber] << endl;
    }
}
void fourthOption(int randomNumber)
{
    cout << "1) " << values[randomNumber];
    cout << endl;
    cout << "2) " << values[randomNumber%1];
    cout << endl;
    cout << "3) " << values[randomNumber%2];
    cout << endl;
    cout << "4) " << values[randomNumber%3];
    cout << endl;

    cout << "\n\nEnter your answer (1, 2, 3 or 4) ";
    cin >> answer;
    clearScreen();
    if (answer == 1)
    {
        cout << "Correct!!\n\n";
        score++;
    }
    else
    {
        cout << "\nWrong answer idiot.\n\n";
        cout << "The actual answer was " << values[randomNumber] << endl;
    }
}

//Again, just a quick and dirty screen clear
void clearScreen()
{
    cout << string(90, '\n');
}
