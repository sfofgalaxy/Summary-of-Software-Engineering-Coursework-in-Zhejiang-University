#include "student.h"
#include <iostream>
using namespace std;

int main()
{
	//����ĳ�ʼ��
	Student zhangsan("����",22,"��");
	cout << zhangsan.get_name() << endl;
	zhangsan.print();

    Student lisi("����",20,"Ů");
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
	//ͬһ���ڴ棬�ͷ�����,��(��������)
	char *p = (char *)malloc(10);
	free(p);
	free(p);
	*/

	system("pause");
	return 0;
}