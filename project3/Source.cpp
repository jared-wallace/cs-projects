#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

char checkWin(char array[]);
int algorithm(char array[], int count, char playerSymbol, char compSymbol);
int checkEmpty(char array[], int pos);
int inputValidation(char array[], int row, int col, char playerSymbol);
void clearScreen();
void displayBoard(char array[]);
int findEmptySpace(char array[], int value1, int value2, int value3, char compSymbol);
bool playerFirst = false;

int main()
{
	char board[9];
	int row = 0, col = 0, pos = 0;
	char keepGoing = 'y', playerSymbol = 'p', compSymbol = 'p';

	srand(time(0));
	while (keepGoing == 'y' || keepGoing == 'Y')
	{
		clearScreen();
		cout << right << setw(40) << "Welcome to T Cubed!\n\n\n";
		cout << "We will now toss a coin to determine who goes first.\n\n";

		//initialize the board to empty
		for (int i=0; i<9; i++)
		{
			board[i] = ' ';
		}

		//coin toss
		if (rand()%10<5)
		{
			//computer wins
			cout << "Computer won the toss and elects to use x's" << endl;
			playerSymbol = 'o';
			compSymbol = 'x';
			board[0] = compSymbol;
		}
		else
		{
			cout << "You won the toss!\n\n" << "Do you want x's or o's? (x/o)\n\n";
			do
			{
				cin >> playerSymbol;
				playerFirst = true;
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
			cin >> row;
			cout << endl << "Enter the column of your choice: ";
			cin >> col;
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
			cout << "He's dead Jim!";
			break;
		}

		cout << endl << "You want to play again? (y/n) ";
		cin >> keepGoing;
	}


}

//makes sure input is kosher
int inputValidation(char array[], int row, int col, char playerSymbol)
{
	int pos = 0;

	if (row<1 || row>3 || col<1 || col>3)
	{
		cout << "You entered an invalid combination.\n";
		cout << endl << "Enter the row of your choice: ";
		cin >> row;
		cout << endl << "Enter the column of your choice: ";
		cin >> col;
		inputValidation(array, row, col, playerSymbol);
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
		cout << "Error converting input to position.";
	}

	if (checkEmpty(array, pos) == 1)
	{
		array[pos] = playerSymbol;
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
	returns winning symbol if there is a winner
	returns e if board is not full and no winner
	returns f if board is full and no winner
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

int checkEmpty(char array[], int pos)
{
	if (array[pos] == ' ')
		return 1;
	return 0;
}

int algorithm(char array[], int pos, char playerSymbol, char compSymbol)
{
	//When the human goes first, our first move is based on their first move
	if (playerFirst)
	{
		if (pos == 4)
			array[0] = compSymbol;
		else
			array[4] = compSymbol;
		playerFirst = false;
        return 0;
	}

	//check if we have an opportunity to win

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

	//Checking for needed blocks
	//This has to be a separate run, lest we end up prioritizing blocks over wins :S

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
	*/
	if (checkEmpty(array, 0))
		{
			//debug
			cout << "\nFound corner 0\n\n";
			array[0] = compSymbol;
			return 0;
		}
	else if (checkEmpty(array, 8))
	{
		//debug
		cout << "\nFound corner 8\n\n";

		array[8] = compSymbol;
		return 0;
	}
	else if (checkEmpty(array, 6))
		{
			//debug
			cout << "\nFound corner 6\n\n";
			array[6] = compSymbol;
			return 0;
		}
	else if (checkEmpty(array, 2))
		{
			//debug
			cout << "\nFound corner 2\n\n";
			array[2] = compSymbol;
			return 0;
		}
	else if (checkEmpty(array, 4))
		{
			//debug
			cout << "\nFound center\n\n";
			array[4] = compSymbol;
			return 0;
		}
	else
	{
		//debug
		cout << "\n\nArrived at iteration loop\n\n";
		for (int i=0; i<9; i++)
		{
			if (checkEmpty(array, i))
			{
				array[i] = compSymbol;
				return 0;
			}
		}
		return 0;
	}
	return 0;
}

void clearScreen()
{
	cout << string(90, '\n');
}

void displayBoard(char array[])
{
    clearScreen();
    cout << "       col \n";
	cout << "      1 2 3" << endl;
	cout << "    1 " << array[0] << "|" << array[1] << "|" << array[2] << endl;
	cout << "       -----" << endl;
	cout << "row 2 " << array[3] << "|" << array[4] << "|" << array[5] << endl;
	cout << "      -----" << endl;
	cout << "    3 " << array[6] << "|" << array[7] << "|" << array[8] << endl;
}

int findEmptySpace(char array[], int value1, int value2, int value3, char compSymbol)
{
	if (checkEmpty(array, value1))
	{
		array[value1] = compSymbol;
		return 0;
	}
	if (checkEmpty(array, value2))
	{
		array[value2] = compSymbol;
		return 0;
	}
	if (checkEmpty(array, value3))
	{
		array[value3] = compSymbol;
		return 0;
	}
}
