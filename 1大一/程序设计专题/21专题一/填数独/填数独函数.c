#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

extern int num[9][9];

void fill_num(int x, int y){						//�������������ݹ�		
	int i;
	if(x==8&&y==8&&num[x][y]!=0)produce_sudoku();		//�������һ������������� 
	else if(x==8&&y==8&&num[x][y]==0){
		for(i=1;i<=9;i++){
			num[x][y]=i;
			if(judge()==TRUE)produce_sudoku();
			else num[x][y]=0;
		}
		if(i==10)num[x][y]=0;
	}
	
	 
	else if(x!=8&&y==8&&num[x][y]!=0)fill_num(x+1,0);			//����ÿ�����һ�б�ת����һ�� 
	else if(x!=8&&y==8&&num[x][y]==0){
		for(i=1;i<=9;i++){
			num[x][y]=i;
			if(judge()==TRUE)fill_num(x+1,0);
			else num[x][y]=0;
		}
		if(i==10)num[x][y]=0;
	}
	
	
	
	else if(num[x][y]==0){										//��������������һ������ 
		for(i=1;i<=9;i++){
			num[x][y]=i;
			if(judge()==TRUE)fill_num(x,y+1);
			else num[x][y]=0;
		}
		if(i==10)num[x][y]=0;
	}
	else if(num[x][y]!=0)fill_num(x,y+1);
}
