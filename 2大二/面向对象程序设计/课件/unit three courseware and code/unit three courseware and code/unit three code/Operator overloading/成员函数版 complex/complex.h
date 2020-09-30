#ifndef COMPLEX_H
#define COMPLEX_H

class complex{
public:     
	complex() 
	{
		rpart = ipart = 0.0;
	}

	complex(double d) //������ʽ����ת������,but explicit
	{
		rpart = d;
		ipart = 0.0;
	}

	complex(double rp,double ip)
	{  
		rpart = rp;   
		ipart = ip; 
	}	  
   //const complex add(const complex& com); 

	//a + b  a.operator+(b) 
	const complex operator+(const complex& com)  const ;//��Ŀ��
   
   //+a   a.operator+()
 	const complex operator+() const;//��Ŀ��  

	void print() const;
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
	/*
	operator double() const
	{
		return sqrt(rpart*rpart+ipart*ipart);
	}*/
	friend const complex operator+(int i, const complex& obj);
private:   
	double rpart;
    double ipart;
};

#endif






