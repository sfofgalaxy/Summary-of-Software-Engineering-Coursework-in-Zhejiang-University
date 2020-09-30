#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

//ģ����ǰ������
template <typename T> class MATRIX;
//MATRIXģ�������Ԫ����
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
    MATRIX& operator<<(const T& t); //����д��:����ֵMATRIX ��Ҳ���ܶ����const��Ա����
    MATRIX operator+(const MATRIX<T>& m);//����д��:����ֵMATRIX&
	T* operator[](int i); //����д��T&	
	//friend ostream& operator<< <>(ostream &out, MATRIX<T> & n);
	friend istream& operator>> <> (istream&, MATRIX<T>&);

	//�ں������������<>��ָ������֮ǰ�����ĺ���ģ�� ��ʵ��
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
		std::cout << "���±�Խ�磡" << std::endl;
	    return 0;
	}
}
/*������������ز�����ģ������������ģ������ʵ�֡���Ϊģ��Ƚ����⣬������ģ������ʵ�����صĻ���*/
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
/*������������ģ����ĳ�Ա�������˴��൱�ڶ�����һ���µĺ���ģ�塣�˴���T��ģ�����е�T�ǲ�ͬ�ġ�
*/

template<typename T>
istream& operator>>(istream &in, MATRIX<T> &a){
	for (int i = 0; i < a.row*a.col; i++)
		in >> pv[i];
	return in;
}


#endif