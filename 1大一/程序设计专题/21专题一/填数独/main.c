#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

int num[9][9];						//�������� 
int count;							//��¼�ⷨ���� 

int main(void)
{	
	int i,j;
	int flag=1;
	printf("����������9*9��0����δ�����֣���\n");
	for(i=0;i<9;i++)
		for(j=0;j<9;j++){
			scanf("%d",&num[i][j]);
			if(num[i][j]>9||num[i][j]<0)flag=0;
		}
	printf("\n");
	while(flag==0||judge()==FALSE){
		printf("�������벻�Ϸ������������룺\n");
		flag=1;
		for(i=0;i<9;i++)
		for(j=0;j<9;j++){
			scanf("%d",&num[i][j]);
			if(num[i][j]>9||num[i][j]<0)flag=0;
		}
		printf("\n");
	}
	fill_num(0,0);					//�ӵ�һ����ʼ�� 
	if(count>=1)printf("�����ⷨ���ϣ���%d�ֽⷨ",count);
	else printf("�������޽�"); 
}
