#include <stdio.h>
#include <stdlib.h>


extern int count;		//主函数的全局变量，在该文件中的声明 


//走迷宫函数 
void move(int **maze,int **best,int x,int y,int exit_x,int exit_y,int length,int width,int flag){		//x,y为当前坐标 
	int i;
	maze[x][y]=1;	
	if(x==exit_x&&y==exit_y){
		produce_maze(maze,best,length,width,flag);
		maze[exit_x][exit_y]=2;
		count++;
		return;
	}
	else if(flag==2){
		for(i=1;i<=4;i++)switch(i){									//计数，遍历某位置的各个位置 
			case 1:if(x<=width+1&&maze[x+1][y]==2)move(maze,best,x+1,y,exit_x,exit_y,length,width,flag);break;
			case 2:if(x>0&&maze[x-1][y]==2)move(maze,best,x-1,y,exit_x,exit_y,length,width,flag);break;
			case 3:if(y<=length+1&&maze[x][y+1]==2)move(maze,best,x,y+1,exit_x,exit_y,length,width,flag);break;
			case 4:if(y>0&&maze[x][y-1]==2)move(maze,best,x,y-1,exit_x,exit_y,length,width,flag);break;
		}
		maze[x][y]=2;
	}
	else {
		for(i=1;i<=4;i++)switch(i){									//计数，遍历某位置的各个位置 
			case 1:if(x<=width-1&&maze[x+1][y]==2)move(maze,best,x+1,y,exit_x,exit_y,length,width,flag);break;
			case 2:if(x>0&&maze[x-1][y]==2)move(maze,best,x-1,y,exit_x,exit_y,length,width,flag);break;
			case 3:if(y<=length-1&&maze[x][y+1]==2)move(maze,best,x,y+1,exit_x,exit_y,length,width,flag);break;
			case 4:if(y>0&&maze[x][y-1]==2)move(maze,best,x,y-1,exit_x,exit_y,length,width,flag);break;
		}
		maze[x][y]=2;
	}
}
