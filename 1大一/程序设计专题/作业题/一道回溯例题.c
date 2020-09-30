/*假设有2n个人去排队买同一种商品，该商品价值5元，其中有n个人有5元，n个人有10元（一张纸币，不能兑换），
问有多少种排队方法可令商家（商家刚开始时没有钱）当每一10元的人排到时都有零钱找。*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int count;
void place(int a[],int _2n,int m){
	int i,j,k;
	
		if(m<_2n-1&&judge(a,m,_2n)){
		place(a,_2n,m+1);a[m]=0;place(a,_2n,m+1);
	}
		else if(m<_2n-1){
		a[m]=0;place(a,_2n,m+1);
		}
		else if(m==_2n-1&&judge(a,m,_2n))count++;
	

}
int judge(int a[],int i,int _2n){
	a[i]=1;int x=0,y=0;int j;
	for(j=0;j<=i;j++){
		if(a[j]==1)x++;
		else y++;
	}
	if(x>y||x>_2n/2||y>_2n/2)return 0;
	return 1;
}
int main(void){
	int _2n;int i;
	scanf("%d",&_2n);
	int *a=(int *)malloc(sizeof(int)*_2n);
	for(i=0;i<_2n;i++){
		a[i]=-1;
	}
	place(a,_2n,0);
	printf("%d",count);
}


