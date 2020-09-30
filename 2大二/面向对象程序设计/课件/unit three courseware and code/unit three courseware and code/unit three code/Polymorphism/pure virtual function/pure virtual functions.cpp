//虚函数的定义
#include <iostream>
using namespace std;

class Shape {
private:
   int ID;
public:
	int objectID() const   //non-virtual member function
	{
		return ID;
	}
    virtual void error() const;  //virtual member function
	virtual void draw() const = 0;   //pure virtual function,基类与派生类有同名操作，派生类必须有自己的实现（只继承接口）。
    //...
	virtual ~Shape()
	{}
};
//shape类提供处理错误的缺省实现
void Shape::error() const
{
	cout << "default code for error." << endl;
}
/*
//if draw() is a virtual function
void Shape::draw() const
{
	有怎样的缺省绘制代码？
}*/

class Rectangle: public Shape { 
public:
	virtual void error() const
	{
		cout << "code for Rectangle::error."  << endl;
	}
	virtual void draw() const
	{
		cout << "drawing rectangle." << endl;
	}
	//... 
};
class Ellipse: public Shape { 
public:
	virtual void draw() const
	{
		cout << "drawing ellipse." << endl;
	}
};


void main()
{
	Shape *ps;
	//Shape s;
	Rectangle r;
	ps = &r;
	ps->draw();
	ps = new Ellipse;  
	ps->draw();

}