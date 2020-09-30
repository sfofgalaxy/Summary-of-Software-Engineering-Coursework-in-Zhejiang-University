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

/*�沨��ʽ���м���������*/
char RPN[MAXEXP]; /*�沨��ʽ���ʽ���У��Իس�����*/
int pRPN = -1;/*�沨��ʽ���ʽ���е�ǰλ�ã���ʼΪ-1*/
void AppendRPN(char ch);/*���һ���ַ����沨��ʽ���ʽ����*/
char FetchRPN(void); /*ȡ�沨��ʽ���ʽ���е�ǰ�ַ�*/
char CurRPN(void); /*�沨��ʽ���е�ǰ�ַ�*/
void RewindRPN(void);/*��ʼ���沨��ʽ����ָ����ʼλ��*/ 

void Prompt(void);
void ChangetoRPN(void);
void CompRPN(void);
 
main()
{
    Prompt();/*��ʾ������׺�������ʽ*/
    ChangetoRPN();/*��׺���ʽת��Ϊ�沨��ʽ*/
    CompRPN();/*�����沨��ʽ��ֵ*/
    system("pause");
}

/*��ʾ��Ϣ*/
void Prompt(void)
{
     printf("��������׺�������ʽ��");
}

/*ת��Ϊ�Ⲩ��ʽʱ�Ĳ�������ջ����������*/
char StackOp[MAXOP];/*��������ջ*/ 
int OpTop = -1;/*��������ջջ��ָ��*/
void PushOp(char op);/*��������ջ*/
char PopOp(void); /*��������ջ*/
char TopOp(void);/*������ջ��Ԫ��*/

/*ת��Ϊ�沨��ʽ*/
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
     printf("���沨��ʽ�ǣ�%s", RPN);
}

/*����Ϊ�沨��ʽ���в�������*/
void AppendRPN(char ch)/*���һ���ַ����沨��ʽ���ж�β*/
{
     RPN[++pRPN] = ch;
}

char FetchRPN(void) /*ȡ�沨��ʽ���ʽ���е�ǰ�ַ�*/
{
     return  RPN[pRPN++];
}

char CurRPN(void) /*�沨��ʽ���е�ǰ�ַ�*/
{
     return RPN[pRPN];
}

void RewindRPN(void)/*��ʼ���沨��ʽ���г�ʼλ��ָ��*/ 
{
     pRPN = 0;
}

/*����Ϊ��������ջ��������*/     
void PushOp(char Op)/*��������ջ*/
{
     StackOp[++OpTop] = Op;
}

char PopOp(void) /*��������ջ*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop--];
}

char TopOp(void) /*������ջ��Ԫ��*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop];
}

/*�����沨��ʽʱ�Ĳ�������ջ�Ͳ�������*/
double StackOpn[MAXOPN]; /*�����沨�����ʽʱ�Ĳ�������ջ*/
int OpnTop = -1;/*�����沨�����ʽʱ�Ĳ�������ջջ��ָ��*/
void PushOpn(double Opn);/*��������ջ*/
double PopOpn(void); /*��������ջ*/
double TopOpn(void);/*������ջ��Ԫ��*/

#define NUMBER '0'  /*������������Ϊ������*/
char GetOp(char num[]);/*��ȡ�沨��ʽ���еĵ�ǰλ�ò�������*/

/*��ȡ�沨��ʽ���еĵ�ǰλ�ò�������
  NUMBER��������
  '+','-','*','/':������
  '\n': ������
  ��������Ч����
*/
 char GetOp(char num[])
{
    char opType = 0;
    int i = 0;
 
    while (CurRPN() == ' ') FetchRPN();/*Skip the SPACE*/    

    switch(CurRPN()) {
    case '0':case '1':case '2':case '3':case '4':
    case '5':case '6':case '7':case '8':case '9': /*�����ַ�*/
         opType = NUMBER;
         while (isdigit(CurRPN())) num[i++] = FetchRPN();/*��������*/
         if (CurRPN() == '.') {/*С����*/
             num[i++] = FetchRPN();
             while (isdigit(CurRPN())) num[i++] = FetchRPN();/*С������*/
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
     char tmp[20]; /*�����������ַ�����*/     
     
     RewindRPN();/*��ʼ���沨��ʽ����λ��ָ��*/
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

/*����Ϊ��������ջ����*/

void PushOpn(double Opn)/*��������ջ*/
{
     StackOpn[++OpnTop] = Opn;
}

double PopOpn(void) /*��������ջ*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop--];
}

double TopOpn(void) /*������ջ��Ԫ��*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop];
} 
