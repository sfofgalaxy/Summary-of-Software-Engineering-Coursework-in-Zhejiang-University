#include "myheadfile.h"


struct contacts *deletec(struct contacts *head){
	struct contacts *ptr,*p;
	char name[20];
	printf("请输入想要删除的联系人的姓名：");
	scanf("%s",name);
	ptr = findc(name,head);
	if(ptr)printf("未找到该联系人！");
	else if(ptr!=head){
		for(p=head;p->next != ptr;p=p->next);
		p->next = ptr->next;
		free(ptr);
		printf("已删除成功！");
	}
	else {
		head = head->next;
		free(ptr);
	}
	return head;
} 
