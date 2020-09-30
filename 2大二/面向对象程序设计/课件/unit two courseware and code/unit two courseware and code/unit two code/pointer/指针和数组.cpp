#include <iostream>

int main()
{	
	int k = 0;
	int x[10];  
	int j = 0 ;
    int i;
	//用下表遍历数组，下标不要越界
	for (i = 0; i < 10; i++ )  //<=10,运行观察j的值
	{
		x[i] = 1 ; //x[10] <==> *(x+10)
	}
	//用指针遍历数组，小心使用数组最后一个元素的地址
    int* p;
	const int* const pend = x + 9;   //小心使用x+10
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

/*第二个参数是必须的。指向数组的指针不会保留数组边界
地址传递*/
void sort(int a[], int size)	
{
	std::cout << sizeof(a)/sizeof(a[0]) << std::endl;
	//a不是真正的数组名，而是整数指针,等价于int *a
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