#include<stdio.h>
#include <stdlib.h>

extern int count;										
extern int a[100];										


void partition_1(int *p,int n,int num_of_array){ 	//�ݹ麯�� ����p���������������ֵ��n���������ֵ�����num_of_terms������һ��浽������һ���� 
		int i,j,sum=0;						
		a[num_of_array]=n;		
		for(j=0;a[j]!=0;j++)sum+=a[j];				//sum��ǰ��Ϊ���x��Ա���������ж� 
		
		for(i=n;i>=1;i--){							//������1��ʼѭ���ж�����sum�ĺ� 						
			if((sum+i)==*p){						//��Ҫ��ֵ����ʱ���ǰx�Ϊ����� 
				printf("%d = ",*p);
				for(j=0;a[j]!=0;j++)printf("%d + ",a[j]);	
				printf("%d ",i);
				printf("\n");
				count++;
			}
			else if((sum+i)<*p){					//С������ֵ��ʱ��ʼ�ݹ飬���浽��һ�� 
				partition_1(p,i,num_of_array+1);
			}
		}
		a[num_of_array]=0;							//ѭ�������󽫸ô����е�����������˳����� 
}

