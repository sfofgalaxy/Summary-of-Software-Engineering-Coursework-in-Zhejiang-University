#include <iostream>
using namespace std;
#define max_size 100

/*数据与操作他们的操作放在一起*/
struct Gun{
	char v[max_size];//用数组表示弹匣 Data member
    char *p;  
	void push(char ch);	//member function 
    char pop();
};
void Gun::push(char ch)	//member function 
{
	if(p-v>=max_size){
		cout<<"弹匣已满！"<<endl;
		exit(1);
	}
	*p++=ch;//*与++优先级相同，右结合
}
char Gun::pop()
{
	if(p==v){
		cout<<"已经没有子弹！"<<endl;
		exit(1);
	}
	return *--p;
}

void main()
{   
	struct Gun myGun;  //myGun对象，既有数据也有操作代码
	myGun.p = myGun.v;  //初始化
    myGun.push('1');//通过对象调用成员函数
	myGun.push('2');

	struct Gun herGun; //herGun对象，有自己的数据，共享struct Gun的成员函数代码
	//忘记初始化？
    herGun.push('a');
	herGun.push('b');
	/*but
	1:对象数据没有初始化
	2:对象数据缺少保护
	*myGun.p++ = '3';
	*/
}


