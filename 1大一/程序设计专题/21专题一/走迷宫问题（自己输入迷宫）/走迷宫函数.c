#include <stdio.h>
#include <stdlib.h>


extern int count;		//主函数的全局变量，在该文件中的声明 


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
			case 1:if(x<width-1&&a[x+1][y]==1)move(a,best,x+1,y,exit_x,exit_y,length,width);break;
			case 2:if(x>0&&a[x-1][y]==1)move(a,best,x-1,y,exit_x,exit_y,length,width);break;
			case 3:if(y<length-1&&a[x][y+1]==1)move(a,best,x,y+1,exit_x,exit_y,length,width);break;
			case 4:if(y>0&&a[x][y-1]==1)move(a,best,x,y-1,exit_x,exit_y,length,width);break;
		}
		a[x][y]=1;
	}
}
