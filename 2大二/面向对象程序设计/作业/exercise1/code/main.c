/* *
 * @copyright 2019-2020, Zhejiang University
 * @file   Heterogeneous linked list.c
 * @brief  实现异质链表 
 *
 * 版本历史：   
 * @Verson  0.1 @date 2019-03-5   pzf：新建文件
 * @Verson  0.2 @date 2012-03-8   pzf：修改了Heterogeneous linked list.h头文件 
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
		printf("0.输出所有节点\n1.插入到头节点\n2.插入到尾部\n3.删除头节点\n4.删除尾节点");
		printf("\n5.销毁链表\n6.倒置链表\n7.合并两个链表到第一个链表中\n8.退出\n");
		scanf("%d", &operation);
		system("cls");
		if (operation <= 6)
		{
			printf("请输入所要操作的链表编号（1或2）\n");
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
			printf("请选择数据类型：\n0.插入整型\n1.插入字符型\n");
			printf("2.插入单精度浮点数\n3.插入双精度浮点\n4.插入结构体型\n5.返回上一层\n");
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
