#include "myheadfile.h"

struct terms *combineterms(struct terms *head)
{
	struct terms *ptr1,*ptr2,*p;
	head = sortterms(head);								//�Ƚ��䰴��С�������� 
	for(ptr1=head;ptr1;ptr1 = ptr1->next){						//�ϲ�ͬ�η��� 
		p = ptr1;
		for(ptr2=ptr1->next;ptr2;ptr2 = ptr2->next){
			if(ptr2->power==ptr1->power){
				ptr1->coefficient = ptr1->coefficient+ptr2->coefficient;
				p->next = ptr2->next;
			}
			else p = p->next;
		}
	}
	while(head->coefficient==0){				//�����һ��Ϊ�㣬ɾ����ֱ����һ�Ϊ�� 
		head = head->next;
	}
	ptr2 = head;								//ɾ����������� 
	for(ptr1=head->next;ptr1;ptr1=ptr1->next){
		if(ptr1->coefficient==0&&ptr1->next!=NULL)ptr2->next=ptr1->next;
		else if(ptr1->coefficient==0&&ptr1->next==NULL)ptr2->next = NULL;
		else ptr2 = ptr2->next;
	}
	return head;
} 
