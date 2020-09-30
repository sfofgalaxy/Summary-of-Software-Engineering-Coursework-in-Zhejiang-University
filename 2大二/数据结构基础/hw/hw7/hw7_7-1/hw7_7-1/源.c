#include <stdio.h>
#include <stdlib.h>

void merge_pass(int list[], int sorted[], int N, int length);
void insert_pass(int list[], int index);

void output(int list[], int N)
{
	int i;
	for (i = 0; i<N-1; i++) printf("%d ", list[i]);
	printf("%d\n", list[i]);
}

int  merge_sort(int list[], int compare[], int N)
{
	int i,flag=1;
	int extra[200];
	int  length=1;  

	while (length < N) {
		flag = 1;

		merge_pass(list, extra, N, length);
		for (i = 0; i < N; i++)if (extra[i] != compare[i])flag = 0;
		if (flag) {
			printf("Merge Sort\n");
			merge_pass(extra, list, N, length * 2);
			output(list, N);
			return 1;
		}

		length *= 2;
		flag = 1;

		merge_pass(extra, list, N, length);
		for (i = 0; i < N; i++)if (list[i] != compare[i])flag = 0;
		if (flag) {
			printf("Merge Sort\n");
			merge_pass(list, extra, N, length * 2);
			output(extra, N);
			return 1;
		}

		length *= 2;
	}
	return 0;
}


void insert_sort(int list[], int compare[], int N)
{
	int i, j, flag = 1;
	for (i = 1; i < N; i++)
	{
		flag = 1;
		insert_pass(list, i);
			for (j = 0; j < N; j++)if (list[j] != compare[j])flag = 0;
			if (flag) {
				printf("Insertion Sort\n");
				insert_pass(list, i + 1);
				output(list, N);
				return;
			}
	}
}

int main()
{
	int N, i;
	int initial[200];
	int merge[200];
	int compare[200];
	int insert[200];
	scanf("%d", &N);
	for (i = 0; i < N; i++)scanf("%d", &initial[i]);
	for (i = 0; i < N; i++)scanf("%d", &compare[i]);
	for (i = 0; i < N; i++)
	{
		merge[i] = initial[i];
		insert[i] = initial[i];
	}
	if(merge_sort(merge, compare, N));

	else insert_sort(insert,compare,N);

	return 0;
}

void merge_pass(int list[], int sorted[], int N, int length)
{
	int i;
	int left, right, new = 0;
	for (i = 0; new < N; i += 2 * length)
	{
		left = i;
		right = i + length;
		new = i;
		while (right<i + 2 * length&&right<N&&left<i + length)
		{
			if (list[right]<list[left])
				sorted[new ++] = list[right++];
			else
				sorted[new ++] = list[left++];
		}
		while (right<length * 2 + i && right<N)
			sorted[new ++] = list[right++];
		while (left<length + i)
			sorted[new ++] = list[left++];
	}
}

void insert_pass(int list[], int index)
{
	int i;
	int temp = list[index];
	for (i = index - 1; i >= 0; i--) {
		if (temp < list[i])list[i + 1] = list[i];
		else break;
	}
	list[i + 1] = temp;
}