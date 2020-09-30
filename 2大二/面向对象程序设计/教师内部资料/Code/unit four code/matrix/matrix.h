#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

//模板类前置声明
template <typename T> class MATRIX;
//MATRIX模板类的友元声明
template <typename T> ostream& operator<< <>(ostream &out, MATRIX<T> & n);

template <typename T>
class MATRIX {
public:
	MATRIX(int r,int c);
	~MATRIX()
	{
		delete[] pv;
	}
	MATRIX(const MATRIX& m);
    MATRIX& operator<<(const T& t); //不能写成:返回值MATRIX ，也不能定义成const成员函数
    MATRIX operator+(const MATRIX<T>& m);//不能写成:返回值MATRIX&
	T* operator[](int i); //不能写成T&	
	//friend ostream& operator<< <>(ostream &out, MATRIX<T> & n);
	friend istream& operator>> <> (istream&, MATRIX<T>&);

	//在函数名后面加上<>，指明它是之前声明的函数模板 的实例
private:
	int row,col;
    T *pv;
	MATRIX& operator=(const MATRIX& m);
};

template <class T>
MATRIX<T>::MATRIX(int r, int c):row(r),col(c)
{	
	pv = new T[row*col];
}

template <class T>
MATRIX<T>::MATRIX(const MATRIX& m)
{
	row = m.row;
	col = m.col;
	pv = new T[row*col];
	memcpy( pv, m.pv, row*col*sizeof(T) );
}

template <typename T>
MATRIX<T>& MATRIX<T>::operator<<(const T& t)
{
	static int i = 0;
	int k;
	if (i >= row*col) i = 0;
	k = i / col;
	*(pv + k*col + i%3) = t;
	i++;
	return *this;
}

template <typename T>
MATRIX<T> MATRIX<T>:: operator+(const MATRIX<T>& m)
{
	if(row == m.row && col == m.col)
	{
		MATRIX temp(row,col);

		for (int i=0; i<m.row*m.col; i++)
			*(temp.pv+i) = *(pv+i) + *(m.pv+i);
		
		return temp;
	}
}

template <typename T>
T* MATRIX<T>::operator[](int i)
{
	if (i<row && i>=0)
		return pv + i*col;
	else 
	{
		std::cout << "行下标越界！" << std::endl;
	    return 0;
	}
}
/*输入输出流重载不能在模板类内声明，模板类外实现。因为模板比较特殊，若果在模板类外实现重载的话：*/
/*template <typename T>
ostream& operator<<(ostream &out, MATRIX<T> & n)
{
	int total = n.row * n.col;
 	for(int i = 0;i < total;i++){
		os << *(n.pv+i);
		if ((i+1)%n.col == 0)
			os << std::endl;
	}
     return os;
}*/
/*上述函数不是模板类的成员函数，此处相当于定义了一个新的函数模板。此处的T与模板类中的T是不同的。
*/

template<typename T>
istream& operator>>(istream &in, MATRIX<T> &a){
	for (int i = 0; i < a.row*a.col; i++)
		in >> pv[i];
	return in;
}


#endif