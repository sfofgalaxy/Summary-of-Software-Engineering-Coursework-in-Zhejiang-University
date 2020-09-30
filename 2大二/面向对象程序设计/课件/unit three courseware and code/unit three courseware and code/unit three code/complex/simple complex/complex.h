#ifndef COMPLEX_H
#define COMPLEX_H
class complex{
public:
    complex();  //default constructor
	complex(double r);
	complex(double real, double imag);

	//complex(double real=0.0, double imag=0.0);

	void print();
	void set_real(double rpart);
	void set_imaginary(double ipart);
	double get_real();
	double get_imaginary();
    complex& operator=(const complex&);//operator overloading

	void f(complex c);

private:   
	double real_part;
    double imaginary_part;
	//double m[2];
}; 

#endif
