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

inline float power(int x);//inline�������ã�������ͨ����ʹ��

int main()
{
     int i=2;
	 //�����ǰʱ��
	 for(int k=0; k <= 10000; k++){
		int j = power(i++);
		std::cout << i << endl << j << std::endl;
	 }
	 //�����ǰʱ��
     return 0;
 }

inline float power(int x)  //����main֮ǰ
{       
	return x * x; 
}
*/