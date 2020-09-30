/*
#include <iostream>
using namespace std;

#define max_size 100

static char v[max_size];	//静态全局变量，用数组表示栈体
static char *p=v;		   //栈高指示

void push(char);   //压栈操作	函数声明
char pop();		   //出栈操作

void push(char ch)
{
	if(p-v>=max_size){
		cout<<"上溢！"<<endl;
		exit(1);
	}
	*p++=ch;
}

char pop()
{
	if(p==v){
		cout<<"下溢！"<<endl;
		exit(1);
	}
	return *--p;
}
*/