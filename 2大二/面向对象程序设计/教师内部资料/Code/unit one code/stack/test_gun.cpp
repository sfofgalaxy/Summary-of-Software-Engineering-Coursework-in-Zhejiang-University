#include <iostream>
using namespace std;

extern void push(char);//ȫ�ֺ�����������ȫ�ֵ�
extern char pop();
//extern void fun();

void main()
{
	push('a');
	push('b');
	char ch1 = pop();
	cout << ch1 << endl;
	push('c');
	//fun();
    getchar();
}



