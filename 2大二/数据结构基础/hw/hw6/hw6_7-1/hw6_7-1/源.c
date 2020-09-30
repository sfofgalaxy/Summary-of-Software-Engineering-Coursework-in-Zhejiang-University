#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void BubbleSort(int *nums, int n);
void insertNode(int *heap, int *nums, int left, int right,int i,int N);
int pow2(int n);
void output(int *heap,int N);
int leftLeavesNum(int n);
int main()
{
	int i,N,num;
	scanf("%d", &N);
	int *nums = (int *)malloc(sizeof(int)*(N));
	int *heap = (int *)malloc(sizeof(int)*(N + 1));
	heap[0] = 0;
	for (i = 0; i < N; i++)scanf("%d", &nums[i]);
	BubbleSort(nums, N);
	insertNode(heap, nums, 0,N-1,1,N);
	output(heap, N);
	return 0;
}

void BubbleSort(int *nums,int n)
{
	int i,j,temp;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (nums[j] < nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

void insertNode(int *heap, int *nums, int left, int right,int i,int N)
{
	if (i > N)return;
	heap[i] = nums[right  - leftLeavesNum(right - left + 1)];
	insertNode(heap, nums, right - leftLeavesNum(right - left + 1) + 1, right, i * 2, N);
	insertNode(heap, nums, left, right - leftLeavesNum(right - left + 1) - 1, i * 2 + 1, N);
}

int pow2(int n)
{
	int s = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		s *= 2;
	}
	return s;
}

void output(int *heap,int N)
{
	int i;
	for (i = 1; i < N; i++)
	{
		printf("%d ", heap[i]);
	}
	printf("%d\n", heap[N]);
}

int leftLeavesNum(int n)
{
	if (n == 1)return 0;
	int num;
	if (n - pow2((int)log2(n + 1) - 1) - pow2((int)log2(n + 1)) + 1 >= 0)num = pow2((int)log2(n + 1)) - 1;
	else num = n - pow2((int)log2(n + 1)) + pow2((int)log2(n + 1) - 1);
	return num;
}