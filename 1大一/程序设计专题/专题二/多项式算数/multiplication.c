#include "myheadfile.h"

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
