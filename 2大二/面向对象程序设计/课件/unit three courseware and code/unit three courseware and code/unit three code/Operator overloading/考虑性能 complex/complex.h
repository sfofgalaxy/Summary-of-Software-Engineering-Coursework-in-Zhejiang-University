#include <iostream.h>
#include <math.h>


class complex{
private:   
	double rpart;
    double ipart;
public: 
	complex(double rp=0.0,double ip=0.0)//explicit
	{  
		rpart=rp;   
		ipart=ip; 
	}			  
   
	const complex operator+( const complex& x);
    friend const complex operator+(int i, const complex& y);//��Ա������
    friend const complex operator+( const complex& y, int i);
 
//	complex& operator+=(const complex& x);

	friend ostream& operator<<(ostream& os, const complex& com);//ȥ��&���ԣ���
    friend istream& operator>>(istream& is, complex& com);
   
};
