#include <iostream>
using namespace std;

struct example{
	int a;
	double b;
	//example(int a=0,double b=0.0):a(a),b(b){}
}ex,*pe;

void main()
{

//关于对象的类型转换:C风格的类型转换过于粗鲁,在程序语句中难以识别, 
//但你无能为力，因为它是C语言的内部机制。
   char ch;
   int i = 65;
   float f = float(2.5);  //explicit type conversion 收缩转换
   double db ;
 
   ch = i;//收缩转换  implicit type conversion 
   db = f;//扩大转换
   ch = char(db); //explicit type conversion 收缩转换
 
//C++中提倡的写法：目的是这样的类型转换不论是对人工还是对程序都很容易识别
 
   ch = static_cast<char>(i);         // int to char
   db = static_cast<double>(f);         // float to double
   f = static_cast<float>(db);          //double to float
   ch = static_cast<char>(db);

   //int *pi = (int*)i;
   //int *pi = static_cast<int*>(i);//compile-time error！因为C中不存在这样的隐式转换
    
	//enum E { first=1, second=2, third=3 };
	//int ii = second; // 隐式转换
	//E e = ii;
	//ii = 4;
	//E e = static_cast<E>(ii); // 反向隐式转换 value of e is second
	
    //reinterpret_cast
	//int *pi = (int*)i;
    //int *pi = reinterpret_cast<int*>(i);
    //int j = reinterpret_cast<int>(pi);
	
	//ex = i; //error! example与int不相容,除非提供相应的构造函数
   //ex = example(i);//不相容类型对象强制转化也不行
  

//关于对象指针的类型转换
/*
	int in = 3;
	int* p_int;
	double du = 3.3;
	double* p_double;
	example* pe;

	p_double = &du;
	p_int = &in;
*/
//	p_int = p_double; //编译错误，指针类型不一样的指针不能隐含转换
//	p_double = p_int;
 //   p_int = pe;
//或pe = p_int;
/* C Style
	p_int = (int*)p_double;
	pe = (example*)p_int;//任何类型的指针之间都可以相互强制类型转换,编译通过 
	pe->a; //编译通过，按照pe的静态类型去访问
	pe->b; //内存错误
	cout<<"int="<<sizeof(int)<<"	double="<<sizeof(double)<<"		example="<<sizeof(example)<<endl;
	cout<<pe->a<<endl;
	cout<<pe->b<<endl;
*/
/*C++ Style
    pe = static_cast<example*>(p_int); //编译错误
    p_int = static_cast<int*>(pe);
	int *q1 = new int(1);
	double* q2 = new double(1.1);
	q2 = static_cast<int*>(q1);
*/
}
