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
	}//缺省构造函数
	
	Big(const Big& b)//拷贝构造函数
	{
		i = b.i;
		d = b.d;
		::strcpy(buf,b.buf);
		cout << "I am an object of Big,i am in Big(const Big& )" << endl;
	}
	~Big()
	{
		cout << "I am in ~Big()" << endl;
	}
   
};

Big& fun(Big& temp) {  //实参对象就是形参对象
  temp.i = 3; // Do something to the argument 
  temp.d = 3.3;
  ::strcpy(temp.buf,"I am temp!");
  return temp;//函数返回对象temp本身
}

int main() 
{
	Big b1, b2;
	b1.i = 1;
	b1.d = 1.1;
	::strcpy(b1.buf,"I am b1!");
	b2.i = 2;
	b2.d = 2.2;
	::strcpy(b2.buf,"I am b2!");

    b2 = fun(b1);
   return 0;
}

