/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)����looptimes���������㣺
����ƽ�������������� (x1, y1) �� (x2, y2)����������֮��ľ���(����2λС��)��
Ҫ����͵��ú��� dist(x1, y1, x2, y2)���������ľ��룬�����β�x1��y1��x2��y2�����Ͷ���double������������double��
�������ʾ������������˵��
����
1               (looptimes=1)
10 10           (x1=10, y1=10)
200 100         (x2=200, y2=100)
���
Distance = 210.24*/
#include <stdio.h>
#include <math.h>
double dist(double x1, double y1, double x2, double y2);
int main(void)
{
    int looptimes, ri;
    double distance, x1, y1, x2, y2;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        distance=dist(x1,y1,x2,y2);
        printf("Distance = %.2f\n", distance);
    }
}
double dist(double x1,double y1,double x2,double y2){
	double a;
	a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	a=sqrt(a);
	return a;
}
