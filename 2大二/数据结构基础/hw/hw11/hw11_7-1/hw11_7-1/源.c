#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int nextprime(int n)
{
	if (n == 1 || n == 2)return 2;
	while (!isprime(n))n++;
	return n;
}

int isprime(int n)
{
	int i;
	for (i = 2; i <= (int)sqrt(n) + 1; i++)
	{
		if (n%i == 0)return 0;
	}
	return 1;
}

int find(int key, int *b, int TSize)
{
	int position = key % TSize;
	int increment = 0;
	if (!b[position])
	{
		b[position] = 1;
		return position;
	}

//rehashing

	else
	{
		while (position < TSize&&b[position])
		{
			position += 2 * ++increment - 1;
			if (position >= TSize)position -= TSize;
		}
		if (position >= TSize)return -1;
		else 
		{
			b[position] = 1;
			return position;
		}
	}
}

int main(void)
{
	int i, MSize, N, TSize, temp;
	scanf("%d %d", &MSize, &N);
	TSize = nextprime(MSize);

	//读入与初始化
	int *a = (int *)malloc(sizeof(int)*N);
	int *b = (int *)malloc(sizeof(int)*TSize);
	for (i = 0; i < N; i++)scanf("%d", &a[i]);
	for (i = 0; i < TSize; i++)b[i] = 0;//0代表没被占用，1代表已被占用

	//输出
	for (i = 0; i < N - 1; i++)
	{
		temp = find(a[i], b, TSize);
		if (temp >= 0)printf("%d ", temp);
		else printf("- ");
	}
	temp = find(a[N - 1], b, TSize);
	if (temp >= 0)printf("%d", temp);
	else printf("-");
}