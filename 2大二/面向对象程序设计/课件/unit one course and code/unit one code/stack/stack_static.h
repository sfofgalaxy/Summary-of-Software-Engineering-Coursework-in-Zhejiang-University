/*
#include <iostream>
using namespace std;

#define max_size 100

static char v[max_size];	//��̬ȫ�ֱ������������ʾջ��
static char *p=v;		   //ջ��ָʾ

void push(char);   //ѹջ����	��������
char pop();		   //��ջ����

void push(char ch)
{
	if(p-v>=max_size){
		cout<<"���磡"<<endl;
		exit(1);
	}
	*p++=ch;
}

char pop()
{
	if(p==v){
		cout<<"���磡"<<endl;
		exit(1);
	}
	return *--p;
}
*/