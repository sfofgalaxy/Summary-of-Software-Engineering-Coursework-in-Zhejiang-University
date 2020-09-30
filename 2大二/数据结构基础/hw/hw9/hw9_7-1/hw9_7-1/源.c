#include<stdio.h>
#include<stdlib.h>

int find(int *a,int x)
{
	int m;
	m = x;
	while (a[m] > 0) m = a[m];
	return m;
}

void combine(int *a, int x, int y)
{
	int s1, s2;
	s1 = find(a,x);
	s2 = find(a,y);
	if (a[s1] < a[s2])a[s2] = s1;
	else if (a[s2] < a[s1])a[s1] = s2;
	else {
		a[s2] = s1;
		a[s1]--;
	}
	return; 
}

void check(int *a, int x, int y)
{
	int s1,s2;
	s1 = find(a,x);
	s2 = find(a,y);
	if (s1 == s2)printf("yes\n");
	else printf("no\n");
}

int main(void)
{
	int N, computer1, computer2, i,flag,num;
	char ch;
	scanf("%d", &N);
	int *dis_set = (int *)malloc(sizeof(int)*(N+1));
	for (i = 0; i <= N; i++)dis_set[i] = -1;
	ch = getchar();
	while (ch!='S')
	{
		scanf("%d %d",&computer1,&computer2);
		if(ch=='I')combine(dis_set, computer1, computer2);
		else if (ch == 'C')check(dis_set, computer1, computer2);
		ch = getchar();
	}
	num = 0;
	for (i = 1; i <= N; i++)if (dis_set[i] < 0)num++;

	if (num == 1)printf("The network is connected.\n");
	else printf("There are %d components.\n", num);
}
