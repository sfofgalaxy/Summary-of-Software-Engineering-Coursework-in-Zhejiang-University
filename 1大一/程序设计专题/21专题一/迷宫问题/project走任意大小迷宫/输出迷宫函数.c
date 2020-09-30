#include <stdio.h>
#include <stdlib.h>


extern int count;		//��������ȫ�ֱ������ڸ��ļ��е����� 
extern int min;			
extern int best_count;

//�����Թ�����¼���Ž� 
void produce_maze(int **a,int **best,int length,int width){
	int i,j;
	int step=0;
	for(i=0;i<width;i++){
		for(j=0;j<length;j++){
			if(a[i][j]==0)printf("@");
			else if(a[i][j]==1)printf(" ");
			else {
				step++;
				printf("o");
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
				if(best[i][j]==0)printf("@");
				else if(best[i][j]==1)printf(" ");
				else printf("o");
			}
		printf("\n");
		}
} 
	
