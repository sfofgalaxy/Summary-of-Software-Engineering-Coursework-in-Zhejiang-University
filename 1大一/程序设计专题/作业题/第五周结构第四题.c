/*������գ���Ҫ�ı�����������йص���䡣
����4������a1,b1,a2,b2���ֱ��ʾ����������ʵ�����鲿������������֮��(a1��b1i)*(a2��b2i)���˻���ʵ��Ϊ��a1*a2��b1*b2���鲿Ϊ��a1*b2��a2*b1��
�������ʾ����������Ϊ˵��
���룺
3 4 5 6
�����
(3+4i) * (5+6i) = -9 + 38i
*/ 

#include <stdio.h>
int main(void)
{
    struct complex{
        int real;
        int imag;
    }product, x, y;

    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
	product.real=x.real*y.real-x.imag*y.imag;
	product.imag=x.real*y.imag+x.imag*y.real; 
    printf("(%d+%di) * (%d+%di) = %d + %di\n", x.real, x.imag, y.real, y.imag, product.real, product.imag);
}

