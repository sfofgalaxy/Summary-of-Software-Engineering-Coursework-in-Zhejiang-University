#include <iostream>
#include "gunClass.h"
using namespace std;

void main()  //主控对象
{   
	struct Gun myGun;  //myGun对象，既有数据也有操作代码
	//myGun.p = myGun.v;
	myGun.push('1');   //main()与myGun对象通信

	struct Gun herGun; //herGun对象，有自己的数据，共享struct Gun的成员函数代码
    herGun.push('1');
}