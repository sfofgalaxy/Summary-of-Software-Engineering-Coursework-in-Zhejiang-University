/*infix2rpn.c --- Change infix notation to postfix notation (RPN)
*/
#include <stdio.h>
#include "genlib.h"

#define MAXEXP  200
#define MAXOP   30

#define EMPTY '\0'

/*逆波兰式队列及操作函数*/
char RPN[MAXEXP]; /*逆波兰式表达式队列，以回车结束*/
int pRPN = -1;/*逆波兰式表达式队列当前位置，初始为-1*/
void AppendRPN(char ch);/*添加一个字符到逆波兰式表达式队列*/
char FetchRPN(void); /*取逆波兰式表达式队列当前字符*/
char CurRPN(void); /*逆波兰式队列当前字符*/
void RewindRPN(void);/*初始化逆波兰式队列指针起始位置*/ 

void Prompt(void);
void ChangetoRPN(void);
void PrintRPN(void); 
 
main()
{
    Prompt();/*提示输入中缀算术表达式*/
    ChangetoRPN();/*中缀表达式转换为逆波兰式*/
    PrintRPN();/*打印波兰式*/
}

/*提示信息*/
void Prompt(void)
{
     printf("请输入中缀算术表达式：");
}

void PrintRPN(void)
{
     int i = 0;
     
     while (RPN[i++]!='\n') putchar(RPN[i-1]);
     putchar('\n');
}
/*转换为逆波兰式时的操作符堆栈及操作函数*/
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
