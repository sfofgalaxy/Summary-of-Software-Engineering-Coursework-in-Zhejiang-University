/*CompInfix.c --- Compute the value of a arithmatic expression inluding the 
  operators of + - * / ( and ), with terminal ENTER.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"

#define MAXEXP  200
#define MAXOP   30
#define MAXOPN  100  

#define EMPTY 0

/*逆波兰式队列及操作函数*/
char RPN[MAXEXP]; /*逆波兰式表达式队列，以回车结束*/
int pRPN = -1;/*逆波兰式表达式队列当前位置，初始为-1*/
void AppendRPN(char ch);/*添加一个字符到逆波兰式表达式队列*/
char FetchRPN(void); /*取逆波兰式表达式队列当前字符*/
char CurRPN(void); /*逆波兰式队列当前字符*/
void RewindRPN(void);/*初始化逆波兰式队列指针起始位置*/ 

void Prompt(void);
void ChangetoRPN(void);
void CompRPN(void);
 
main()
{
    Prompt();/*提示输入中缀算术表达式*/
    ChangetoRPN();/*中缀表达式转换为逆波兰式*/
    CompRPN();/*计算逆波兰式的值*/
    system("pause");
}

/*提示信息*/
void Prompt(void)
{
     printf("请输入中缀算术表达式：");
}

/*转换为拟波兰式时的操作符堆栈及操作函数*/
char StackOp[MAXOP];/*操作符堆栈*/ 
int OpTop = -1;/*操作符堆栈栈顶指针*/
void PushOp(char op);/*操作符进栈*/
char PopOp(void); /*操作符出栈*/
char TopOp(void);/*操作符栈顶元素*/

/*转换为逆波兰式*/
void ChangetoRPN(void)
{
    bool isEnd = FALSE;
    char ch;
    
    while (!isEnd) {
        ch = getchar();
        switch (ch) {
            case '(':
                 PushOp(ch);
                 break;
            case ')':
                 if (CurRPN()!=' ') AppendRPN(' ');                 
                 while (TopOp() != '(') {
                     AppendRPN(PopOp());
                     AppendRPN(' ');
                 }
                 PopOp();/*Throw away the '(' character*/
                 break;
            case '+':
            case '-':
                 if (CurRPN()!=' ') AppendRPN(' ');
                 while (TopOp() != EMPTY && TopOp() != '(') {
                     AppendRPN(PopOp());
                     AppendRPN(' ');
                 }
                 PushOp(ch); 
                 break;
            case '*':
            case '/':
                 if (CurRPN()!=' ') AppendRPN(' ');
                 while (TopOp() == '*' || TopOp() == '/'){
                     AppendRPN(PopOp());
                     AppendRPN(' ');
                 } 
                 PushOp(ch);
                 break;
            case '\n':
                 if (CurRPN()!=' ') AppendRPN(' ');
                 while (TopOp()!= EMPTY) {
                       AppendRPN(PopOp());
                       AppendRPN(' ');
                 }
                 AppendRPN(ch);
                 isEnd = TRUE;
                 break;
            case ' ':
            case '\t':/*Throw away the blank character*/
                 break;
            default:      /*0,1,2,3,4,5,6,7,8,9 and .*/
                AppendRPN(ch);
                break;
        }
    } 
     AppendRPN('\0');
     printf("其逆波兰式是：%s", RPN);
}

/*以下为逆波兰式队列操作函数*/
void AppendRPN(char ch)/*添加一个字符到逆波兰式队列队尾*/
{
     RPN[++pRPN] = ch;
}

char FetchRPN(void) /*取逆波兰式表达式队列当前字符*/
{
     return  RPN[pRPN++];
}

char CurRPN(void) /*逆波兰式队列当前字符*/
{
     return RPN[pRPN];
}

void RewindRPN(void)/*初始化逆波兰式队列初始位置指针*/ 
{
     pRPN = 0;
}

/*以下为操作符堆栈操作函数*/     
void PushOp(char Op)/*操作符进栈*/
{
     StackOp[++OpTop] = Op;
}

char PopOp(void) /*操作符出栈*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop--];
}

char TopOp(void) /*操作符栈顶元素*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop];
}

/*计算逆波兰式时的操作数堆栈和操作函数*/
double StackOpn[MAXOPN]; /*计算逆波兰表达式时的操作数堆栈*/
int OpnTop = -1;/*计算逆波兰表达式时的操作数堆栈栈顶指针*/
void PushOpn(double Opn);/*操作数进栈*/
double PopOpn(void); /*操作数出栈*/
double TopOpn(void);/*操作数栈顶元素*/

#define NUMBER '0'  /*操作对象类型为操作数*/
char GetOp(char num[]);/*获取逆波兰式队列的当前位置操作对象*/

/*获取逆波兰式队列的当前位置操作对象
  NUMBER：操作数
  '+','-','*','/':操作符
  '\n': 结束符
  其它：无效对象
*/
 char GetOp(char num[])
{
    char opType = 0;
    int i = 0;
 
    while (CurRPN() == ' ') FetchRPN();/*Skip the SPACE*/    

    switch(CurRPN()) {
    case '0':case '1':case '2':case '3':case '4':
    case '5':case '6':case '7':case '8':case '9': /*数字字符*/
         opType = NUMBER;
         while (isdigit(CurRPN())) num[i++] = FetchRPN();/*整数部分*/
         if (CurRPN() == '.') {/*小数点*/
             num[i++] = FetchRPN();
             while (isdigit(CurRPN())) num[i++] = FetchRPN();/*小数部分*/
         }
         num[i] = '\0';
         break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '\n':
         opType = FetchRPN();
         break;
    default:
         opType = '#';
    }
    return opType;    
} 

void CompRPN(void)
{
     double opn1, opn2, result=0;
     bool isEnd = FALSE;
     int op;
     char tmp[20]; /*操作数数字字符序列*/     
     
     RewindRPN();/*初始化逆波兰式队列位置指针*/
     while (!isEnd) {
         op = GetOp(tmp);
         switch(op) {
         case NUMBER:
              PushOpn(atof(tmp));
              break;
         case '+':
              PushOpn(PopOpn() + PopOpn());
              break;
         case '-':
              opn2 = PopOpn();
              PushOpn(PopOpn() - opn2);
              break;
         case '*':
              PushOpn(PopOpn() * PopOpn());
              break;
         case '/':
              opn2 = PopOpn();
              PushOpn(PopOpn() / opn2);
              break;
         case '\n':
              printf("The value of the expression is: %g\n", PopOpn());
              isEnd = TRUE;
              break; 
         default:
              printf("Invalid expression!\n");
              return;
         }    
     }
}

/*以下为操作数堆栈函数*/

void PushOpn(double Opn)/*操作数进栈*/
{
     StackOpn[++OpnTop] = Opn;
}

double PopOpn(void) /*操作数出栈*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop--];
}

double TopOpn(void) /*操作数栈顶元素*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop];
} 
