//�麯���Ķ���
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
	virtual void draw() const = 0;   //pure virtual function,��������������ͬ��������������������Լ���ʵ�֣�ֻ�̳нӿڣ���
    //...
	virtual ~Shape()
	{}
};
//shape���ṩ��������ȱʡʵ��
void Shape::error() const
{
	cout << "default code for error." << endl;
}
/*
//if draw() is a virtual function
void Shape::draw() const
{
	��������ȱʡ���ƴ��룿
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