#include <iostream>
#include "inline.h"

int main()
{
     int i = 2;
	
	 for (i = 1; i <= 1000000; i++)
        int j = power(i++);

     std::cout << i << std::endl;
     return 0;
 }

/*
#include <iostream>

inline float power(int x);//inline不起作用，当作普通函数使用

int main()
{
     int i=2;
	 //输出当前时间
	 for(int k=0; k <= 10000; k++){
		int j = power(i++);
		std::cout << i << endl << j << std::endl;
	 }
	 //输出当前时间
     return 0;
 }

inline float power(int x)  //放在main之前
{       
	return x * x; 
}
*/