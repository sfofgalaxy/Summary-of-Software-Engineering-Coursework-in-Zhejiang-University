#ifndef FUNCTION_TEMPLATE
#define FUNCTION_TEMPLATE

//function template prototype
template <typename T> T sum(T *array,int size);
template <typename T> T sum(T *array1,T *array2,int size);

//function template definition
template <typename T> 
T sum(T array[],int size)
{
	T total = 0;

	for (int i=0;i<size;i++)
		total = total + array[i];  //*(array+i)
	
	return total;
}

template <typename T> 
T sum(T *array1,T* array2,int size)//function template overloading
{
	T total = 0;

	for (int i=0;i<size;i++)
		total = total + array1[i] + array2[i];

	return total;
}

template <typename T> 
void sort(T a[],int size)//或T* 
{
	int index,k,i;
	T temp;
    for(k = 0; k < size-1; k++){   
        index = k;
        for(i = k + 1; i < size; i++) { 
            if(a[i] < a[index])  index = i;
		}
        temp = a[index]; 
        a[index] = a[k]; 
        a[k] = temp;
	}
}  

template <typename T> 
inline T Max(T x,T y)
{
	cout << "In template function Max, ";
	return (x>y)?x:y;
}

inline int Max(char x,int y)
{
	cout << "In function Max(char x,int y), ";
   return (x>y)?x:y;
}

inline int Max(int x, int y)
{
	cout << "In function Max(int x, int y), ";
	return (x>y)?x:y;
}

#endif

/*
函数模版的声明与定义或在头文件中，如：
f_head.h


a.cpp
函数模版声明
函数模版定义
函数模版使用

*/








