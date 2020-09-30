#include <stdio.h>
#include <stdlib.h> 
int puzzleprocess(int** Map, int currentrow, int currentcolumn, int maxrow);      //�Թ�������� 
int printmap(int** map, int length);                                              //��ӡ�Թ�����  
int Judge = 1;                                                                    //�����ж��Ƿ��н� 
int *a = &Judge;
	
int main(int argc, char** argv) {
	int i, j, length;
	
	printf("Enter the length :");                                                 //�����Թ��߳� 
	scanf("%d",&length);      
	int ** map;                                                                   //�����ά�����ʾ�Թ���1����Χǽ��0��������ߵ�· 
 
    map = (int**)malloc(length*sizeof(int*));
	for(i = 0; i < length; i++){                                                   //Ϊ��ά�������ռ� 
    map[i]=(int*)malloc(length*sizeof(int));
	}
	/*	int** path; 
	path = (int**)malloc(length*length*sizeof(int*)); 
	
	for(int i=0;i<length*length;i++){  
    path[i]=(int*)malloc(2*sizeof(int));
	}*/
	
    printf("Enter the puzzle:\n 1 mean the wall, 0 mean road\n");
    for(i = 0; i < length; i++)                                                   //�����Թ� 
       for(j = 0; j < length; j++){
	   scanf("%d",&map[i][j]);
	  // path[i][j] = 0; //��ʼ��·������ 
	   }
       
    puzzleprocess(map, 1, 1, length);                                         //���� 
    
	if(Judge == 0)                                                             //������ 
    	printf("The Maze can not be solved.\n");
	else
	printmap(map, length);
	
	
	
    for(i = 0; i < length; i++){
	free(map[i]);                                                             //�ͷ������ڴ�ռ� 
    }
    /*for(i = 0; i < length*length; i++){
    free(path[i]);
	}
	free(path);*/
	free(map);
}


int puzzleprocess(int** Map, int currentrow, int currentcolumn, int maxrow){//�ݹ����Թ� 
	Map[currentrow][currentcolumn] = 2;                                      //���µ�ǰλ��  
	if(currentrow == maxrow-2&&currentcolumn == maxrow-2)return 1;           //����Թ��ߵ����½ǽ����ݹ顣 
	if(Map[currentrow + 1][currentcolumn] == 0)                              //�ж�����ΪΧǽ���ǵ�·������������˳���ж� 
		puzzleprocess(Map, currentrow+1, currentcolumn, maxrow);
	else if(Map[currentrow][currentcolumn+1] == 0)
		puzzleprocess(Map, currentrow, currentcolumn + 1, maxrow);
	else if(Map[currentrow-1][currentcolumn] == 0)
	    puzzleprocess(Map, currentrow - 1, currentcolumn, maxrow);
	else if(Map[currentrow][currentcolumn - 1] == 0)
	    puzzleprocess(Map, currentrow, currentcolumn - 1, maxrow);
	else{
		Map[currentrow][currentcolumn] = 3;                                  //�����ǰλ�ò��ܽ�һ����ǰ��Ǵ˴�Ϊ��·��            
		if(Map[currentrow -1][currentcolumn] == 2)                           //������һ����ͨ��·������ж���һ��
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
















