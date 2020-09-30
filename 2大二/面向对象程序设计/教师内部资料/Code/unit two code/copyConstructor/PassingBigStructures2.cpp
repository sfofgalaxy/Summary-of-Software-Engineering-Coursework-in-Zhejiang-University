//: C11:PassingBigStructures.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
#include <string>
using namespace std;

class Big{
public:
    char buf[100];
    int i;
    double d;

	Big(){
		cout << "I am an object of Big,i am in Big()" << endl;
	}//default constructor
    
	Big(const Big& b)   //copy constructor
	{
		i = b.i;
		d = b.d;
		//buf = b.buf;
		strcpy(buf,b.buf);
		cout << "I am an object of Big,i am in Big(const Big& )" << endl;
	}

	~Big()
	{
		cout << "I am in ~Big()" << endl;
	}   
};

Big fun(Big temp) {  //ʵ�ζ��󴫵ݸ��βζ���ʱ�����ÿ�����ʼ�����캯��
  temp.i = 3; // Do something to the argument 
  temp.d = 3.3;
  strcpy(temp.buf,"I am temp!");
  return temp;//�������ض���ʱ�����ÿ������캯����ʼ��һ�����������ں������غ������������Ϊ��������ֵ
  //��������ǰ����������������temp����
}

int main() 
{
	Big b1, b2;
	b1.i = 1;
	b1.d = 1.1;
	strcpy(b1.buf,"I am b1!");
	b2.i = 2;
	b2.d = 2.2;
	strcpy(b2.buf,"I am b2!");

	Big b3(b2); // call Big(const Big& b)
	
    b2 = fun(b1);  
   //�������ص���������ֵ��b2�󣬵������������Ѹ�������������
   cout << "�˴��۲�......" << endl;  
	return 0;
}