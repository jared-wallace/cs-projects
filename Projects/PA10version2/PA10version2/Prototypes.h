#include <string>
#include <fstream>
#include "global.h"
using namespace std;


double matrixA[nrows][ncols]={0}, matrixB[nrows][ncols]={0}, matrixC[nrows][ncols]={0}, matrixD[nrows][ncols]={0};
void multiply(double X[nrows][ncols], int rowsx, int colsx, double Y[nrows][ncols], int rowsy, int colsy, double Z[nrows][ncols], double Z2[nrows][ncols], int square);
void printarray(double X[nrows][ncols], int rowsx, int colsx, double Y[nrows][ncols], int rowsy, int colsy, double Z[nrows][ncols], double Z2[nrows][ncols], ostream& out, int square);
int inputBlock(double matrixX[nrows][ncols], double matrixY[nrows][ncols], int &rows1, int &cols1, int &rows2, int &cols2, string &filename3, bool &cont);
int errorCheck(int rows1, int cols1, int rows2, int cols2);