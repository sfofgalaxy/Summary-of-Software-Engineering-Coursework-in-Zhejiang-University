/*������գ���Ҫ�ı�����������йص���䡣
��������n(n<10)��������n��ѧ���Ļ�����Ϣ��������š������ͳɼ���Ҫ����㲢������ǵ�ƽ���ɼ�(����2λС��)��
�������ʾ����������Ϊ˵��
���룺
3	(n=3)
1  zhang  70
2  wang  80
3  qian  90
�����
average: 80.00*/ 

#include <stdio.h>
int main(void)
{
    int i, n;
    double average, sum;
    struct student{
        int num;
        char name[10];
        int score;
    }s[10];
	sum=0;
    scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %s %d",&s[i].num,s[i].name,&s[i].score);
		sum+=s[i].score;
	}
	average=sum/n;
    printf("average: %.2f\n", average);
}
