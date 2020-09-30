#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

extern int num[9][9];

void fill_num(int x, int y){						//填数独函数，递归		
	int i;
	if(x==8&&y==8&&num[x][y]!=0)produce_sudoku();		//填完最后一个数便输出数独 
	else if(x==8&&y==8&&num[x][y]==0){
		for(i=1;i<=9;i++){
			num[x][y]=i;
			if(judge()==TRUE)produce_sudoku();
			else num[x][y]=0;
		}
		if(i==10)num[x][y]=0;
	}
	
	 
	else if(x!=8&&y==8&&num[x][y]!=0)fill_num(x+1,0);			//填完每行最后一列便转入下一列 
	else if(x!=8&&y==8&&num[x][y]==0){
		for(i=1;i<=9;i++){
			num[x][y]=i;
			if(judge()==TRUE)fill_num(x+1,0);
			else num[x][y]=0;
		}
		if(i==10)num[x][y]=0;
	}
	
	
	
	else if(num[x][y]==0){										//其他情况便填本行下一列数字 
		for(i=1;i<=9;i++){
			num[x][y]=i;
			if(judge()==TRUE)fill_num(x,y+1);
			else num[x][y]=0;
		}
		if(i==10)num[x][y]=0;
	}
	else if(num[x][y]!=0)fill_num(x,y+1);
}
