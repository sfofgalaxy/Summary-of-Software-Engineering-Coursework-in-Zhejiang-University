#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned int word;

//判断是否溢出
int judge(word oldcode,word currentcode)
{
	if ((oldcode > 0x8000 && currentcode < 0x18000) || (oldcode < 0x8000 && currentcode < 0x8000))return 1;
	else return 0;
}
//字符串转数
word atom(char* str)
{
	int i = 0;
	word temp = 0;
	if (str[0] == '-')
	{
		temp = temp | 0x8000;
		i = 1;
	}
	for (; str[i]; i++)
	{
		if(judge(temp,temp*10+(str[i]-48)))temp = temp * 10 + (str[i] - 48);
		else
		{
			printf("该字符串溢出！\n");
			return 0;
		}
	} 
	return temp;
}
//数转字符串
char* mtoa(word code)
{
	char *temp1;
	int temp2;
	temp1 = (char *)malloc(sizeof(char) * 20);
	char* str = (char*)malloc(sizeof(char) * 20);
	if (code & 0x8000)
	{
		str[0] = '-';
		str[1] = 0;
	}
	else str[0] = 0;
	code = code & 0x7FFF;
	temp2 = code;
	itoa(temp2, temp1, 2);
	strcat(str, temp1);
	return str;
}
//加法
word madd(word code1, word code2)
{
	if (code1 & 0x8000 || code2 & 0x8000)
	{
		if (code1 & 0x8000 && code2 & 0x8000)
		{
			code1 = code1 & 0x7FFF;
			code2 = code2 & 0x7FFF;
			return madd(code1, code2) | 0x8000;
		}
		else if (code1 & 0x8000)return msub(code2, code1 & 0x7FFF);
		else return msub(code1, code2 & 0x7FFF);
	}
	else
	{
		if (code1 + code2 < 0x8000)
		{
			return (code1 + code2);
		}
		else printf("溢出！\n");
	}
	return 0;
}
//减法
word msub(word code1 , word code2)
{
	if (code1 & 0x8000 || code2 & 0x8000)
	{
		if (code1 & 0x8000 && code2 & 0x8000)
			return msub(code2 & 0x7FFF, code1 & 0x7FFF);
		else return madd(code1, code2 & 0x7FFF);
	}
	else
	{
		if (code2 > code1)return (code2 - code1) | 0x8000;
		else return code1 - code2;
	}
}
//乘法
word mmul(word code1 , word code2)
{
	if ((code1 & 0x8000 && code2 & 0x8000) || !(code1 & 0x8000 || code2 & 0x8000))
	{
		if ((code1 & 0x7FFF) * (code2 & 0x7FFF) > 0x8000)printf("溢出！\n");
		else return (code1 & 0x7FFF) * (code2 & 0x7FFF);
	}
	else return mmul(code1 & 0x7FFF, code2) | 0x8000;
	
	return 0;
}
//除法
word mdiv(word code1, word code2)
{
	if ((code1 & 0x8000 && code2 & 0x8000) || !(code1 & 0x8000 || code2 & 0x8000))return (code1 & 0x7FFF) / (code2 & 0x7FFF);
	else return mmul(code1 & 0x7FFF, code2) | 0x8000;
}
//取余
word mmod(word code1 , word code2)
{
	if ((code1 & 0x8000 && code2 & 0x8000) || !(code1 & 0x8000 || code2 & 0x8000))return (code1 & 0x7FFF) % (code2 & 0x7FFF);
	else if (code1 & 0x8000)
		return ((code1 & 0x7FFF) % code2) | 0x8000;
	else
		return code1 % (code2 & 0x7FFF);
}
//比大小
int compare(word code1, word code2)
{
	if (code1 == code2)return 0;
	else if (code1 & 0x8000 && code2 & 0x8000)return compare(code2 & 0x7FFF, code1 & 0x7FFF);
	else if (code1 & 0x8000)return -1;
	else if (code2 & 0x8000)return 1;
	else
	{
		if (code1 > code2)return 1;
		else return -1;
	}
}