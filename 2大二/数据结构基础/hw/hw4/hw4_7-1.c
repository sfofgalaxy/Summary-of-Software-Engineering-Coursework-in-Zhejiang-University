#include <stdio.h>
#include <stdlib.h>

struct mystruct
{
	int num;
	int Right;
	int Left;
	int Dad;
	int flag;
};

typedef struct mystruct *Tree;


int main(){
	int i,N,num,last=0,this=0,operation=0;
	int flag=0;
	char ch[5];
	scanf("%d",&N);
	Tree tree=(Tree)malloc(sizeof(struct mystruct)*N);
	//初始化
	for(i=0;i<N;i++){
		(tree[i]).num=0;	
		(tree[i]).Left=-1;
		(tree[i]).Right=-1;
		(tree[i]).Dad=-1;
		(tree[i]).flag=0;
	}
	//将树储存在一个数组中
		scanf("%s",ch);
		scanf("%d",&num);
		(tree[0]).num=num;
	for(i=1;i<2*N;i++){ 
		scanf("%s",ch);
		if(strcmp(ch,"Push")==0){
			scanf("%d",&num);
			this++;
			(tree[this]).num=num;
			(tree[this]).Dad = last;
			if((tree[last]).flag)(tree[last]).Right=this;
			else (tree[last]).Left=this;
			last = this;
		}
		else{
			if((tree[last]).flag){
				while((tree[last]).flag)last = (tree[last]).Dad;
				(tree[last]).flag=1;
			}
			(tree[last]).flag=1;
		}	
	}
	
	for(i=0;i<N;i++)printf("%d\n",(tree[i]).num);
	printf("\n");
	for(i=0;i<N;i++)printf("%d\n",(tree[i]).Left);
	printf("\n");
	for(i=0;i<N;i++)printf("%d\n",(tree[i]).Right);
	printf("\n");
	for(i=0;i<N;i++)printf("%d\n",(tree[i]).Dad);
	
	this = last=0;
	//输出
	//operation中：
	//0代表从父亲到右儿子；1代表从父亲到左儿子；2代表从左儿子到父亲；3代表从右儿子到父亲
	for(;1;){
		if(operation==0||operation==1){
			if((tree[this]).Left!=-1){
				this=(tree[this]).Left;
				operation = 1;
			}
			else if((tree[this]).Right!=-1){
				this=(tree[this]).Right;
				operation = 0;
			}
			else{
				if(this==0){
					printf("%d", (tree[this]).num);
					break;
				}
				printf("%d ",(tree[this]).num);
				this = (tree[this]).Dad;
				if(operation==0)operation=3;
				else if(operation==1)operation=2;
			}
		}
		
		
		else if(operation==2){
			if((tree[this]).Right!=-1){
				this = (tree[this]).Right;
				operation=0;
			}
			else {
				if(this==0){
					printf("%d", (tree[this]).num);
					break;
				}
				printf("%d ", (tree[this]).num);
				if((tree[(tree[this]).Dad]).Right==this)operation=3;
				else operation=2;
				this = (tree[this]).Dad;
			}
		}
		else if(operation==3){
			if(this==0){
				printf("%d", (tree[this]).num);
				break;
			}
			printf("%d ", (tree[this]).num);
			if((tree[(tree[this]).Dad]).Right==this)operation=3;
			else operation=2;
			this = (tree[this]).Dad;
		}
	}
}

