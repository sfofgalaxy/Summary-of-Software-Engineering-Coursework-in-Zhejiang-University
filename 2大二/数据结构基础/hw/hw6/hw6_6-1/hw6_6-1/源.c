#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1
#define MinPQSize 1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
	ElementType  *Elements;
	int Capacity;
	int Size;
};

PriorityQueue  Initialize(int  MaxElements)
{
	PriorityQueue  H;
	H = malloc(sizeof(struct HeapStruct));
	/* Allocate the array plus one extra for sentinel */
	H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;  /* set the sentinel */
	return  H;
}


void PercolateUp(int p, PriorityQueue H);
void PercolateDown(int p, PriorityQueue H);

void Insert(ElementType X, PriorityQueue H)
{
	int p = ++H->Size;
	H->Elements[p] = X;
	PercolateUp(p, H);
}

ElementType DeleteMin(PriorityQueue H)
{
	ElementType MinElement;
	MinElement = H->Elements[1];
	H->Elements[1] = H->Elements[H->Size--];
	PercolateDown(1, H);
	return MinElement;
}

int main()
{
	int n, i, op, X;
	PriorityQueue H;

	scanf("%d", &n);
	H = Initialize(n);
	for (i = 0; i<n; i++) {
		scanf("%d", &op);
		switch (op) {
		case 1:
			scanf("%d", &X);
			Insert(X, H);
			break;
		case 0:
			printf("%d ", DeleteMin(H));
			break;
		}
	}
	printf("\nInside H:");
	for (i = 1; i <= H->Size; i++)
		printf(" %d", H->Elements[i]);
	return 0;
}

void PercolateUp(int p, PriorityQueue H)
{
	ElementType temp = H->Elements[p];
	while (temp < H->Elements[p / 2])
	{
		H->Elements[p] = H->Elements[p / 2];
		p = p/2;
	}
	H->Elements[p] = temp;
}
void PercolateDown(int p, PriorityQueue H)
{
	int child;
	ElementType temp;
	temp = H->Elements[1];
	for (; p * 2 <= H->Size; p = child)
	{
		child = p * 2;
		if ((child != H->Size) &&(H->Elements[child + 1] < H->Elements[child]))child++;
		if (temp > H->Elements[child])
		{
			H->Elements[p] = H->Elements[child];
		}
		else
		{
			break;
		}
	}
	H->Elements[p] = temp;
}