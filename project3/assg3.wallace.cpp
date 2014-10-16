/*
	@author: Jared Wallace
	@date: 10-13-2012
	CS1428 Honors

	This program offers a single player tic tac toe game which the computer will never lose.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

char checkWin(char array[]);
int algorithm(char array[], int count, char playerSymbol, char compSymbol);
int inputValidation(char array[], int row, int col, char playerSymbol);
int findEmptySpace(char array[], int value1, int value2, int value3, char compSymbol);
void clearScreen();
void displayBoard(char array[]);
bool checkEmpty(char array[], int pos);

//global variables
bool playerFirst = false;
int turnCount = 0;

int main()
{
	char board[9];
	int row = 0, col = 0, pos = 0;
	char keepGoing = 'y', playerSymbol = 'p', compSymbol = 'p';

	srand(time(0));

	do
	{
		clearScreen();
		cout << right << setw(40) << "Welcome to T Cubed!\n\n\n";
		cout << "We will now toss a coin to determine who goes first.\n\n";
		cout << "Press <enter> to toss the coin\n";
		cin.get();

		//initialize the board to empty
		for (int i=0; i<9; i++)
		{
			board[i] = ' ';
		}

		//coin toss
		if (rand()%10<5)
		{
			cout << "Computer won the toss and elects to use x's\n\n\n\n" << endl;
			cout << "Press <enter> to continue\n";
			cin.get();
			playerSymbol = 'o';
			compSymbol = 'x';
			board[0] = compSymbol;			//we always grab a corner if we win the toss
		}
		else
		{
			cout << "You won the toss!\n\n" << "Do you want x's or o's? (x/o)\n\n";
			playerFirst = true;
			do
			{
				cin >> playerSymbol;
				if (playerSymbol != 'x' && playerSymbol != 'o')
					cout << "Please re-enter your choice\n";
			}while(playerSymbol != 'x' && playerSymbol != 'o');
			if (playerSymbol == 'x')
				compSymbol = 'o';
			else
				compSymbol = 'x';
		}

		displayBoard(board);

		do
		{
			cout << endl << "Enter the row of your choice: ";
			if (!(cin>>row))
			{
				cin.clear();
				cin.ignore();
				cout << "\nYou did not enter an integer value\n";
				continue;
			}
			cout << endl << "Enter the column of your choice: ";
			if (!(cin>>col))
			{
				cin.clear();
				cin.ignore();
				cout << "\nYou did not enter an integer value\n";
				continue;
			}
			pos = inputValidation(board, row, col, playerSymbol);
			if (checkWin(board) == 'e')
				algorithm(board, pos, playerSymbol, compSymbol);
			displayBoard(board);
		}while(checkWin(board) == 'e');

		cout << "And the winner is..." << endl;

		switch (checkWin(board))
		{
		case 'x':
			if (compSymbol == 'x')
				cout << "The computer!!\n\n";
			else
				cout << "The human!!\n\n";
			break;
		case 'o':
			if (compSymbol == 'o')
				cout << "The computer!!\n\n";
			else
				cout << "The human!!\n\n";
			break;
		case 'f':
			cout << "Neither!! (It's a scratch)";
			break;
		default:
			cout << "He's dead Jim! (failure in the checkWin switch)";
			break;
		}

		cout << endl << "You want to play again? (y/n) ";
		cin >> keepGoing;
        turnCount = 0;
	}while(keepGoing == 'y' || keepGoing == 'Y');


}

/*
	We do a couple of things with this function.
	First up is making sure the input given matches what is legal.
	In other words, is the row and column given between 1 and 3.

	Next we convert the inputted coordinates into a single index.

	Then we check the index given to see if in fact that spot is empty.
	If it is not empty, we give the human another chance to try his/her input.

	Finally, we return the index chosen by the player to the variable 'pos',
	which is sent to the computer's algorithm (unless the player just made the last move
	possible in the game).

	It accepts as input an array, two integers representing the coordinates of the human's desired move,
	and the char that represents the human's symbol.

	It returns an integer that represents the index value of the human's move.
*/
int inputValidation(char array[], int row, int col, char playerSymbol)
{
	int pos = 0;

	//check if input is legal
	if (row<1 || row>3 || col<1 || col>3)
	{
		cout << "You entered an invalid combination.\n";
		cout << endl << "Re-Enter the row of your choice: ";
		cin >> row;
		cout << endl << "Re-Enter the column of your choice: ";
		cin >> col;
		return inputValidation(array, row, col, playerSymbol);
	}

	//convert row/col to position
	switch (row)
	{
	case 1:
		pos = col - 1;
		break;
	case 2:
		pos = col + 2;
		break;
	case 3:
		pos = col + 5;
		break;
	default:
		cout << "He's dead Jim! (Error converting input to position)";
	}

	if (checkEmpty(array, pos))
	{
		array[pos] = playerSymbol;
		turnCount++;
	}
	else
	{
		cout << "That spot is not empty\n";
		cout << endl << "Enter the row of your choice: ";
		cin >> row;
		cout << endl << "Enter the column of your choice: ";
		cin >> col;
		inputValidation(array, row, col, playerSymbol);
	}

	return pos;
}
/*
	This function also does a couple of things. It decides when the board is full
	or not, and then if the board is full it returns the winner.

	Accepts an array as input.
	Returns winning symbol if there is a winner.
	Returns 'e' if board is not full and no winner exists.
	Returns 'f' if board is full and yet no winner exists (scratch (or draw) game)
*/
char checkWin(char array[])
{
	cout << endl;
	//checking rows
	if (array[0] == array[1] && array[1] == array[2] && array[0] != ' ')
		return array[0];
	if (array[3] == array[4] && array[4] == array[5] && array[3] != ' ')
		return array[3];
	if (array[6] == array[7] && array[7] == array[8] && array[6] != ' ')
		return array[6];
	//checking columns
	if (array[0] == array[3] && array[3] == array[6] && array[0] != ' ')
		return array[0];
	if (array[1] == array[4] && array[4] == array[7] && array[1] != ' ')
		return array[1];
	if (array[2] == array[5] && array[5] == array[8] && array[2] != ' ')
		return array[2];
	//check diagonals
	if (array[0] == array[4] && array[4] == array[8] && array[0] != ' ')
		return array[0];
	if (array[2] == array[4] && array[4] == array[6] && array[2] != ' ')
		return array[2];

	//check if the board is full
	for (int i=0; i<9; i++)
	{
		if (array[i] == ' ')
			return 'e';
	}

	//now we have established a full board and no winner, so
	return 'f';
}

