#include "graphics.h"  
#include "extgraph.h"  
#include "genlib.h"  
#include "simpio.h"  
#include "strlib.h"  
#include "conio.h"  
#include <stdio.h>  
#include <stdlib.h>  
#include <stddef.h>  
  
#include <windows.h>  
#include <olectl.h>  
#include <stdio.h>  
#include <mmsystem.h>  
#include <wingdi.h>  
#include <ole2.h>  
#include <ocidl.h>  
#include <winuser.h>

#define TIMER_BLINK  1			 /*定时器事件标志号*/

const int mseconds = 750;

static char text[100]={0}; /*输入的字符串缓冲区*/
static int textlen = 0;/*输入的字符串长度*/
static int location = 0;/*定义当前位置*/ 
static char str[2]={0};//定义长度为二的字符串以便进行单个字符的操作 

static bool isBlink = TRUE;   /*是否闪烁标志*/

void KeyboardEventProcess(int key,int event);/*键盘消息回调函数*/
void CharEventProcess(char c);/*字符消息回调函数*/
void MouseEventProcess(int x, int y, int button, int event);/*鼠标消息回调函数*/
void TimerEventProcess(int timerID);/*定时器消息回调函数*/ 
void Main(void){
	InitGraphics();    
	MovePen(0.2,GetWindowHeight()/2); 
	registerKeyboardEvent(KeyboardEventProcess);/*注册键盘消息回调函数*/
	registerCharEvent(CharEventProcess);/*注册字符消息回调函数*/
	registerTimerEvent(TimerEventProcess);/*注册定时器消息回调函数*/
	startTimer(TIMER_BLINK, mseconds);
} 

void KeyboardEventProcess(int key,int event)
{
	switch(event){
		case KEY_DOWN:
			switch(key){
				case VK_BACK: 
					{
						if(location<=0)return;
						SetEraseMode(TRUE);
						DrawTextString("_");
						SetEraseMode(FALSE);
						MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
						int i; 
						string s1,s2;
						s1 = SubString(text,location,textlen);
						s2 = SubString(text,location-1,textlen);
						SetEraseMode(TRUE);
						str[0] = text[--location];
						MovePen(GetCurrentX()-TextStringWidth(str),GetCurrentY());
						DrawTextString(s2);
						SetEraseMode(FALSE);
						MovePen(GetCurrentX()-TextStringWidth(s2),GetCurrentY());
						DrawTextString(s1);
						MovePen(GetCurrentX()-TextStringWidth(s1),GetCurrentY());
						DrawTextString("_");
						MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
						isBlink = TRUE;
						for(i=location;i<textlen;i++)text[i]=text[i+1];
						textlen--; 
						break;
					}
				case VK_DELETE:
					{
						if(location>=textlen-1)return;
						int i; 
						string s1,s2; 
						location++;
						s1 = SubString(text,location,textlen);
						s2 = SubString(text,location-1,textlen);
						SetEraseMode(TRUE);
						str[0] = text[--location];
						DrawTextString(s2);
						SetEraseMode(FALSE);
						MovePen(GetCurrentX()-TextStringWidth(s2),GetCurrentY());
						DrawTextString(s1);
						MovePen(GetCurrentX()-TextStringWidth(s1),GetCurrentY());
						for(i=location;i<textlen;i++)text[i]=text[i+1];
						textlen--; 
						break;
					}
				case VK_LEFT:
					if(location==0)return;
					string s;
					location--;
					str[0]=text[location];
					SetEraseMode(TRUE);
					DrawTextString("_");
					MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY()); 
					SetEraseMode(FALSE);
					MovePen(GetCurrentX()-TextStringWidth(str),GetCurrentY());
					DrawTextString("_");
					MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY()); 
					isBlink = TRUE;
					break;
				case VK_RIGHT:
					if(location==textlen)return;
					str[0] = text[location];
					location++;
					SetEraseMode(TRUE);
					DrawTextString("_");
					MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
					SetEraseMode(FALSE);
					MovePen(GetCurrentX()+TextStringWidth(str),GetCurrentY());
					DrawTextString("_");
					MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
					isBlink = TRUE;
					break;
				default:
					break;
		}
		 default:
			break; 
	}
	return;
}

void CharEventProcess(char c)
{
	if(textlen>=99||GetCurrentX()>GetWindowWidth()||c==VK_DELETE||c==VK_BACK)return;
	switch(c){
		int i;
		case '\r':
			if(text[0]==0)return;
			SetEraseMode(TRUE);
			DrawTextString("_");
			SetEraseMode(FALSE);
			MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
			InitConsole();
			printf("%s\n",text);
			system("pause");
			FreeConsole();
			MovePen(0.2,GetWindowHeight()/2);
			SetEraseMode(TRUE);
			DrawTextString(text);
			SetEraseMode(FALSE);
			MovePen(0.2,GetWindowHeight()/2);
			location = 0;
			for(i=0;i<100;i++)text[i]=0;
			textlen = 0;
			break;
		default:{
			str[0] = c;
				SetEraseMode(TRUE);
				DrawTextString("_");
				MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
				SetEraseMode(FALSE);
				string s;
				s = SubString(text,location,textlen);
				SetEraseMode(TRUE);
				DrawTextString(s);
				SetEraseMode(FALSE);
				MovePen(GetCurrentX()-TextStringWidth(s),GetCurrentY());
				DrawTextString(str);
				DrawTextString(s);
				MovePen(GetCurrentX()-TextStringWidth(s),GetCurrentY());
				DrawTextString("_");
				MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
				isBlink = TRUE;
				for(i=textlen;i>location;i--)text[i]=text[i-1];
				text[location] = c;
				location++;
				textlen++;
				break;		
		}	
	}
}

void TimerEventProcess(int timerID){
		switch (timerID) {
	   		case TIMER_BLINK: /*光标闪烁定时器*/
				SetEraseMode(isBlink);
				DrawTextString("_");/*当前位置会随字符串后移*/
				MovePen(GetCurrentX()-TextStringWidth("_"), GetCurrentY());
				isBlink = !isBlink;/*交替显示/隐藏光标*/
				break;
			default:
				break;
		}
}
