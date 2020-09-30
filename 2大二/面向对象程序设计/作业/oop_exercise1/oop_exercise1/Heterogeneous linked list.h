#ifndef HETEROGENEOUS_LINKED_LIST_H_
#define	HETEROGENEOUS_LINKED_LIST_H_

enum TYPE/*异质链表类型的定义*/
{
	INT, CHAR, FLOAT, DOUBLE, STRUCT
};

struct NODE/*异质链表节点的定义*/
{
	void* value;
	int type;
	struct NODE* Next;
};
typedef struct NODE* ptrNode;

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

#endif /*HETEROGENEOUS_LINKED_LIST_H_*/
