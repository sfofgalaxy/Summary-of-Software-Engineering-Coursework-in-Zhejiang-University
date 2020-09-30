#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30

ElementType EvalPostfix(char *expr) {
	struct sstack {
		ElementType* a;
		int top;
	};
	typedef struct sstack Stack;
	Stack stack;
	stack.a = (ElementType *)malloc(sizeof(ElementType)*Max_Expr);
	ElementType result = 0;
	stack.top = -1;
	int i, j,flag = 0, decimal_digit = 0;
	ElementType decimal = 1;

	for (i = 0; expr[i] != 0; i++) {
		switch (expr[i])
		{
		case ' ':
			break;
		case '+':
		case '*':
		case '/':
			if (stack.top < 1)return Infinity;
			else {
				switch (expr[i])
				{
				case '+':
					(stack.a)[stack.top - 1] = (stack.a)[stack.top] + (stack.a)[stack.top - 1];
					stack.top--;
					break;
				case '*':
					(stack.a)[stack.top - 1] = (stack.a)[stack.top - 1] * (stack.a)[stack.top];
					stack.top--;
					break;
				case '/':
					if ((stack.a)[stack.top] == 0)return Infinity;
					(stack.a)[stack.top - 1] = (stack.a)[stack.top - 1] / (stack.a)[stack.top];
					stack.top--;
					break;
				}
				break;
			}
		case '-':
			if (expr[i + 1] != ' '&&expr[i + 1] != 0) { flag = 1; }
			else {
				(stack.a)[stack.top - 1] = (stack.a)[stack.top - 1] - (stack.a)[stack.top];
				stack.top--;
			}
			break;
		case '.':
			decimal_digit=1;
			break;
		default:
			if (expr[i] <= '9'&&expr[i] >= '0') {
				if (decimal_digit == 0) {
					result = result * 10 + (expr[i] - 48);
				}
				else {
					for (j = 1; j <= decimal_digit;j++)decimal *= 10;
					result += (expr[i] - 48)*(1.0 / decimal);
					decimal_digit++;
					decimal = 1;
				}
				if (expr[i + 1] == ' ' || expr[i + 1] == 0) {
					if (flag == 1) {
						result = -result;
						flag = 0;
					}
					(stack.a)[++stack.top] = result;
					decimal_digit = 0;
					result = 0;
				}
			}
			break;
		}
	}
	if (stack.top != 0)return Infinity;
	return (stack.a)[0];
}



int main()
{
	ElementType v;
	char expr[Max_Expr];
	gets(expr);
	v = EvalPostfix(expr);
	if (v < Infinity)
		printf("%f\n", v);
	else
		printf("ERROR\n");
	return 0;
}

/* Your function will be put here */