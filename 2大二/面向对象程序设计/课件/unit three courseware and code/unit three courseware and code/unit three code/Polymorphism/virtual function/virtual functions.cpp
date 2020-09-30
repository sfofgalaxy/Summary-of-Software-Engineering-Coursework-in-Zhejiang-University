//�麯���Ķ���
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
    virtual void error() const ;  //shape�����ṩ����ʵ��
    //...
};
/*ÿ�������඼����֧��һ���������ϴ���ʱ�ɵ��á��ĺ�����
ÿ������������ɴ���������ĳ�������಻����Դ��������κ�������Ϊ��
�������˻ص�����shape�ṩ��ȱʡ��������Ϊ��
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
	ps -> error();//dynamic binding��call Rectangle::error()

	ps = new Ellipse;
	ps->error();  //dynamic binding	call Shape::error()
		
	Shape &rs1 = *ps;//dynamic binding
	rs1.error();   //dynamic binding call Rectangle::error()
   
}