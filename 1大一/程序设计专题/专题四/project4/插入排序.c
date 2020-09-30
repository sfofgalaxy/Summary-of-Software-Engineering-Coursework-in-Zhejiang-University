#include "myheadfile.h"

void insert_sort(int n)
{
	FILE *fp;
	int i,j,k,temp; 
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	start_t = clock();
	
	printf("开始排序！\n");
	//核心排序算法 
	for(j=0;j<n-1;j++){
		for(i=0;i<=j;i++){
			if(a[i]>=a[j+1]){
				temp = a[j+1];
				for(k=j;k>=i;k--)a[k+1]=a[k];
				a[i]=temp;
				break;
			}
		}
	}
	
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fp = fopen("插入排序结果.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"插入排序所用总时间为%fs\n",total_t);
	printf("排序完成，并保存排序结果于“插入排序结果.txt”中！\n插入排序所用总时间为%fs\n",total_t);
	fclose(fp);
}
