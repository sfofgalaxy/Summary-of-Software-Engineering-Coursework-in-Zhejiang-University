#include "myheadfile.h"

//LSD���Ӹ�λ��ʼ 
 
void radix_sort(int n)
{
	FILE *fp;
	int i,j,bn,temp; 
	int  *a = (int *)malloc(sizeof(int)*n);
	fp =  fopen("generate.txt","r");
	for(i=0;i<n;i++)fscanf(fp,"%d\n",&a[i]);
	fclose(fp);
	printf("��ʼ����\n");
	start_t = clock();
	
	int **bucket = (int **)malloc(sizeof(int *)*10);
	for(i=0;i<10;i++)bucket[i] = (int *)malloc(sizeof(int)*n);
	

	//��λ 
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

	//ʮλ 
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
		
		
	//��λ 
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

	//ǧλ 
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

	//��λ 
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
	fp = fopen("����������.txt","w");
	for(i=0;i<n;i++)fprintf(fp,"%d\n",a[i]);
	fprintf(fp,"��������������ʱ��Ϊ%fs\n",total_t);
	printf("������ɣ��������������ڡ�����������.txt���У�\n��������������ʱ��Ϊ%fs\n",total_t);
	fclose(fp);
	return; 
}
