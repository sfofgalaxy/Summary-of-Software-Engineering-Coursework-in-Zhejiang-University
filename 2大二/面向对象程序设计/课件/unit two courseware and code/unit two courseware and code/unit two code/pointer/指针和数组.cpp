#include <iostream>

int main()
{	
	int k = 0;
	int x[10];  
	int j = 0 ;
    int i;
	//���±�������飬�±겻ҪԽ��
	for (i = 0; i < 10; i++ )  //<=10,���й۲�j��ֵ
	{
		x[i] = 1 ; //x[10] <==> *(x+10)
	}
	//��ָ��������飬С��ʹ���������һ��Ԫ�صĵ�ַ
    int* p;
	const int* const pend = x + 9;   //С��ʹ��x+10
	for ( p = x; p <= pend; ++p )   
	{
		*p = 1;
	}

   std::cout << sizeof(x)/sizeof(x[0]) << std::endl;
	
   void sort(int a[],int size); //or:void sort(int *a,int size);
   int sum(const int *a, int size);

   sort( x, 10 );
    
	for (i = 0; i < 10; i++ )
	{
		std::cout  << x[i] << '\t';
	}
	std::cout << sum(x, 10) << std::endl;
     return 0;
}

/*�ڶ��������Ǳ���ġ�ָ�������ָ�벻�ᱣ������߽�
��ַ����*/
void sort(int a[], int size)	
{
	std::cout << sizeof(a)/sizeof(a[0]) << std::endl;
	//a��������������������������ָ��,�ȼ���int *a
    int k,i;
	int index;
	int temp;

    for (k = 0; k < size-1; k++)
	{
        index = k;
        for (i = k + 1; i < size; i++)
		{
            if (a[i] < a[index])  
			{
				index = i;
			}
		}
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }

}

int sum(const int *pa, int size)	
{
	const int * const p = pa + size - 1;
	int total = 0;
    for ( ; pa <= p; pa++)
	{
       total += *pa;
    }
	return total;
}