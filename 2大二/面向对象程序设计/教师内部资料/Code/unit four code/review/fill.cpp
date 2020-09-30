/*Fill in the blanks£¨25%£©Pay attention to the comments. No fill may also be an answer.*/
#include <iostream>           
#include <cmath>              
using namespace std;
#define PI 3.14159            
class Shape {                 
private:  
    int ID;
    static int counter;
public:
    Shape():ID(counter++) {}
    int objectID() const { return ID; }
    virtual void error() const ;  
    virtual double area() = 0;
    static int getcounter() { return counter; }
};
int Shape::counter = 0; //____(1)_____
/* Default error handling function provided by base class Shape, to display default code for error.*/
//____(2)_____
double Shape::error() const
{
	cout << "default code for error." << endl;
}

class Ellipse: public Shape
{
private:
    int lax,sax;
    static int counter;
public:
    Ellipse(int l,int s): lax(l),sax(s) //____(3)_____
    {
        if (lax!=sax) counter++;
    }
    //____(4)_____
	virtual double area()
    {
	    return PI*lax*sax;
    }

     /* Ellipse class to handle errors */
    //____(5)_____
	virtual void error() const
    {
        cout << "Ellipse code for error." << endl;
    }

    static int getcounter() { return counter; }
};
//____(6)_____
int Ellipse::counter = 0;

class Circle: public Ellipse 
{
public:
    Circle(int r): Ellipse(r,r)//____(7)_____
    {
        counter++;//____(8)_____
    } 
    static int getcounter() { return counter; }
    //not fill____(9)_____ 
     /* The Circle class does not want to make any special behavior for the error */
    //not fill ____(10)_____
private:
    static int counter;
};
int Circle::counter = 0;//____(11)_____

class Rectangle: public Shape
{
protected:
    int width,length;
    static int counter;
public:
    Rectangle(int w,int l): width(w),length(l)//____(12)_____
    {
        if (w!=l) counter++;//____(13)_____;
    }
    //____(14)_____
	virtual double area()
	{
		return width*length;
	}
    /* Rectangle class to handle errors */
    //____(15)_____
	virtual void error() const
	{
		cout << "Rectangle code for error." << endl;
	}

    static int getcounter() { return counter; }
};
int Rectangle::counter = 0;//____(16)_____

class Square: public Rectangle 
{
public:
    Square(int r): Rectangle(r,r)//____(17)_____
    {
        counter++//____(18)_____;
    }
    //not fill____(19)_____
    /* The Square class does not want to make any special behavior for the error */
    //not fill____(20)_____
    static int getcounter() { return counter; }
private:
    static int counter;
};
int Square::counter = 0;//____(21)_____;
class Triangle: public Shape 
{
    int a,b,c;
    static int counter;
public:
    Triangle(int a, int b, int c): a(a),b(b),c(c)//____(22)_____
    {
        counter++;
    }
    //____(23)_____
	virtual double area()
	{
		double l;
		l = (a+b+c)/2;
		return sqrt(l*(l-a)*(l-b)*(l-c));
	}
   /* Rectangle class to handle errors */
    //____(24)_____
	virtual void error() const
	{
		cout << "Triangle code for error." << endl;
	}
    static int getcounter() { return counter; }
};
//____(25)_____;
int Triangle::counter=0;

int main ()                                  
{
    Shape *list[6] = { 
        new Ellipse(2,4), new Circle(3), 
        new Rectangle(3,5), new Square(4), 
        new Triangle(1,2,2),new Ellipse(1,3)}; 
    for (int i=0; i<6; i++) {
        cout << list[i]->area() << '\n';
        list[i]->error();
    }
    cout << Ellipse::getcounter() << endl;  //output: 2
    cout << Circle::getcounter() << endl;  //output: 1
    cout << Rectangle::getcounter() << endl;  //output: 1
    cout << Square::getcounter() << endl;   //output: 1
    cout << Triangle::getcounter() << endl;   //output: 1
}
