#include <iostream>
#include "gunClass.h"
using namespace std;

void Gun::push(char ch)	//member function 
{
	if(p-v>=max_size){
		cout<<"弹匣已满！"<<endl;
		exit(1);
	}
	*p++=ch;//*与++优先级相同，右结合
}
char Gun::pop()
{
	if(p==v){
		cout<<"已经没有子弹！"<<endl;
		exit(1);
	}
	return *--p;
}