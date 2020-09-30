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
 
	Matrix& operator<<(const int& t); //����д��:����ֵMatrix ��Ҳ���ܶ����const��Ա����

//	friend Matrix& operator<<(Matrix& m,const int& t);//����д�ɣ�const Matrix& m

	Matrix operator+(const Matrix& m);//����д��:����ֵMatrix&

	int* operator[](int i); //����д��T&

	friend ostream& operator<<(ostream& out,const Matrix& m);

	Matrix& operator=(const Matrix& m);

	//	friend T& operator[](T* p,int j) ;
};

