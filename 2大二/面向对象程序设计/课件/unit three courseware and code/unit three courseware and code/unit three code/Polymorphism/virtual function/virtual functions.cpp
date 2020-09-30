//虚函数的定义
#include <iostream>
using namespace std;

class Shape {
private:
   int ID;
public:
	int objectID() const  //non-virtual member function
	{
	    return ID;
	}
    virtual void error() const ;  //shape类需提供函数实现
    //...
};
/*每个派生类都可以支持一个“当遇上错误时可调用”的函数，
每个派生类可自由处理错误。如果某个派生类不想针对错误做出任何特殊行为，
它可以退回到基类shape提供的缺省错误处理行为。
*/
void Shape::error() const
{
	cout << "default code for error." << endl;
}

class Rectangle: public Shape { 
public:
	virtual void error() const
	{
		cout << "code for Rectangle::error."  << endl;
	}
	//...
private:
	int width,length; 
};
class Ellipse: public Shape { 
public:
		//...
private:
	int shortHalfAxle,longHalfAxle;
};

void main()
{
 	Shape *ps;
	
	ps = new Rectangle;//upcasting   
	ps -> error();//dynamic binding，call Rectangle::error()

	ps = new Ellipse;
	ps->error();  //dynamic binding	call Shape::error()
		
	Shape &rs1 = *ps;//dynamic binding
	rs1.error();   //dynamic binding call Rectangle::error()
   
}