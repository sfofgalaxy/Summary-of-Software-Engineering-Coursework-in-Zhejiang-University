#include "student.h"
#include <iostream>

int main()
{
	Student zhangsan("����", 22, "��");
	Student lisi("����", 21, "Ů");
	Student wangwu("����", 22, "��");

	//std::cout << Student::classFee ;
	std::cout << zhangsan.getClassFee();
	std::cout << Student::getClassFee();  
	return 0;
}