/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)����looptimes���������㣺
����һ������ in���������������
Ҫ���岢���ú���reverse(number)�����Ĺ����Ƿ���number���������������β�number��������int������������int�����磬reverse(12345)�ķ���ֵ��54321��
�������ʾ������������˵��
����
5        (looptimes=4) 
12345    (in=12345) 
-100     (in=-100) 
-2       (in=-2) 
99       (in=99) 
0        (in=0) 
���
54321    (12345��������)
-1       (-100��������)
-2       (-2��������)
99       (99��������)
0        (0��������)*/ 

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int fun(int n);
int fn(int n);
int main()
{	
    int m1,m2;
    
    m1=GetInteger();
    m2=GetInteger();
  
    printf("%d--->%d\n", m1, fun(m1));  
    printf("%d--->%d\n", m2, fun(m2));  

}
int fun(int n){
	int i,a,b,c,d,e ;e=n;
	i=0;b=0;if(n>=0)n=n;else n=-n;a=n;
	do {
		i++;n/=10;
	}
	while(n>0);
     for(d=1;d<=i;d++){c=a%10;a/=10;
     	b+=c*fn(i-d);
     }
     if(e>=0)return b;
     else return -b;
}
 int fn(int n){
 	int i,a=1;
 	for(i=1;i<=n;i++){
 		a*=10;
 	}
 	return a;
 }


