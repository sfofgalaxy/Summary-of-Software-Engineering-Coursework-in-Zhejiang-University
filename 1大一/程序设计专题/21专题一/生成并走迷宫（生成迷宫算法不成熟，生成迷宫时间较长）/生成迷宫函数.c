#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int k; 

void creat_maze(int **maze,int width,int length,int x,int y)
{
	maze[x][y]=2;
	int i,j;
	int direction;
	while(1){ 
		srand((int)time(NULL));
		k++;
		direction=k*k*rand()%4;
		switch(direction){
			case 0:if(maze[x-2][y]==1){
				maze[x-1][y]=2;
				creat_maze(maze,width,length,x-2,y);
			}break;
			case 1:if(maze[x+2][y]==1){
				maze[x+1][y]=2;
				creat_maze(maze,width,length,x+2,y);
			}break;
			case 2:if(maze[x][y+2]==1){
				maze[x][y+1]=2;
				creat_maze(maze,width,length,x,y+2);
			}break;
			case 3:if(maze[x][y-2]==1){
				maze[x][y-1]=2;
				creat_maze(maze,width,length,x,y-2);
			}break;
		}
		if((maze[x-2][y]==2||maze[x-2][y]==0)&&(maze[x+2][y]==2||maze[x+2][y]==0)&&(maze[x][y+2]==2||maze[x][y+2]==0)&&(maze[x][y-2]==2||maze[x][y-2]==0))break;
	}

}
