/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)���� looptimes ���������㣺
��������������m�� n(1<=m,n<=1000)����� m �� n ֮������������������������Ӻ�����������ȵ��������磬1����������6����������
Ҫ���岢���ú��� factorsum(number)�����Ĺ����Ƿ���number�����Ӻͣ������β�number�����������ͣ��������������͡����磬factorsum(12)�ķ���ֵ��16(1+2+3+4+6)��
���ʹ����䣺printf("%d ", i);
�������ʾ������������˵��
���룺
2        (looptimes=2)
20 
500   (m=20 n=500)
1 
100    (m=1, n=100)
�����
28 496   (20��500֮��������У�28,496)
6 28   (1��100֮��������У�1,6,28) */
#include "stdio.h"
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int i, m, n;
    int looptimes, ri;
    int factorsum(int number); 
    
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
        m=GetInteger();
        n=GetInteger();
        for(i=m;i<=n;i++){
        	if(factorsum(i)==i)printf("%d ", i);
        }
       
      printf("\n");
    }
}
int factorsum(int number){
	int i,a=1;
	for(i=2;i<number;i++){
		if(number%i==0)a+=i;
	}
	return a ;
}



