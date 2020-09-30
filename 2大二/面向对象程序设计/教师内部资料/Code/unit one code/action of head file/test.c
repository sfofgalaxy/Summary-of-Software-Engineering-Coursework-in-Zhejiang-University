#include <stdio.h>
struct gun{
	int a;
	int b;
};
struct gun{
	int a;
	int b;
};

int main()
{
	int a,b;
	scanf("%d%d", &a,&b);
	printf("max(a,b)=%d\n",Max(a,3,4,5));
	return 0;
}

int Max(int x, int y)
{
	return (x > y ? x : y);
}