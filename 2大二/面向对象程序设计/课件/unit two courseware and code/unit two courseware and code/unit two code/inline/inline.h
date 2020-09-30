//#define power(X)  (X)*(X) 
inline float power(int x)//加上关键字inline，成为内联函数
{     
	return x*x; 
}
/*
inline 是一种“用于实现的关键字”，而不仅是一种“用于声明的关键字”。
尽管在大多数教科书中内联函数的声明、定义体前面都加了inline 关键字，
但我认为inline 不应该出现在函数的声明中。这个细节虽然不会影响函数的功能，
但是体现了高质量C++/C 程序设计风格的一个基本原则：声明与定义不可混为一谈，
用户没有必要、也不应该知道函数是否需要内联。
*/

template<typename T>  
inline type compare(T a,T b)  
{  
	return (a>b) ? a : b;  
}  
