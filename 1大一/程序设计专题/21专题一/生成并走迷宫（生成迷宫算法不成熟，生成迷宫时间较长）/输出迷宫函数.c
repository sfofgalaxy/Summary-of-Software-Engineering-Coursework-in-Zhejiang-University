#include <stdio.h>
#include <stdlib.h>


extern int count;		//主函数的全局变量，在该文件中的声明 
extern int min;			
extern int best_count;

//生成迷宫并记录最优解 
void produce_maze(int **maze,int **best,int length,int width,int flag){
	if(flag==2){
	int i,j;
	int step=0;
	for(i=2;i<width+2;i++){
		for(j=2;j<length+2;j++){
			if(maze[i][j]==0)printf("@");
			else if(maze[i][j]==2)printf(" ");
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
		for(i=2;i<width+2;i++){
			for(j=2;j<length+2;j++){
				if(maze[i][j]==0)best[i][j]=0;
				else if(maze[i][j]==2)best[i][j]=2;
				else {
				    best[i][j]=1;
				}
			}
		}
	}
	else if(step==min)best_count++;		//记录最优解个数 
	printf("\n");		
	}
	else {
		int i,j;
	int step=0;
	for(i=0;i<width;i++){
		for(j=0;j<length;j++){
			if(maze[i][j]==0)printf("@");
			else if(maze[i][j]==2)printf(" ");
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
				if(maze[i][j]==0)best[i][j]=0;
				else if(maze[i][j]==2)best[i][j]=2;
				else {
				    best[i][j]=1;
				}
			}
		}
	}
	else if(step==min)best_count++;		//记录最优解个数 
	printf("\n");
	}
} 

//最优解输出 
void best_maze(int **best,int length,int width,int flag){
	if(flag==2){
		int i,j;
		printf("有%d种最优解，其中一种最优解如下：\n",best_count);
		for(i=2;i<width+2;i++){
			for(j=2;j<length+2;j++){
				if(best[i][j]==0)printf("@");
				else if(best[i][j]==2)printf(" ");
				else printf("o");
			}
		printf("\n");
		}	
	}
	else {
		int i,j;
		printf("有%d种最优解，其中一种最优解如下：\n",best_count);
		for(i=0;i<width;i++){
			for(j=0;j<length;j++){
				if(best[i][j]==0)printf("@");
				else if(best[i][j]==2)printf(" ");
				else printf("o");
			}
		printf("\n");
		}
	}

} 
	
