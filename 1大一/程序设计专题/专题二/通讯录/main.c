#include "myheadfile.h"


int main(void) {
	int judge,i;
	struct contacts *head,*ptr;
	head = NULL;
	do{
		printf("��ѡ�����֣�\n[1]�ֶ�����µ���ϵ�˵�ͨѶ¼ĩβ\n[2]���ļ��е�����ϵ�˵�ͨѶ¼ĩβ\n[3]ɾ��ָ����ϵ��\n[4]����ָ����ϵ��\n[5]Ϊָ����ϵ����ӵ绰����[6]����ϵ�˰�������Ӵ�С����\n[7]����ϵ�˰�����������\n[8]�˳���������ϵ��\n");
		scanf("%d",&judge);
		switch(judge){								/*8����ͬ�ĺ���ѡ��*/ 
			case 1:head = inputc(head);break; 
			case 2:head = importc(head);break; 
			case 3:head = deletec(head);break;
			case 4:{
				char name[20];
				printf("��������ҪѰ�ҵ���ϵ�˵�������");
				scanf("%s",name);
				ptr = findc(name,head);
				if(!ptr)printf("δ�ҵ�����ϵ�ˣ�");
				else{
					printf("����ϵ�˵ĵ绰����Ϊ��");
					printf("%s ",ptr->tel[0]);
					printf("\n");
					printf("����ϵ�˵�סַΪ��%s\n",ptr->addr);
					printf("����ϵ�˵�����Ϊ��%s\n",ptr->birth);
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
