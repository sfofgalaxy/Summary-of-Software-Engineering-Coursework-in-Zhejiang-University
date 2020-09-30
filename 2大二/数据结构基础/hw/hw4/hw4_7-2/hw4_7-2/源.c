#include <stdio.h>
#include <stdlib.h>


/*用结构数组 先根据编号把所有节点记录，且仅记录父亲
	输出时仅判断其是否做父亲 和 前X代是根
	tree的Index代表其ID
*/
struct Nodes
{
	int IsDad;//是否做父亲
	int Gnrton;//第几代
	int Dad;//爹是谁，初始为-1
};


int main(void) 
{
	int GnrtonNum[100] = { 0 };
	int N, M, K, DadID, ID, nums, index, temp, MaxGnrton = 1;
	int i, j;
	struct Nodes *tree;
	scanf("%d %d", &N,&M);
	while (N)
	{
		for (i = 0; i++; i < 100)GnrtonNum[i] = 0;


		index = 1;//从1开始记录儿子，0为root
		tree = (struct Nodes *)malloc(sizeof(struct Nodes)*(N+1));
		for (i = 0; i < N+1; i++)
		{
			tree[i].Dad = -1;
			tree[i].Gnrton = 1;
			tree[i].IsDad = 0;
		}

		//数组建树
		for (i = 1; i <= M; i++) 
		{
			scanf("%d %d", &DadID,&nums);
			for (j = 1; j <= nums; j++) 
			{
				scanf(" %d", &ID);
				tree[ID].Dad = DadID;
			}
		}
		
		//处理树，数叶子
		for (i = 1; i < N+1; i++)
		{
			temp = i;
			while (tree[temp].Dad != -1) {
				tree[i].Gnrton++;
				if (tree[i].Gnrton >= MaxGnrton)MaxGnrton = tree[i].Gnrton;
				temp = tree[temp].Dad;
				tree[temp].IsDad = 1;
			}
		}

		for (i = 1; i < N+1; i++)
		{
			if (!(tree[i].IsDad))
			{
				GnrtonNum[tree[i].Gnrton]++;
			}
		}

		for (i = 1; i < MaxGnrton; i++)printf("%d ", GnrtonNum[i]);
		printf("%d", GnrtonNum[MaxGnrton]);
		
		
		free(tree);
		scanf("%d %d", &N, &M);
	}








	return 0;
}