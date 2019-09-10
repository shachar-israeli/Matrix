

Matrix | ReadMe


EX3:

The program represents a mathematic matrix.
there are  only 3 types of matrices that we deal with:  Arrowhead matrix, Toeplitz matrix and any matrix

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
