/* *
 * @copyright 2019-2020, Zhejiang University
 * @file   Heterogeneous linked list.c
 * @brief  ʵ���������� 
 *
 * �汾��ʷ��   
 * @Verson  0.1 @date 2019-03-5   pzf���½��ļ�
 * @Verson  0.2 @date 2012-03-8   pzf���޸���Heterogeneous linked list.hͷ�ļ� 
 *     
*/


#include "Heterogeneous linked list.h"
#include "Heterogeneous linked list.c"

#include <stdio.h>
#include <stdlib.h>




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
			if (num == 1)DeleteHead(list1);
			else DeleteHead(list2);
			break;
		case 4:
			if (num == 1)DeleteTail(list1);
			else DeleteTail(list2);
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
