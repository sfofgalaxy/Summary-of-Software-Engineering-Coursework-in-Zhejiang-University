#include "myheadfile.h"

void counting_sort(int n)
{
	FILE *fp;
	int i,j,count,same,temp; 
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	printf("开始排序！\n");
	start_t = clock();
	
	int *tempa = (int*)malloc(sizeof(int)*n); 
	for(i=0;i<n;i++){
		same = count = 0;
		for(j=0;j<n;j++){
			if(a[j]<=a[i]){
				count++;
				if(a[j]==a[i])same++;
			}
		}
		for(;same>0;same--,count--)tempa[count-1]=a[i];
	}
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fp = fopen("计数排序结果.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",tempa[i]);
	fprintf(fp,"排序完成，并保存排序结果于“计数排序结果.txt”中！\n计数排序所用总时间为%fs\n",total_t);
	printf("计数排序所用总时间为%fs\n",total_t);
	fclose(fp);
} 
