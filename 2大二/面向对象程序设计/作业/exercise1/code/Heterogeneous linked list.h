#ifndef HETEROGENEOUS_LINKED_LIST_H_
#define	HETEROGENEOUS_LINKED_LIST_H_

#include "Heterogeneous linked list.c"
enum TYPE/*异质链表类型的定义*/
{
	INT, CHAR, FLOAT, DOUBLE, STRUCT
};

typedef struct NODE* ptrNode;
struct NODE/*异质链表节点的定义*/
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

void PrintNode(ptrNode list);/*顺序输出全部节点*/
ptrNode InsertHead(ptrNode list,int type);/*链表头节点的插入*/
ptrNode	InsertTail(ptrNode list, int type);/*链表尾节点的插入*/
ptrNode DeleteHead(ptrNode list);/*链表头节点的删除*/
ptrNode DeleteTail(ptrNode list);/*链表尾节点的删除*/
ptrNode Reverse(ptrNode list);/*链表的倒置*/
void Clear(ptrNode list);/*链表的销毁*/
ptrNode	Merge(ptrNode list1, ptrNode list2);/*链表的合并(list1 + list2)*/

#endif /*HETEROGENEOUS_LINKED_LIST_H_*/
