/*��һ��n*n�������Ϸ���n���ʺ�ʹ����֮�以�಻���Ե������� ���ܳԵ��ᡢ����б�Խ��߷�������ӣ�������һ���ж����ְڷ��� �������
���磺
���룺
4   (n=4)
�����
2������2�ְڷ���*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int judge(int a[],int i,int j);//�ж��ܷ�ڵ���ڵĵط� 
void place(int a[],int i,int n); //���ûʺ� 
int count;//ȫ�ֱ�������ÿ�ε���place���ֵ 
int main(void)
{
	int n;
	scanf("%d",&n);
	int *a=(int*)malloc(sizeof(int)*n);//��̬����a[n]��ֵ��¼�ڵ����� 
	place(a,0,n);//�ӵ�һ�п�ʼ���� 
	printf("%d",count);
} 
int judge(int a[],int i,int j)
{
	int k,l=1;
	for(k=0;k<i;k++){
		if(abs(i-k)==abs(j-a[k])||a[k]==j){
			l=0;break;
		}
	}
	return l;
}
void place(int a[],int i,int n)
{
	int j;
	for(j=0;j<n;j++){
		if(judge(a,i,j)){
			if(i<n-1) {
				a[i]=j;place(a,i+1,n);//������ֵΪ�У����û�аڵ����һ����ô�ݹ� 
			}
			else if(i==n-1)count++;//�ݹ���ֹ�������������һ��count+1 
		}	
	}	
}
	

