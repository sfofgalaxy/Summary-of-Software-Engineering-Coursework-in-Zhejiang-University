#include <stdio.h>
#include <stdlib.h>

int count;			//����ȫ�ֱ�����¼�Թ��߷� 
int min=1000;			//��¼���·���ĳ��� 
int best_count;			//��¼���Ž���� 

//�����Թ�����¼���Ž� 
void produce_maze(int **a,int **best,int length,int width){
	int i,j;
	int step=0;
	for(i=0;i<width;i++){
		for(j=0;j<length;j++){
			if(a[i][j]==0)printf("#");
			else if(a[i][j]==1)printf(" ");
			else {
				step++;
				printf("*");
			}
		}
		printf("\n");
	}
	if(step<min){
		best_count=1;
		min=step;
		for(i=0;i<width;i++){
			for(j=0;j<length;j++){
				if(a[i][j]==0)best[i][j]=0;
				else if(a[i][j]==1)best[i][j]=1;
				else {
				    best[i][j]=2;
				}
			}
		}
	}
	else if(step==min)best_count++;		//��¼���Ž���� 
	printf("\n");
} 

//���Ž���� 
void best_maze(int **best,int length,int width){
	int i,j;
	printf("��%d�����Ž⣬����һ�����Ž����£�\n",best_count);
		for(i=0;i<width;i++){
			for(j=0;j<length;j++){
				if(best[i][j]==0)printf("#");
				else if(best[i][j]==1)printf(" ");
				else printf("*");
			}
		printf("\n");
		}
} 



//���Թ����� 
void move(int **a,int **best,int x,int y,int exit_x,int exit_y,int length,int width){		//x,yΪ��ǰ���� 
	int i;
	a[x][y]=2;	
	if(x==exit_x&&y==exit_y){
		produce_maze(a,best,length,width);
		a[exit_x][exit_y]=1;
		count++;
		return;
	}
	else {
		for(i=1;i<=4;i++)switch(i){									//����������ĳλ�õĸ���λ�� 
			case 1:if(a[x+1][y]==1)move(a,best,x+1,y,exit_x,exit_y,length,width);break;
			case 2:if(a[x-1][y]==1)move(a,best,x-1,y,exit_x,exit_y,length,width);break;
			case 3:if(a[x][y+1]==1)move(a,best,x,y+1,exit_x,exit_y,length,width);break;
			case 4:if(a[x][y-1]==1)move(a,best,x,y-1,exit_x,exit_y,length,width);break;
		}
		a[x][y]=1;
	}
}

int main(void)
{
	int i,j;
    int enter_x,enter_y,exit_x,exit_y;            					//��¼��ںͳ������� 
    int length,width; 
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
		for(j=0;j<length;j++)scanf("%d",&a[i][j]);
		
		
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
		printf("���Թ��Ľ����ϣ���%d�ֽⷨ\n\n",count);
		best_maze(best,length,width); 
	}
	else printf("���Թ��޽�");
	free(a); 
	free(best);															//free��ָ̬�� 
	return 0; 
}


