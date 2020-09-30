#ifndef HETEROGENEOUS_LINKED_LIST_H_
#define	HETEROGENEOUS_LINKED_LIST_H_

#include "Heterogeneous linked list.c"
enum TYPE/*�����������͵Ķ���*/
{
	INT, CHAR, FLOAT, DOUBLE, STRUCT
};

typedef struct NODE* ptrNode;
struct NODE/*��������ڵ�Ķ���*/
{
	void* value;
	int type;
	struct NODE* Next;
};


struct doublenum
{
	double value;
};

struct floatnum
{
	float value;
};

struct mystruct
{
	
	int value;
	/*
	-------------
	-------------
	-------------
	*/
};

void PrintNode(ptrNode list);/*˳�����ȫ���ڵ�*/
ptrNode InsertHead(ptrNode list,int type);/*����ͷ�ڵ�Ĳ���*/
ptrNode	InsertTail(ptrNode list, int type);/*����β�ڵ�Ĳ���*/
ptrNode DeleteHead(ptrNode list);/*����ͷ�ڵ��ɾ��*/
ptrNode DeleteTail(ptrNode list);/*����β�ڵ��ɾ��*/
ptrNode Reverse(ptrNode list);/*����ĵ���*/
void Clear(ptrNode list);/*���������*/
ptrNode	Merge(ptrNode list1, ptrNode list2);/*����ĺϲ�(list1 + list2)*/

#endif /*HETEROGENEOUS_LINKED_LIST_H_*/
