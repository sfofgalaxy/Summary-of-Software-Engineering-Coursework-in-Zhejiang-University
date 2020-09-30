//: C13:GlobalOperatorNew.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Overload global new/delete
#include <cstdio>
#include <cstdlib>
/*运算符new的返回值是一个void*，而不是指向任何特定类型的指针。
它所做的是分配内存，而不是完成一个对象的建立—直到构造函数调用了才完成对象的创建，
这是由编译器所确保的动作，不在我们的控制范围内。
*/
void* operator new(size_t sz) {
  printf("operator new: %d Bytes\n", sz);
  void* m = malloc(sz);
  if(!m) puts("out of memory");
  return m;
}

void operator delete(void* m) {
  puts("operator delete");
  free(m);
}

class S {
  int i[100];
public:
  S() { puts("S::S()"); }
  ~S() { puts("S::~S()"); }
};

void main() {
  puts("creating & destroying an int");
  int* p = new int(47);
  delete p;
  puts("creating & destroying an s");
  S* s = new S;
  delete s;
  puts("creating & destroying S[3]");
  S* sa = new S[3];
  delete []sa;
} ///:~

//printf( ) and puts( ) are used rather than iostreams. This is because 
//when an iostream object is created (like the global cin, cout, and cerr), 
//it calls new to allocate memory. With printf( ), you don’t get into a deadlock 
//because it doesn’t call new to initialize itself.
