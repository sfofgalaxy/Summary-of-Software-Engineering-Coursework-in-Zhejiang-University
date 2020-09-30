/*infix2rpn.c --- Change infix notation to postfix notation (RPN)
*/
#include <stdio.h>
#include "genlib.h"

#define MAXEXP  200
#define MAXOP   30

#define EMPTY '\0'

/*�沨��ʽ���м���������*/
char RPN[MAXEXP]; /*�沨��ʽ���ʽ���У��Իس�����*/
int pRPN = -1;/*�沨��ʽ���ʽ���е�ǰλ�ã���ʼΪ-1*/
void AppendRPN(char ch);/*���һ���ַ����沨��ʽ���ʽ����*/
char FetchRPN(void); /*ȡ�沨��ʽ���ʽ���е�ǰ�ַ�*/
char CurRPN(void); /*�沨��ʽ���е�ǰ�ַ�*/
void RewindRPN(void);/*��ʼ���沨��ʽ����ָ����ʼλ��*/ 

void Prompt(void);
void ChangetoRPN(void);
void PrintRPN(void); 
 
main()
{
    Prompt();/*��ʾ������׺�������ʽ*/
    ChangetoRPN();/*��׺���ʽת��Ϊ�沨��ʽ*/
    PrintRPN();/*��ӡ����ʽ*/
}

/*��ʾ��Ϣ*/
void Prompt(void)
{
     printf("��������׺�������ʽ��");
}

void PrintRPN(void)
{
     int i = 0;
     
     while (RPN[i++]!='\n') putchar(RPN[i-1]);
     putchar('\n');
}
/*ת��Ϊ�沨��ʽʱ�Ĳ�������ջ����������*/
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
