#include<stdio.h>
#include<time.h>
#include<memory.h>
#include<stdlib.h>

#define N 100000

int number[N];
int hash[1005];
int main(){
	FILE *fp;
	fp=fopen("test2.txt","w");
	if(fp==NULL){
		puts("ERROR");
		return -1;
	}
	int num=50,i,j,m,temp,sit,n;
	srand((unsigned)time(NULL));
	//num控制测试总组数 
	while(num--){
		memset(hash,-1,1005*sizeof(int));
		memset(number,0,N*sizeof(int));
		//m控制 第一个数 ,建议取10,方便调试 
		//m=rand()%1000+1;
		m=10;
		fprintf(fp,"%d\n",m);
		n=1;
		if(m!=1)	n=rand()%(m/2)+(m/2)+1;
		for(i=0;i<n;i++){
			temp=rand()%N;
			while(number[temp]==1){
				temp=rand()%N;
			}
			//printf("%d ",temp);
			number[temp]=1;
			sit=temp%m;
			while(hash[sit]!=-1){
				sit=(sit+1)%m;
			}
			hash[sit]=temp;
		}
		//puts("");
		for(i=0;i<m;i++){
			fprintf(fp,"%d ",hash[i]);
		}
		fprintf(fp,"\n");
	}
	return 0;
}
