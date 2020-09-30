/*编写递归程序，求正整数的所有不同的划分组合。例如输入6，则输出：
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

int count;											//记录有多少种拆分方法 
int a[100];											//定义全局数组自动为零，记下不为零前x项以便输出 
void partition_1(int *p,int n,int num_of_array){ 	//递归函数 其中p来传输输入的数的值，n代表所需拆分的数，num_of_terms代表下一项存到数组哪一项中 
		int i,j,sum=0;						
		a[num_of_array]=n;		
		for(j=0;a[j]!=0;j++)sum+=a[j];				//sum求前不为零的x项，以便接下来的判断 
		
		for(i=n;i>=1;i--){							//从自身到1开始循环判断其与sum的和 						
			if((sum+i)==*p){						//与要拆分的相等时输出前x项不为零的数 
				printf("%d = ",*p);
				for(j=0;a[j]!=0;j++)printf("%d + ",a[j]);	
				printf("%d ",i);
				printf("\n");
				count++;
			}
			else if((sum+i)<*p){					//小于输入值的时候开始递归，数存到下一项 
				partition_1(p,i,num_of_array+1);
			}
		}
		a[num_of_array]=0;							//循环结束后将该次运行的项清除，并退出函数 
}
int main(void)
{
	int n;int i;
	scanf("%d",&n);
	int *p=&n;
	for(i=n;i>=1;i--)partition_1(p,i,0);			//从n到1所有拆分情况遍历 
	printf("该整数拆分情况如上，有%d种拆分方法",count);
}


