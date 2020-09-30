#include <stdio.h>
#include <stdlib.h>

extern int num[9][9];
extern int count;

void produce_sudoku(void){							//Êä³öÊı¶À 
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++)printf("%d ",num[i][j]);
		printf("\n");
	}
	count++;
	printf("\n");

}
