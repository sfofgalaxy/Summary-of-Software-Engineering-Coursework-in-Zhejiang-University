#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
 
int count;				//����ȫ�ֱ�����¼�Թ��߷� 
int min=1000;			//��¼���·���ĳ��� 
int best_count;			//��¼���Ž���� 

int main(void)
{
	int i,j;
    int enter_x,enter_y,exit_x,exit_y;            					//��¼��ںͳ������� 
    int length,width; 
    int flag=1;														//��¼�Թ������Ƿ�Ϸ� 
    printf("�������Թ���С����������*��");
    scanf("%d%d",&length,&width);
    
    int **a;														//���嶯̬��ά���� 
    a=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)a[i]=(int *)malloc(length*sizeof(int));
	int **best;														//�����¼���Ž�Ķ�̬��ά���� 
	best=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)best[i]=(int *)malloc(length*sizeof(int));
	
		
	printf("�������Թ���0����ǽ��1������ߵ�·�������һ����ǽ��:\n");	//�����Թ� 
	for(i=0;i<width;i++)
		for(j=0;j<length;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=1&&a[i][j]!=0)flag=0;
		}
	while(flag==0){
		flag=1;
		printf("�Թ����벻�Ϸ����������룺\n");
		for(i=0;i<width;i++)
			for(j=0;j<length;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]!=1&&a[i][j]!=0)flag=0;
			}
	}
		
		
		
	printf("������������꣨��ֱΪx�ᣬˮƽΪy�ᣩ��");					//������� 
	scanf("%d%d",&enter_x,&enter_y);
	while((enter_x!=0&&enter_x!=width-1&&enter_y!=0&&enter_y!=length-1)||enter_x>width-1||enter_y>length-1){
		printf("������벻�Ϸ�����������������Χǽ��ĳһ���꣺");
		scanf("%d%d",&enter_x,&enter_y);
	}	
	a[enter_x][enter_y]=1;												//���������Ϊ· 
	
	
	printf("������������꣨��ֱΪx�ᣬˮƽΪy�ᣩ: ");					//�������� 
	scanf("%d%d",&exit_x,&exit_y);
	while((exit_x!=0&&exit_x!=width-1&&exit_y!=0&&exit_y!=length-1)||(exit_x==enter_x&&exit_y==enter_y)||exit_x>width-1||exit_y>length-1){
		printf("�������벻�Ϸ�����������������Χǽ��ĳһ���꣺");
		scanf("%d%d",&exit_x,&exit_y);
	}	
	a[exit_x][exit_y]=1;												//����������Ϊ· 
	
	
	move(a,best,enter_x,enter_y,exit_x,exit_y,length,width);					//��ʼ�ݹ����Թ����� 

	if(count>=1){
		printf("���Թ��Ľ����ϣ���%d���߷�\n\n",count);
		best_maze(best,length,width); 
	}
	else printf("���Թ��޽�");
	free(a); 
	free(best);															//free��ָ̬�� 
	return 0; 
}
