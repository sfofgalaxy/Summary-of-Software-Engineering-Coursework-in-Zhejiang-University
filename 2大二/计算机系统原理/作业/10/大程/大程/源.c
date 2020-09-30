#include<stdio.h>
#include<stdlib.h>

typedef unsigned int dwrd; //32 - bit
char* ftoa(dwrd num)
{
	int i = 0;
	char *str = (char *)malloc(sizeof(char) * 32);
	for (int i = 0; i < 32; i++)
	{
		if (num&(0x00000001 << i))str[i] = '1';
		else str[i] = '0';
	}
	return str;
}

dwrd atof(char* str)
{
	dwrd a=0x00000000;
	for (int i = 0; i < 32; i++)
	{
		if (str[i] == '1')
			a | (0x00000001 << i);

	}
	return a;
}

dwrd fadd(dwrd num1, dwrd num2)
{
	int temp1, temp2;
	int e;
	if (num1 & 0x80000000)
	{
		if (num2 & 0x80000000)
		{
			return -fadd(num1 & 0x7FFFFFFF, num2 & 0x7FFFFFFF);
		}
		else
		{
			return fsub(num2 & 0x7FFFFFFF, num1 & 0x7FFFFFFF);
		}
	}
	else
	{
		if (num2 & 0x80000000)
		{
			return fsub(num1 & 0x7FFFFFFF, num2 & 0x7FFFFFFF);
		}
		else
		{
			temp1 = num1 >> 23;
			temp2 = num2 >> 23;
			if (temp1 > temp2)
			{
				e = temp1 - temp2;
				temp1 = num1&0x007FFFFF;
				temp2 = num2&0x007FFFFF;
				temp2 = temp2 >> e;
				temp1 = temp1 + temp2;
				temp1 = temp1 | (num1 & 0x7F800000);
				return temp1;
			}
			else
			{
				e = temp2 - temp1;
				temp2 = num1 & 0x007FFFFF;
				temp1 = num2 & 0x007FFFFF;
				temp1 = temp1 >> e;
				temp2 = temp2 + temp1;
				temp2 = temp2 | (num2 & 0x7F800000);
				return temp2;
			}
		}
	}
}

dwrd fsub(dwrd num1, dwrd num2)
{
	int temp1, temp2;
	int e;
	if (num1 & 0x80000000)
	{
		if (num2 & 0x80000000)
		{
			return fsub(num2 & 0x7FFFFFFF, num1 & 0x7FFFFFFF);
		}
		else
		{
			return -fadd(num2 & 0x7FFFFFFF, num1 & 0x7FFFFFFF);
		}
	}
	else
	{
		if (num2 & 0x80000000)
		{
			return fadd(num1 & 0x7FFFFFFF, num2 & 0x7FFFFFFF);
		}
		else
		{
			temp1 = num1 >> 23;
			temp2 = num2 >> 23;
			if (temp1 > temp2)
			{
				e = temp1 - temp2;
				temp1 = num1 & 0x007FFFFF;
				temp2 = num2 & 0x007FFFFF;
				temp2 = temp2 >> e;
				temp1 = temp1 - temp2;
				temp1 = temp1 | (num1 & 0x7F800000);
				return temp1;
			}
			else
			{
				e = temp2 - temp1;
				temp2 = num1 & 0x007FFFFF;
				temp1 = num2 & 0x007FFFFF;
				temp1 = temp1 >> e;
				temp2 = temp2 - temp1;
				temp2 = temp2 | (num2 & 0x7F800000);
				return temp2;
			}
		}
	}
}

dwrd fmul(dwrd num1, dwrd num2)
{
	int temp1, temp2;
	int e;
	if (num1 & 0x80000000)
	{
		if (num2 & 0x80000000)
		{
			return fmul(num2 & 0x7FFFFFFF, num1 & 0x7FFFFFFF);
		}
		else
		{
			return -fmul(num2 & 0x7FFFFFFF, num1 & 0x7FFFFFFF);
		}
	}
	else
	{
		if (num2 & 0x80000000)
		{
			return -fmul(num1 & 0x7FFFFFFF, num2 & 0x7FFFFFFF);
		}
		else
		{
			temp1 = num1 >> 23;
			temp2 = num2 >> 23;
			e = temp1 + temp2;
			temp1 = num1 & 0x007FFFFF;
			temp2 = num2 & 0x007FFFFF;
			temp1 = temp1 * temp2;
			temp1 = temp1 | (e << 23);
			return temp1;
		}
	}
}

dwrd fdiv(dwrd num1, dwrd num2)
{
	int temp1, temp2;
	int e;
	if (num1 & 0x80000000)
	{
		if (num2 & 0x80000000)
		{
			return fdiv(num2 & 0x7FFFFFFF, num1 & 0x7FFFFFFF);
		}
		else
		{
			return -fdiv(num2 & 0x7FFFFFFF, num1 & 0x7FFFFFFF);
		}
	}
	else
	{
		if (num2 & 0x80000000)
		{
			return -fdiv(num1 & 0x7FFFFFFF, num2 & 0x7FFFFFFF);
		}
		else
		{
			temp1 = num1 >> 23;
			temp2 = num2 >> 23;
			if (temp1 > temp2)
			{
				e = temp1 - temp2;
				temp1 = num1 & 0x007FFFFF;
				temp2 = num2 & 0x007FFFFF;
				temp2 = temp2 >> e;
				temp1 = temp1 / temp2;
				temp1 = temp1 | (e << 23);
				return temp1;
			}
			else
			{
				e = temp2 - temp1;
				temp2 = num1 & 0x007FFFFF;
				temp1 = num2 & 0x007FFFFF;
				temp1 = temp1 >> e;
				temp2 = temp2 / temp1;
				temp2 = temp2 | (e << 23);
				return temp2;
			}
		}
	}
}