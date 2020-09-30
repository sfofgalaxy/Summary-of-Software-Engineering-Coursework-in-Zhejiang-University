#include<stdio.h>
#include<stdlib.h>
#define Null -1
//define struct Tree
typedef struct Tree{
	int Element;
	int Left;
	int Right;
}BTree;
int *a;
BTree *T;
void ArraySort(int *a,int n)//define a function to sort the element and get the result of Inorder Traversal
{
  int temp = 0;
  for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void insert(BTree *s,int n)//define a function to insert values into Binary Search Tree
{
	int b[n];
	int Flag=0;
	int top=0;
	int Temp=0;
	while(top || Flag!=Null)
   {
	  while(Flag!=Null)
	    {
		    b[top++]=Flag;
		    Flag=s[Flag].Left;
	    }
	    Flag=b[--top];
	    s[Flag].Element=a[Temp++];
	    if(Flag!=Null)
	    {
	    	Flag=s[Flag].Right;
		}
   }
}
void levelOrder(BTree *T1,BTree *T2,int n)//define a function to output the level order traversal sequence of the Binary Search Tree
{
	int Flag=0;
	T2[0]=T1[0];
	int Front=0;
	int Rear=1;
	while(Front!=Rear)
	{
		Flag=T2[Front].Left;
		if(Flag!=Null)
		{
			T2[Rear++]=T1[Flag];
		    
	    }
		Flag=T2[Front++].Right;
		if(Flag!=Null)
		{
		   T2[Rear++]=T1[Flag];
	    }
	}
	printf("The result :");
	for(int i=0; i<n; i++)
	{
		if(i!=n-1)
		{
			printf("%d ",T2[i].Element);
		}
		else
		{
			printf("%d",T2[i].Element);
		}
	}
	printf("\n");
}

int main(void)
{
	int i,N,left,right,repeattimes;//input 
	printf("Please input the run times that you want£º");
	scanf("%d",&repeattimes);
	for(i=1;i<=repeattimes;i++)
	{
	printf("Please input statics:\n");
	scanf("%d",&N);
	BTree BST1[N],BST2[N];
	a = (int *)malloc(sizeof(int)*N);
	for(int i=0; i<N; i++)
	{
		scanf("%d %d",&left,&right);
		BST1[i].Left=left;
		BST1[i].Right=right;
	}//bulid the Binary Search Tree
	for(int i=0; i<N; i++)
	{
		scanf("%d",&a[i]);
	}//input the orginal sequence
	ArraySort(a,N);
	insert(BST1,N);
    levelOrder(BST1,BST2,N);
	}
    system("pause");
}
    
