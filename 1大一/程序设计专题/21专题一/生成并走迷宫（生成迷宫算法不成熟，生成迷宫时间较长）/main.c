#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
 
int count;				//定义全局变量记录迷宫走法 
int min=1000;			//记录最短路径的长度 
int best_count;			//记录最优解个数 


int main(void)
{
	int i,j;
    int enter_x,enter_y,exit_x,exit_y;            					//记录入口和出口坐标 
    int length,width; 
    int flag;
    printf("请选择：\n[1]自己输入迷宫\n[2]随机生成迷宫\n");
    scanf("%d",&flag);
    while(flag!=1&&flag!=2){
    	printf("输入错误，请重新输入：\n");
    	printf("请选择：\n[1]自己输入迷宫\n[2]随机生成迷宫\n");
    	scanf("%d",&flag);
    }
    
    
    
    
//随机生成迷宫的情况 
    
    if(flag==2){
    printf("请输入迷宫大小（奇数）长*宽：");
    scanf("%d%d",&length,&width);
    
	int **best;														//定义记录最优解的动态二维数组 
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
	
	printf("请输入入口坐标（竖直为x轴，水平为y轴）：");					//入口坐标 
	scanf("%d%d",&enter_x,&enter_y);
	while((enter_x!=0&&enter_x!=width-1&&enter_y!=0&&enter_y!=length-1)||enter_x>width-1||enter_y>length-1){
		printf("入口输入不合法，请重新输入最外围墙的某一坐标：");
		scanf("%d%d",&enter_x,&enter_y);
	}	
	maze[enter_x+2][enter_y+2]=2;
	
	printf("请输入出口坐标（竖直为x轴，水平为y轴）: ");					//出口坐标 
	scanf("%d%d",&exit_x,&exit_y);
	while((exit_x!=0&&exit_x!=width-1&&exit_y!=0&&exit_y!=length-1)||(exit_x==enter_x&&exit_y==enter_y)||exit_x>width-1||exit_y>length-1){
		printf("出口输入不合法，请重新输入最外围墙的某一坐标：");
		scanf("%d%d",&exit_x,&exit_y);
	}	
	maze[exit_x+2][exit_y+2]=2;
	
	move(maze,best,enter_x+2,enter_y+2,exit_x+2,exit_y+2,length,width,flag);					//开始递归走迷宫函数 

	if(count>=1){
		printf("该迷宫的解如上\n");
	}
	else printf("该迷宫无解"); 
	free(best);	
	free(maze);														//free动态指针 
	return 0;
    }
    
    
    
    
    
    
//自己输入迷宫的情况 
    

    else {														
    int i,j;
    int enter_x,enter_y,exit_x,exit_y;            					//记录入口和出口坐标 
    int length,width; 
    int fla=1;														//记录迷宫输入是否合法 
    printf("请输入迷宫大小（整数）长*宽：");
    scanf("%d%d",&length,&width);
    
    int **a;														//定义动态二维数组 
    a=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)a[i]=(int *)malloc(length*sizeof(int));
	int **best;														//定义记录最优解的动态二维数组 
	best=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)best[i]=(int *)malloc(length*sizeof(int));
	
		
	printf("请输入迷宫（0代表墙，2代表可走的路，最外层一周是墙）:\n");	//输入迷宫 
	for(i=0;i<width;i++)
		for(j=0;j<length;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=2&&a[i][j]!=0)fla=0;
		}
	while(fla==0){
		fla=1;
		printf("迷宫输入不合法请重新输入：\n");
		for(i=0;i<width;i++)
			for(j=0;j<length;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]!=2&&a[i][j]!=0)fla=0;
			}
	}
		
		
		
	printf("请输入入口坐标（竖直为x轴，水平为y轴）：");					//入口坐标 
	scanf("%d%d",&enter_x,&enter_y);
	while((enter_x!=0&&enter_x!=width-1&&enter_y!=0&&enter_y!=length-1)||enter_x>width-1||enter_y>length-1){
		printf("入口输入不合法，请重新输入最外围墙的某一坐标：");
		scanf("%d%d",&enter_x,&enter_y);
	}	
	a[enter_x][enter_y]=2;												//将入口设置为路 
	
	
	printf("请输入出口坐标（竖直为x轴，水平为y轴）: ");					//出口坐标 
	scanf("%d%d",&exit_x,&exit_y);
	while((exit_x!=0&&exit_x!=width-1&&exit_y!=0&&exit_y!=length-1)||(exit_x==enter_x&&exit_y==enter_y)||exit_x>width-1||exit_y>length-1){
		printf("出口输入不合法，请重新输入最外围墙的某一坐标：");
		scanf("%d%d",&exit_x,&exit_y);
	}	
	a[exit_x][exit_y]=2;												//将出口设置为路 
	
	
	move(a,best,enter_x,enter_y,exit_x,exit_y,length,width,flag);					//开始递归走迷宫函数 

	if(count>=1){
		printf("该迷宫的解如上，有%d种走法\n",count);
		best_maze(best,length,width,flag); 
	}
	else printf("该迷宫无解");
	free(a); 
	free(best);															//free动态指针 
	return 0; 
    }
    
}
