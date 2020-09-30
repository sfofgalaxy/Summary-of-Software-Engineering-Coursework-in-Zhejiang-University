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

int main()
{
	ptrNode list1 = (ptrNode)malloc(sizeof(struct NODE));
	ptrNode list2 = (ptrNode)malloc(sizeof(struct NODE));
	list1->Next = list2->Next = NULL;
	int type, operation = 100, num;
	while (operation != 8)
	{
		printf("0.������нڵ�\n1.���뵽ͷ�ڵ�\n2.���뵽β��\n3.ɾ��ͷ�ڵ�\n4.ɾ��β�ڵ�");
		printf("\n5.��������\n6.��������\n7.�ϲ�����������һ��������\n8.�˳�\n");
		scanf("%d", &operation);
		system("cls");
		if (operation <= 6)
		{
			printf("��������Ҫ�����������ţ�1��2��\n");
			scanf("%d", &num);
			system("cls");
		}
		switch (operation)
		{
		case 0:
			if (num == 1)PrintNode(list1);
			else PrintNode(list2);
			break;
		case 1:
		case 2:
			printf("��ѡ���������ͣ�\n0.��������\n1.�����ַ���\n");
			printf("2.���뵥���ȸ�����\n3.����˫���ȸ���\n4.����ṹ����\n5.������һ��\n");
			scanf("%d", &type);
			if (operation == 1 && num == 1)InsertHead(list1, type);
			else if (operation == 1 && num == 2)InsertHead(list2, type);
			else if (operation == 2 && num == 1)InsertTail(list1, type);
			else if (operation == 2 && num == 2)InsertTail(list2, type);
			break;
		case 3:
			if (num == 1)DeleteHead(list1, type);
			else DeleteHead(list2, type);
			break;
		case 4:
			if (num == 1)DeleteTail(list1, type);
			else DeleteTail(list2, type);
			break;
		case 5:
			if (num == 1)Clear(list1);
			else Clear(list2);
			break;
		case 6:
			if (num == 1)Reverse(list1);
			else Reverse(list2);
			break;
		case 7:
			list1 = Merge(list1, list2);
			list2->Next = NULL;
			break;
		default:
			break;
		}
		system("cls");
	}
}