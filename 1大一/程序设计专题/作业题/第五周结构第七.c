/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数 repeat (0<repeat<10)，做 repeat 次下列运算：
编写程序，输入一个日期(年、月、日)，计算并输出该日是该年中的第几天。
要求定义并调用函数 day_of_year(p) 计算某日是该年的第几天，函数形参p的类型是结构指针，
指向表示日期的结构变量，函数类型是int，注意区分闰年。
输入输出示例：括号内为说明
输入：
2	   (repeat=2)
2006  3  5
2000  3  5
输出：
64    (2006年3月5日是该年的第64天)
65    (2000年3月5日是该年的第65天)
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

