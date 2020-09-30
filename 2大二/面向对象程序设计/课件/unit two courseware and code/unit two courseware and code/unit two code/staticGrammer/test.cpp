#include "point.h"
#include <iostream>
using namespace std;
 
static point m(0, 0);  //静态全局对象，观察m，pointer::counter的地址

void g_f()
{
	static point n(1000,1000);  //静态局部对象
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


