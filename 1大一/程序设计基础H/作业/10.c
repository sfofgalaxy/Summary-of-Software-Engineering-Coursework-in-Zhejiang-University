/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)����looptimes���������㣺
�������������� a �� n, ��a��aa��aaa��aa��a(n��a)֮�͡�
Ҫ���岢���ú���fn(a, n)�����Ĺ����Ƿ��� aa��a��n��a���������β�a��n��������int������������long�����磬fn(3,2)�ķ���ֵ��33��
�������ʾ������������˵��
����
2       (looptimes=2)
2 
3     (a=2, n=3)
8 
5     (a=8, n=5)
���
246     (2+22+222)
98760   (8+88+888+8888+88888) */
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int a, i, n;
    int ri, looptimes;
    long sn;
    long fn(int a, int n);
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){sn=0;
        a=GetInteger();
        n=GetInteger();
        for(i=1;i<=n;i++){
        sn+=fn(a,i)	;
        }
        printf("%ld\n", sn);
    }
}
  long fn(int a,int n){
  	int i ;
  	long b=0;
  	for(i=1;i<=n;i++){
  		b+=a;
  		a*=10;
  	}
  		return b ;
  }
