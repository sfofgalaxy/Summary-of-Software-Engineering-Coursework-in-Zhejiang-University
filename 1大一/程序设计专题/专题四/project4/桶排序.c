#include "myheadfile.h"

void bucket_sort(int n)
{
	FILE *fp;
	int i,j,k,temp,bn;
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	int **bucket = (int **)malloc(sizeof(int *)*10);
	for(i=0;i<10;i++)bucket[i]=(int *)malloc(sizeof(int)*n);
	for(i=0;i<10;i++)
		for(j=0;j<n;j++)
			bucket[i][j]=0;//初始化为零 
	printf("开始排序！\n");		
	start_t = clock();
		
	for(i=0;i<n;i++){
		for(j=0;bucket[a[i]/10000][j]!=0;j++);
		bucket[a[i]/10000][j]=a[i];
	}


	for(bn=0;bn<10;bn++){
		for(j=0;bucket[bn][j+1]!=0&&j<n-1;j++){
			for(i=0;i<=j;i++){
				if(bucket[bn][i]>=bucket[bn][j+1]){
					temp = bucket[bn][j+1];
					for(k=j;k>=i;k--)bucket[bn][k+1]=bucket[bn][k];
					bucket[bn][i]=temp;
					break;
				}
			}
		}
	}

	j=0;
		for(bn=0;bn<10;bn++){
			for(i=0;bucket[bn][i]&&i<n;i++){
				a[j]=bucket[bn][i];
				j++;
			}
		}
   
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fp = fopen("桶排序结果.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"桶排序所用总时间为%fs\n",total_t);
	printf("排序完成，并保存排序结果于“桶排序结果.txt”中！\n桶排序所用总时间为%fs\n",total_t);
	fclose(fp);
}
