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
    int flag;
    printf("��ѡ��\n[1]�Լ������Թ�\n[2]��������Թ�\n");
    scanf("%d",&flag);
    while(flag!=1&&flag!=2){
    	printf("����������������룺\n");
    	printf("��ѡ��\n[1]�Լ������Թ�\n[2]��������Թ�\n");
    	scanf("%d",&flag);
    }
    
    
    
    
//��������Թ������ 
    
    if(flag==2){
    printf("�������Թ���С����������*��");
    scanf("%d%d",&length,&width);
    
	int **best;														//�����¼���Ž�Ķ�̬��ά���� 
	best=(int **)malloc((width+4)*sizeof(int *));
	for(i=0;i<width+4;i++)best[i]=(int *)malloc((length+4)*sizeof(int));
	
	int **maze;
	maze=(int **)malloc(sizeof(int *)*(width+4));
	for(i=0;i<width+4;i++)maze[i]=(int *)malloc(sizeof(int)*(length+4));
	for(i=0;i<width+4;i++)
		for(j=0;j<length+4;j++){
			if(i%2==1&&j%2==1)maze[i][j]=1;
			else maze[i][j]=0;
		}
	for(i=0;i<width+4;i++)
		for(j=0;j<length+4;j++){
			if(i==1||i==width+2||j==1||j==length+2)maze[i][j]=0;
		}
	creat_maze(maze,width,length,3,3);
	for(i=2;i<width+2;i++){
		for(j=2;j<length+2;j++){
			if(maze[i][j]==0)printf("@");
			else printf(" ");
		}
		printf("\n");
	}
	printf("\n");
	
	printf("������������꣨��ֱΪx�ᣬˮƽΪy�ᣩ��");					//������� 
	scanf("%d%d",&enter_x,&enter_y);
	while((enter_x!=0&&enter_x!=width-1&&enter_y!=0&&enter_y!=length-1)||enter_x>width-1||enter_y>length-1){
		printf("������벻�Ϸ�����������������Χǽ��ĳһ���꣺");
		scanf("%d%d",&enter_x,&enter_y);
	}	
	maze[enter_x+2][enter_y+2]=2;
	
	printf("������������꣨��ֱΪx�ᣬˮƽΪy�ᣩ: ");					//�������� 
	scanf("%d%d",&exit_x,&exit_y);
	while((exit_x!=0&&exit_x!=width-1&&exit_y!=0&&exit_y!=length-1)||(exit_x==enter_x&&exit_y==enter_y)||exit_x>width-1||exit_y>length-1){
		printf("�������벻�Ϸ�����������������Χǽ��ĳһ���꣺");
		scanf("%d%d",&exit_x,&exit_y);
	}	
	maze[exit_x+2][exit_y+2]=2;
	
	move(maze,best,enter_x+2,enter_y+2,exit_x+2,exit_y+2,length,width,flag);					//��ʼ�ݹ����Թ����� 

	if(count>=1){
		printf("���Թ��Ľ�����\n");
	}
	else printf("���Թ��޽�"); 
	free(best);	
	free(maze);														//free��ָ̬�� 
	return 0;
    }
    
    
    
    
    
    
//�Լ������Թ������ 
    

    else {														
    int i,j;
    int enter_x,enter_y,exit_x,exit_y;            					//��¼��ںͳ������� 
    int length,width; 
    int fla=1;														//��¼�Թ������Ƿ�Ϸ� 
    printf("�������Թ���С����������*��");
    scanf("%d%d",&length,&width);
    
    int **a;														//���嶯̬��ά���� 
    a=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)a[i]=(int *)malloc(length*sizeof(int));
	int **best;														//�����¼���Ž�Ķ�̬��ά���� 
	best=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)best[i]=(int *)malloc(length*sizeof(int));
	
		
	printf("�������Թ���0����ǽ��2������ߵ�·�������һ����ǽ��:\n");	//�����Թ� 
	for(i=0;i<width;i++)
		for(j=0;j<length;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=2&&a[i][j]!=0)fla=0;
		}
	while(fla==0){
		fla=1;
		printf("�Թ����벻�Ϸ����������룺\n");
		for(i=0;i<width;i++)
			for(j=0;j<length;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]!=2&&a[i][j]!=0)fla=0;
			}
	}
		
		
		
	printf("������������꣨��ֱΪx�ᣬˮƽΪy�ᣩ��");					//������� 
	scanf("%d%d",&enter_x,&enter_y);
	while((enter_x!=0&&enter_x!=width-1&&enter_y!=0&&enter_y!=length-1)||enter_x>width-1||enter_y>length-1){
		printf("������벻�Ϸ�����������������Χǽ��ĳһ���꣺");
		scanf("%d%d",&enter_x,&enter_y);
	}	
	a[enter_x][enter_y]=2;												//���������Ϊ· 
	
	
	printf("������������꣨��ֱΪx�ᣬˮƽΪy�ᣩ: ");					//�������� 
	scanf("%d%d",&exit_x,&exit_y);
	while((exit_x!=0&&exit_x!=width-1&&exit_y!=0&&exit_y!=length-1)||(exit_x==enter_x&&exit_y==enter_y)||exit_x>width-1||exit_y>length-1){
		printf("�������벻�Ϸ�����������������Χǽ��ĳһ���꣺");
		scanf("%d%d",&exit_x,&exit_y);
	}	
	a[exit_x][exit_y]=2;												//����������Ϊ· 
	
	
	move(a,best,enter_x,enter_y,exit_x,exit_y,length,width,flag);					//��ʼ�ݹ����Թ����� 

	if(count>=1){
		printf("���Թ��Ľ����ϣ���%d���߷�\n",count);
		best_maze(best,length,width,flag); 
	}
	else printf("���Թ��޽�");
	free(a); 
	free(best);															//free��ָ̬�� 
	return 0; 
    }
    
}
