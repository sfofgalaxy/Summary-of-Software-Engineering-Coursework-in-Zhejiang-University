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

double cx,cy;
double omx,omy;
double startx,starty;
void MouseEventProcess(int x,int y,int button,int event);
bool inBox(double x0, double y0);
void Main(void){
	InitGraphics();           
    cx = GetWindowWidth();  
    cy = GetWindowHeight();  
    registerMouseEvent(MouseEventProcess);  
    SetPenSize(1);  
} 

bool inBox(double x0, double y0)  
{  
    return (x0 > 0 && x0 < cx && y0 > 0 && y0 < cy);  
} 
void MouseEventProcess(int x,int y,int button,int event)
{
	static double lx=0.0, ly=0.0;  
    double mx, my;  
     mx = ScaleXInches(x);/*pixels --> inches*/  
     my = ScaleYInches(y);/*pixels --> inches*/  
     static bool isDraw = FALSE;  
   
     switch (event) {  
         case BUTTON_DOWN:  
              if (button == LEFT_BUTTON&&inBox(mx,my)){ 
			  	 startx=omx=mx;
			  	 starty=omy=my;
                  isDraw = TRUE;      
            }   
              break;  
         case BUTTON_DOUBLECLICK:  
              break;
         case BUTTON_UP:  
              if (button == LEFT_BUTTON) isDraw = FALSE;  
              break;  
         case MOUSEMOVE:  
              if (isDraw) {
              	SetEraseMode(TRUE);
              	MovePen(startx,starty);
              	DrawLine(omx-startx,omy-starty);
              	MovePen(startx,starty);
              	SetEraseMode(FALSE);
                  DrawLine(mx-startx,my-starty);  
                  omx = mx;
                  omy = my;
                  
              }   
              break;  
     }    
     lx=mx;  
     ly=my;  
}

 
