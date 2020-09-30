#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

extern int num[9][9];

int judge(void){											//用于判断此时数独是否成立 
	int i,j,k;
	int n;
	int a[9];												//记录每个九宫格 
	for(i=0;i<9;i++){										//判断橫行是否合法 
		for(j=0;j<8;j++){
			for(k=j+1;k<9;k++){
				if(num[i][j]==num[i][k]&&num[i][k]!=0)return FALSE;
			}
		}
	}
	
	
	for(i=0;i<9;i++){
		for(j=0;j<8;j++){
			for(k=j+1;k<9;k++){
				if(num[j][i]==num[k][i]&&num[k][i]!=0)return FALSE;		//判断竖行是否合法 
			}
		}
	}
	
	for(i=0;i<9;i++){		//判断每个小九宫格，用i代表第i个小九宫格，找到每个小九宫格与i的关系，并用另一个数组进行记录 
		n=0;								
		for(j=(i/3)*3;j<(i/3)*3+3;j++){
			for(k=i%3*3;k<i%3*3+3;k++){
				a[n]=num[j][k];
				n++;
			} 
		}
		for(j=0;j<8;j++)
			for(k=j+1;k<9;k++)if(a[j]==a[k]&&a[k]!=0)return FALSE;			
    }
	return TRUE;
}
