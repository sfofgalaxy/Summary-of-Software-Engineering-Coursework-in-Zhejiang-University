#include "myheadfile.h"

struct contacts *inputc(struct contacts *head){
	struct contacts *ptr,*p1;
	int n,i; 
	for(ptr=head;ptr;ptr=ptr->next){
		p1 = ptr;
	}
	ptr = (struct contacts *)malloc(sizeof(struct contacts));
	if(head == NULL){
		head = ptr;
		printf("请输入联系人姓名：");
		scanf("%s",ptr->name); 
		printf("请输入%s的电话个数（1~3）：",ptr->name);
		scanf("%d",&n); 
		for(i=0;i<n;i++){
			printf("请输入%s的电话号码：",ptr->name);
			scanf("%s",ptr->tel[i]); 
		}
		printf("请输入%s的地址：",ptr->name);
		scanf("%s",ptr->addr);
		printf("请输入%s的生日（格式xxxx-xx-xx)：",ptr->name);
		scanf("%s",ptr->birth);
		head->next=NULL;
	}
	else{
		p1->next=ptr;
		printf("请输入联系人姓名："); 
		scanf("%s",ptr->name);
		while(!findc(ptr->name,head)){
			printf("该联系人已存在！\n请重新输入：");
			scanf("%s",ptr->name);
		}
		printf("请输入%s的电话个数（1~3）：",ptr->name);
		scanf("%d",&n); 
		for(i=0;i<n;i++){
			printf("请输入%s的电话号码：",ptr->name);
			scanf("%s",ptr->tel[i]); 
		}
		printf("请输入%s的地址",ptr->name);
		scanf("%s",ptr->addr);
		printf("请输入%s的生日（格式xxxx-xx-xx)：",ptr->name);
		scanf("%s",ptr->birth);
		ptr->next=NULL;
	}
	return head;
} 
 