/*
	This function accepts an array and an index.
	It checks the given index in the array passed to it and determines whether or not
	the spot is empty.
	If the index position is empty, it returns true. Otherwise, it returns false.
*/
bool checkEmpty(char array[], int pos)
{
	if (array[pos] == ' ')
		return true;
	return false;
}

/*
	This function contains the real meat of the program. While there exist a couple of nifty algorithms
	that would have accomplished the same goal in like 40 lines, and been much more elegant, I didn't feel
	comfortable implementing them as I do not yet understand them completely. For example, MinMax or AlphaBeta.

	The function accepts an array, the index of the players move, and the symbol each player uses.

	This function really doesn't return anything, the return statement is just used to exit from the algorithm.
*/
int algorithm(char array[], int pos, char playerSymbol, char compSymbol)
{
	/*
		When the human goes first, the computer's first move is based on the human's first move
		If the human grabs center, we snag a corner.
		If they choose a corner, we nab center.
	*/
	if (playerFirst && turnCount==1)
	{

        if (pos == 4)
        {
            array[0] = compSymbol;
            turnCount++;
        }
		else
        {
            array[4] = compSymbol;
            turnCount++;
        }
        return 0;
	}

	//If the human goes first, and is smart, they grab two opposing corners in their first two moves.
	//This next bit of code ensures we respond to this with an edge move, preventing the fork.
	if (playerFirst && turnCount==2)
	{
		if ((array[0]==array[8] && array[0]!=' ') || (array[2]==array[6] && array[2]!=' '))
		{
			array[1] = compSymbol;
            turnCount++;
			return 0;
		}
	}

	//now we get to the general section:
	//We first check if we have an opportunity to win

	//row 1
	if (array[0]==compSymbol && array[1]==compSymbol && array[2] == ' ' || array[1]==compSymbol && array[2]==compSymbol && array[0]
		== ' ' || array[0]==compSymbol && array[2]==compSymbol && array[1]==' ')
		{
			findEmptySpace(array, 0, 1, 2, compSymbol);
			return 0;
		}
	//row 2
	if (array[3]==compSymbol && array[4]==compSymbol && array[5] == ' ' || array[4]==compSymbol && array[5]==compSymbol && array[3]
		== ' ' || array[3]==compSymbol && array[5]==compSymbol && array[4]==' ')
		{
			findEmptySpace(array, 3, 4, 5, compSymbol);
			return 0;
		}
	//row 3
	if (array[6]==compSymbol && array[7]==compSymbol && array[8] == ' ' || array[7]==compSymbol && array[8]==compSymbol && array[6]
		== ' '|| array[6]==compSymbol && array[8]==compSymbol && array[7]==' ')
		{
			findEmptySpace(array, 6, 7, 8, compSymbol);
			return 0;
		}
	//column 1
	if (array[0]==compSymbol && array[3]==compSymbol && array[6] == ' ' || array[3]==compSymbol && array[6]==compSymbol && array[0]
        == ' ' || array[0]==compSymbol && array[6]==compSymbol && array[3]==' ')
		{
			findEmptySpace(array, 0, 3, 6, compSymbol);
			return 0;
		}
	//column 2
	if (array[1]==compSymbol && array[4]==compSymbol && array[7] == ' ' || array[4]==compSymbol && array[7]==compSymbol && array[1]
        == ' ' || array[1]==compSymbol && array[7]==compSymbol && array[4]==' ')
		{
			findEmptySpace(array, 1, 4, 7, compSymbol);
			return 0;
		}
	//column 3
	if (array[2]==compSymbol && array[5]==compSymbol && array[8] == ' ' || array[5]==compSymbol && array[8]==compSymbol && array[2]
        == ' ' || array[2]==compSymbol && array[8]==compSymbol && array[5]==' ')
		{
			findEmptySpace(array, 2, 5, 8, compSymbol);
			return 0;
		}
	//diagonal number 1
	if (array[0]==compSymbol && array[4]==compSymbol && array[8] == ' ' || array[4]==compSymbol && array[8]==compSymbol && array[0]
        == ' ' || array[0]==compSymbol && array[8]==compSymbol && array[4]==' ')
		{
			findEmptySpace(array, 0, 4, 8, compSymbol);
			return 0;
		}
	//diagonal number 2
	if (array[2]==compSymbol && array[4]==compSymbol && array[6] == ' ' || array[4]==compSymbol && array[6]==compSymbol && array[2]
        == ' ' || array[2]==compSymbol && array[6]==compSymbol && array[4]==' ')
		{
			findEmptySpace(array, 2, 4, 6, compSymbol);
			return 0;
		}

	/*
		Now we check for any needed blocks.
		This has to be a separate run, lest we end up prioritizing blocks over wins :S
	*/
    if (array[0]==playerSymbol && array[1]==playerSymbol && array[2] == ' ' || array[1]==playerSymbol && array[2]==playerSymbol && array[0]
		== ' ' || array[0]==playerSymbol && array[2]==playerSymbol && array[1]==' ')
		{
			findEmptySpace(array, 0, 1, 2, compSymbol);
			return 0;
		}
	//row 2
	if (array[3]==playerSymbol && array[4]==playerSymbol && array[5] == ' ' || array[4]==playerSymbol && array[5]==playerSymbol && array[3]
		== ' ' || array[3]==playerSymbol && array[5]==playerSymbol && array[4]==' ')
		{
			findEmptySpace(array, 3, 4, 5, compSymbol);
			return 0;
		}
	//row 3
	if (array[6]==playerSymbol && array[7]==playerSymbol && array[8] == ' ' || array[7]==playerSymbol && array[8]==playerSymbol && array[6]
		== ' '|| array[6]==playerSymbol && array[8]==playerSymbol && array[7]==' ')
		{
			findEmptySpace(array, 6, 7, 8, compSymbol);
			return 0;
		}
	//column 1
	if (array[0]==playerSymbol && array[3]==playerSymbol && array[6] == ' ' || array[3]==playerSymbol && array[6]==playerSymbol && array[0]
        == ' ' || array[0]==playerSymbol && array[6]==playerSymbol && array[3]==' ')
		{
			findEmptySpace(array, 0, 3, 6, compSymbol);
			return 0;
		}
	//column 2
	if (array[1]==playerSymbol && array[4]==playerSymbol && array[7] == ' ' || array[4]==playerSymbol && array[7]==playerSymbol && array[1]
        == ' ' || array[1]==playerSymbol && array[7]==playerSymbol && array[4]==' ')
		{
			findEmptySpace(array, 1, 4, 7, compSymbol);
			return 0;
		}
	//column 3
	if (array[2]==playerSymbol && array[5]==playerSymbol && array[8] == ' ' || array[5]==playerSymbol && array[8]==playerSymbol && array[2]
        == ' ' || array[2]==playerSymbol && array[8]==playerSymbol && array[5]==' ')
		{
			findEmptySpace(array, 2, 5, 8, compSymbol);
			return 0;
		}
	//diagonal number 1
	if (array[0]==playerSymbol && array[4]==playerSymbol && array[8] == ' ' || array[4]==playerSymbol && array[8]==playerSymbol && array[0]
        == ' ' || array[0]==playerSymbol && array[8]==playerSymbol && array[4]==' ')
		{
			findEmptySpace(array, 0, 4, 8, compSymbol);
			return 0;
		}
	//diagonal number 2
	if (array[2]==playerSymbol && array[4]==playerSymbol && array[6] == ' ' || array[4]==playerSymbol && array[6]==playerSymbol && array[2]
        == ' ' || array[2]==playerSymbol && array[6]==playerSymbol && array[4]==' ')
		{
			findEmptySpace(array, 2, 4, 6, compSymbol);
			return 0;
		}


	/*
		Since we can't win, and nothing needs to be blocked, we turn to strategy
	*/

	/*
		We check first for an available corner, then center, and finally an edge spot

		Corners are indices 0, 2, 6, and 8.
		We check corners in a specific order. If the top left is unavailable, we then check
		the bottom right corner. Checking in this order does matter! If we don't check like
		this, we open ourselves up to a fork.

		Center is index 4.

		Edges are indices 1, 3, 5 and 7.
	*/
	if (checkEmpty(array, 0))
		{
			array[0] = compSymbol;
            turnCount++;
			return 0;
		}
	else if (checkEmpty(array, 8))
		{
			array[8] = compSymbol;
            turnCount++;
			return 0;
		}
	else if (checkEmpty(array, 6))
		{
			array[6] = compSymbol;
            turnCount++;
			return 0;
		}
	else if (checkEmpty(array, 2))
		{
			array[2] = compSymbol;
            turnCount++;
			return 0;
		}
	else if (checkEmpty(array, 4))
		{
			array[4] = compSymbol;
            turnCount++;
			return 0;
		}
	else
	{
		for (int i=0; i<9; i++)
		{
			if (checkEmpty(array, i))
			{
				array[i] = compSymbol;
                turnCount++;
				return 0;
			}
		}
		return 0;
	}
	return 0;
}

