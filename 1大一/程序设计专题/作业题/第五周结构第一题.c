/*ʹ�ýṹ�����̣�����һ��������n��3��n��10����������n����Ա����Ϣ����
���������޿ո񣩡��������ʡ��������ʺ�֧�������ÿ�˵�������ʵ�����ʣ�ʵ�����ʣ���������+��������-֧����
˵����
��1���������ʡ��������ʡ�֧����ʵ������ʹ��˫���ȸ����ͣ�����������10���ַ���
��2�������ʽʹ�ã�"%5s sfgz: %7.2f"�����С�
�������ʾ����������Ϊ˵��
���룺
3		(n=3)
zhao 240 400 75
qian 360 120 50
zhou 560 0 80
����� 
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
