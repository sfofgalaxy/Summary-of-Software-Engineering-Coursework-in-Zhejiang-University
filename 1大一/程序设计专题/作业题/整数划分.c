/*��д�ݹ�����������������в�ͬ�Ļ�����ϡ���������6���������
6 = 5+1
6 = 4+2
6 = 4+1+1
6 = 3+3
6 = 3+2+1
6 = 3+1+1+1
6 = 2+2+2
6 = 2+2+1+1
6 = 2+1+1+1+1
6 = 1+1+1+1+1+1
*/ 

#include<stdio.h>

int count;											//��¼�ж����ֲ�ַ��� 
int a[100];											//����ȫ�������Զ�Ϊ�㣬���²�Ϊ��ǰx���Ա���� 
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
int main(void)
{
	int n;int i;
	scanf("%d",&n);
	int *p=&n;
	for(i=n;i>=1;i--)partition_1(p,i,0);			//��n��1���в��������� 
	printf("���������������ϣ���%d�ֲ�ַ���",count);
}


