/*在一个n*n的棋盘上放置n个皇后，使他们之间互相不被吃掉。（皇 后能吃掉横、竖和斜对角线方向的棋子），计算一共有多少种摆法， 并输出。
例如：
输入：
4   (n=4)
输出：
2（共有2种摆法）*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int judge(int a[],int i,int j);//判断能否摆到想摆的地方 
void place(int a[],int i,int n); //放置皇后 
int count;//全局变量保留每次调用place后的值 
int main(void)
{
	int n;
	scanf("%d",&n);
	int *a=(int*)malloc(sizeof(int)*n);//动态数组a[n]的值记录摆到列数 
	place(a,0,n);//从第一行开始放置 
	printf("%d",count);
} 
int judge(int a[],int i,int j)
{
	int k,l=1;
	for(k=0;k<i;k++){
		if(abs(i-k)==abs(j-a[k])||a[k]==j){
			l=0;break;
		}
	}
	return l;
}
void place(int a[],int i,int n)
{
	int j;
	for(j=0;j<n;j++){
		if(judge(a,i,j)){
			if(i<n-1) {
				a[i]=j;place(a,i+1,n);//令数组值为列，如果没有摆到最后一行那么递归 
			}
			else if(i==n-1)count++;//递归终止条件，摆完最后一行count+1 
		}	
	}	
}
	

