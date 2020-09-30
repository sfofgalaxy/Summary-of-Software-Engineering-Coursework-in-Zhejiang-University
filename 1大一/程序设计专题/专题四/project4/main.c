#include "myheadfile.h"

int main(void){
	int i,n;
	FILE *fp;
	srand((unsigned)time(NULL));
	i = rand()%37+13;
	n = i*rand()%100000+1;
	printf("生成了%d个小于等于%d的数于generate.txt的文件中\n",n,n);
	int *a = (int *)malloc(sizeof(int)*n);
	fp = fopen("generate.txt","w");
	for(i = 0;i<n;i++){
		a[i] = 3*rand()%(n+1)+1;
		fprintf(fp,"%d\n",a[i]);
	}
	fclose(fp);
	do{
		printf("选择排序方式：\n【0】重新生成随机数\n【1】插入排序\n【2】归并排序\n【3】桶排序\n【4】基数排序\n【5】计数排序\n【6】快速排序\n【其他】退出\n");
		scanf("%ld",&i);
		switch(i){
			case 0: srand((unsigned)time(NULL));
					int i;
					i = rand()%37+13;
					n = i*rand()%100000+1;
					printf("生成了%d个小于等于%d的数于generate.txt的文件中\n",n,n);
					int *a = (int *)malloc(sizeof(int)*n);
					fp = fopen("generate.txt","w");
					for(i = 0;i<n;i++){
						a[i] = 3*rand()%(n+1)+1;
						fprintf(fp,"%d\n",a[i]);
					}
					fclose(fp);
					break;
			case 1:insert_sort(n);break;
			case 2:merge_sort(n);break;
			case 3:bucket_sort(n);break;
			case 4:radix_sort(n);break;
			case 5:counting_sort(n);break;
			case 6:quick_sort(n);break;
			default:return 0; 
		}	
	}while(1);
	
}
