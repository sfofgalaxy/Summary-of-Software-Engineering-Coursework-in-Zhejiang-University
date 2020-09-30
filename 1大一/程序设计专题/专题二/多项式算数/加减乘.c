#include "myheadfile.h"

struct terms *multinomialplus(struct terms *multihead1,struct terms *multihead2)
{
	struct terms *ptr;
	for(ptr=multihead1;ptr->next;ptr=ptr->next);		//将两多项式连接，并调用合并同类项函数即完成加法 
	ptr->next = multihead2;
	combineterms(multihead1);
	return multihead1;
}

struct terms *multiplication(struct terms *head1,struct terms *head2)
{
	struct terms *ptr1,*ptr2,*head,*tail,*p;			//计算多项式相乘，将结果输出在一个新的链表里 
	head = tail = NULL;
	int size = sizeof(struct terms);
	for(ptr1=head1;ptr1;ptr1=ptr1->next){
		for(ptr2=head2;ptr2;ptr2 = ptr2->next){
			p =  (struct terms *)malloc(size);
			p->coefficient = ptr1->coefficient * ptr2->coefficient;
			p->power = ptr1->power + ptr2->power;
			p->next = NULL;
			if(head==NULL)
				head=p;
			else
				tail->next=p;
			tail = p;
		}
	}
	head = combineterms(head);
	return head;
}

struct terms * multinomialsubtract(struct terms *multihead1,struct terms *multihead2)
{
	struct terms *ptr;
	for(ptr=multihead1;ptr->next;ptr=ptr->next);
	ptr->next = multihead2;					//连接两多项式 
	for(ptr=multihead2;ptr;ptr = ptr->next)ptr->coefficient=-ptr->coefficient;//将第二个多项式系数变为负数 
	combineterms(multihead1);		//合并同类项即可完成减法 
	return multihead1;
} 
