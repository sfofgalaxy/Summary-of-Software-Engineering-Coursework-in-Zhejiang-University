#include <iostream>
using namespace std;
#define max_size 100

/*������������ǵĲ�������һ��*/
struct Gun{
	char v[max_size];//�������ʾ��ϻ Data member
    char *p;  
	void push(char ch);	//member function 
    char pop();
};
void Gun::push(char ch)	//member function 
{
	if(p-v>=max_size){
		cout<<"��ϻ������"<<endl;
		exit(1);
	}
	*p++=ch;//*��++���ȼ���ͬ���ҽ��
}
char Gun::pop()
{
	if(p==v){
		cout<<"�Ѿ�û���ӵ���"<<endl;
		exit(1);
	}
	return *--p;
}

void main()
{   
	struct Gun myGun;  //myGun���󣬼�������Ҳ�в�������
	myGun.p = myGun.v;  //��ʼ��
    myGun.push('1');//ͨ��������ó�Ա����
	myGun.push('2');

	struct Gun herGun; //herGun�������Լ������ݣ�����struct Gun�ĳ�Ա��������
	//���ǳ�ʼ����
    herGun.push('a');
	herGun.push('b');
	/*but
	1:��������û�г�ʼ��
	2:��������ȱ�ٱ���
	*myGun.p++ = '3';
	*/
}


