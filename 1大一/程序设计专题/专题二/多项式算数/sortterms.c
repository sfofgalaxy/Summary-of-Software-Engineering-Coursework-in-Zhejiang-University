#include "myheadfile.h"

struct terms *sortterms(struct terms *head)
{
	struct terms *ptr1,*ptr2,*p;				//冒泡排序将多项式按幂从小到大排序 
	double coefficient;
	int power;
	for(ptr1=head;ptr1->next;ptr1 = ptr1->next){
		p = head;
		for(ptr2=head->next;ptr2;ptr2=ptr2->next){
			if(ptr2->power<p->power){
				coefficient = p->coefficient;
				power = p->power;
				p->coefficient = ptr2->coefficient;
				p->power = ptr2->power;
				ptr2->coefficient = coefficient;
				ptr2->power = power;
			}
			p = p->next;
		}
	}
	return head;
}
