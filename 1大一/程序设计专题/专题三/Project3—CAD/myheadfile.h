#ifndef _myheadfile_h
#define _myheadfile_h

#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#define bx 0.2//�����ı���x���� 
#define TIMER_BLINK  1
//�궨������˸ʯʱ�� 


//�����ṹ����¼ÿ��ͼ����ʼλ�ý���λ���Լ���ź����� 
struct picture{
	int num;
	double x1;
	double y1;
	double x2;
	double y2;
	int type;
}pic[100],temp;//type��ʼ��Ϊ0����4�֣�1��2��3��4��������1��ֱ�ߣ�2����Բ��3�Ǿ��Σ�4���ı� 

//��¼��ʱ��ѡ���ѡ�� 
bool isdraw = FALSE;//��¼�Ƿ�ʼ��ͼ 
bool ischoose = FALSE;
bool isline = FALSE;
bool iscircle = FALSE;
bool isrectangle = FALSE;
bool istext = FALSE;
bool ischange = FALSE;
bool ismove = FALSE;
bool isBlink = FALSE;//��¼�����˸ 
bool isdelete = FALSE;
 
char text[99][100];//��¼�ı�
 
double omx,omy;//��¼����ƶ�ǰ�����λ�� 
int picnum,location,textlen,textnum;//�ֱ��¼ͼƬ��ţ������ı�ʱ����λ�ã����ȣ��Լ��ı��ĸ��� 
double startx,starty;//��¼��ͼ��ʼ��λ�� 
double choosey,ly,cy,ry,ty,dy;//��¼ѡ�ť�������� 
char str[2]={0};//��ʱ�ַ����������ַ����� 
const int mseconds = 750;

void MouseEventProcess(int x, int y, int button, int event);/*�����Ϣ�ص�����*/
void KeyboardEventProcess(int key,int event);/*������Ϣ�ص�����*/ 
void CharEventProcess(char c);/*�ַ���Ϣ�ص�����*/ 
void TimerEventProcess(int timerID);/*��ʱ����Ϣ�ص�����*/ 

double f(double x0,double x1,double y1,double x2,double y2);
void DrawRectangle(double lenth,double width);//������ 
bool InBox(double x0, double y0, double x1, double x2, double y1, double y2);//�ж��Ƿ��ڿ��� 
void initialize(void);//��ʼ������ 


#endif 
