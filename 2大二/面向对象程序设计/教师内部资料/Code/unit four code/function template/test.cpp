#include <iostream>
using namespace std;
#include "function_template.h"

//ģ�庯���÷�
void main()
{
	int i = 90;
	char c = 'a';
	float f = 91.0;

	Max(i,i);  //static binding,ģ�庯���ĺ������Ԥ�������ɼ�
	Max(c,c);
	Max(f,f);
	Max(1.1, 2.2);

	Max(c,i);//�������������һ����ģ�庯������һ��ͬ����ģ�庯��
	//Max(1.1, 2);

	static int intarr1[]={1,2,3,4,5,6,7,8,9,10};
	static int intarr2[]={2,4,6,8,10,12,14,16};
	static double douarr[]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.0};
	
	int itotal1 = sum(intarr1,10);
	double dtotal = sum(douarr,10);
	int itotal2 = sum(intarr1,intarr2,8);
	sort(intarr1,10);
	cout<<itotal1<<endl;
	cout<<itotal2<<endl;
	cout<<dtotal<<endl;

}
