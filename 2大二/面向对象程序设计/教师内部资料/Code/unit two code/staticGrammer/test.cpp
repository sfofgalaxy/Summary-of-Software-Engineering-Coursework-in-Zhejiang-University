#include "point.h"
#include <iostream>
using namespace std;
 
static point m(0, 0);  //��̬ȫ�ֶ��󣬹۲�m��pointer::counter�ĵ�ַ

void g_f()
{
	static point n(1000,1000);  //��̬�ֲ�����
}

int main()
{
	void g_f();
	point a(2,3);
	point b(40,50);
	point *p = new point(3,5);
	cout << point::pointexisted() << endl;  //be equal to: 
	//cout << a.pointexisted() << endl;
	g_f();
	cout << point::pointexisted() << endl;
	g_f();
	cout << point::pointexisted() << endl;	
    delete p;
	return 0;
}


