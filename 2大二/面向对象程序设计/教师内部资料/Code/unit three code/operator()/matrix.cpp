#include "matrix.h"

Matrix::Matrix(int r, int c):row(r),col(c)
{	
	pv = new int[row*col];
	memset(pv,0, sizeof(int)*row*col);
}
/*
const Matrix Matrix:: operator+(const Matrix& m)
{
	if(row == m.row && col == m.col)
	{
		Matrix temp(row,col);

		for (int i=0; i<m.row*m.col; i++)
			*(temp.pv+i) = *(pv+i) + *(m.pv+i);
		
		return temp;
	}
}*/

int Matrix::operator()(int i,int j) const
{
	if ((i<0 || i>=row) || (j<0 || j>=col) ) exit(0);
	return *(pv + i*col + j);
}

int& Matrix::operator()(int i,int j) 
{
	if ((i<0 || i>=row) || (j<0 || j>=col) ) exit(0);
	return *(pv + i*col + j);
}

std::ostream& operator<<(std::ostream& os, const Matrix& n)
{
    int total = n.row * n.col;
    for(int i = 0;i < total;i++){
	    os << *(n.pv+i) << "\t";
	    if ((i+1)%n.col == 0) os << std::endl;
    }
    return os;
}