#include "point.h"

//ͨ�������cpp�ļ���ʼ����ʼ������ľ�̬���ݳ�Ա��
int point::counter=0; //�ȼ���int point::counter;
//point::counter;  //compile-time error

int point::pointexisted()  //û��thisָ��
{
	//f();//be equal to this->f(); compile-time error,û��thisָ��,�����Է�����point�ĳ�Ա
	return counter;// ���Է�����point��static��Ա
}
