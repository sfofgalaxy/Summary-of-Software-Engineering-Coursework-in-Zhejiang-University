#include "Heterogeneous linked list.h"

#include <stdio.h>
#include <stdlib.h>


void PrintNode(ptrNode list)/*˳�����ȫ���ڵ�*/
{
	if (!(list->Next))
	{
		printf("������Ϊ�գ�\n");
		system("pause");
		return;
	}
	ptrNode ptr = list->Next;
	while (ptr)
	{
		switch (ptr->type)
		{
		case INT:
			printf("%d\n", ptr->value);
			break;
		case CHAR:
			printf("%c\n", ptr->value);
			break;
		case FLOAT:
			printf("%f\n", ((struct floatnum*)(ptr->value))->value);
			break;
		case DOUBLE:
			printf("%lf\n", ((struct doublenum*)(ptr->value))->value);
			break;
		case STRUCT:
			printf("�ṹ��������Ϊ��%d\n", ((struct mystruct*)(ptr->value))->value);
		default:
			break;
		}
		ptr = ptr->Next;
	}
	system("pause");
	return;
}

ptrNode InsertHead(ptrNode list,int type)/*����ͷ�ڵ�Ĳ���*/
{
	system("cls");
	printf("���������ڵ����ݣ�\n");
	ptrNode headnode = (ptrNode)malloc(sizeof(struct NODE));
	headnode->Next = list->Next;
	list->Next = headnode;
	headnode->type = type;
	switch (type)
	{
	case INT:
		scanf("%d",&(headnode->value));
		break;
	case CHAR:
		getchar();
		scanf("%c", &(headnode->value));
		break;
	case FLOAT:
		headnode->value = (struct floatnum*)malloc(sizeof(struct floatnum));
		scanf("%f", &((struct floatnum*)(headnode->value))->value);
		break;
	case DOUBLE:
		headnode->value = (struct doublenum*)malloc(sizeof(struct doublenum));
		scanf("%lf", &((struct doublenum*)(headnode->value))->value);
		break;
	case STRUCT:
		headnode->value = (struct mystruct*)malloc(sizeof(struct mystruct));
		scanf("%d", &((struct mystruct*)(headnode->value))->value);
		break;
	default:
		break;
	}
	return list;
}

ptrNode	InsertTail(ptrNode list, int type)/*����β�ڵ�Ĳ���*/
{
	system("cls");
	printf("���������ڵ����ݣ�\n");
	ptrNode tailnode = (ptrNode)malloc(sizeof(struct NODE));
	ptrNode ptr = list;
	while (ptr->Next)
	{
		ptr = ptr->Next;
	}
	tailnode->Next = NULL;
	ptr->Next = tailnode;
	tailnode->type = type;
	switch (type)
	{
	case INT:
		scanf("%d", &(tailnode->value));
		break;
	case CHAR:
		getchar();
		scanf("%c", &(tailnode->value));
		break;
	case FLOAT:
		tailnode->value = (struct floatnum*)malloc(sizeof(struct floatnum));
		scanf("%f", &((struct floatnum*)(tailnode->value))->value);
		break;
	case DOUBLE:
		tailnode->value = (struct doublenum*)malloc(sizeof(struct doublenum));
		scanf("%lf", &((struct doublenum*)(tailnode->value))->value);
		break;
	case STRUCT:
		tailnode->value = (struct mystruct*)malloc(sizeof(struct mystruct));
		scanf("%d", &((struct mystruct*)(tailnode->value))->value);
		break;
	default:
		break;
	}
	return list;
}

ptrNode DeleteHead(ptrNode list)/*����ͷ�ڵ��ɾ��*/
{
	ptrNode ptr = list;
	if (!(ptr->Next))printf("������Ϊ�գ�\n");
	else
	{
		list->Next = ptr->Next->Next;
	}
	return list;
}

ptrNode DeleteTail(ptrNode list)/*����β�ڵ��ɾ��*/
{
	ptrNode ptr = list;
	if (!(ptr->Next))printf("������Ϊ�գ�\n");
	else
	{
		while (ptr->Next->Next)
		{
			ptr = ptr->Next;
		}
		ptr->Next = NULL;
	}
	return list;
}


ptrNode Reverse(ptrNode list)/*����ĵ���*/
{
	if (!(list->Next))return list;
	ptrNode ptr = list->Next, ptrlast = list, ptrnext = list->Next->Next;
	while (ptrnext)
	{
		ptr->Next = ptrlast;
		ptrlast = ptr;
		ptr = ptrnext;
		ptrnext = ptrnext->Next;
	}
	ptr->Next = ptrlast;
	list->Next->Next = NULL;
	list->Next = ptr;
	return list;
}

void Clear(ptrNode list)/*���������*/
{
	ptrNode ptr = list;
	list->Next = NULL;
	return;
}

ptrNode	Merge(ptrNode list1, ptrNode list2)/*����ĺϲ�(list1 + list2)*/
{
	ptrNode ptr = list1;
	while (ptr->Next)
	{
		ptr = ptr->Next;
	}
	ptr->Next = list2->Next;
	return list1;
}