//just like it sounds :)
void clearScreen()
{
	cout << string(90, '\n');
    return;
}

/*
	I've chosen to display the row and column labels, as well as the numbers of the
	rows and columns for legibility's sake
*/
void displayBoard(char array[])
{
    clearScreen();
    cout << "     column \n";
	cout << "      1 2 3" << endl;
	cout << "    1 " << array[0] << "|" << array[1] << "|" << array[2] << endl;
	cout << "      -----" << endl;
	cout << "row 2 " << array[3] << "|" << array[4] << "|" << array[5] << endl;
	cout << "      -----" << endl;
	cout << "    3 " << array[6] << "|" << array[7] << "|" << array[8] << endl;
    return;
}

/*
	This function gets invoked when a need for a block or a win is discovered.
	The function checks each of the three positions, finds the empty spot and
	fills it (makes the computer's move)

	The function accepts an array, the three indices we want to explore, and the computer's symbol.

*/
int findEmptySpace(char array[], int value1, int value2, int value3, char compSymbol)
{
	if (checkEmpty(array, value1))
	{
		array[value1] = compSymbol;
        turnCount++;
		return 0;
	}
	if (checkEmpty(array, value2))
	{
		array[value2] = compSymbol;
        turnCount++;
		return 0;
	}
	if (checkEmpty(array, value3))
	{
		array[value3] = compSymbol;
        turnCount++;
		return 0;
	}
}
