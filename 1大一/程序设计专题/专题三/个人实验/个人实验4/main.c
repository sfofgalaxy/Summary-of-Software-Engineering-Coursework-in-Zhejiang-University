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

#define TIMER_BLINK  1			 /*��ʱ���¼���־��*/

const int mseconds = 750;

static char text[100]={0}; /*������ַ���������*/
static int textlen = 0;/*������ַ�������*/
static int location = 0;/*���嵱ǰλ��*/ 
static char str[2]={0};//���峤��Ϊ�����ַ����Ա���е����ַ��Ĳ��� 

static bool isBlink = TRUE;   /*�Ƿ���˸��־*/

void KeyboardEventProcess(int key,int event);/*������Ϣ�ص�����*/
void CharEventProcess(char c);/*�ַ���Ϣ�ص�����*/
void MouseEventProcess(int x, int y, int button, int event);/*�����Ϣ�ص�����*/
void TimerEventProcess(int timerID);/*��ʱ����Ϣ�ص�����*/ 
void Main(void){
	InitGraphics();    
	MovePen(0.2,GetWindowHeight()/2); 
	registerKeyboardEvent(KeyboardEventProcess);/*ע�������Ϣ�ص�����*/
	registerCharEvent(CharEventProcess);/*ע���ַ���Ϣ�ص�����*/
	registerTimerEvent(TimerEventProcess);/*ע�ᶨʱ����Ϣ�ص�����*/
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
	   		case TIMER_BLINK: /*�����˸��ʱ��*/
				SetEraseMode(isBlink);
				DrawTextString("_");/*��ǰλ�û����ַ�������*/
				MovePen(GetCurrentX()-TextStringWidth("_"), GetCurrentY());
				isBlink = !isBlink;/*������ʾ/���ع��*/
				break;
			default:
				break;
		}
}
