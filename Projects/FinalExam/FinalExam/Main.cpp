/* 
Student: Jared Wallace
Assignment #: Final Exam
Assignment Description: Apply some of what you have learned this semester. (all you have learned from this book)
Issue Date: n/a
Due Date: 5-7-2012
Course: Computer Programming for Engineers
Instructor: Bobby Eddy

This program made me grit my teeth.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int nrows(10), ncols(10);

int main()
{
	int Array_In[nrows][ncols]={0}, Sub_Array_A[nrows][ncols]={0}, Sub_Array_B[nrows][ncols]={0}, Sub_Array_C[nrows][ncols]={0}, rowsx(0), colsx(0), Sub_Rows(0), Sub_Cols(0), Row_Number(0);
	int Starting_Position_Row(0), Starting_Position_Col(0), Sub_Rows2(0), Sub_Cols2(0);
	double Average_Value(0);
	void subarray(int original[nrows][ncols], int Sub_A[nrows][ncols], int SubRows, int Subcols, int startrow, int startcol);
	void subtract(int Sub_A[nrows][ncols], int SubRows1, int Subcols1, int Sub_B[nrows][ncols], int Subrows2, int Subcols2, int Sub_C[nrows][ncols]);
	double average(int Sub_c[nrows][ncols], int Subcols, int Row_Number);
	void Print_Screen(int matrix[nrows][ncols], int rows, int cols);
	void Print_File(int matrix1[nrows][ncols], int matrix2[nrows][ncols], int matrix3[nrows][ncols], int matrix4[nrows][ncols], int rows1, int cols1, int rows2, int cols2, int rows3, int cols3, int Row_Number, double average);
	string filename1;
	ifstream fin;

	system("Cls");
	cout << "Enter the name of the input file\n\n";
	cin >> filename1;
	fin.open(filename1.c_str());

	if (!fin)
	{
		cerr << "Error opening file, please try again.\n\n";
		system("Pause");
		main();
	}

	cout << "Please enter the rows of the desired matrix\n\n";
	cin >> rowsx;
	cout << "Please enter the columns of the desired matrix\n\n";
	cin >> colsx;
	if (rowsx > 10 || colsx > 10)
	{
		system("Cls");
		cerr << "\n\nWhat the deuce do you think you're doing?!?\n\nThe most I can handle is a 10 X 10 array!\n\n";
		cerr << "Go directly to jail, do not pass go and do not collect 200 dollars\n\n";
		system("Pause");
		main();
	}

	cout << "The initial array looks like this: \n\n";

	for (int i=0; i<rowsx; i++)
		for (int j=0; j<colsx; j++)
				fin >> Array_In[i][j];
	Print_Screen(Array_In, rowsx, colsx);

	fin.close();
	


	cout << "Please enter starting position (row then column) of the first matrix\n\nyou want to extract\n\n";
	cin >> Starting_Position_Row >> Starting_Position_Col;
	cout << "Enter the desired size of the sub-array, rows and then columns\n\n";
	cin >> Sub_Rows >> Sub_Cols;
	if (Sub_Rows > 5 || Sub_Cols > 5)
	{
		system("Cls");
		cerr << "Sorry, maximum size permitted is 5 X 5.\n\nYour penalty for this mistake...\n\n\n\n\n\n\n\n\n\nIs starting over!!!!!  Bwahahahahahaha\n\n";
		system("Pause");
		main();
	}

	subarray(Array_In, Sub_Array_A, Sub_Rows, Sub_Cols, Starting_Position_Row, Starting_Position_Col);
	cout << "The first sub-array looks like this:\n\n";
	Print_Screen(Sub_Array_A, Sub_Rows, Sub_Cols);




	cout << "Please enter starting position (row then column) of the second matrix\n\nyou want to extract\n\n";
	cin >> Starting_Position_Row >> Starting_Position_Col;
	cout << "Enter the desired size of the sub-array, rows and then columns\n\n";
	cin >> Sub_Rows2 >> Sub_Cols2;
	if (Sub_Rows2 > 5 || Sub_Cols2 > 5)
	{
		system("Cls");
		cerr << "Sorry, maximum size permitted is 5 X 5.\n\nYour penalty for this mistake...\n\n\n\n\n\n\n\n\nIs starting over!!!!!   Bwahahahahaha\n\n";
		system("Pause");
		main();
	}

	subarray(Array_In, Sub_Array_B, Sub_Rows2, Sub_Cols2, Starting_Position_Row, Starting_Position_Col);
	cout << "The second sub-array looks like this:\n\n";
	Print_Screen(Sub_Array_B, Sub_Rows2, Sub_Cols2);


	system("Pause");
	system("Cls");
	subtract(Sub_Array_A, Sub_Rows, Sub_Cols, Sub_Array_B, Sub_Rows2, Sub_Cols2, Sub_Array_C);
	cout << "The result of the subtraction looks like this:\n\n";
	Print_Screen(Sub_Array_C, Sub_Rows, Sub_Cols);
	cout << "Please enter the row number of the result you want to average\n\n";
	cin >> Row_Number;
	Average_Value = average(Sub_Array_C, Sub_Cols, Row_Number);
	cout << "The average value of row " << Row_Number << " is: " << Average_Value << endl;

	Print_File(Array_In, Sub_Array_A, Sub_Array_B, Sub_Array_C, rowsx, colsx, Sub_Rows, Sub_Cols, Sub_Rows2, Sub_Cols2, Row_Number, Average_Value);

	system("Pause");

}

void subarray(int original[nrows][ncols], int Sub_A[nrows][ncols], int SubRows, int Subcols, int startrow, int startcol)
{
	startrow--;
	startcol--;
	for (int i=0; i<SubRows; i++)
		for (int j=0; j<Subcols; j++)
			Sub_A[i][j] = original[i+startrow][j+startcol];
}

void subtract(int Sub_A[nrows][ncols], int Subrows1, int Subcols1, int Sub_B[nrows][ncols], int Subrows2, int Subcols2, int Sub_C[nrows][ncols])
{
	if (Subrows1 != Subrows2 || Subcols1 != Subcols2)
	{
		cerr << "\n\nSubtraction of these two arrays is impossible using any known technique.\n\nYou just earned a free trip to the beginning!!!\n\n";
		system("Pause");
		main();
	}

	for (int i=0; i<Subrows1; i++)
		for (int j=0; j<Subcols1; j++)
			Sub_C[i][j] = Sub_A[i][j] - Sub_B[i][j];
}

double average(int Sub_c[nrows][ncols], int Subcols, int Row_Number)
{
	double average(0), sum(0);
	Row_Number--;
	for (int i=0; i<Subcols; i++)
		sum += Sub_c[Row_Number][i];
	average = sum/Subcols;
	return(average);
}

void Print_Screen(int matrix[nrows][ncols], int rows, int cols)
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void Print_File(int matrix1[nrows][ncols], int matrix2[nrows][ncols], int matrix3[nrows][ncols], int matrix4[nrows][ncols], int rows1, int cols1, int rows2, int cols2, int rows3, int cols3, int Row_Number, double average)
{
	ofstream fout("data.dat");

	fout << "The initial array looks like this: \n\n";
	for (int i=0; i<rows1; i++)
	{
		for (int j=0; j<cols1; j++)
			fout << matrix1[i][j] << " ";
		fout << endl;
	}

	fout << "The first sub-array looks like this:\n\n";
	for (int i=0; i<rows2; i++)
	{
		for (int j=0; j<cols2; j++)
			fout << matrix2[i][j] << " ";
		fout << endl;
	}

	fout << "The second sub-array looks like this:\n\n";
	for (int i=0; i<rows3; i++)
	{
		for (int j=0; j<cols3; j++)
			fout << matrix3[i][j] << " ";
		fout << endl;
	}

	fout << "The third sub-array looks like this:\n\n";
	for (int i=0; i<rows3; i++)
	{
		for (int j=0; j<cols3; j++)
			fout << matrix4[i][j] << " ";
		fout << endl;
	}

	fout << "The average value of row " << Row_Number << " is: " << average << endl;

}