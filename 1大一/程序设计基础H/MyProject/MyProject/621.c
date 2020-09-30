/*柱状图是一种显示每个区间内出现数据的频率的图，例如，对于下面的一组成绩：
100,95,47,88,86,92,75,89，81,70,55,80。在计算机中产生柱状图如下：
    0-9  |
    10-19|
    20-29|
    30-39|
    40-49| *
    50-59| *
    60-69|
    70-79| * *
    80-89| * * * * *
    90-99| * *
    100  | *
    输入一个正整数looptimes, 做looptimes次重复操作，在每一次中输入一组数据（以小于0的数结束），输出该数组的柱状图。

    输入输出示例：
    输入
    1
    100 95 47 88 86 92 75 89 81 70 55 80 -1
    输出
    0 -9 |
    10-19|
    20-29|
    30-39|
    40-49| *
    50-59| *
    60-69|
    70-79| * *
    80-89| * * * * *
    90-99| * *
    100  | *
	*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{   	    
    int looptimes = 0;          
    int grades[100];          
    int i,j,k;
    int counts[12];
    scanf("%d" ,&looptimes );
    for(i = 0; i < looptimes; i++){
      for(k=0;k<12;k++){
      	counts[k]=0;
      }
	 j=0;scanf("%d",&grades[0]);
    while(grades[j]>=0){
	switch(grades[j]/10){
		case 0:counts[0]++;break;
		case 1:counts[1]++;break;
		case 2:counts[2]++;break;
		case 3:counts[3]++;break;
		case 4:counts[4]++;break;
		case 5:counts[5]++;break;
		case 6:counts[6]++;break;
		case 7:counts[7]++;break;
		case 8:counts[8]++;break;
		case 9:counts[9]++;break;
		case 10:counts[10]++;break;
	}
	
	j++;
    	scanf("%d",&grades[j]);
    
    }                    
    	for(k = 0; k < 12; k++){         
    	switch(k){
    		case 0:printf("0 -9 |");break;
    		case 1:printf("10-19|");break;
    		case 2:printf("20-29|");break;
    		case 3:printf("30-39|");break;
    		case 4:printf("40-49|");break;
    		case 5:printf("50-59|");break;
    		case 6:printf("60-69|");break;
    		case 7:printf("70-79|");break;
    		case 8:printf("80-89|");break;
    		case 9:printf("90-99|");break;
    		case 10:printf("100  |");break;
				
    	}
    	while(counts[k] > 0){printf(" *");counts[k]--;}     
    	printf("\n");
    }
    }
    return 0;
 }
