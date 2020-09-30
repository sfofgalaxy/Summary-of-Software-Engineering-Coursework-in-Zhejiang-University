#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord {
	int Capacity;       /* maximum size of the stack array */
	int Top1;           /* top pointer for Stack 1 */
	int Top2;           /* top pointer for Stack 2 */
	ElementType *Array; /* space for the two stacks */
};

Stack CreateStack(int MaxElements) {
	Stack stack = (Stack)malloc(sizeof(struct StackRecord));
	stack->Capacity = MaxElements;
	stack->Array = (ElementType *)malloc(sizeof(ElementType)*MaxElements);
	stack->Top1 = -1;
	stack->Top2 = MaxElements;
	return stack;
}

int IsEmpty(Stack S, int Stacknum) {
	if(Stacknum == 1 && S->Top1 == -1)return 1;
	else if(Stacknum == 2 && S->Top2 == S->Capacity)return 1;
	else return 0;
}

int IsFull(Stack S) {
	if (S->Top2 - S->Top1 == 1)return 1;
	else return 0;
}
int Push(ElementType X, Stack S, int Stacknum) {
	if (IsFull(S))return 0;
	else if(Stacknum==1){
		(S->Array)[++(S->Top1)] = X;
		return 1;
	}
	else if(Stacknum==2){
		(S->Array)[--(S->Top2)] = X;
		return 1;
	}
	return 0;
}

ElementType Top_Pop(Stack S, int Stacknum) {
	if (IsEmpty(S, Stacknum))return ERROR;
	else if (Stacknum == 1)return (S->Array)[(S->Top1)--];
	else return (S->Array)[(S->Top2)++];
}

Operation GetOp() {
	char *s = (char *)malloc(sizeof(char));
	scanf("%s", s);
	if (strcmp(s, "push")==0)return push;
	else if (strcmp(s, "pop") == 0)return pop;
	else if(strcmp(s,"end")==0)return end;
}
void PrintStack(Stack S, int Stacknum) {
	int i;
	if (Stacknum == 1) {
		for (i = S->Top1; i >=0; i--)printf("%d ", S->Array[i]);
		printf("\n");
	}
	else {
		for (i = S->Top2; i < S->Capacity; i++)printf("%d ", S->Array[i]);
		printf("\n");
	}
}

int main()
{
	int N, Sn, X;
	Stack S;
	int done = 0;

	scanf("%d", &N);
	S = CreateStack(N);
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf("%d %d", &Sn, &X);
			if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
			break;
		case pop:
			scanf("%d", &Sn);
			X = Top_Pop(S, Sn);
			if (X == ERROR) printf("Stack %d is Empty!\n", Sn);
			break;
		case end:
			PrintStack(S, 1);
			PrintStack(S, 2);
			done = 1;
			break;
		}
	}
	return 0;
}

/* Your function will be put here */