#include "myheadfile.h"


struct contacts *importc(struct contacts *head){
	FILE *fp;
	struct contacts *ptr,*p1,*p2;
	int i;
	int n;
	int size = sizeof(struct contacts); 
	char ch[30];
	fp = fopen("导入联系人.txt","r");
	if(fp==NULL){
		printf("open error");
		exit(0);
	}
	p1=head;
	for(ptr=head;ptr;ptr=ptr->next){
		p1=ptr;
	}
	ptr = (struct contacts *)malloc(sizeof(size));
	if(p1!=NULL){
		p1->next = ptr;
	}
	else{
		head = ptr;
	}
	while(!feof(fp)){
		fscanf(fp,"%s",ptr->name);
		fscanf(fp,"%d",&n);
		for(i=0;i<n;i++)fscanf(fp,"%s",ptr->tel[i]);
		fscanf(fp,"%s",ptr->addr);
		fscanf(fp,"%s",ptr->birth);
		p2 = (struct contacts *)malloc(size);
		ptr->next = p2;
		ptr = ptr->next;
	}
	printf("导入成功！\n"); 
	fclose(fp);
	return head;
}
