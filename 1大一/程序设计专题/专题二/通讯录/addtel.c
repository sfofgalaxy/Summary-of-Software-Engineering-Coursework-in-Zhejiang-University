#include "myheadfile.h"

void addtel(struct contacts *head){
	struct contacts *ptr,*p;
	int i;
	char name[20];
	printf("请输入需要添加电话号码的联系人的姓名：");
	scanf("%s",name);
	ptr = findc(name,head);
	if(ptr)printf("未找到该联系人！");
	else {
		for(i=0;i<3;i++)if(ptr->tel[i])break;
		if(i==3){
			printf("其电话号码已为三个，请另行添加新的联系人来为其添加电话号码！");
			return;
		}
		printf("请输入电话号码：");
		scanf("%s",ptr->tel[i]);
		printf("添加成功！"); 
	}
	return;
}
