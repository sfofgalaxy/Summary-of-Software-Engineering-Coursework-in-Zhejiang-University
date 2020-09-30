#include<stdio.h>
#include<stdlib.h>

//注意事项：
//1.未提交过结果为 - 
//2.提交过但未通过编译器或得分为零输出 0
//3.未提交过能通过编译器的不出现在排名上

typedef struct result
{
	//根据前三个排序，排序时交换信息
	int marks;//未提交过能通过编译器的该值设为-1
	int perfect_solve_nums;
	int ID;

	int rank;
};

void rank_sort(struct result *rslt, int **mark, int N);//给相同分数排名排序
void output(struct result *rslt, int **mark, int N, int K);//输出
void Msort(struct result A[], struct result TmpA[], int L, int RightEnd);
void Merge(struct result A[], struct result TmpA[], int L, int R, int RightEnd);


int main()
{
	//定义所有所需变量并输入
	int i, j, N, K, M, flag, total, id, problem_id, marks;
	scanf("%d %d %d", &N, &K, &M);

	int *p = (int *)malloc(sizeof(int)*(K + 1));
	for (i = 1; i <= K; i++)scanf("%d", &p[i]);

	int **mark = (int **)malloc(sizeof(int *)*(N + 1));
	for (i = 1; i <= N; i++)mark[i] = (int *)malloc(sizeof(int)*(K + 1));

	struct result *rslt = (struct result *)malloc(sizeof(struct result)*(N + 1));

	//初始化
	for (i = 1; i <= N; i++)
	{
		rslt[i].ID = i;
		rslt[i].marks = -1;//代表不显示，排序时将mark为-1的排在最前，然后略过
		rslt[i].perfect_solve_nums = 0;
		rslt[i].rank = 0;	//不显示的排名就是0，输出时从1开始输出
		for (j = 1; j <= K; j++)mark[i][j] = -2;//mark为-2代表未提交过，显示“-”
	}

	for (i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &id, &problem_id, &marks);
		if (marks > mark[id][problem_id])mark[id][problem_id] = marks;
	}

	//将基本信息录入到rslt中
	for (i = 1; i <= N; i++)
	{
		total = 0;
		flag = 0;//记录是否有通过编译器的提交
		for (j = 1; j <= K; j++) {
			if (mark[i][j] >= 0) {
				total += mark[i][j];
				flag = 1;
				if (mark[i][j] == p[j])rslt[i].perfect_solve_nums++;
			}
		}
		if (flag)rslt[i].marks = total;
	}

	//按分数排序
	struct result *TmpA;
	TmpA = (struct result *)malloc((N + 1) * sizeof(struct result));
	Msort(rslt, TmpA, 1, N);

	/*for (i = 1; i <= N; i++) {
		printf("%d %d %d %d\n", rslt[i].ID, rslt[i].marks, rslt[i].perfect_solve_nums, rslt[i].rank);
		for (j = 1; j <= K; j++)printf("%d ", mark[i][j]);
		printf("\n");
	}*/
	
	//把rank排出
	rank_sort(rslt, mark, N);

	//输出
	output(rslt, mark, N, K);
}

//处理分数相同的顺序与rank

void rank_sort(struct result *rslt, int **mark, int N)
{
	int i, j, k, left, right, num = 1, rank = 1;
	struct result temp;

	for (i = 1; i <= N; i = right + 1)
	{
		if (rslt[i].marks == -1)break;
		rank = num;
		right = left = i;
		//处理rank
		for (j = left; rslt[j].marks == rslt[j + 1].marks; j++)
		{
			num++;
			rslt[j + 1].rank = rank;
			right++;
		}
		num++;
		rslt[left].rank = rank;

		//处理完美解决问题个数以及ID排序
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