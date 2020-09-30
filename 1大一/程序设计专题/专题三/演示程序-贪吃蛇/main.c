#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>


#define  INIT_X                0     //��Ϸԭ��X���� 
#define  INIT_Y                0     //��Ϸԭ��Y����  ��0,0��λ�ڵ�ͼ�����½� 
#define  GAME_WIDE             9     //��Ϸ����Ŀ� 
#define  GAME_HEIGHT           6     //��Ϸ����ĸ� 
#define  BOX_WIDE              0.3   //�����巽��߳� 

const int speed = 75;          //��ʱ���ٶȣ�Ҳ�������ƶ����ٶȣ�ԽСԽ�� 
bool isStart = 0;               //�����ж����Ƿ����ƶ�״̬��bool���� 
int map[30][20]={0};            //��ͼ����������ߣ��߱߳������˵�ͼ��С��30*20����ʼ��ֵΪ0����ʾ�ա�1,2,3,4��ʾ�����ֱ��ʾ���������������ƶ���5��ʾʵ� 

struct node{
	int x;
	int y;
};
struct node head;                //��ͷ������� 
struct node tail;                //��β������� 
struct node tmp;                 //��ͼλ���ݴ��� ����TimerEventProcess�������ݴ���β��� ���� 

static int CurrentDirection=1;   //��ǰ�ߵ��ƶ����򣬳�ʼ���� 
static int d;                    //���¼����Ժ�����ķ����������¼������ң���ʹd����1 

void DrawArea();                  //������Ϸ��ʼ�߽� 
void DrawBox(double x, double y); //�ڣ�x��y��������һ��С���� 
void CreatFood();                 //����ʳ�� 
void DrawSnake();                 //���ݵ�ǰ��ͼ��Ϣ������������һ���� 
void InitSnake();                 //��ʼ���� 
void KeyboardEventProcess(int key,int event);//������Ϣ�ص�����
void TimerEventProcess(int timerID);//��ʱ����Ϣ�ص�����

void Main(){
	InitGraphics();
    DrawArea();
	InitSnake();
	CreatFood();
	DrawSnake();
	registerKeyboardEvent(KeyboardEventProcess);/*ע�������Ϣ�ص�����*/
	registerTimerEvent(TimerEventProcess);/*ע�ᶨʱ����Ϣ�ص�����*/
}

void DrawArea(){
	SetPenSize(2);
	SetPenColor("blue");
	MovePen(INIT_X, INIT_Y);
    DrawLine(GAME_WIDE, 0);
    DrawLine(0, GAME_HEIGHT);
    DrawLine(-GAME_WIDE,0);
    DrawLine(0, -GAME_HEIGHT);
} 

void DrawBox(double x, double y){  
	SetPenSize(1);
    MovePen(x, y);
    DrawLine(BOX_WIDE, 0);
    DrawLine(0, BOX_WIDE);
    DrawLine(-BOX_WIDE, 0);
    DrawLine(0, -BOX_WIDE);
}

void CreatFood()	
{
	int x, y;
	srand((unsigned)time(NULL));
	while (1)
	{
		x = rand() % 30;  //ѡ��һ��������� 
		y = rand() % 20;

		if (map[x][y] != 1&map[x][y] != 2&&map[x][y] != 3&&&map[x][y] != 4)  //�����ǰ���겻������ 
		{
			map[x][y] = 5;                                                   //���õ�ǰ������5����ʾʳ�� 
			SetPenColor("green");                                            //�û��ʱ��� 
		    DrawBox(x*BOX_WIDE,y*BOX_WIDE);                                  //��ʳ�� 
			break;
		}

	}

}

void DrawSnake(){
	int i,j;
	SetPenColor("red");           //�����趨Ϊ��ɫ 
	for(i=0;i<30;i++)             //������ͼ���������� 
		for(j=0;j<20;j++){
			if(map[i][j]==1||map[i][j]==2||map[i][j]==3||map[i][j]==4){
				DrawBox(i*BOX_WIDE,j*BOX_WIDE);
				}
		}
}

void InitSnake(){     //�����ʼ����ͷ��㣨3,10����β��㣨1,10�����ܹ�ռ�������飬�������� 
	head.x=3;
	head.y=10;
	tail.x=1;
	tail.y=10;
	map[1][10]=1;
	map[2][10]=1;
	map[3][10]=1;
}
 
