#ifndef COMPLEX_H
#define COMPLEX_H

class complex{
public: 
	complex(double rp=0.0, double ip=0.0)
	{  
		rpart = rp;   
		ipart = ip; 
	}
	complex(const complex& obj)
	{
		rpart = obj.rpart;
		ipart = obj.ipart;
	}
	
	double getImaginary() const
	{
		return ipart;
	}
	double getReal() const
	{
		return rpart;
	}
	void setImaginary(double i)
	{
		ipart = i;
	}
	void setReal(double r)
	{
		rpart = r;
	}
	
	operator double() const
	{
		return sqrt(rpart*rpart+ipart*ipart);
	}

    friend const complex operator+(const complex& add1, const complex& add2);//友员函数版
    friend const complex operator+(const complex& x);
	
	friend const complex operator*( const complex& x, const complex& y)
	{
		complex temp(sqrt(x.rpart + y.rpart), sqrt(x.ipart + y.ipart));
		return temp;
	}

	friend ostream& operator<<(ostream& os, const complex& com);//去掉&调试？？
    friend istream& operator>>(istream& is, complex& com);
private:   
	double rpart;
    double ipart;
};

#endif
