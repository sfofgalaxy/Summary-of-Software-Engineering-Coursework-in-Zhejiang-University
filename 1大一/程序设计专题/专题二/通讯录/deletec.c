#include "myheadfile.h"


struct contacts *deletec(struct contacts *head){
	struct contacts *ptr,*p;
	char name[20];
	printf("��������Ҫɾ������ϵ�˵�������");
	scanf("%s",name);
	ptr = findc(name,head);
	if(ptr)printf("δ�ҵ�����ϵ�ˣ�");
	else if(ptr!=head){
		for(p=head;p->next != ptr;p=p->next);
		p->next = ptr->next;
		free(ptr);
		printf("��ɾ���ɹ���");
	}
	else {
		head = head->next;
		free(ptr);
	}
	return head;
} 
