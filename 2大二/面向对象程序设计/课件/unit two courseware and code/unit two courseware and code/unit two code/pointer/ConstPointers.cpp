//: C08:ConstPointers.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>

void main()
{
	int d = 1;
	const int e = -1;//int const e=-1;
//	d=d+1;
//	e=e-1;//error

	int* pointer;
	const int* pointer_to_const;  //����ָ��pointer_to_const is a pointer, which points to a const int
	
	//int const* pointer_to_const;	//�������ȼ�
	
	pointer = &d;//ok
    *pointer = *pointer+1;//d=d+1;

	//pointer = &e;//not ok,you can��t assign the address of a const object to a non-const pointer because then you��re saying you might change the object via the pointer. 
    //*pointer=1;
	// 
	pointer = (int*)&e;//ok,����Ա�Լ�������const�ṩ�İ�ȫ���ƣ�������������Ϊ����
    *pointer = 1;
	std::cout << e << std::endl;  //��ʾ-1,why? e is a compile-time constant

	pointer_to_const = &e;
	d = *pointer_to_const+1;   //ok
	//*pointer_to_const = 1;//error


	pointer_to_const = &d;//ok,	You can assign the address of a non-const object to a const pointer because you��re simply promising not to change something that is OK to change.
 
	//*pointer_to_const = 99999;//not ok

	int* const const_pointer = &d;	//ָ�볣��const_pointer is a pointer, which is const, that points to an int.  ������ʼ��
	//int* const const_pointer = &e;  //error
	*const_pointer = *const_pointer+1; //d=d+1
	//const_pointer = &d2; //error

	const int* const x = &e;  // (1)   const pointer points to a const object 
	//const int* const x = &d;
	int const* const x2 = &e; // (2) �� (1)�ȼ�
	/*
     char *p = "hello";
	 *p = 'A';
	 std::cout << p << std::endl;
	 */
} 
