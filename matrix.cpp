
/*
EX3:

Authored by Shachar Israeli
203713094
15/12/2017

The program represents a mathematic matrix.
there are  only 3 types of matrices that we deal with:
Arrowhead matrix, Toeplitz matrix and any matrix


Name : Shachar Israeli
ID   : 203713094
*/

#include <iostream>
#include <string> 
#include "matrix.h"
#include <assert.h>

#define ARROW_HEAD "Arrowhead"
#define TOEPLITZ "Toeplitz"
#define ANY "any"


Matrix::Matrix(int rows, int cols, string matType)   // counstractor. built the metrix and put 0 in it
	{
	if (rows <= 0 || cols <= 0) // checks for legal operators
	{
		cout << "Invalid input: please enter valid type of matrix" << endl;
		this->~Matrix() ;               // // do delete the matrix
		return;               
	}

	if (matType != ANY && matType != ARROW_HEAD && matType != TOEPLITZ)// check valid type
	{
		cout << "Invalid input: please enter valid type of matrix" << endl;
		this->~Matrix();
		return;
	}

	if (matType == ARROW_HEAD && rows != cols)  // ArrowHead can be only row = col
	{
		cout << "Invalid input: for constructring ArrowHead matrix you must have same rows and cols" << endl;
		this->~Matrix();
		return;
	}
    	rowSize = rows;
	    colSize = cols;
	    type = matType;

		_array = new double*[rows];   // make the matrix
		assert(_array != NULL);

		for (int i = 0; i < rows; i++) 
		{
			_array[i] = new double[cols];
			assert(_array[i] != NULL);
		}
		
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				_array[i][j] = 0;
	}

Matrix::~Matrix()   // destracor of the matrix
{
	for (int i = 0; i < rowSize; i++)
	{
		delete[] _array[i];
	}
	delete[]_array;
}

void Matrix::setElement(int i, int j, double data)
{

	if (_array == NULL)// check if the matrix is initialized
	{ 
		cout << "NA - The matrix should be initialized first"<< endl;
		return;
	}

	bool flag = true;     // to see if we gonna change the element or not
	
	if (i >= rowSize || j >= colSize || i < 0 || j < 0)    // check the parameters
	{
		cout << "NA\n";
		return;
	}
	
	if (type.compare(TOEPLITZ) == 0 || type.compare(ARROW_HEAD) == 0)  // check the special cases
	{
		Matrix* originCopy = copyMat(); // make copy of the matrix
		originCopy->_array[i][j] = data; 

		if (originCopy->isA(originCopy->type) == false)   // check if the type still true
		{
			flag = false;
			cout << "NA\n";
		}
		delete originCopy;     // delete the copy matrix
	}
	if (flag)           // the type still true after the change
		_array[i][j] = data;	
 }

double Matrix::getElement(int i, int j)
{	
	if (i < rowSize && j < colSize && i >= 0 && j >= 0)  // check the paramaters
	{
		return _array[i][j];
	}
	cout << "NA\n";
	this->~Matrix();
	exit(1);
}

bool Matrix::isFit(Matrix& a1, Matrix& a2)   //private method. return true if same type and size
{

	if (a1.colSize == a2.colSize && a1.rowSize == a2.rowSize && a1.type.compare(a2.type) == 0)
		return true;
	return false;
}

void Matrix::add(Matrix& other, Matrix& result)  // add only if type and size the same 
{
	if (_array == NULL || other._array == NULL)// check if the matrix is initialized
	{
		cout << "NA - The matrixs should be initialized first" << endl;
		return;
	}

	if (isFit(other, result) && other.rowSize == rowSize && other.colSize == colSize && type.compare(other.type) == 0) 
	{
		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				result._array[i][j] = _array[i][j] + other._array[i][j]; // add places by place
	}
	else 
	{
		cout << "NA\n";
	}
}

