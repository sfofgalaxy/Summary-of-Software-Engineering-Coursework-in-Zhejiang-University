#include "myheadfile.h"

//LSD、从个位开始 
 
void radix_sort(int n)
{
	FILE *fp;
	int i,j,bn,temp; 
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	printf("开始排序！\n");
	start_t = clock();
	
	int **bucket = (int **)malloc(sizeof(int *)*10);
	for(i=0;i<10;i++)bucket[i] = (int *)malloc(sizeof(int)*n);
	

	//个位 
	for(i=0;i<10;i++)for(j=0;j<n;j++)bucket[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n&&bucket[a[i]%10][j];j++);
		bucket[a[i]%10][j] = a[i];
	}
	j=0;
	for(bn=0;bn<10;bn++){
		for(i=0;i<n&&bucket[bn][i];i++){
			a[j]=bucket[bn][i];
			j++;
		}
	}

	//十位 
	for(i=0;i<10;i++)for(j=0;j<n;j++)bucket[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n&&bucket[a[i]%100/10][j];j++);
		bucket[a[i]%100/10][j] = a[i];
	}
	j=0;
	for(bn=0;bn<10;bn++){
		for(i=0;i<n&&bucket[bn][i];i++){
			a[j]=bucket[bn][i];
			j++;
		}
	}
		
		
	//百位 
	for(i=0;i<10;i++)for(j=0;j<n;j++)bucket[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n&&bucket[a[i]%1000/100][j];j++);
			bucket[a[i]%1000/100][j] = a[i];
	}
	j=0;
	for(bn=0;bn<10;bn++){
		for(i=0;i<n&&bucket[bn][i];i++){
			a[j]=bucket[bn][i];
			j++;
		}	
	}

	//千位 
	for(i=0;i<10;i++)for(j=0;j<n;j++)bucket[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n&&bucket[a[i]%10000/1000][j];j++);
			bucket[a[i]%10000/1000][j] = a[i];
	}
	j=0;
	for(bn=0;bn<10;bn++){
		for(i=0;i<n&&bucket[bn][i];i++){
			a[j]=bucket[bn][i];
			j++;
		}
	}

	//万位 
	for(i=0;i<10;i++)for(j=0;j<n;j++)bucket[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n&&bucket[a[i]/10000][j];j++);
			bucket[a[i]/10000][j] = a[i];
	}
	j=0;
	for(bn=0;bn<10;bn++){
		for(i=0;i<n&&bucket[bn][i];i++){
			a[j]=bucket[bn][i];
			j++;
		}
	}

	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fp = fopen("基数排序结果.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"基数排序所用总时间为%fs\n",total_t);
	printf("排序完成，并保存排序结果于“基数排序结果.txt”中！\n基数排序所用总时间为%fs\n",total_t);
	fclose(fp);
	return; 
}
