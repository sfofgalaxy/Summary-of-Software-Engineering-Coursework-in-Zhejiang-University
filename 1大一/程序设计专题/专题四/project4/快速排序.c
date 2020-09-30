#include "myheadfile.h"

void sort(int *a, int left, int right);
void quick_sort(int n)
{
	FILE *fp;
	int i,j,k,temp; 
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	printf("开始排序！\n");
	start_t = clock();
	
	sort(a,0,n-1);
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fp = fopen("快速排序结果.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"快速排序所用总时间为%fs\n",total_t);
	printf("排序完成，并保存排序结果于“快速排序结果.txt”中！\n快速排序所用总时间为%fs\n",total_t);
	fclose(fp);
} 

void sort(int *a, int left, int right)
{
    if(left >= right)return;/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    int i = left;
    int j = right;
    int key = a[left];
     
    for(;i < j;)                               /*控制在当组内寻找一遍*/
    {
        for(;i < j && key <= a[j];j--);
        /*找到一个小于或者大于key的数*/ 
        a[i] = a[j];
        for(;i < j && key >= a[i];i++);
        /*这是i在当组内向前寻找，同上，*/
        a[j] = a[i];
    }
     
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
}
