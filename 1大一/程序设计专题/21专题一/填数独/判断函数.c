#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

extern int num[9][9];

int judge(void){											//�����жϴ�ʱ�����Ƿ���� 
	int i,j,k;
	int n;
	int a[9];												//��¼ÿ���Ź��� 
	for(i=0;i<9;i++){										//�жϙM���Ƿ�Ϸ� 
		for(j=0;j<8;j++){
			for(k=j+1;k<9;k++){
				if(num[i][j]==num[i][k]&&num[i][k]!=0)return FALSE;
			}
		}
	}
	
	
	for(i=0;i<9;i++){
		for(j=0;j<8;j++){
			for(k=j+1;k<9;k++){
				if(num[j][i]==num[k][i]&&num[k][i]!=0)return FALSE;		//�ж������Ƿ�Ϸ� 
			}
		}
	}
	
	for(i=0;i<9;i++){		//�ж�ÿ��С�Ź�����i�����i��С�Ź����ҵ�ÿ��С�Ź�����i�Ĺ�ϵ��������һ��������м�¼ 
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
