#include <iostream>
using namespace std;

/*����������ȫ�ֱ�����ʹȫ�ֱ���ģ��˽�л�*/
static double classFee = 0.0; //���

void set(double money)
{
	classFee += money;
}

double get()
{
	return classFee;
}

void oneFun()
{
	static int count = 0;
	count++;
	std:: cout << "The " << count << "'the times call me." << std::endl;
}