void KeyboardEventProcess(int key,int event)/*ÿ������������Ϣ����Ҫִ��*/
{	 
     switch (event) {
	 	case KEY_DOWN:
			 switch (key) {
			     case VK_ESCAPE:/*����ESC���򿪻�رն�ʱ��������Ϸ��ʼ������ͣ*/
                     isStart = !isStart;
                     if (isStart) {
						startTimer(1, speed);
                     } else {
						cancelTimer(1);
					 }
                     break;
                 case VK_UP:/*�����ϼ�������֮�������ǰ����Ͱ��²���ͻ����ı䵱ǰ����������ǰ���������ң���ô�Ϻ��²��Ƿǳ�ͻ����������������ͬ��*/
                     d=2;
                     if((d+CurrentDirection)%2!=0)
                     	CurrentDirection=2;
                     break;
			     case VK_DOWN:
			     	 d=4;
			     	 if((d+CurrentDirection)%2!=0)
                     	CurrentDirection=4;
                     break;
			     case VK_LEFT:
			     	 d=3;
			     	 if((d+CurrentDirection)%2!=0)
                     	CurrentDirection=3;
                     break;
			     case VK_RIGHT:
			     	 d=1;
			     	 if((d+CurrentDirection)%2!=0)
                     	CurrentDirection=1;
                     break;
			 }
			 break;
		case KEY_UP:
			 break;
	 }	 
}
 
void TimerEventProcess(int timerID)/*��ʱ���ص����������������ߵ��ƶ�*/
{
	  switch (timerID) {
	    case 1: 
		  if (!isStart) return;
          SetEraseMode(TRUE);
		  DrawSnake();	  
          map[head.x][head.y]=CurrentDirection;
          int tailD= map[tail.x][tail.y];            //�ݴ���β�ƶ����� 
		  tmp = tail;                                //�ݴ���β���� 
          map[tail.x][tail.y]=0;                     //�����ߵ��ƶ�����ͼ��ԭ������βλ����� 
          if(tailD==1){                              //����֮ǰ��β���ƶ����򣬸�����β���� 
          	tail.x+=1;
          }
          else if(tailD==2){
          	tail.y+=1;
          }
          else if(tailD==3){
          	tail.x-=1;
          }
          else if(tailD==4){
          	tail.y-=1;
          }
          
          if(CurrentDirection==1){                    //�����ߵ�ǰ�ƶ����򣬸�����ͷ���� 
          	head.x+=1;	
          }
          else if(CurrentDirection==2){
          	head.y+=1;
          }
          else if(CurrentDirection==3){
          	head.x-=1;
          }
          else if(CurrentDirection==4){
          	head.y-=1;
          }
          if(map[head.x][head.y]==5){                //��������ͷ�����Ժ󣬷��ֳԵ�ʳ�� ����˵���߳��ȼ�һ����������β����ĸ��� �������ƶ����ֳԵ���ʳ���βλ��û�� 
          	tail=tmp;                                 
          	map[tail.x][tail.y]=tailD;
          }
          if(map[head.x][head.y]!=0&&map[head.x][head.y]!=5){  //��ײ���������� 
          	cancelTimer(1);
          	char text[100]="GAME OVER";
          	MovePen(4,3);
          	SetEraseMode(FALSE);
          	SetPenSize(10);
          	DrawTextString(text);
          	break;
          }
          if(head.x<0||head.x>29||head.y<0||head.y>19){        //��ײ��ǽ������ 
          	cancelTimer(1);
          	char text[100]="GAME OVER";
          	MovePen(4,3);
          	SetEraseMode(FALSE);
          	SetPenSize(10);
          	DrawTextString(text);
          	break;
          }
          map[head.x][head.y]=CurrentDirection;
          SetEraseMode(FALSE);
		  DrawSnake();
          int i,j;
          int Exist=0;            //�����жϵ�ͼ���Ƿ����ʳ�� 
          for(i=0;i<30;i++)
		  	for(j=0;j<20;j++){
				if(map[i][j]==5){
				Exist=1;
				}
			}
		  if(Exist==0){           //�����ھʹ���ʳ�� 
		  	CreatFood(); 
		  }
		  
		  break;
	    default:
		  break;
	  }
} 
