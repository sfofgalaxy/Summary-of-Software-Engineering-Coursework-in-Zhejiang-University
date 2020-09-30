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
     printf("�������ʾ�������ݳ�ʼ������\n ");   
     pHead = createNode(COUNT);   
     assert(pHead != NULL);   
     printf("�������ɹ����洢�������£�\n ");   
     printNode(pHead);   
     while (!isExit)   
     {   
         printf("\n --------------------------\n ");   
         printf("��ѡ��Ҫ���еĲ�����\n ");   
         printf("1.��ӡ���������нڵ����ݣ�\n ");   
         printf("2.����ID��ѯ���ơ�\n ");   
         printf("3.ɾ��ָ��ID�Ľڵ㡣\n ");   
         printf("4.��ָ��ID�Ľڵ�����һ���µĽڵ㡣\n ");   
         printf("5.�˳���\n ");   
         printf("\n ---------------------------\n ");   
         scanf("%d",&nSelect);   
         switch(nSelect)   
         {   
             case 1:   
                 printf("�������нڵ��������£�\n ");   
                 printNode(pHead);   
                 break;   
             case 2:   
                 printf("������Ҫ��ѯ�Ľڵ��ID��\n ");   
                 scanf("%d",&uID);   
                 pDest = searchNode(pHead, uID);   
                 if (pDest != NULL)   
                 {   
                     printf("���ҵ��ڵ㣬����Ϊ��%s ",pDest->strName);   
                 }   
                 break;   
             case 3:   
                 printf("������Ҫɾ���Ľڵ��ID��\n ");   
                 scanf("%d",&uID);   
                 pHead = deleteNode(pHead, uID);   
                 break;   
             case 4:   
                 printf("������Ҫɾ���Ľڵ��ID��\n ");   
                 scanf("%d",&uID);   
                 pHead = insertNode(pHead, uID);   
                 break;   
             case 5:   
                 isExit = true;   
                 printf("�������˳��� ");   
                 break;   
              default:   
                  printf("��������������ѡ�� ");   
                  break;   
          }   
      }   
      return 1;   

}