void Matrix::print()
{

	if (_array == NULL)// check if the matrix is initialized
	{
		cout << "NA - The matrix should be initialized first" << endl;
		return;
	}

	for (int i = 0; i < rowSize; i++)       // print the matrix with , between the values
	{
		for (int j = 0; j < colSize; j++)
		{
			if (j == colSize - 1)
				cout << _array[i][j];
			else
				cout << _array[i][j] << ",";
		}
		cout << "\n";
	}
	cout << "\n";
}

Matrix* Matrix::copyMat()        //copy the matrix
{

	Matrix *a = new Matrix (rowSize, colSize, type) ;  // pointer to the copy
	assert(a != NULL);
	 for (int i = 0; i < rowSize; i++)
		 for (int j = 0; j < colSize; j++)
			 a->_array[i][j] = _array[i][j];
	 return a;          
}


int Matrix::HowMuchToShift(const int shiftSize, int decide_shift)  // private . check the shift size
{
	int toShift;

	if (shiftSize < 0)         // left or up
	{
		int temp = ((abs(shiftSize)) % decide_shift);    // == how much to shift if it was positive number
		toShift = decide_shift - temp;
	}

	else            // shift > 0
	{
		toShift = shiftSize % decide_shift;
	}

	return toShift;
}



void Matrix::colShift(const int shiftSize)
{
	if (_array == NULL)// check if the matrix is initialized
	{
		cout << "NA - The matrix should be initialized first" << endl;
		return;
	}

	int toShift = HowMuchToShift(shiftSize, colSize); // shift size after check

	if (toShift == 0)         // dont need to move so return
		return;

	Matrix* origin = copyMat();        // copy matrix

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			_array[i][(toShift + j) % colSize] = origin->_array[i][j]; // change it

	if (type.compare(TOEPLITZ) == 0 || type.compare(ARROW_HEAD) == 0)
	{
		if (isA(type) == false)         // check if still like the type should be
		{
			for (int i = 0; i < rowSize; i++)
				for (int j = 0; j < colSize; j++)
					_array[i][j] = origin->_array[i][j];   // return to the origin matrix
		}
	}
	delete origin;   // del temp
}

void Matrix::rowShift(const int shiftSize)
{
	if (_array == NULL)// check if the matrix is initialized
	{
		cout << "NA - The matrix should be initialized first" << endl;
		return;
	}

	int toShift = HowMuchToShift(shiftSize, rowSize);  // shift after check

	if ( toShift == 0)        // dont need to move so return
		return;

	 Matrix* origin =  copyMat();        //copy of the matrix
	 
	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			_array[(toShift + i) % rowSize][j] = origin->_array[i][j];  // move to the place to shift

	if (type.compare(TOEPLITZ) == 0 || type.compare(ARROW_HEAD) == 0)
	{
		if (isA(type) == false)  // if its not like the type should be change to the origin matrix
		{
			for (int i = 0; i < rowSize; i++)
				for (int j = 0; j < colSize; j++)
					_array[i][j] = origin->_array[i][j]; // return to the origin matrix
		}
	}

	delete origin;         // delete the temp
}

bool Matrix::isA(string matType)  
{
	if (_array == NULL)// check if the matrix is initialized
	{
		cout << "NA - The matrix should be initialized first" << endl;
		return false;
	}

	 if (matType.compare(ARROW_HEAD) == 0)  // for ArrowHead 
	{   
		if (colSize != rowSize)  // must be =
			return false;

		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < colSize; j++)
			{

				if (_array[i][j] != 0)      // if there is num!= it should be only there
				{
					if (i != 0 && j != 0 && i != j)
						return false;
				}
			}
		}
		return true;
	}
	else if (matType.compare(TOEPLITZ) == 0)
	{
		for (int i = 0; i < rowSize - 1; i++)
		{
			for (int j = 0; j < colSize - 1; j++)
			{
				if (_array[i][j] != _array[i + 1][j + 1])
					return false;
			}
		}
		return true;
	}
	else              // about ANY matrix
		 return true;
}