#include <stdio.h>
#include <stdlib.h>


/*�ýṹ���� �ȸ��ݱ�Ű����нڵ��¼���ҽ���¼����
	���ʱ���ж����Ƿ������� �� ǰX���Ǹ�
	tree��Index������ID
*/
struct Nodes
{
	int IsDad;//�Ƿ�������
	int Gnrton;//�ڼ���
	int Dad;//����˭����ʼΪ-1
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


		index = 1;//��1��ʼ��¼���ӣ�0Ϊroot
		tree = (struct Nodes *)malloc(sizeof(struct Nodes)*(N+1));
		for (i = 0; i < N+1; i++)
		{
			tree[i].Dad = -1;
			tree[i].Gnrton = 1;
			tree[i].IsDad = 0;
		}

		//���齨��
		for (i = 1; i <= M; i++) 
		{
			scanf("%d %d", &DadID,&nums);
			for (j = 1; j <= nums; j++) 
			{
				scanf(" %d", &ID);
				tree[ID].Dad = DadID;
			}
		}
		
		//����������Ҷ��
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