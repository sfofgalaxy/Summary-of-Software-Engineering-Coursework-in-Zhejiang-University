#ifndef HETEROGENEOUS_LINKED_LIST_H_
#define	HETEROGENEOUS_LINKED_LIST_H_

enum TYPE/*�����������͵Ķ���*/
{
	INT, CHAR, FLOAT, DOUBLE, STRUCT
};

struct NODE/*��������ڵ�Ķ���*/
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
