/*ţ���㷨����ƽ����ʱ�������²��ԣ�
    1.����x��ƽ����ʱ������ѡ���ʼ�Ĳ²�ֵg��
    2.����²�ֵg�㹻�ӽ�����ȷ��ƽ�������㹻�ӽ���ָǰ�������²�ֵg�Ĳ�ľ���ֵ��������ֵ�о���ֵ��С��ֵ�Ľ��С��0.000001���ú���ApproximatelyEqual��x,y���ж�)���㷨������������g��Ϊ������ء�
    3.���g������ȷ����g��x/g��ƽ��ֵ��Ϊ�µĲ²�ֵ����Ϊ������ֵ�е�һ��С��ȷ�е�ƽ��������һ������ȷ�е�ƽ��ֵ�����ߵ�ƽ��ֵ���ӽ�����ȷ�𰸵�ֵ��
    4.���µĲ²�ֵ�������g,�ӵڶ����ظ�������̡�
	
    �������16��ƽ����ʱ�������ʼ�Ĳ²�ֵ��8,8*8=64>16�²�ֵ������ȷ������16/8=2,�µĲ²�ֵg=(2+8)/2=5���ظ�������̣����εõ��²�ֵ4.1�� 4.001219512��4.00000018584��ͨ�����ĸ��²�ֵ��ţ�ٷ��Ѿ�����һ���ǳ��ӽ�����ȷ�𰸵�ֵ��

    ���������㷨������һ�����������������㷨��ʾΪһ������cubeRoot(double n),��ȡһ��double���͵Ĳ���������һ��double���͵�ֵ����������������

    ����һ��������looptimes, ��looptimes���ظ���������ÿһ���У�����һ��double���͵���n�������������������ʹ�������䣺printf("cuberoot = %.5f\n",y);
	
    �������ʾ����
    ���룺
    4
    9
    19
    29
    64
  

    �����
    cuberoot = 2.08008
    cuberoot = 2.66840
    cuberoot = 3.07232
    cuberoot = 4.00000
    */

#include <stdio.h>
#include <math.h>
double ae(double o,double p); 
double min(double x,double y);/*������Сֵ*/ 
double ay(double k); /*����ʵ�;���ֵ*/ 
int main()
{ 
    int looptimes, ri;
    double  n,g,g1,g2;     
    scanf("%d",&looptimes);
    for(ri = 1; ri <= looptimes; ri++){ 
    	scanf("%lf",&n);
    g1=8;
    g=g1-1;
    while(ae(g,g1)>=0.00000001||ae(g,g1)<=-0.00000001)
    {
    g1=g;	
		g=(g+n/(g*g))/2;  /*ţ�ٷ�*/
	}
       printf("cuberoot = %.5f\n",g);
    }
    return 85002; 
}
double ae(double o,double p)
{
	double a,b,c;
	a=o-p;
	b=min(ay(o),ay(p));
	c=a/b;
	return c;
}
double min(double x,double y)
{
double u,v,z;
u=x;
v=y;
if(u<v){
	z=u;
}
else{
	z=v;
}
return z;}
double ay(double k)
{
	double u;
	if(k<0.0)
	{
		u=-k;
	}
	else{
		u=k;
	}
	return u;
}
