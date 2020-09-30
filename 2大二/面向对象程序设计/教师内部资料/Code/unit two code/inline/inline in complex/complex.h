#ifndef COMPLEX_H
#define COMPLEX_H
 
#include <iostream>
#include <cfloat>

class complex{
private:   
	double real_part;
    double imaginary_part;
public:
	complex(double r=0,double i=0)  //��ʽ��inline����
	{
		real_part = r ;
		imaginary_part = i;
	}

	complex(const complex& obj)//�������캯��
	{
		real_part = obj.real_part ;
		imaginary_part = obj.imaginary_part;
	}

	void set_real(double rpart)
	{
		real_part = rpart;
	}

	void set_imaginary(double ipart) 
	{
		imaginary_part = ipart;
	}
	inline void print() const; 
	inline double get_real();  //��ʽ��inline����
	inline double get_imaginary();
    inline complex operator+(const complex& m) const;
    //ϵͳ�Զ����ɵ���������
	~complex()
	{}
};

inline void complex::print() const
{
	using std::cout;
	using std::endl;

	if ((-DBL_EPSILON < imaginary_part) && (imaginary_part < DBL_EPSILON))
		cout << real_part << endl;
	else if (imaginary_part > 0)
		cout << real_part << "+" << imaginary_part << 'i' << endl;
	else
		cout << real_part << "-" << -imaginary_part << 'i' << endl;
}

inline double complex::get_real()
{
	return real_part;
}

inline double complex::get_imaginary()
{
	return imaginary_part;
}

inline complex complex::operator+(const complex& m) const
{
	complex temp;
	temp.real_part = real_part+m.real_part;
	temp.imaginary_part = imaginary_part+m.imaginary_part;
	return temp;
}
#endif