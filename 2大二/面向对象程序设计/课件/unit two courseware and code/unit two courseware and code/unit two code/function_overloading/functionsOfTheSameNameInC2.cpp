//functions Of The Same Name in C++：
#include <iostream>
using namespace std;

int Max(int x, int y);
int Max(long int x, long int y);
int Max(short int x, short int y); 
float Max(float x, float y);
int Max(int x, int y, int z);
float Max(float x[], int size);	

int main()  
{
	cout << Max(5, 4) << endl;//int	
	cout << Max((short)5, (short)4) << endl;	
	cout << Max((long)5, (long)4) << endl;	

	//cout << Max(5.1, 4.1) << endl; //5.1 is a const double

	cout << Max((int)5.1, 4.1) << endl;

	cout << Max(1, 2, 3)<<endl;

	cout << Max(1.1, 2.0, 3.0)<<endl;//把double转换成int

	cout << Max(5.1, 4) << endl;	//标准转换

	float a[10];
	for(int i=0 ; i<10; i++)
		a[i] = (float)i;
	cout << Max(a, 10) << endl;
	return 0;
}

int Max(int x, int y) 
{
	return (x>y?x:y);
}

int Max(long int x, long int y) 
{
	return (x>y?x:y);
}

int Max(short int x, short int y) 
{
	return (x>y?x:y);
}

float Max(float x, float y)
{
	return (x>y?x:y);
}

int Max(int x, int y, int z)	
{
	int Max = x;
	if( y > Max)
		Max = y;
	if( z > Max)
		Max = z;
	return Max;
}

float Max(float x[], int size)	
{
	float Max = x[0];
	for(int i = 0 ; i< size ; i++)
		if(x[i] > Max)
			Max = x[i];
	return Max;
}	

/*
int Max(const int x, const int y) 
{
	return (x>y?x:y);
}*/

/*
编译时，根据这些函数的参数个数、参数类型来区分（束定/绑定binding)。
*/

