#include "myheadfile.h"

void addtel(struct contacts *head){
	struct contacts *ptr,*p;
	int i;
	char name[20];
	printf("��������Ҫ��ӵ绰�������ϵ�˵�������");
	scanf("%s",name);
	ptr = findc(name,head);
	if(ptr)printf("δ�ҵ�����ϵ�ˣ�");
	else {
		for(i=0;i<3;i++)if(ptr->tel[i])break;
		if(i==3){
			printf("��绰������Ϊ����������������µ���ϵ����Ϊ����ӵ绰���룡");
			return;
		}
		printf("������绰���룺");
		scanf("%s",ptr->tel[i]);
		printf("��ӳɹ���"); 
	}
	return;
}
