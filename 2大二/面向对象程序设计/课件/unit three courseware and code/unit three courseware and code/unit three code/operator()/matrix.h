
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
	Matrix(int r,int c);
	
	~Matrix()
	{
		delete[] pv;	
	}	
    //const Matrix operator+(const Matrix& m);//不能写成:返回值Matrix&
    int operator()(int i,int j) const;
	int& operator()(int i,int j);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& n);
private:
	int row,col;
    int *pv;
	Matrix(const Matrix& m);
	Matrix& operator=(const Matrix& m);
};
#endif