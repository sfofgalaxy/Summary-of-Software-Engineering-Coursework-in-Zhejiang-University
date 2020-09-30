#include<stdio.h>
#include<stdlib.h>

//ע�����
//1.δ�ύ�����Ϊ - 
//2.�ύ����δͨ����������÷�Ϊ����� 0
//3.δ�ύ����ͨ���������Ĳ�������������

typedef struct result
{
	//����ǰ������������ʱ������Ϣ
	int marks;//δ�ύ����ͨ���������ĸ�ֵ��Ϊ-1
	int perfect_solve_nums;
	int ID;

	int rank;
};

void rank_sort(struct result *rslt, int **mark, int N);//����ͬ������������
void output(struct result *rslt, int **mark, int N, int K);//���
void Msort(struct result A[], struct result TmpA[], int L, int RightEnd);
void Merge(struct result A[], struct result TmpA[], int L, int R, int RightEnd);


int main()
{
	//���������������������
	int i, j, N, K, M, flag, total, id, problem_id, marks;
	scanf("%d %d %d", &N, &K, &M);

	int *p = (int *)malloc(sizeof(int)*(K + 1));
	for (i = 1; i <= K; i++)scanf("%d", &p[i]);

	int **mark = (int **)malloc(sizeof(int *)*(N + 1));
	for (i = 1; i <= N; i++)mark[i] = (int *)malloc(sizeof(int)*(K + 1));

	struct result *rslt = (struct result *)malloc(sizeof(struct result)*(N + 1));

	//��ʼ��
	for (i = 1; i <= N; i++)
	{
		rslt[i].ID = i;
		rslt[i].marks = -1;//������ʾ������ʱ��markΪ-1��������ǰ��Ȼ���Թ�
		rslt[i].perfect_solve_nums = 0;
		rslt[i].rank = 0;	//����ʾ����������0�����ʱ��1��ʼ���
		for (j = 1; j <= K; j++)mark[i][j] = -2;//markΪ-2����δ�ύ������ʾ��-��
	}

	for (i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &id, &problem_id, &marks);
		if (marks > mark[id][problem_id])mark[id][problem_id] = marks;
	}

	//��������Ϣ¼�뵽rslt��
	for (i = 1; i <= N; i++)
	{
		total = 0;
		flag = 0;//��¼�Ƿ���ͨ�����������ύ
		for (j = 1; j <= K; j++) {
			if (mark[i][j] >= 0) {
				total += mark[i][j];
				flag = 1;
				if (mark[i][j] == p[j])rslt[i].perfect_solve_nums++;
			}
		}
		if (flag)rslt[i].marks = total;
	}

	//����������
	struct result *TmpA;
	TmpA = (struct result *)malloc((N + 1) * sizeof(struct result));
	Msort(rslt, TmpA, 1, N);

	/*for (i = 1; i <= N; i++) {
		printf("%d %d %d %d\n", rslt[i].ID, rslt[i].marks, rslt[i].perfect_solve_nums, rslt[i].rank);
		for (j = 1; j <= K; j++)printf("%d ", mark[i][j]);
		printf("\n");
	}*/
	
	//��rank�ų�
	rank_sort(rslt, mark, N);

	//���
	output(rslt, mark, N, K);
}

//���������ͬ��˳����rank

void rank_sort(struct result *rslt, int **mark, int N)
{
	int i, j, k, left, right, num = 1, rank = 1;
	struct result temp;

	for (i = 1; i <= N; i = right + 1)
	{
		if (rslt[i].marks == -1)break;
		rank = num;
		right = left = i;
		//����rank
		for (j = left; rslt[j].marks == rslt[j + 1].marks; j++)
		{
			num++;
			rslt[j + 1].rank = rank;
			right++;
		}
		num++;
		rslt[left].rank = rank;

		//�������������������Լ�ID����
		for (k = 1; k <= right - left; k++)
		{
			for (j = left; j < right; j++)
			{
				if (rslt[j].perfect_solve_nums < rslt[j + 1].perfect_solve_nums)
				{
					temp = rslt[j + 1];
					rslt[j + 1] = rslt[j];
					rslt[j] = temp;
				}

				else if (rslt[j].perfect_solve_nums == rslt[j + 1].perfect_solve_nums&&rslt[j].ID > rslt[j + 1].ID)
				{
					temp = rslt[j + 1];
					rslt[j + 1] = rslt[j];
					rslt[j] = temp;
				}
			}
		}
	}
}

void output(struct result *rslt, int **mark, int N, int K)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		if (rslt[i].marks < 0)break;
		printf("%d %05d %d", rslt[i].rank, rslt[i].ID, rslt[i].marks);
		for (j = 1; j <= K; j++)
		{	
			if (mark[rslt[i].ID][j] == -2)printf(" -");
			else if (mark[rslt[i].ID][j] == -1)printf(" 0");
			else printf(" %d", mark[rslt[i].ID][j]);
		}
		printf("\n");
	}
	return;
}

void Merge(struct result A[], struct result TmpA[], int L, int R, int RightEnd)
{ 
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; 
	Tmp = L;         
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L].marks >= A[R].marks)
			TmpA[Tmp++] = A[L++]; 
		else
			TmpA[Tmp++] = A[R++]; 
	}

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++]; 
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; 
}

void Msort(struct result A[], struct result TmpA[], int L, int RightEnd)
{ 
	int Center;

	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, Center);            
		Msort(A, TmpA, Center + 1, RightEnd);     
		Merge(A, TmpA, L, Center + 1, RightEnd);  
	}
}