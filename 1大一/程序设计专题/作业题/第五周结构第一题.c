/*使用结构数组编程，输入一个正整数n（3≤n≤10），再输入n个雇员的信息，包
括姓名（无空格）、基本工资、浮动工资和支出，输出每人的姓名和实发工资，实发工资＝基本工资+浮动工资-支出。
说明：
（1）基本工资、浮动工资、支出和实发工资使用双精度浮点型，姓名不超过10个字符；
（2）输出格式使用："%5s sfgz: %7.2f"及换行。
输入输出示例：括号内为说明
输入：
3		(n=3)
zhao 240 400 75
qian 360 120 50
zhou 560 0 80
输出： 
 zhao sfgz:  565.00
 qian sfgz:  430.00
 zhou sfgz:  480.00  */

#include<stdio.h>
int main(void)
{
	int i,n;
	double reality[10];
	scanf("%d",&n);
	struct {
		char name[11];
		double basic;
		double floating;
		double  expend;
	}employee[10];
	for(i=0;i<n;i++){
		scanf("%s %lf %lf %lf",employee[i].name,&employee[i].basic,&employee[i].floating,&employee[i].expend);
		reality[i]=employee[i].basic+employee[i].floating-employee[i].expend;
	}
	for(i=0;i<n;i++){
		printf("%5s sfgz: %7.2f\n",employee[i].name,reality[i]);
	}
} 
