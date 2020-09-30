#include<stdio.h>
#include<stdlib.h>


int down(int *a, int n, int x) {
	int i, j;
	for (i = x + 1; i < n - 1; ) {
		for (j = i + 1; a[j]>a[x]; j++);
		if (a[i] < a[j])return 0;
		i = j;
	}
	return 1;
}

int judge(int *a, int m, int n) {
	int i, j;
	int max = 1, current = 1;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	//judging logic
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i] < a[j]) {
				if (!down(a, n, j))return 0;
			}
		}

		//judging space
		for (j = i; j < n - 1; j++) {
			if (a[j] > a[j + 1])current++;
			else break;
		}
		if (current > max)max = current;
		current = 1;
	}


	if (max > m)return 0;
	return 1;
}



int main() {
	int M, N, K;
	int i;
	scanf("%d %d %d", &M, &N, &K);
	int *num = (int *)malloc(sizeof(int)*N);
	for (i = 1; i <= K; i++) {
		if (judge(num, M, N))printf("YES\n");
		else printf("NO\n");
	}
}
