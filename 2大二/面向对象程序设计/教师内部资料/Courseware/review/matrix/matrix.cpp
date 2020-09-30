#include "matrix.h"
#include <iostream.h>
#include <memory.h>


Matrix::Matrix(int m1,int n1)
{  
	row = m1;
    col = n1;
	pM = new int[m1*n1];
}

Matrix::Matrix(const Matrix& m)
{
	row = m.row;
	col = m.col;
	pM = new int[row*col];
	::memcpy( pM, m.pM, row*col*sizeof(int) );
}

Matrix& Matrix::operator<<(const int& t)
{
	static int i=0;
	int k;
	if (i>=row*col)	
		i=0;
	k=i/col;
	*(pM+k*col+i%3)=t;
	i++;
	return *this;
}

/*
//全局函数
Matrix& operator<<(Matrix& m,const int& t)
{
	static int i=0;
	int k;
	if (i>=m.row*m.col)	
		i=0;
	k=i/m.col;
	*(m.pM+k*m.col+i%3)=t;
	i++;
	return m;
}*/

Matrix Matrix::operator+(const Matrix& m)
{
	if(row == m.row && col == m.col)
	{
		Matrix temp(row,col);

		for (int i=0; i<m.row*m.col; i++)
			*(temp.pM+i) = *(pM+i) + *(m.pM+i);
		
		return temp;
	}
}
int& array::operator[](int index)
{
	//..
}

int* Matrix::operator [](int i)
{
	if (i<row && i>=0)
		return pM+i*col;
	else 
	{
		cout << "行下标越界！" << endl;
	    return 0;
	}
}

ostream& operator<<(ostream &out,const Matrix& m)  
{
	for(int i=0;i<m.row*m.col;i++){
		out<<*(m.pM+i);
		if((i+1)%m.col==0)
			out<<endl;
	}
	return out;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	delete[] pM;
	row = m.row;
	col = m.col;
	pM = new int[row*col];
	memcpy( pM, m.pM, row*col*sizeof(int) );
	return *this;
}

/*
int& operator[](int* p,int j)	 
{
	if (j<col && j>=0)
		return *(p+j*sizeof(T));
	else {
		cout<<" 列下标越界！"<<endl;
	    return 0;
	}
}
*/








