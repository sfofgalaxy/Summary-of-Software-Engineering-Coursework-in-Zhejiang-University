/*������2n����ȥ�Ŷ���ͬһ����Ʒ������Ʒ��ֵ5Ԫ��������n������5Ԫ��n������10Ԫ��һ��ֽ�ң����ܶһ�����
���ж������Ŷӷ��������̼ң��̼Ҹտ�ʼʱû��Ǯ����ÿһ10Ԫ�����ŵ�ʱ������Ǯ�ҡ�*/

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


