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
	
	printf("��ʼ����\n");
	//���������㷨 
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
	fp = fopen("����������.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"��������������ʱ��Ϊ%fs\n",total_t);
	printf("������ɣ��������������ڡ�����������.txt���У�\n��������������ʱ��Ϊ%fs\n",total_t);
	fclose(fp);
}
