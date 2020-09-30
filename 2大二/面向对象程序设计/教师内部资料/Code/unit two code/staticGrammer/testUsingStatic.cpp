#include "student.h"
#include <iostream>

int main()
{
	Student zhangsan("张三", 22, "男");
	Student lisi("李四", 21, "女");
	Student wangwu("王五", 22, "男");

	//std::cout << Student::classFee ;
	std::cout << zhangsan.getClassFee();
	std::cout << Student::getClassFee();  
	return 0;
}