#include <iostream>
#include <string>
using namespace std;

struct A{  //sizeof(A)  8
	char ch;
	int i;
	void  display() const
	{
		cout << ch << "\t" << i << endl;
	}
};

struct B{
	int i;  //sizeof(B)  8
	char ch;
	void display() const
	{
		cout << i << "\t" << ch << endl;
	}
};

void main()
{ 
	//ͨ��������ֱ�ӷ���
	A a;
	a.ch = 'a';
	a.i = 11;
	a.display();
	B b;
	b.ch = 'a';
	b.i = 11;
	b.display();

	//ͨ������ָ���ӷ���
	A *pa = &a;
	pa->display();
	B * pb = &b;
	pb->display();

	//����ͬ����ָ�벻����ֱ�Ӹ�ֵ
    pa = &b;  //or pb = pa;

  	//�κ�����ָ�붼����ǿ������ת��
	//pa = (A*)pb;  //����ͨ�����������
	//pa->display();  //A::display()
	//pa = static_cast<A*>(pb);  //compile-time error
}