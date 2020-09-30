#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */

int main()
{
    Tree T1, T2;
    T1 = BuildTree();
    T2 = BuildTree();
    printf(“%d\n”, Isomorphic(T1, T2));
    return 0;
}

int Isomorphic( Tree T1, Tree T2 ){
	Tree a1[1000],a2[1000];
	Tree temp1=T1,temp2=T2;
	int front1=0,rear1=1;
	int front2=0,rear2=1;
	int i;
	a1[0]=T1;
	a2[0]=T2;
	if(T1==NULL&&T2==NULL)return 1;
	else if((T1==NULL&&T2!=NULL)||(T1!=NULL&&T2==NULL))return 0;
	while(front1!=rear1){
		temp1 = a1[front1];
		front1++;
		if(temp1->Left!=NULL)a1[rear1++]=temp1->Left;
		if(temp1->Right!=NULL)a1[rear1++]=temp1->Right;
	}
	while(front2!=rear2){
		temp2 = a2[front2];
		front2++;
		if(temp2->Right!=NULL)a2[rear2++]=temp2->Right;
		if(temp2->Left!=NULL)a2[rear2++]=temp2->Left;
	}
	if(rear1!=rear2)return 0;
	for(i=0;i<rear1;i++){
		if(a1[i]->Element!=a2[i]->Element)return 0;
	}
	return 1;
}