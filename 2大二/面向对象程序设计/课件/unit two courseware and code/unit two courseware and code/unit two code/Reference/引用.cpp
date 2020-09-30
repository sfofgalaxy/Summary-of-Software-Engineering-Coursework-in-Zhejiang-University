//版本1
#include <iostream>
using namespace std;
                    
void swap(int x, int y)	//sizeof(int)*3 bytes存储空间							   
{
    int temp;
    temp = x; 
	x = y; 
	y = temp;
}

void main()
{
    int x = 10;
	int y = 20;

    swap(x, y);		  //值传递，单向传递  

    cout << "x=" << x << "   y=" << y << endl;
}  



//版本2
#include <iostream>
using namespace std;

void swap(int *a, int *b)	//sizeof(int)*3 bytes存储空间						 
{
    int temp;
    temp = *a; 
	*a = *b; 
	*b = temp;
}

void main()
{
    int x = 10;
	int y = 20;

    swap(&x, &y);  // 地址传递，双向传递

    cout << "x=" << x << "   y=" << y << endl;

}
/*
尽管使用指针能实现双向传递，
但在程序中使用运算符*、&，不易阅读。
*/

//版本3
#include <iostream>
using namespace std;
void swap(int &a, int &b)//sizeof(int)*1 bytes存储空间							
{
    int temp;
    temp = a; 
	a = b; 
	b = temp;
}
void main()
{
    int x = 10;
	int y = 20;
    swap(x, y);   //引用传递，双向传递   
 
	cout << "x=" << x << "   y=" << y << endl;
}



//引用参数的声明与一般的引用对象声明语句有不同的地方。
//在引用参数的声明中所声明的标识符与它所代表的对象的映射关系是在程序运行时动态地确定。
int i;
int& j;   //×
j = i;
//一般的引用对象声明语句中，对象与引用对象的映射关系是静止的。
//引用参数通常用在需要给函数传递大型对象的场合：比如：数组、记录、链表等。


