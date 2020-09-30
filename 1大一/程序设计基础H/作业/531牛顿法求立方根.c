/*牛顿算法计算平方根时采用如下策略：
    1.计算x的平方根时，任意选择初始的猜测值g。
    2.如果猜测值g足够接近于正确的平方根（足够接近是指前后两个猜测值g的差的绝对值除以两个值中绝对值较小的值的结果小于0.000001，用函数ApproximatelyEqual（x,y）判断)，算法结束，函数将g作为结果返回。
    3.如果g不够精确，用g和x/g的平均值作为新的猜测值。因为这两个值中的一个小于确切的平方根，另一个大于确切的平均值，两者的平均值更接近于正确答案的值。
    4.把新的猜测值存入变量g,从第二步重复这个过程。
	
    例如计算16的平方根时，假设初始的猜测值是8,8*8=64>16猜测值不够精确，计算16/8=2,新的猜测值g=(2+8)/2=5。重复这个过程，依次得到猜测值4.1、 4.001219512、4.00000018584，通过第四个猜测值，牛顿法已经产生一个非常接近于正确答案的值。

    仿照上述算法，计算一个数的立方根，该算法表示为一个函数cubeRoot(double n),它取一个double类型的参数，返回一个double类型的值即参数的立方根。

    输入一个正整数looptimes, 做looptimes次重复操作，在每一次中：输入一个double类型的数n，输出该数的立方根。使用输出语句：printf("cuberoot = %.5f\n",y);
	
    输入输出示例：
    输入：
    4
    9
    19
    29
    64
  

    输出：
    cuberoot = 2.08008
    cuberoot = 2.66840
    cuberoot = 3.07232
    cuberoot = 4.00000
    */

#include <stdio.h>
#include <math.h>
double ae(double o,double p); 
double min(double x,double y);/*定义最小值*/ 
double ay(double k); /*定义实型绝对值*/ 
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
		g=(g+n/(g*g))/2;  /*牛顿法*/
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
