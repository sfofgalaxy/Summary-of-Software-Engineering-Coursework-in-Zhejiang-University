#include "student.h"
#include <iostream>
using namespace std;

int main()
{
	//对象的初始化
	Student zhangsan("张三",22,"男");
	cout << zhangsan.get_name() << endl;
	zhangsan.print();

    Student lisi("李四",20,"女");
	lisi.print();
	
	//Student m;   //Student() 
	//cin >> m;
	/*
	free(zhangsan.name);
	zhangsan.destroy();
	lisi.destroy();
	m.destroy();
	*/
	/*
	//同一块内存，释放两次,错(调试运行)
	char *p = (char *)malloc(10);
	free(p);
	free(p);
	*/

	system("pause");
	return 0;
}