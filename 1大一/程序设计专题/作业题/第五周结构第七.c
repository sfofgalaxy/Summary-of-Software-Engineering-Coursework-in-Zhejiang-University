/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� repeat (0<repeat<10)���� repeat ���������㣺
��д��������һ������(�ꡢ�¡���)�����㲢��������Ǹ����еĵڼ��졣
Ҫ���岢���ú��� day_of_year(p) ����ĳ���Ǹ���ĵڼ��죬�����β�p�������ǽṹָ�룬
ָ���ʾ���ڵĽṹ����������������int��ע���������ꡣ
�������ʾ����������Ϊ˵��
���룺
2	   (repeat=2)
2006  3  5
2000  3  5
�����
64    (2006��3��5���Ǹ���ĵ�64��)
65    (2000��3��5���Ǹ���ĵ�65��)
*/ 

#include <stdio.h>

int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int runmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};
struct date{
    int year;
    int month;
    int day;
};
int day_of_year(struct date *p);

int main(void)
{
    int yearday;
    int repeat, ri;
    struct date date;
	struct date *p;
	p=&date;
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d%d", &date.year, &date.month, &date.day);
		yearday=day_of_year(p); 
        printf("%d\n", yearday);
    }
}

int day_of_year(struct date *p){
	int yearday,i;
	yearday=0;
	if(((*p).year%4==0&&(*p).year%100!=0)||(*p).year%400==0){
		for(i=0;i<(*p).month-1;i++)yearday+=runmonth[i];
		yearday+=(*p).day;
	}
	else{
		for(i=0;i<(*p).month-1;i++)yearday+=month[i];
		yearday+=(*p).day;
	}
	return yearday;
}

