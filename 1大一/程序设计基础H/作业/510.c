/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)����looptimes���������㣺
�������a,b,c����һԪ���η���a*x*x��b*x��c��0�ĸ����������2λС����
���ʹ��������䣺
printf("������Ϊ�㣬����������!\n");
printf("a��bΪ0��c��Ϊ0�����̲�����\n");
printf("x = %0.2f\n", -c/b);
printf("x1 = %0.2f\n", (-b+sqrt(d))/(2*a));
printf("x2 = %0.2f\n", (-b-sqrt(d))/(2*a));
printf("x1 = %0.2f+%0.2fi\n", -b/(2*a), sqrt(-d)/(2*a));
printf("x2 = %0.2f-%0.2fi\n", -b/(2*a), sqrt(-d)/(2*a));
�������ʾ����������Ϊ˵��
���룺
5               (looptimes=5)
0 0 0           (a=0,b=0,c=0)
0 0 1           (a=0,b=0,c=1)
0 2 4           (a=0,b=2,c=4)
2.1 8.9 3.5     (a=2.1,b=8.9,c=3.5)
1 2 3           (a=1,b=2,c=3)
�����
������Ϊ�㣬����������!
a��bΪ0��c��Ϊ0�����̲�����
x = -2.00
x1 = -0.44
x2 = -3.80
x1 = -1.00+1.41i
x2 = -1.00-1.41i*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    int looptimes, ri;
    double a, b, c, d;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%lf%lf%lf", &a, &b, &c);  d=b*b-4*a*c;
        if(a==0&&b==0&&c==0){
        	printf("������Ϊ�㣬����������!\n");
        }
        else if(a==0&&b==0&&c!=0){
        	printf("a��bΪ0��c��Ϊ0�����̲�����\n");
        }
        else if(a==0&&b!=0&&c!=0){
        	printf("x = %0.2f\n", -c/b);
        }
		else if(d>=0){
			printf("x1 = %0.2f\n", (-b+sqrt(d))/(2*a));printf("x2 = %0.2f\n", (-b-sqrt(d))/(2*a));
		}
		else {
			printf("x1 = %0.2f+%0.2fi\n", -b/(2*a), sqrt(-d)/(2*a));
printf("x2 = %0.2f-%0.2fi\n", -b/(2*a), sqrt(-d)/(2*a));
		}
    }     
}


