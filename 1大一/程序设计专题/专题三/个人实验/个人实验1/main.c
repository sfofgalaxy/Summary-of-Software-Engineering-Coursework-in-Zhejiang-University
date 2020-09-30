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

void Main(void){
	InitGraphics();
	double cx,cy;
	cx = GetWindowWidth()/2;
	cy = GetWindowHeight()/2;
	MovePen(cx+1, cy);
	DrawLine(0,-2.5);
	DrawLine(-2,0);
	DrawLine(0,2.5);
	DrawLine(1,2);
	DrawLine(1,-2);
	DrawLine(-2,0);
	MovePen(cx-0.2,cy-0.5);
	DrawLine(0,-0.5);
	DrawLine(-0.5,0);
	DrawLine(0,0.5);
	DrawLine(0.5,0);
	MovePen(cx,cy-0.5);
	DrawLine(0.5,0);
	DrawLine(0,-2);
	DrawLine(-0.5,0);
	DrawLine(0,2);
	MovePen(cx-0.4,cy+1.2);
	DrawLine(0,0.3);
	MovePen(cx-0.3,cy+1.5);
	DrawLine(0,0.2);
	DrawLine(-0.5,0);
	DrawLine(0,-0.2);
	DrawLine(0.5,0);
	MovePen(cx-0.7,cy+0.6);
	DrawLine(0,0.9);
} 
