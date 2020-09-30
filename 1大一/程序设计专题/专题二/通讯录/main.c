#include "myheadfile.h"


int main(void) {
	int judge,i;
	struct contacts *head,*ptr;
	head = NULL;
	do{
		printf("请选择数字：\n[1]手动添加新的联系人到通讯录末尾\n[2]从文件中导入联系人到通讯录末尾\n[3]删除指定联系人\n[4]查找指定联系人\n[5]为指定联系人添加电话号码[6]将联系人按照年龄从大到小排序\n[7]将联系人按照姓氏排序\n[8]退出并导出联系人\n");
		scanf("%d",&judge);
		switch(judge){								/*8个不同的函数选项*/ 
			case 1:head = inputc(head);break; 
			case 2:head = importc(head);break; 
			case 3:head = deletec(head);break;
			case 4:{
				char name[20];
				printf("请输入所要寻找的联系人的姓名：");
				scanf("%s",name);
				ptr = findc(name,head);
				if(!ptr)printf("未找到该联系人！");
				else{
					printf("该联系人的电话号码为：");
					printf("%s ",ptr->tel[0]);
					printf("\n");
					printf("该联系人的住址为：%s\n",ptr->addr);
					printf("该联系人的生日为：%s\n",ptr->birth);
				}
				break;
			}
			case 5:addtel(head);break; 
			case 6:head = birth_sort(head);break;
			case 7:head = name_sort(head);break;
			case 8:exportc(head);return 0;
		};
	}
	while(1);
}
