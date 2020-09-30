#include "myheadfile.h"

struct terms *multinomialplus(struct terms *multihead1,struct terms *multihead2)
{
	struct terms *ptr;
	for(ptr=multihead1;ptr->next;ptr=ptr->next);		//��������ʽ���ӣ������úϲ�ͬ���������ɼӷ� 
	ptr->next = multihead2;
	combineterms(multihead1);
	return multihead1;
}

struct terms *multiplication(struct terms *head1,struct terms *head2)
{
	struct terms *ptr1,*ptr2,*head,*tail,*p;			//�������ʽ��ˣ�����������һ���µ������� 
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
	ptr->next = multihead2;					//����������ʽ 
	for(ptr=multihead2;ptr;ptr = ptr->next)ptr->coefficient=-ptr->coefficient;//���ڶ�������ʽϵ����Ϊ���� 
	combineterms(multihead1);		//�ϲ�ͬ�������ɼ��� 
	return multihead1;
} 
