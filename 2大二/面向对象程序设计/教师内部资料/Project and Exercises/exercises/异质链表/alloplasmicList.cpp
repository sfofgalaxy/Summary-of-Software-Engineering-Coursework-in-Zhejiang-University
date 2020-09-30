/*
次序如下：C库、C++库、其他库的.h文件、项目内的.h文件。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "alloplasmicList.h"


PNODE createNode(int n)   
{   
    PNODE pHead, //首节点指针   
          pRear, //尾节点指针   
          pNew; //新节点指针   
    int i;   
 
    for (i=0; i<n; i++)   
    {   
        pNew = (PNODE)malloc(sizeof(Node));   
        printf("\n请输入第%d个节点的类型(INT:0, DOUBLE:1, FLOAT:2, CHAR:3)：",i+1);
		scanf("%d", &pNew->type);
		switch(pNew->type)
		{
			case INT:
				pNew->data = (int*)malloc(sizeof(int));
	 			printf("请输入第%d个节点的数据: ",i+1);
				scanf("%d", pNew->data);
				break;
			case DOUBLE:
				pNew->data = (double*)malloc(sizeof(double));
	 			printf("请输入第%d个节点的数据: ",i+1);
				scanf("%lf", pNew->data);
				break;
			case FLOAT:
				pNew->data = (float*)malloc(sizeof(float));
	 			printf("请输入第%d个节点的数据: ",i+1);
				scanf("%f", pNew->data);
				break;
			case CHAR:
				pNew->data = (char*)malloc(1);
	 			printf("请输入第%d个节点的数据: ",i+1);
				getchar();
				scanf("%c", pNew->data);
				break;   
        }  
          
		if (i==0)   
        {   
            pRear = pHead = pNew;   
        }   
        else   
        {   
            pRear->next = pNew;   
        }   
        pNew->next = NULL;   
        pRear = pNew;   
    }   
     
    return pHead;   
}

void print(PNODE pHead)
{
	PNODE p;
	p = pHead;
	if (pHead != NULL) /*只要不是空链表，就输出链表中所有节点 */
	{
		do{
			switch(p->type)
			{
			case INT:
				printf ("整数：%d\t", *(int*)(p->data));
			    break;
		    case DOUBLE:
   			    printf ("双精度数：%lf\t", *(double*)(p->data));
			    break;
		    case FLOAT:
			    printf ("单精度数：%f\t", *(float*)(p->data));
			    break;
		    case CHAR:
			    printf ("字符：%c\t", *(char*)(p->data));
			    break;\
			}
			p = p->next; //移到下一个节点
		}while (p != NULL);
	}
	printf("\n");
}

void destory(PNODE pHead)
{
	PNODE temp, p;

	for (p=pHead; p!=NULL; )
	{
		temp = p;
		p = p->next;
		free(temp->data);
		free(temp);
	}
}
/*
PNODE insert(PNODE pHead, TYPE type, int data)
{
	PNODE pTemp = (PNODE)malloc(sizeof(Node));
	pTemp->type = type;
	pTemp->data = (int*)malloc(sizeof(int));
	*(int*)pTemp->data = data;
	pTemp->next = NULL;

	if(pHead){//链表非空
		pTemp->next = pHead;
		pHead = pTemp;
	}
	else {
		pTemp->next = pHead;
	}

	return pHead;
}*/

PNODE insert(PNODE &pHead, TYPE type, int data)
{
	PNODE pTemp = (PNODE)malloc(sizeof(Node));
	pTemp->type = type;
	pTemp->data = (int*)malloc(sizeof(int));
	*(int*)pTemp->data = data;
	pTemp->next = NULL;

	if(pHead){//链表非空
		pTemp->next = pHead;
		pHead = pTemp;
	}
	else {
		pTemp->next = pHead;
	}

	return pHead;
}

PNODE insert(PNODE &pHead, TYPE type, double data)
{
	PNODE pTemp = (PNODE)malloc(sizeof(Node));
	pTemp->type = type;
	pTemp->data = (double*)malloc(sizeof(double));
	*(double*)pTemp->data = data;
	pTemp->next = NULL;

	if(pHead){//链表非空
		pTemp->next = pHead;
		pHead = pTemp;
	}
	else {
		pTemp->next = pHead;
	}

	return pHead;
}

PNODE insert(PNODE &pHead, TYPE type, float data)
{
	PNODE pTemp = (PNODE)malloc(sizeof(Node));
	pTemp->type = type;
	pTemp->data = (float*)malloc(sizeof(float));
	*(float*)pTemp->data = data;
	pTemp->next = NULL;

	if(pHead){//链表非空
		pTemp->next = pHead;
		pHead = pTemp;
	}
	else {
		pTemp->next = pHead;
	}

	return pHead;
}

PNODE insert(PNODE &pHead, TYPE type, char data)
{
	PNODE pTemp = (PNODE)malloc(sizeof(Node));
	pTemp->type = type;
	pTemp->data = (char*)malloc(sizeof(char));
	*(char*)pTemp->data = data;
	pTemp->next = NULL;

	if(pHead){//链表非空
		pTemp->next = pHead;
		pHead = pTemp;
	}
	else {
		pTemp->next = pHead;
	}

	return pHead;
}