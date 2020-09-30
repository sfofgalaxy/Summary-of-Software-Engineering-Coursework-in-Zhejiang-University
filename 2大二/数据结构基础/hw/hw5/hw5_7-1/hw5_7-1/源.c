#include <stdio.h>
#include <stdlib.h>

struct Tree
{
	int Value;
	int Left;
	int Right;
};

void insert(struct Tree *tree, int num, int current, int i)
{
	if (current!=-1)
	{
		if (num > tree[current].Value)
		{
			insert(tree, num, tree[current].Right, i);
			if (tree[current].Right == -1)tree[current].Right = i;
		}
		else
		{
			insert(tree, num, tree[current].Left, i);
			if (tree[current].Left == -1)tree[current].Left = i;
		}
	}

	else tree[i].Value = num;
}

struct Tree *BuildTree(struct Tree *root, int N)
{
	int i, num;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if(i==0)root[0].Value = num;
		else insert(root, num, 0, i);
	}
	return root;
}

int compare(struct Tree *T1, struct Tree *T2, int i,int j)
{
	if (i!=-1)
	{
		if (T1[i].Value == T2[j].Value&&compare(T1, T2, T1[i].Left,T2[j].Left) && compare(T1, T2, T1[i].Right,T2[j].Right))return 1;
		else return 0;
	}
	return 1;
}
int main()
{
	int N, L, i, j, flag;
	scanf("%d", &N);
	struct Tree **treenode;
	while (N)
	{
		scanf("%d", &L);
		//构建L*N数组
		treenode = (struct Tree **)malloc(sizeof(struct Tree *)*(L+1));
		for (i = 0; i<=L; i++)treenode[i] = (struct Tree *)malloc(sizeof(struct Tree)*N);

		//初始化
		for (i = 0; i <= L; i++)
		{
			for (j = 0; j < N; j++)
			{
				treenode[i][j].Left = -1;
				treenode[i][j].Right = -1;
				treenode[i][j].Value = 0;
			}
		}

		//建立L棵树
		for (i = 0; i<=L; i++)
		{
			treenode[i] = BuildTree(treenode[i], N);
			//for (j = 0; j < N; j++)printf("%d %d %d\n", treenode[i][j].Value, treenode[i][j].Left, treenode[i][j].Right);
			if (i>0)
			{
				flag = compare(treenode[0], treenode[i], 0,0);
				if (flag)printf("Yes\n");
				else printf("No\n");
			}
		}


		//释放空间
		for (i = 0; i <= L; i++)free(treenode[i]);
		free(treenode);

		scanf("%d", &N);
	}
}