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
	printf("��ʼ����\n");
	start_t = clock();
	
	sort(a,0,n-1);
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fp = fopen("����������.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"��������������ʱ��Ϊ%fs\n",total_t);
	printf("������ɣ��������������ڡ�����������.txt���У�\n��������������ʱ��Ϊ%fs\n",total_t);
	fclose(fp);
} 

void sort(int *a, int left, int right)
{
    if(left >= right)return;/*�������������ڻ��ߵ����ұߵ������ʹ����Ѿ��������һ������*/
    int i = left;
    int j = right;
    int key = a[left];
     
    for(;i < j;)                               /*�����ڵ�����Ѱ��һ��*/
    {
        for(;i < j && key <= a[j];j--);
        /*�ҵ�һ��С�ڻ��ߴ���key����*/ 
        a[i] = a[j];
        for(;i < j && key >= a[i];i++);
        /*����i�ڵ�������ǰѰ�ң�ͬ�ϣ�*/
        a[j] = a[i];
    }
     
    a[i] = key;/*���ڵ���������һ���Ժ�Ͱ��м���key�ع�*/
    sort(a, left, i - 1);/*�����ͬ���ķ�ʽ�Էֳ�������ߵ�С�����ͬ�ϵ�����*/
    sort(a, i + 1, right);/*��ͬ���ķ�ʽ�Էֳ������ұߵ�С�����ͬ�ϵ�����*/
}
