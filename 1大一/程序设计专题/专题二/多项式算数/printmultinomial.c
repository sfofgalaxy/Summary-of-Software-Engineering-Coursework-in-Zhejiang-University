#include "myheadfile.h"

void printmultinomial(struct terms *head)
{
	struct terms *ptr;								//打印多项式函数 
	printf("结果如下：\nf(x) = ");
	for(ptr = head;ptr->next;ptr = ptr->next){
		if(ptr->power==0)printf("%f + ",ptr->coefficient);
		else printf("%fx^%d + ",ptr->coefficient,ptr->power);	
	}
	if(ptr->power!=0)printf("%fx^%d\n",ptr->coefficient,ptr->power);
	else printf("%f\n",ptr->coefficient);
	return;
}
