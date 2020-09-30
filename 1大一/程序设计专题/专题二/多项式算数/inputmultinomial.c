#include "myheadfile.h"

struct terms *inputmultinomial(void){	//输入多项式 
	struct terms *head,*p,*tail;
	double coefficient=0;
	int power=0;
	int size = sizeof(struct terms);
	head = tail = NULL;
	scanf("%lf%d",&coefficient,&power);
	while(coefficient!=-1||power!=-1){
		p =  (struct terms *)malloc(size);
		p->coefficient = coefficient;
		p->power = power;
		p->next = NULL;
		if(head==NULL)
			head=p;
		else
			tail->next=p;
		tail = p;
		scanf("%lf%d",&coefficient,&power);
	}
	return head;
}
