#include <iostream>
using namespace std;

class B {
  int i;
public:
  B(int ii = 0) : i(ii) {}//��int����ת����B����
  
};

class A{
  int x;
public:
  A(int xx) : x(xx) 	//��int����ת����A����
  {} 
  operator B() const// ��A����ת����B���ͣ����Զ�ִ��
  { 
	  return B(x); //����һ��B����
  }

};

void g(B b) {}

void main() {
  A a(1);
  g(a);  //Calls g(operator B())
  g(1);  // Calls g( A(1) )
} ///:~









