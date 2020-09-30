#include<stdio.h>	
#include<stdlib.h>

void insert_pass(int list[],  int index);//一次插排
int insert_sort(int list[],int compare[], int N);
void heap_sort(int list[], int compare[], int N);
void output(int list[], int N);//输出函数
void adjust_to_Maxheap(int list[], int N);//调整成最大堆


int main(void)
{
	int compare[200];
	int insert[200];
	int heap[200];
	int i, N;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &insert[i]);
		heap[i+1] = insert[i];
	}
	for (i = 0; i < N; i++)scanf("%d", &compare[i]);
	heap[0] = -1;
	if (insert_sort(insert, compare, N));
	else heap_sort(heap, compare, N);

	return 0;
}


int insert_sort(int list[], int compare[], int N)
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
			return 1;
		}
	}
	return 0;
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

void heap_sort(int list[], int compare[], int N)
{
	int i, j, flag;
	for (i = N; i > 0; i--)
	{
		flag = 1;
		adjust_to_Maxheap(list, i);
		for (j = 0; j < N; j++)if (list[j + 1] != compare[j])flag = 0;
		j = list[i];
		list[i] = list[1];
		list[1] = j;
		if (flag)
		{
			printf("Heap Sort\n");
			adjust_to_Maxheap(list, i - 1);
			for (j = 1; j < N; j++)printf("%d ", list[j]);
			printf("%d\n", list[j]);
			return;
		}
	}
}

void adjust_to_Maxheap(int list[], int N)
{
	int i, temp, child, parent;

	for (i = N / 2; i > 0; i--)
	{
		for (parent = i; parent * 2 <= N && parent > 0; parent = child)
		{
			child = parent * 2;
			if (child<N&&list[child + 1]>list[child])child++;
			if (list[child] > list[parent])
			{
				temp=list[child];
				list[child] = list[parent];
				list[parent] = temp;
			}
		}
	}
	return;
}

void output(int list[], int N)
{
	int i;
	for (i = 0; i < N - 1; i++)printf("%d ", list[i]);
	printf("%d\n", list[i]);
	return;
}
