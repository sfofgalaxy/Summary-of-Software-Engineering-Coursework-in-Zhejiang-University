/* *
 * @copyright 2012-2013, Zhejiang University
 * @file   gun.cpp
 * @brief  ʵ���ӵ�ѹ�ź��������
 *
 * �汾��ʷ��   
 * @Verson  0.1 @date 2011-02-17   hlq���½��ļ�
 * @Verson  0.2 @date 2012-08-11   hlq���޸���......
 *     
*/
#include <iostream>
using namespace std;

#define max_size 100  //��ϻ����
char v[max_size];	//ȫ�ֱ������������ʾ��ϻ�����ַ���ʾ�ӵ�
char *p = v;		   //��ϻ����

/**
* @brief   ���� : �ӵ�ѹ�� 
* @param [in]  �������ch :  char��ʾ�ӵ�
* @return      void
* @exception   �����ϻ������������ֹ���С�
*/
void push(char ch)	//function define
{
	if (p-v >= max_size)
	{
		cout << "��ϻ������" << endl;
		exit(1);
	}
	*p++ = ch;//*��++���ȼ���ͬ���ҽ��
}

/**
* @brief   ���� : ������� 
* @return      ����ֵ�ַ���
* @exception   �����ϻΪ�գ��������ֹ����
*/
char pop()
{
	if (p == v)
	{
		cout << "�Ѿ�û���ӵ���" << endl;
		exit(1);
	}
	return *--p;
}