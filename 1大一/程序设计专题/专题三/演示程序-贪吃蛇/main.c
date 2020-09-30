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


#define  INIT_X                0     //游戏原点X坐标 
#define  INIT_Y                0     //游戏原点Y坐标  （0,0）位于地图的左下角 
#define  GAME_WIDE             9     //游戏区域的宽 
#define  GAME_HEIGHT           6     //游戏区域的高 
#define  BOX_WIDE              0.3   //蛇身体方块边长 

const int speed = 75;          //定时器速度，也就是蛇移动的速度，越小越快 
bool isStart = 0;               //用于判断蛇是否处于移动状态的bool变量 
int map[30][20]={0};            //地图，由区域宽，高，蛇边长决定了地图大小是30*20，初始赋值为0，表示空。1,2,3,4表示蛇身，分别表示正在向右上左下移动，5表示实物。 

struct node{
	int x;
	int y;
};
struct node head;                //蛇头结点坐标 
struct node tail;                //蛇尾结点坐标 
struct node tmp;                 //地图位置暂存结点 ，在TimerEventProcess函数中暂存蛇尾结点 坐标 

static int CurrentDirection=1;   //当前蛇的移动方向，初始向右 
static int d;                    //按下键盘以后产生的方向，例，按下键盘向右，就使d等于1 

void DrawArea();                  //画出游戏初始边界 
void DrawBox(double x, double y); //在（x，y）处画出一个小方块 
void CreatFood();                 //产生食物 
void DrawSnake();                 //根据当前地图信息，画出完整的一条蛇 
void InitSnake();                 //初始化蛇 
void KeyboardEventProcess(int key,int event);//键盘消息回调函数
void TimerEventProcess(int timerID);//定时器消息回调函数

void Main(){
	InitGraphics();
    DrawArea();
	InitSnake();
	CreatFood();
	DrawSnake();
	registerKeyboardEvent(KeyboardEventProcess);/*注册键盘消息回调函数*/
	registerTimerEvent(TimerEventProcess);/*注册定时器消息回调函数*/
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
		x = rand() % 30;  //选定一个随机坐标 
		y = rand() % 20;

		if (map[x][y] != 1&map[x][y] != 2&&map[x][y] != 3&&&map[x][y] != 4)  //如果当前坐标不是蛇身 
		{
			map[x][y] = 5;                                                   //就让当前坐标变成5，表示食物 
			SetPenColor("green");                                            //让画笔变绿 
		    DrawBox(x*BOX_WIDE,y*BOX_WIDE);                                  //画食物 
			break;
		}

	}

}

void DrawSnake(){
	int i,j;
	SetPenColor("red");           //蛇身设定为红色 
	for(i=0;i<30;i++)             //遍历地图，画出蛇身 
		for(j=0;j<20;j++){
			if(map[i][j]==1||map[i][j]==2||map[i][j]==3||map[i][j]==4){
				DrawBox(i*BOX_WIDE,j*BOX_WIDE);
				}
		}
}

void InitSnake(){     //蛇身初始化，头结点（3,10），尾结点（1,10），总共占三个方块，方向都向右 
	head.x=3;
	head.y=10;
	tail.x=1;
	tail.y=10;
	map[1][10]=1;
	map[2][10]=1;
	map[3][10]=1;
}
 
void KeyboardEventProcess(int key,int event)/*每当产生键盘消息，都要执行*/
{	 
     switch (event) {
	 	case KEY_DOWN:
			 switch (key) {
			     case VK_ESCAPE:/*键盘ESC，打开或关闭定时器，让游戏开始或者暂停*/
                     isStart = !isStart;
                     if (isStart) {
						startTimer(1, speed);
                     } else {
						cancelTimer(1);
					 }
                     break;
                 case VK_UP:/*键盘上键，按下之后如果当前方向和按下不冲突，则改变当前方向，例：当前方向是向右，那么上和下才是非冲突方向，其他三个方向同理*/
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
 
void TimerEventProcess(int timerID)/*定时器回调函数，用来控制蛇的移动*/
{
	  switch (timerID) {
	    case 1: 
		  if (!isStart) return;
          SetEraseMode(TRUE);
		  DrawSnake();	  
          map[head.x][head.y]=CurrentDirection;
          int tailD= map[tail.x][tail.y];            //暂存蛇尾移动方向 
		  tmp = tail;                                //暂存蛇尾坐标 
          map[tail.x][tail.y]=0;                     //由于蛇的移动，地图上原来的蛇尾位置清空 
          if(tailD==1){                              //根据之前蛇尾的移动方向，更新蛇尾坐标 
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
          
          if(CurrentDirection==1){                    //根据蛇当前移动方向，更新蛇头坐标 
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
          if(map[head.x][head.y]==5){                //更新完蛇头坐标以后，发现吃到食物 ，就说明蛇长度加一，撤销对蛇尾坐标的更新 ，即，移动后又吃到了食物，蛇尾位置没变 
          	tail=tmp;                                 
          	map[tail.x][tail.y]=tailD;
          }
          if(map[head.x][head.y]!=0&&map[head.x][head.y]!=5){  //蛇撞到自身死亡 
          	cancelTimer(1);
          	char text[100]="GAME OVER";
          	MovePen(4,3);
          	SetEraseMode(FALSE);
          	SetPenSize(10);
          	DrawTextString(text);
          	break;
          }
          if(head.x<0||head.x>29||head.y<0||head.y>19){        //蛇撞到墙壁死亡 
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
          int Exist=0;            //用来判断地图上是否存在食物 
          for(i=0;i<30;i++)
		  	for(j=0;j<20;j++){
				if(map[i][j]==5){
				Exist=1;
				}
			}
		  if(Exist==0){           //不存在就创建食物 
		  	CreatFood(); 
		  }
		  
		  break;
	    default:
		  break;
	  }
} 
