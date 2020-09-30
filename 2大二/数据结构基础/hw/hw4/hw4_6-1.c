#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
	ElementType Element;
	Tree  Left;
	Tree  Right;
};


Tree BuildTree() {
	Tree root = (Tree)malloc(sizeof(struct TreeNode));
	root->Left =      
}
void PrintNode(Tree NodePtr)
{
	printf(" %d", NodePtr->Element);
}

void Level_order(Tree T, void(*visit)(Tree ThisNode));

int main()
{
	Tree T = BuildTree();
	printf("Level-order:");
	Level_order(T, PrintNode);
	return 0;
}

void Level_order(Tree T, void(*visit)(Tree ThisNode)){
	Tree a[MaxTree];Tree temp=T;
	if(T==NULL)return;
	a[0]=T;
	int front=0,rear=1;
	while(front!=rear){
		temp = a[front];
		visit(temp);
		front++;
		if(temp->Left!=NULL)a[rear++]=temp->Left;
		if(temp->Right!=NULL)a[rear++]=temp->Right;
	}
}