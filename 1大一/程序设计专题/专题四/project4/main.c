#include "myheadfile.h"

int main(void){
	int i,n;
	FILE *fp;
	srand((unsigned)time(NULL));
	i = rand()%37+13;
	n = i*rand()%100000+1;
	printf("������%d��С�ڵ���%d������generate.txt���ļ���\n",n,n);
	int *a = (int *)malloc(sizeof(int)*n);
	fp = fopen("generate.txt","w");
	for(i = 0;i<n;i++){
		a[i] = 3*rand()%(n+1)+1;
		fprintf(fp,"%d\n",a[i]);
	}
	fclose(fp);
	do{
		printf("ѡ������ʽ��\n��0���������������\n��1����������\n��2���鲢����\n��3��Ͱ����\n��4����������\n��5����������\n��6����������\n���������˳�\n");
		scanf("%ld",&i);
		switch(i){
			case 0: srand((unsigned)time(NULL));
					int i;
					i = rand()%37+13;
					n = i*rand()%100000+1;
					printf("������%d��С�ڵ���%d������generate.txt���ļ���\n",n,n);
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
