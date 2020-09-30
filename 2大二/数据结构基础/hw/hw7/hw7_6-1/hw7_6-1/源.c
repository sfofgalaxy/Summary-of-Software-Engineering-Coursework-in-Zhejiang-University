#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass(ElementType list[], ElementType sorted[], int N, int length);

void output(ElementType list[], int N)
{
	int i;
	for (i = 0; i<N; i++) printf("%d ", list[i]);
	printf("\n");
}

void  merge_sort(ElementType list[], int N)
{
	ElementType extra[MAXN];  /* the extra space required */
	int  length = 1;  /* current length of sublist being merged */
	while (length < N) {
		merge_pass(list, extra, N, length); /* merge list into extra */
		output(extra, N);
		length *= 2;
		merge_pass(extra, list, N, length); /* merge extra back to list */
		output(list, N);
		length *= 2;
	}
}


int main()
{
	int N, i;
	ElementType A[MAXN];

	scanf("%d", &N);
	for (i = 0; i<N; i++) scanf("%d", &A[i]);
	merge_sort(A, N);
	output(A, N);

	return 0;
}

void merge_pass(ElementType list[], ElementType sorted[], int N, int length)
{
	int i;
	int left, right, new=0;
	for (i = 0; new < N; i += 2 * length)
	{
		left = i;
		right = i + length;
		new = i;
		while (right<i + 2 * length&&right<N&&left<i+length)
		{
			if (list[right]<list[left])
				sorted[new ++] = list[right++];
			else
				sorted[new ++] = list[left++];
		}
		while (right<length * 2 + i&&right<N)
			sorted[new ++] = list[right++];
		while (left<length + i)
			sorted[new ++] = list[left++];
	}
}