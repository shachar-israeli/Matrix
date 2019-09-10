
#ifndef _MATRIX_H
#include <iostream>
#include <string>

#define ARROW_HEAD "Arrowhead"
#define TOEPLITZ "Toeplitz"
#define ANY "any"

using namespace std;

class Matrix
{	
private:
	double **_array;
	int rowSize, colSize;
	string type;

	bool isFit(Matrix& a1, Matrix& a2); //check matrix size and type
	Matrix* copyMat(); // copy matrix
	int HowMuchToShift(const int shiftSize, int decide_shift);  // for shift methods

public:

	
	Matrix(int rows, int cols,string matType);// constractor
	
	void setElement(int i, int j, double data); // set arr[i][j]
	
	double getElement(int i, int j); // get arr[i][j]
	 
	void add(Matrix& other, Matrix& result); //add 2 matrix to result

	void rowShift(const int shiftSize); // shift up-down

	void colShift(const int shiftSize); //shift left - right

	bool isA(string matType);  // check type of the matrix

	void print();

	~Matrix();  //destractor

#endif //	_MATRIX_H
};


