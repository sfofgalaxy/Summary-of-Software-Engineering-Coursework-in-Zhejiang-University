//�汾1
#include <iostream>
using namespace std;
                    
void swap(int x, int y)	//sizeof(int)*3 bytes�洢�ռ�							   
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

    swap(x, y);		  //ֵ���ݣ����򴫵�  

    cout << "x=" << x << "   y=" << y << endl;
}  



//�汾2
#include <iostream>
using namespace std;

void swap(int *a, int *b)	//sizeof(int)*3 bytes�洢�ռ�						 
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

    swap(&x, &y);  // ��ַ���ݣ�˫�򴫵�

    cout << "x=" << x << "   y=" << y << endl;

}
/*
����ʹ��ָ����ʵ��˫�򴫵ݣ�
���ڳ�����ʹ�������*��&�������Ķ���
*/

//�汾3
#include <iostream>
using namespace std;
void swap(int &a, int &b)//sizeof(int)*1 bytes�洢�ռ�							
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
    swap(x, y);   //���ô��ݣ�˫�򴫵�   
 
	cout << "x=" << x << "   y=" << y << endl;
}



//���ò�����������һ������ö�����������в�ͬ�ĵط���
//�����ò������������������ı�ʶ������������Ķ����ӳ���ϵ���ڳ�������ʱ��̬��ȷ����
int i;
int& j;   //��
j = i;
//һ������ö�����������У����������ö����ӳ���ϵ�Ǿ�ֹ�ġ�
//���ò���ͨ��������Ҫ���������ݴ��Ͷ���ĳ��ϣ����磺���顢��¼������ȡ�


