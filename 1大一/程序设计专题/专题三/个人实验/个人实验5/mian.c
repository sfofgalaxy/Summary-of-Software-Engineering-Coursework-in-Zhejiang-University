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
#include <math.h> 

#define PI 3.1415926535

void KochFractal(double size, int order); 
void DrawFractalLine(double len, double theta, int order); 
void DrawPolarLine(double r ,double theta);
void MouseEventProcess(int x,int y,int button,int event);
void Main(void){
	double size;
	int order;
	InitGraphics();
	InitConsole();  
	printf("请输入零阶时等边三角形的边长大小：");
	scanf("%lf",&size);   
	printf("请输入雪花阶数：");
	scanf("%d",&order);
	KochFractal(size, order);
	FreeConsole();
}

void DrawFractalLine(double len, double theta, int order) {
	if (order == 0)DrawPolarLine(len,theta);
	else {
		DrawFractalLine(len/3,theta,order-1);
		DrawFractalLine(len/3,theta-60,order-1);
		DrawFractalLine(len/3,theta+60,order-1);
		DrawFractalLine(len/3,theta,order-1);
	}
}

void KochFractal(double size, int order) {  
	MovePen(GetWindowWidth()/2-size/2,GetWindowHeight()/2-sqrt(3)*size/6);
	DrawFractalLine(size,0,order);
	DrawFractalLine(size,120,order); 
	DrawFractalLine(size,240,order);
}

void DrawPolarLine(double r ,double theta){
	DrawLine(r*cos(theta/180*PI),r*sin(theta/180*PI));
} 
