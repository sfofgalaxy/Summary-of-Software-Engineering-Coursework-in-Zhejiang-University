#include <iostream.h>
#include <memory.h>

class Matrix{
private:
	int row;
	int col;
	int * pM; 
public:
	Matrix(int m1,int n1);

	~Matrix()
	{
		delete[] pM;
	}

	Matrix(const Matrix& m);
 
	Matrix& operator<<(const int& t); //不能写成:返回值Matrix ，也不能定义成const成员函数

//	friend Matrix& operator<<(Matrix& m,const int& t);//不能写成：const Matrix& m

	Matrix operator+(const Matrix& m);//不能写成:返回值Matrix&

	int* operator[](int i); //不能写成T&

	friend ostream& operator<<(ostream& out,const Matrix& m);

	Matrix& operator=(const Matrix& m);

	//	friend T& operator[](T* p,int j) ;
};

