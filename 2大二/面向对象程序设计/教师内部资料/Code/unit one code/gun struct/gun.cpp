#include <iostream>
#include "gunClass.h"
using namespace std;

void Gun::push(char ch)	//member function 
{
	if(p-v>=max_size){
		cout<<"��ϻ������"<<endl;
		exit(1);
	}
	*p++=ch;//*��++���ȼ���ͬ���ҽ��
}
char Gun::pop()
{
	if(p==v){
		cout<<"�Ѿ�û���ӵ���"<<endl;
		exit(1);
	}
	return *--p;
}