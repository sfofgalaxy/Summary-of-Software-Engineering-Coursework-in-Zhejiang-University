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
		printf("��������ϵ��������");
		scanf("%s",ptr->name); 
		printf("������%s�ĵ绰������1~3����",ptr->name);
		scanf("%d",&n); 
		for(i=0;i<n;i++){
			printf("������%s�ĵ绰���룺",ptr->name);
			scanf("%s",ptr->tel[i]); 
		}
		printf("������%s�ĵ�ַ��",ptr->name);
		scanf("%s",ptr->addr);
		printf("������%s�����գ���ʽxxxx-xx-xx)��",ptr->name);
		scanf("%s",ptr->birth);
		head->next=NULL;
	}
	else{
		p1->next=ptr;
		printf("��������ϵ��������"); 
		scanf("%s",ptr->name);
		while(!findc(ptr->name,head)){
			printf("����ϵ���Ѵ��ڣ�\n���������룺");
			scanf("%s",ptr->name);
		}
		printf("������%s�ĵ绰������1~3����",ptr->name);
		scanf("%d",&n); 
		for(i=0;i<n;i++){
			printf("������%s�ĵ绰���룺",ptr->name);
			scanf("%s",ptr->tel[i]); 
		}
		printf("������%s�ĵ�ַ",ptr->name);
		scanf("%s",ptr->addr);
		printf("������%s�����գ���ʽxxxx-xx-xx)��",ptr->name);
		scanf("%s",ptr->birth);
		ptr->next=NULL;
	}
	return head;
} 
 
