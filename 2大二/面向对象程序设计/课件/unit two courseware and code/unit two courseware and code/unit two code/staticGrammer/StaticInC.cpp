#include <iostream>
using namespace std;

/*尽可能少用全局变量，使全局变量模块私有化*/
static double classFee = 0.0; //班费

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