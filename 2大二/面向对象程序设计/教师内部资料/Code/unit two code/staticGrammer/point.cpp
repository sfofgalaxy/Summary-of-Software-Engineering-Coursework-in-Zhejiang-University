#include "point.h"

//通常在类的cpp文件开始处初始化该类的静态数据成员。
int point::counter=0; //等价于int point::counter;
//point::counter;  //compile-time error

int point::pointexisted()  //没有this指针
{
	//f();//be equal to this->f(); compile-time error,没有this指针,不可以访问类point的成员
	return counter;// 可以访问类point的static成员
}
