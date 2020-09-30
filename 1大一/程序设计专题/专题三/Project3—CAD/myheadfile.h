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

#define bx 0.2//定义文本框x坐标 
#define TIMER_BLINK  1
//宏定义光标闪烁石时间 


//创建结构来记录每个图形起始位置结束位置以及编号和类型 
struct picture{
	int num;
	double x1;
	double y1;
	double x2;
	double y2;
	int type;
}pic[100],temp;//type初始化为0，有4种（1、2、3、4），其中1是直线，2是椭圆，3是矩形，4是文本 

//记录此时所选择的选项 
bool isdraw = FALSE;//记录是否开始画图 
bool ischoose = FALSE;
bool isline = FALSE;
bool iscircle = FALSE;
bool isrectangle = FALSE;
bool istext = FALSE;
bool ischange = FALSE;
bool ismove = FALSE;
bool isBlink = FALSE;//记录光标闪烁 
bool isdelete = FALSE;
 
char text[99][100];//记录文本
 
double omx,omy;//记录鼠标移动前的鼠标位置 
int picnum,location,textlen,textnum;//分别记录图片编号，输入文本时所在位置，长度，以及文本的个数 
double startx,starty;//记录画图开始的位置 
double choosey,ly,cy,ry,ty,dy;//记录选项按钮的纵坐标 
char str[2]={0};//临时字符串来进行字符操作 
const int mseconds = 750;

void MouseEventProcess(int x, int y, int button, int event);/*鼠标消息回调函数*/
void KeyboardEventProcess(int key,int event);/*键盘消息回调函数*/ 
void CharEventProcess(char c);/*字符消息回调函数*/ 
void TimerEventProcess(int timerID);/*定时器消息回调函数*/ 

double f(double x0,double x1,double y1,double x2,double y2);
void DrawRectangle(double lenth,double width);//画矩形 
bool InBox(double x0, double y0, double x1, double x2, double y1, double y2);//判断是否在框内 
void initialize(void);//初始化界面 


#endif 
