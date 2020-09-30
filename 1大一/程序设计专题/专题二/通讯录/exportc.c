#include "myheadfile.h"

void exportc(struct contacts *head){
	int i=0; 
	struct contacts *ptr,*p;
	FILE *fp;
	fp = fopen("导出联系人.txt","w");
	fprintf(fp,"序号\t姓名\t联系电话\t住址\t生日\n");
	for(ptr=head;ptr;ptr=ptr->next){
		i++;
		fprintf(fp,"%d\t%s\t%s,%s,%s\t%s\t%s\n",i,ptr->name,ptr->tel[0],ptr->tel[1],ptr->tel[2],ptr->addr,ptr->birth);
	} 
	fclose(fp);
}
