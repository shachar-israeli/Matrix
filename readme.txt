
This program makes matrices. It does that by the class Matrix the program is build on. Each matrix being build by the number of rows * number of columns the user put as an input, and also has a type the user input. Each matrix the user makes is initialized to be zeroes matrix at the start.The matrix type can be 1 of 3 types actually: "Arrowhead", "Toeplitz" or "any". Each one of the types is different, and has certain rules that the matrix has to handle. There are several methods which can be performed on the matrices, and they are programmed to check that every change which is being performed on the matrix does not break it's type. If a method break the matrix type, the program will not change the matrix by it. Those methods are basic methods which can be done on matrices, like shifting rows, shifting columns, sum matrices (the add method) etc.



Arrowhead   :https://en.wikipedia.org/wiki/Arrowhead_matrix
Toeplitz  : https://en.wikipedia.org/wiki/Toeplitz_matrix

Source code:
matrix.h
matrix.cpp

Data :

double **_array;
int rowSize, colSize;
string type;

++++++++++++++++++++++

Functions:

**private functions**

bool isFit(Matrix& a1, Matrix& a2); //check matrix size and type
Matrix* copyMat(); // copy matrix
int HowMuchToShift(const int shiftSize, int decide_shift);  // for shift methods

Matrix* copyMatrix();
bool isLegit(Matrix& a, Matrix& b)
bool sameType(Matrix& a, Matrix& b)
int checkShiftSize(const int shiftSize, int decide_shift)



//matrix main functions (public)

Matrix(int rows, int cols, string matType)	//constructor
void setElement(int i, int j, double data)
double getElement(int i, int j)
void add(Matrix& other, Matrix& result)
void rowShift(const int shiftSize)
void colShift(const int shiftSize)
bool isA(string matType)		//returns true / false is this->_array is the entered matrix type
void print()
~Matrix()				//destructor


Input:

 there is no input from console.

Output:
print()	- prints to the console the matrix.

Compile:
Visual Studio: Build Solution (Ctrl + Shift + B)


Run:
Visual Studio: Start Without Debugging (Ctrl + F5)
