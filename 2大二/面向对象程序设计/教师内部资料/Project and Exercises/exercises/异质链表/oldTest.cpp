#include "diff.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	PNODE head1;
	PNODE head2;
	head1 = createNode(3);
	print(head1);
	head2 = createNode(5);
	print(head2);
NODE *pHead, *pDest;   
     int nSelect;   
     bool isExit = false;   
     unsigned long uID;   
     printf("请根据提示输入数据初始化链表：\n ");   
     pHead = createNode(COUNT);   
     assert(pHead != NULL);   
     printf("链表创建成功！存储数据如下：\n ");   
     printNode(pHead);   
     while (!isExit)   
     {   
         printf("\n --------------------------\n ");   
         printf("请选择要进行的操作：\n ");   
         printf("1.打印出链表所有节点数据：\n ");   
         printf("2.输入ID查询名称。\n ");   
         printf("3.删除指定ID的节点。\n ");   
         printf("4.在指定ID的节点后插入一个新的节点。\n ");   
         printf("5.退出。\n ");   
         printf("\n ---------------------------\n ");   
         scanf("%d",&nSelect);   
         switch(nSelect)   
         {   
             case 1:   
                 printf("链表所有节点数据如下：\n ");   
                 printNode(pHead);   
                 break;   
             case 2:   
                 printf("请输入要查询的节点的ID：\n ");   
                 scanf("%d",&uID);   
                 pDest = searchNode(pHead, uID);   
                 if (pDest != NULL)   
                 {   
                     printf("已找到节点，名字为：%s ",pDest->strName);   
                 }   
                 break;   
             case 3:   
                 printf("请输入要删除的节点的ID：\n ");   
                 scanf("%d",&uID);   
                 pHead = deleteNode(pHead, uID);   
                 break;   
             case 4:   
                 printf("请输入要删除的节点的ID：\n ");   
                 scanf("%d",&uID);   
                 pHead = insertNode(pHead, uID);   
                 break;   
             case 5:   
                 isExit = true;   
                 printf("程序已退出！ ");   
                 break;   
              default:   
                  printf("按键错误，请重新选择！ ");   
                  break;   
          }   
      }   
      return 1;   

}