#include "myheadfile.h"

void recursion(int *a,int startindex,int endindex); 
void merge_sort(int n)
{
	FILE *fp;
	int i; 
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	start_t = clock();
	
	printf("开始排序！\n");
	recursion(a,0,n-1);
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fp = fopen("归并排序结果.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"归并排序所用总时间为%fs\n",total_t);
	printf("排序完成，并保存排序结果于“归并排序结果.txt”中！\n归并排序所用总时间为%fs\n",total_t);
	fclose(fp);
} 

void recursion(int *a,int startindex,int endindex){
	int temp;
	if(endindex==startindex)return;
	else if(endindex-startindex==1){
		if(a[endindex]<=a[startindex]){
			temp=a[endindex];
			a[endindex]=a[startindex];
			a[startindex]=temp;
		}
	}
	else {
		int i,j,count;
		recursion(a,startindex,(startindex+endindex)/2);
		recursion(a,(startindex+endindex)/2+1,endindex);
		int *a1=(int *)malloc(sizeof(int)*((startindex+endindex)/2-startindex+1));
		int *a2=(int *)malloc(sizeof(int)*(endindex-(startindex+endindex)/2));
		for(i=0;i<(startindex+endindex)/2-startindex+1;i++)a1[i]=a[startindex+i];
		for(i=0;i<endindex-(startindex+endindex)/2;i++)a2[i]=a[(startindex+endindex)/2+1+i];
		i=0;j=0;count=startindex;
		while(1){
			if(i==(startindex+endindex)/2-startindex+1){
				for(;count<=endindex;count++){
					a[count]=a2[j];
					j++;
				}
				break;
			}
			else if(j==endindex-(startindex+endindex)/2){
				for(;count<=endindex;count++){
					a[count]=a1[i];
					i++;
				}
				break;
			}
			if(a1[i]<=a2[j]){
				a[count]=a1[i];
				i++;
				count++;
			}
			else if(a2[j]<=a1[i]){
				a[count]=a2[j];
				j++;
				count++;
			}
		}
	}
	return;
}
