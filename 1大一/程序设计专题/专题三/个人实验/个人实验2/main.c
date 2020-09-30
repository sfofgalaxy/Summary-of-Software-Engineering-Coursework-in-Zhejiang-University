#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
const double pi=acos(-1.0);
double currentangle;
void forward(double distance)
{
	DrawLine(distance*cos(currentangle*pi/180),distance*sin(currentangle*pi/180));
}

void turn(double angle)
{
	currentangle += angle;
}
void move(double distance)
{
	MovePen(GetCurrentX()+distance*cos(currentangle*pi/180),GetCurrentY()+distance*sin(currentangle*pi/180));
}
void Main(void)
{
	double cx,cy;
	InitGraphics();
	SetPenColor("green");
	cx = GetWindowWidth()/2;
	cy = GetWindowHeight()/2;
	MovePen(cx,cy);
	int i,j;
	turn(90);
	for(i=1;i<=20;i++){
		forward(1);
		turn(60);
		forward(1);
		turn(120);
		forward(1);
		turn(60);
		forward(1);
		turn(20);
	}
	for(j=0;j<3;j++){
		MovePen(cx,cy);
		currentangle = 20*j+90;
		move(2);
		turn(120);
		for(i=1;i<=6;i++){
			forward(2);
			turn(60);
		}
	}
}
