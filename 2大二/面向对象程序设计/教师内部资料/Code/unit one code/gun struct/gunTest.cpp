#include <iostream>
#include "gunClass.h"
using namespace std;

void main()  //���ض���
{   
	struct Gun myGun;  //myGun���󣬼�������Ҳ�в�������
	//myGun.p = myGun.v;
	myGun.push('1');   //main()��myGun����ͨ��

	struct Gun herGun; //herGun�������Լ������ݣ�����struct Gun�ĳ�Ա��������
    herGun.push('1');
}