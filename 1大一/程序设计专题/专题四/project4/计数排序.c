#include "myheadfile.h"

void counting_sort(int n)
{
	FILE *fp;
	int i,j,count,same,temp; 
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	printf("��ʼ����\n");
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
	fp = fopen("����������.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",tempa[i]);
	fprintf(fp,"������ɣ��������������ڡ�����������.txt���У�\n��������������ʱ��Ϊ%fs\n",total_t);
	printf("��������������ʱ��Ϊ%fs\n",total_t);
	fclose(fp);
} 
