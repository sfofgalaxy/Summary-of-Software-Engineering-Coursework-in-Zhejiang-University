#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
	ElementType Element;
	PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
	PtrToNode Front, Rear;
};

Deque CreateDeque(){
	Deque deque = (Deque)malloc(sizeof(struct DequeRecord));
	PtrToNode header = (PtrToNode)malloc(sizeof(struct Node));
	deque->Front = header;
	deque->Rear = header;
	header->Next = NULL;
	header->Last = NULL;
	return deque;
}

int Push(ElementType X, Deque D) {
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	if (D->Rear == D->Front) {
		D->Rear = p;
	}
	else {
		D->Front->Next->Last = p;
	}
	p->Element = X;
	p->Next = D->Front->Next;
	p->Last = D->Front;
	D->Front->Next = p;
	return 1;
}
ElementType Pop(Deque D) {
	if (D->Front == D->Rear)return ERROR;
	else {
		ElementType x;
		x = D->Front->Next->Element;
		if (D->Rear == D->Front->Next)D->Rear = D->Front;
		D->Front->Next = D->Front->Next->Next;
		return x;
	}
}

int Inject(ElementType X, Deque D) {
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	p->Element = X;
	D->Rear->Next = p;
	p->Last = D->Rear;
	p->Next = NULL;
	D->Rear = p;
	return 1;
}

ElementType Eject(Deque D) {
	if (D->Front == D->Rear)return ERROR;
	else {
		ElementType x;
		x = D->Rear->Element;
		D->Rear->Last->Next = NULL;
		D->Rear = D->Rear->Last;
		return x;
	}
}

Operation GetOp() {
	char *s = (char *)malloc(sizeof(char));
	scanf("%s", s);
	if (strcmp(s, "pop") == 0)return pop;
	else if (strcmp(s, "push") == 0)return push;
	else if (strcmp(s, "inject") == 0)return inject;
	else if (strcmp(s, "eject") == 0)return eject;
	else if (strcmp(s, "end") == 0)return end;
}
void PrintDeque(Deque D) {
	while (D->Front->Next != NULL) {
		D->Front = D->Front->Next;
		printf("%d ", D->Front->Element);
	}
	printf("\n");
}

int main()
{
	ElementType X;
	Deque D;
	int done = 0;

	D = CreateDeque();
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf("%d", &X);
			if (!Push(X, D)) printf("Memory is Full!\n");
			break;
		case pop:
			X = Pop(D);
			if (X == ERROR) printf("Deque is Empty!\n");
			break;
		case inject:
			scanf("%d", &X);
			if (!Inject(X, D)) printf("Memory is Full!\n");
			break;
		case eject:
			X = Eject(D);
			if (X == ERROR) printf("Deque is Empty!\n");
			break;
		case end:
			PrintDeque(D);
			done = 1;
			break;
		}
	}
	return 0;
}

/* Your function will be put here */