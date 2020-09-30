#include<stdio.h>
#include<stdlib.h>


int M, L;
int order[201];
int lenth[10001];
int pieces[10001];


int DP(int num, int index)//num 为第几个喜欢的数，index代表顺序下表
{
	if (num >= M || index >= L)return 0;
	if (order[num] == pieces[index] && lenth[index] != -1)return lenth[index];
	int times = 0;
	int max = -1;
	int temp = 0;
	for (int i = index; i < L; i++)
	{
		if (order[num] == pieces[i])
		{
			++times;
			temp = times + DP(num + 1, i + 1);
			if (max < temp)
			{
				max = temp;
				lenth[index] = max;
			}
		}
	}
	return lenth[index];
}
int main()
{
	int N;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)scanf("%d", &order[i]);
	scanf("%d", &L);
	for (int i = 0; i < L; i++)scanf("%d", &pieces[i]);
	for (int i = 0; i < L; i++)lenth[i] = -1;
	printf("%d\n", DP(0, 0));
	system("pause");
	return 0;
}