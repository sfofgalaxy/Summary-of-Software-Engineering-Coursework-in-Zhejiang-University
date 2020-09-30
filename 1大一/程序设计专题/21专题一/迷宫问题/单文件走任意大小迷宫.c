#include <stdio.h>
#include <stdlib.h>

int count;			//定义全局变量记录迷宫走法 
int min=1000;			//记录最短路径的长度 
int best_count;			//记录最优解个数 

//生成迷宫并记录最优解 
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
	else if(step==min)best_count++;		//记录最优解个数 
	printf("\n");
} 

//最优解输出 
void best_maze(int **best,int length,int width){
	int i,j;
	printf("有%d种最优解，其中一种最优解如下：\n",best_count);
		for(i=0;i<width;i++){
			for(j=0;j<length;j++){
				if(best[i][j]==0)printf("#");
				else if(best[i][j]==1)printf(" ");
				else printf("*");
			}
		printf("\n");
		}
} 



//走迷宫函数 
void move(int **a,int **best,int x,int y,int exit_x,int exit_y,int length,int width){		//x,y为当前坐标 
	int i;
	a[x][y]=2;	
	if(x==exit_x&&y==exit_y){
		produce_maze(a,best,length,width);
		a[exit_x][exit_y]=1;
		count++;
		return;
	}
	else {
		for(i=1;i<=4;i++)switch(i){									//计数，遍历某位置的各个位置 
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
    int enter_x,enter_y,exit_x,exit_y;            					//记录入口和出口坐标 
    int length,width; 
    printf("请输入迷宫大小（整数）长*宽：");
    scanf("%d%d",&length,&width);
    
    int **a;														//定义动态二维数组 
    a=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)a[i]=(int *)malloc(length*sizeof(int));
	int **best;														//定义记录最优解的动态二维数组 
	best=(int **)malloc(width*sizeof(int *));
	for(i=0;i<width;i++)best[i]=(int *)malloc(length*sizeof(int));
	
		
	printf("请输入迷宫（0代表墙，1代表可走的路，最外层一周是墙）:\n");	//输入迷宫 
	for(i=0;i<width;i++)
		for(j=0;j<length;j++)scanf("%d",&a[i][j]);
		
		
	printf("请输入入口坐标（竖直为x轴，水平为y轴）：");					//入口坐标 
	scanf("%d%d",&enter_x,&enter_y);
	while((enter_x!=0&&enter_x!=width-1&&enter_y!=0&&enter_y!=length-1)||enter_x>width-1||enter_y>length-1){
		printf("入口输入不合法，请重新输入最外围墙的某一坐标：");
		scanf("%d%d",&enter_x,&enter_y);
	}	
	a[enter_x][enter_y]=1;												//将入口设置为路 
	
	
	printf("请输入出口坐标（竖直为x轴，水平为y轴）: ");					//出口坐标 
	scanf("%d%d",&exit_x,&exit_y);
	while((exit_x!=0&&exit_x!=width-1&&exit_y!=0&&exit_y!=length-1)||(exit_x==enter_x&&exit_y==enter_y)||exit_x>width-1||exit_y>length-1){
		printf("出口输入不合法，请重新输入最外围墙的某一坐标：");
		scanf("%d%d",&exit_x,&exit_y);
	}	
	a[exit_x][exit_y]=1;												//将出口设置为路 
	
	
	move(a,best,enter_x,enter_y,exit_x,exit_y,length,width);					//开始递归走迷宫函数 

	if(count>=1){
		printf("该迷宫的解如上，有%d种解法\n\n",count);
		best_maze(best,length,width); 
	}
	else printf("该迷宫无解");
	free(a); 
	free(best);															//free动态指针 
	return 0; 
}


