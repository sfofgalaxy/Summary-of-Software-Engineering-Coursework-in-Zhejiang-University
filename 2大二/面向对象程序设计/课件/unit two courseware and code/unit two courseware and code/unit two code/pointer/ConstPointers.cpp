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
	const int* pointer_to_const;  //常量指针pointer_to_const is a pointer, which points to a const int
	
	//int const* pointer_to_const;	//与上述等价
	
	pointer = &d;//ok
    *pointer = *pointer+1;//d=d+1;

	//pointer = &e;//not ok,you can’t assign the address of a const object to a non-const pointer because then you’re saying you might change the object via the pointer. 
    //*pointer=1;
	// 
	pointer = (int*)&e;//ok,程序员自己打破由const提供的安全机制，编译器就无能为力！
    *pointer = 1;
	std::cout << e << std::endl;  //显示-1,why? e is a compile-time constant

	pointer_to_const = &e;
	d = *pointer_to_const+1;   //ok
	//*pointer_to_const = 1;//error


	pointer_to_const = &d;//ok,	You can assign the address of a non-const object to a const pointer because you’re simply promising not to change something that is OK to change.
 
	//*pointer_to_const = 99999;//not ok

	int* const const_pointer = &d;	//指针常量const_pointer is a pointer, which is const, that points to an int.  当场初始化
	//int* const const_pointer = &e;  //error
	*const_pointer = *const_pointer+1; //d=d+1
	//const_pointer = &d2; //error

	const int* const x = &e;  // (1)   const pointer points to a const object 
	//const int* const x = &d;
	int const* const x2 = &e; // (2) 与 (1)等价
	/*
     char *p = "hello";
	 *p = 'A';
	 std::cout << p << std::endl;
	 */
} 
