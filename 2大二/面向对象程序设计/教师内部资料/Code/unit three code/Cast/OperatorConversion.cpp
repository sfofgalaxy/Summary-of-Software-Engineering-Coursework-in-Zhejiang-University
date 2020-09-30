#include <iostream>
using namespace std;

class B {
  int i;
public:
  B(int ii = 0) : i(ii) {}//把int类型转换成B类型
  
};

class A{
  int x;
public:
  A(int xx) : x(xx) 	//把int类型转换成A类型
  {} 
  operator B() const// 把A类型转换成B类型，且自动执行
  { 
	  return B(x); //返回一个B对象
  }

};

void g(B b) {}

void main() {
  A a(1);
  g(a);  //Calls g(operator B())
  g(1);  // Calls g( A(1) )
} ///:~









