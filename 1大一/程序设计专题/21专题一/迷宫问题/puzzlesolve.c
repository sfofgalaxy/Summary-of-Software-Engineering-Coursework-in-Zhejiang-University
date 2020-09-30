#include <stdio.h>
#include <stdlib.h> 
int puzzleprocess(int** Map, int currentrow, int currentcolumn, int maxrow);      //迷宫解决函数 
int printmap(int** map, int length);                                              //打印迷宫函数  
int Judge = 1;                                                                    //用于判断是否有解 
int *a = &Judge;
	
int main(int argc, char** argv) {
	int i, j, length;
	
	printf("Enter the length :");                                                 //输入迷宫边长 
	scanf("%d",&length);      
	int ** map;                                                                   //定义二维数组表示迷宫，1代表围墙，0代表可行走的路 
 
    map = (int**)malloc(length*sizeof(int*));
	for(i = 0; i < length; i++){                                                   //为二维数组分配空间 
    map[i]=(int*)malloc(length*sizeof(int));
	}
	/*	int** path; 
	path = (int**)malloc(length*length*sizeof(int*)); 
	
	for(int i=0;i<length*length;i++){  
    path[i]=(int*)malloc(2*sizeof(int));
	}*/
	
    printf("Enter the puzzle:\n 1 mean the wall, 0 mean road\n");
    for(i = 0; i < length; i++)                                                   //输入迷宫 
       for(j = 0; j < length; j++){
	   scanf("%d",&map[i][j]);
	  // path[i][j] = 0; //初始化路径数组 
	   }
       
    puzzleprocess(map, 1, 1, length);                                         //解谜 
    
	if(Judge == 0)                                                             //输出结果 
    	printf("The Maze can not be solved.\n");
	else
	printmap(map, length);
	
	
	
    for(i = 0; i < length; i++){
	free(map[i]);                                                             //释放数组内存空间 
    }
    /*for(i = 0; i < length*length; i++){
    free(path[i]);
	}
	free(path);*/
	free(map);
}


int puzzleprocess(int** Map, int currentrow, int currentcolumn, int maxrow){//递归解决迷宫 
	Map[currentrow][currentcolumn] = 2;                                      //记下当前位置  
	if(currentrow == maxrow-2&&currentcolumn == maxrow-2)return 1;           //如果迷宫走到左下角结束递归。 
	if(Map[currentrow + 1][currentcolumn] == 0)                              //判断四周为围墙还是道路。以下右上左顺序判断 
		puzzleprocess(Map, currentrow+1, currentcolumn, maxrow);
	else if(Map[currentrow][currentcolumn+1] == 0)
		puzzleprocess(Map, currentrow, currentcolumn + 1, maxrow);
	else if(Map[currentrow-1][currentcolumn] == 0)
	    puzzleprocess(Map, currentrow - 1, currentcolumn, maxrow);
	else if(Map[currentrow][currentcolumn - 1] == 0)
	    puzzleprocess(Map, currentrow, currentcolumn - 1, maxrow);
	else{
		Map[currentrow][currentcolumn] = 3;                                  //如果当前位置不能进一步向前标记此处为死路，            
		if(Map[currentrow -1][currentcolumn] == 2)                           //返回上一步。通过路径标记判断上一步
		    puzzleprocess(Map, currentrow - 1, currentcolumn, maxrow);
	    else if(Map[currentrow][currentcolumn - 1] == 2)
		    puzzleprocess(Map, currentrow, currentcolumn - 1, maxrow);
	    else if(Map[currentrow + 1][currentcolumn] == 2)
	        puzzleprocess(Map, currentrow + 1, currentcolumn, maxrow);
	    else if(Map[currentrow][currentcolumn + 1] == 2)
	        puzzleprocess(Map, currentrow, currentcolumn + 1, maxrow);
		else 	*a = 0;
	}
	
}

int printmap(int** map, int length){
	int i, j;
	for(i = 0; i < length; i++){
	    for(j = 0; j < length; j++){
	    	if(map[i][j] == 3)printf("0 ");
	    	else printf("%d ",map[i][j]);
		}
		printf("\n");
		
	}
}
















