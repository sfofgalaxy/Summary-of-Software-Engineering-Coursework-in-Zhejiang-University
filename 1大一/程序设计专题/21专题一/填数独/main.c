#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

int num[9][9];						//储存数独 
int count;							//记录解法个数 

int main(void)
{	
	int i,j;
	int flag=1;
	printf("请输入数独9*9（0代表未填数字）：\n");
	for(i=0;i<9;i++)
		for(j=0;j<9;j++){
			scanf("%d",&num[i][j]);
			if(num[i][j]>9||num[i][j]<0)flag=0;
		}
	printf("\n");
	while(flag==0||judge()==FALSE){
		printf("数独输入不合法，请重新输入：\n");
		flag=1;
		for(i=0;i<9;i++)
		for(j=0;j<9;j++){
			scanf("%d",&num[i][j]);
			if(num[i][j]>9||num[i][j]<0)flag=0;
		}
		printf("\n");
	}
	fill_num(0,0);					//从第一个开始填 
	if(count>=1)printf("数独解法如上，有%d种解法",count);
	else printf("该数独无解"); 
}
