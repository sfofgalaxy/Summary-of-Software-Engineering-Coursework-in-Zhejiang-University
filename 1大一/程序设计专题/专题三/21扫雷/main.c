#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
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
#include <math.h>
#include <time.h>
#define  boxlength  0.25
#define  Echelonheight   0.025
#define  bottomx  1
#define  bottomy  0.4
#define  bomber  0.05
#define  flagheight  0.16
#define  flagwidth  0.1
#define  smileboxlength  0.5
#define  smiler  0.17
#define TIMER_BLINK1000 2

const int mseconds500 = 500;   
const int mseconds1000 = 1000;

static int minenumber, nt = 0;
static double boxcx_easy[10] [10], boxcy_easy[10] [10];
static double boxcx_normal[20] [20], boxcy_normal[20] [20];
static double boxcx_hard[19] [30], boxcy_hard[19] [30];
static int isbomb_easy[10][10]={0}, isbomb_normal[20][20]={0}, isbomb_hard[19][30]={0};
static int isopen_easy[10][10]={0}, isopen_normal[20][20]={0}, isopen_hard[19][30]={0};
static int issign_easy[10][10]={0}, issign_normal[20][20]={0}, issign_hard[19][30]={0};
static double cx,cy,timex,timey,minex,miney;
static int choice, ismenu=1, isbomberfield=0, isfail=0;
static int isbegin1=0, isbegin2=0, isbegin3=0;
static char stime[10], smine[10];
static bool istimecount = FALSE;

bool inBox(double x0, double y0, double x1, double x2, double y1, double y2);
void DrawBox(double x, double y, double width, double height);
void Drawbasic(int n);
void DrawField(double x, double y, double width, double height);
void DrawShadow(double x, double y, double width, double height, int n);
void DrawBomb(double x, double y);
void DrawFlag(double x, double y, double width, double height);
void Drawmenu(void);
void MouseEventProcess(int x, int y, int button, int event);
void TimerEventProcess(int timerID);
void DrawSmile(double x, double y, double r);
void DrawCry(double x, double y, double r);
void DrawCross(double x, double y, double r);
void DrawWinFace(double x, double y, double r); 

void Main(){
	int i,j; 
	InitGraphics();
		
	
	cx = GetWindowWidth() / 2.0;
    cy = GetWindowHeight() / 2.0;
    
	registerMouseEvent(MouseEventProcess);	
	registerTimerEvent(TimerEventProcess);			
    
}

void DrawBox(double x, double y, double width, double height){	
    MovePen(x, y);
    DrawLine(0.0, height);
    DrawLine(width, 0.0);
    DrawLine(0.0, -height);
    DrawLine(-width, 0.0);
}

bool inBox(double x0, double y0, double x1, double y1, double x2, double y2){
	return (x0 >= x1 && x0 <= x2 && y0 >= y1 && y0 <= y2);
}

void DrawFlag(double x, double y, double width, double height){
	SetPenColor("Red");
	StartFilledRegion(1);
	MovePen(x, y);
    DrawLine(-height*sqrt(3)/4, height/4);
    DrawLine(height*sqrt(3)/4, height/4);
    DrawLine(0, -height/2);
    EndFilledRegion();
    
    SetPenColor("Black");

    DrawLine(0, -height/3);
    

}

void DrawBomb(double x, double y){
	SetPenColor("Black");
	StartFilledRegion(1);
	MovePen(x + bomber, y);
    DrawArc(bomber, 0.0, 360.0);
    EndFilledRegion();
    SetPenSize(1);
    MovePen(x-0.08, y);
    DrawLine(0.16, 0);
    MovePen(x, y-0.08);
    DrawLine(0., 0.16);
    SetPenColor("White");
    StartFilledRegion(1);
	MovePen(x-0.008, y+0.008);
    DrawArc(0.008, 0.0, 360.0);
    EndFilledRegion();
}

void Drawmenu(void){
	 	
	DrawField(cx-bottomx/2.0, cy+3*bottomy/2.0, bottomx, bottomy);
	MovePen(cx-0.2, cy+0.75);
	SetPenColor("White");
	DrawTextString("Easy");
	DrawField(cx-bottomx/2.0, cy-bottomy/2.0, bottomx, bottomy);
	MovePen(cx-0.25, cy-0.05);
	SetPenColor("White");
	DrawTextString("Normal");
	DrawField(cx-bottomx/2.0, cy-5*bottomy/2.0, bottomx, bottomy);
	MovePen(cx-0.2, cy-0.85);
	SetPenColor("White");
	DrawTextString("Hard");	
}


void DrawShadow(double x, double y, double width, double height, int n){
	if(n==1){
		SetPenColor("light Gray");
		StartFilledRegion(1);
		MovePen(x, y);
		DrawLine(0, width);
		DrawLine(height, -height);
		DrawLine(0, -width+2*height);
		DrawLine(-height, -height);
		EndFilledRegion();		
	}
	if(n==2){
		SetPenColor("light Gray"); 
		StartFilledRegion(1);
		MovePen(x, y);
		DrawLine(width, 0);
		DrawLine(-height, -height);
		DrawLine(-width+2*height, 0);
		DrawLine(-height, height);
		EndFilledRegion();
	}
	if(n==3){
		SetPenColor("Dark Gray"); 
		StartFilledRegion(1);
		MovePen(x, y);
		DrawLine(0, -width);
		DrawLine(-height, height);
		DrawLine(0, width-2*height);
		DrawLine(height, height);
		EndFilledRegion();
    }
    if(n==4){
		SetPenColor("Dark Gray"); 
		StartFilledRegion(1);
		MovePen(x, y);
		DrawLine(-width, 0);
		DrawLine(height, height);
		DrawLine(width-2*height, 0);
		DrawLine(height, -height);
		EndFilledRegion();
	}
}



void DrawField(double x, double y, double width, double height){
	SetPenColor("Gray"); 
	StartFilledRegion(1);
	DrawBox(x, y, width, height);
	EndFilledRegion();
	DrawShadow(x, y, height, Echelonheight, 1);
	DrawShadow(x, y+height, width, Echelonheight, 2);
	DrawShadow(x+width, y+height, height, Echelonheight, 3);
	DrawShadow(x+width, y, width, Echelonheight, 4);
	
}


void Drawbasic(int n){
	int i,j;
	if(n==1){
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){	
			    boxcx_easy[i] [j]=cx-(5-j)*boxlength;
				boxcy_easy[i] [j]=cy+(6-i)*boxlength;					
				DrawField(cx-(5-j)*boxlength, cy+(6-i)*boxlength, boxlength, boxlength);			
			}
		}		
	}
	if(n==2){
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){	
			    boxcx_normal[i] [j]=cx-(10-j)*boxlength;
				boxcy_normal[i] [j]=cy+(7-i)*boxlength;			
				DrawField(cx-(10-j)*boxlength, cy+(7-i)*boxlength, boxlength, boxlength);			
			}
		}		
	}
	if(n==3){
		for(i=0;i<19;i++){
			for(j=0;j<30;j++){
				boxcx_hard[i] [j]=cx-(15-j)*boxlength;
				boxcy_hard[i] [j]=cy+(7-i)*boxlength;
				DrawField(cx-(15-j)*boxlength, cy+(7-i)*boxlength, boxlength, boxlength);
			}
		}		
	}
}


void DrawSmile(double x, double y, double r){
	SetPenColor("Yellow");
	StartFilledRegion(1);
	MovePen(x+r, y);
	DrawArc(r, 0.0, 360);
	EndFilledRegion();
	
	SetPenColor("Black");
	DrawArc(r, x+r, 360);
	StartFilledRegion(1);
	MovePen(x-r*2/5+r/20, y+r/5);
	DrawArc(r/20, 0.0, 360);
	EndFilledRegion();
	StartFilledRegion(1);
	MovePen(x+r*2/5+r/20, y+r/5);
	DrawArc(r/20, 0.0, 360);
	EndFilledRegion();
	
	MovePen(x+r*2/5, y-r/3);
	DrawEllipticalArc(r*2/5, r/4, 0.0, -180);
}

void DrawCry(double x, double y, double r){
	SetPenColor("Yellow");
	StartFilledRegion(1);
	MovePen(x+r, y);
	DrawArc(r, 0.0, 360);
	EndFilledRegion();
	
	SetPenColor("Black");
	DrawArc(r, 0.0, 360);
	DrawCross(x-r*2/5, y+r/5, r/16);
	DrawCross(x+r*2/5, y+r/5, r/16);
	
	MovePen(x+r*2/5, y-r*3/5);
	DrawEllipticalArc(r*2/5, r/4, 0.0, 180);
}

void DrawCross(double x, double y, double r){
	MovePen(x-r, y-r);
	DrawLine(2*r, 2*r);
	MovePen(x-r, y+r);
	DrawLine(2*r, -2*r);
}


void DrawWinFace(double x, double y, double r){
	SetPenColor("Yellow");
	StartFilledRegion(1);
	MovePen(x+r, y);
	DrawArc(r, 0.0, 360);
	EndFilledRegion();
	
	SetPenColor("Black");
	MovePen(x+r, y);
	DrawArc(r, 0.0, 360);

	StartFilledRegion(1);
	MovePen(x-r*2/5+r/3, y+r/4);
	DrawEllipticalArc(r/3, r/5, 0.0, 360);
	EndFilledRegion();
	
	StartFilledRegion(1);
	MovePen(x+r*2/5+r/3, y+r/4);
	DrawEllipticalArc(r/3, r/5, 0.0, 360);
	EndFilledRegion();


    SetPenColor("Black");
	SetPenSize(2);
	MovePen(x-r*2/5+r/3, y+r/4);
	DrawLine(r*4/5, 0.0);
	MovePen(x-r*2/5-r/3, y+r/4);
	DrawLine(-r/4, r/10);
	MovePen(x+r*2/5+r/4, y+r/4);
	DrawLine(r/4, r/10);
	
	MovePen(x+r/3,y-r/3);
	DrawEllipticalArc(r/2, r/4, 0.0, -90);
	
	SetPenSize(1);
}


void MouseEventProcess(int x, int y, int button, int event){
	double mx, my;
	int a,i,j,n,count;
	time_t t;
	mx = ScaleXInches(x);
 	my = ScaleYInches(y);
 	
    if(ismenu){
	    cancelTimer(TIMER_BLINK1000);
		nt=0;    	
    	   if(inBox(mx, my, cx-bottomx/2.0, cy+3*bottomy/2.0, cx+bottomx/2.0, cy+5*bottomy/2.0)){
    		   SetEraseMode(TRUE);
               DrawField(cx-bottomx/2.0, cy+3*bottomy/2.0, bottomx, bottomy);
    		   SetEraseMode(FALSE);	
    		   DrawField(cx-bottomx/2.0-0.1, cy+3*bottomy/2.0-0.1, bottomx+0.2, bottomy+0.2);
			   MovePen(cx-0.2, cy+0.75);
	           SetPenColor("White");
	           DrawTextString("Easy");												
    	   }
    	   else if(inBox(mx, my, cx-bottomx/2.0, cy-bottomy/2.0, cx+bottomx/2.0, cy+bottomy/2.0)){
    		   SetEraseMode(TRUE);
    		   DrawField(cx-bottomx/2.0, cy-bottomy/2.0, bottomx, bottomy);
    		   SetEraseMode(FALSE);	
    		   DrawField(cx-bottomx/2.0-0.1, cy-bottomy/2.0-0.1, bottomx+0.2, bottomy+0.2);				   
	           MovePen(cx-0.25, cy-0.05);
	           SetPenColor("White");
	           DrawTextString("Normal");											
    	   }
    	   else if(inBox(mx, my, cx-bottomx/2.0, cy-5*bottomy/2.0, cx+bottomx/2.0, cy-3*bottomy/2.0)){
    		   SetEraseMode(TRUE);
    		   DrawField(cx-bottomx/2.0, cy-5*bottomy/2.0, bottomx, bottomy);
    		   SetEraseMode(FALSE);	
    		   DrawField(cx-bottomx/2.0-0.1, cy-5*bottomy/2.0-0.1, bottomx+0.2, bottomy+0.2);			   
               MovePen(cx-0.2, cy-0.85);
	           SetPenColor("White");
	           DrawTextString("Hard");												
    	   }
    	   else{
    	   	   ClearWindow();	
			   SetEraseMode(FALSE);
			   Drawmenu();		
    	   }
    	switch (event) {    		
    		case BUTTON_DOWN:
    			if (button == LEFT_BUTTON) {
    				if(inBox(mx, my, cx-bottomx/2.0, cy+3*bottomy/2.0, cx+bottomx/2.0, cy+5*bottomy/2.0)){
    					SetEraseMode(TRUE);
    					DrawField(cx-bottomx/2.0-0.1, cy+3*bottomy/2.0-0.1, bottomx+0.2, bottomy+0.2);
    					SetEraseMode(FALSE);
						DrawField(cx-bottomx/2.0, cy+3*bottomy/2.0, bottomx, bottomy);
						choice=1;										    					
    				}
    	            else if(inBox(mx, my, cx-bottomx/2.0, cy-bottomy/2.0, cx+bottomx/2.0, cy+bottomy/2.0)){
    					SetEraseMode(TRUE);
    					DrawField(cx-bottomx/2.0-0.1, cy-bottomy/2.0-0.1, bottomx+0.2, bottomy+0.2);
    					SetEraseMode(FALSE);					
						DrawField(cx-bottomx/2.0, cy-bottomy/2.0, bottomx, bottomy);
						choice=2;						
    				}
    	            else if(inBox(mx, my, cx-bottomx/2.0, cy-5*bottomy/2.0, cx+bottomx/2.0, cy-3*bottomy/2.0)){
    					SetEraseMode(TRUE);
    			        DrawField(cx-bottomx/2.0-0.1, cy-5*bottomy/2.0-0.1, bottomx+0.2, bottomy+0.2);
    					SetEraseMode(FALSE);					
					    DrawField(cx-bottomx/2.0, cy-5*bottomy/2.0, bottomx, bottomy);
						choice=3;				
    				}
					else{
						choice=0;
					}     	
    	
                }
                break;
            case BUTTON_UP:
			    if (button == LEFT_BUTTON){
			    	if(inBox(mx, my, cx-bottomx/2.0, cy+3*bottomy/2.0, cx+bottomx/2.0, cy+5*bottomy/2.0)&&choice==1){
			    		ismenu=0;  isbomberfield=1;
			    		ClearWindow();
    	                Drawbasic(choice);
    	                DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
    	                DrawSmile(cx, cy+3, smiler);
    	                SetPenColor("Light Gray");
		                StartFilledRegion(1);
		                DrawBox(cx+1, cy+2.75, 0.5, 0.5);
		                EndFilledRegion();
		                timex=cx+1.2;
    		            timey=cy+2.95;
    		            SetPenColor("Red");
		                sprintf(stime, "%d", nt);
		                MovePen(timex, timey);
		                DrawTextString(stime);
    		            startTimer(TIMER_BLINK1000, mseconds1000);
    		            minenumber=20;
    		            SetPenColor("Light Gray");
		                StartFilledRegion(1);
		                DrawBox(cx-1.5, cy+2.75, 0.5, 0.5);
		                EndFilledRegion();
		                minex=cx-1.33;
		                miney=cy+2.95;
		                SetPenColor("Red");
		                sprintf(smine, "%d", minenumber);
		                MovePen(minex, miney);
		                DrawTextString(smine);
			    	}
			    	else if(inBox(mx, my, cx-bottomx/2.0, cy-bottomy/2.0, cx+bottomx/2.0, cy+bottomy/2.0)&&choice==2){
			    		ismenu=0;  isbomberfield=1;
			    		ClearWindow();
    	                Drawbasic(choice);
    	                DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						DrawSmile(cx, cy+3, smiler); 
						SetPenColor("Light Gray");
		                StartFilledRegion(1);
		                DrawBox(cx+2, cy+2.75, 0.5, 0.5);
		                EndFilledRegion();
		                timex=cx+2.2;
    		            timey=cy+2.95;
    		            SetPenColor("Red");
		                sprintf(stime, "%d", nt);
		                MovePen(timex, timey);
		                DrawTextString(stime);
    		            startTimer(TIMER_BLINK1000, mseconds1000);  
						minenumber=50; 
						SetPenColor("Light Gray");
		                StartFilledRegion(1);
		                DrawBox(cx-2.5, cy+2.75, 0.5, 0.5);
		                EndFilledRegion();
		                minex=cx-2.33;
		                miney=cy+2.95;
		                SetPenColor("Red");
		                sprintf(smine, "%d", minenumber);
		                MovePen(minex, miney);
		                DrawTextString(smine);          
			    	}
			    	else if(inBox(mx, my, cx-bottomx/2.0, cy-5*bottomy/2.0, cx+bottomx/2.0, cy-3*bottomy/2.0)&&choice==3){
			    		ismenu=0;  isbomberfield=1;
			    		ClearWindow();
    	                SetEraseMode(FALSE);
    	                Drawbasic(choice);
    	                DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
    	                DrawSmile(cx, cy+3, smiler);
    	                SetPenColor("Light Gray");
		                StartFilledRegion(1);
		                DrawBox(cx+3, cy+2.75, 0.5, 0.5);
		                EndFilledRegion();
		                timex=cx+3.2;
    		            timey=cy+2.95;
    		            SetPenColor("Red");
		                sprintf(stime, "%d", nt);
		                MovePen(timex, timey);
		                DrawTextString(stime);
    		            startTimer(TIMER_BLINK1000, mseconds1000);
    		            minenumber=100;
    		            SetPenColor("Light Gray");
		                StartFilledRegion(1);
		                DrawBox(cx-3.5, cy+2.75, 0.5, 0.5);
		                EndFilledRegion();
		                minex=cx-3.36;
		                miney=cy+2.95;
		                SetPenColor("Red");
		                sprintf(smine, "%d", minenumber);
		                MovePen(minex, miney);
		                DrawTextString(smine);
		                
			    	}
			    }   
    	   	
        }
		   	    	
    }
    
    if(isfail){
    	cancelTimer(TIMER_BLINK1000);
    	nt=0;
    	if(event==BUTTON_DOWN){
    		if(button==LEFT_BUTTON){
    			if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)){
    				SetEraseMode(TRUE);
					DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
					SetEraseMode(FALSE);
					SetPenColor("Gray");
					StartFilledRegion(1);
					DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
					EndFilledRegion();
					DrawCry(cx, cy+3, smiler);
					isfail=2;
    			}
    		}
    	}
    	
    	if(event==BUTTON_UP){
    		if(button==LEFT_BUTTON){
    			if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)&&isfail==2){
    			    ClearWindow();
					Drawmenu();
					isbomberfield=0;
					ismenu=1;
					isfail=0;
    			}
    			else{
    				SetEraseMode(TRUE);
					SetPenColor("Gray");
				    StartFilledRegion(1);
					DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
					EndFilledRegion();
					SetEraseMode(FALSE);
					DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
					DrawCry(cx, cy+3, smiler);
					isfail=1;
    			}
    		}
    	}    	   	    	    	    	   	
    }
    
    if(isbomberfield){
    	if(choice==1){   		
    		if(isbegin1==0){    
			    a=0;			
	            srand((unsigned) time(&t));
	            for(;;){
	            	n=rand()%100;
	            	i=n/10;
	            	j=n%10;
	            	if(isbomb_easy[i][j]==0){
	            		isbomb_easy[i][j]=1;
	            		a++;
	            	}
					if(a==20)
					break;	            		            	
	            }
	            isbegin1=1;	            
    		} 
    		
    		switch (event) {
    			case BUTTON_DOWN:
    				if(button == LEFT_BUTTON) {
    					for(i=0;i<10;i++){
    						for(j=0;j<10;j++){
    							if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&isopen_easy[i][j]==0&&issign_easy[i][j]==0){
    								isopen_easy[i][j]=1;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();						            
    							}    							    							
    						}   						
    					}
						if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)){
							SetEraseMode(TRUE);
							DrawField(cx-smileboxlength/2, cy+2-smileboxlength/2, smileboxlength, smileboxlength);(cx, cy+2);
							SetEraseMode(FALSE);
						    SetPenColor("Gray");
						    StartFilledRegion(1);
						    DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    EndFilledRegion();
						    DrawSmile(cx, cy+3, smiler);
						    isbomberfield=2;
						}   					
    				}
    				if(button == RIGHT_BUTTON){
    					for(i=0;i<10;i++){
    						for(j=0;j<10;j++){
    							if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==0){
    								issign_easy[i][j]=1;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}
								if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==2){
    								issign_easy[i][j]=3;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}
								if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==4){
    								issign_easy[i][j]=5;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}     							    							
    						}   						
    					}
    				}
    				break;
    			case BUTTON_UP:
    				if(button == LEFT_BUTTON){
    					for(i=0;i<10;i++){
    						for(j=0;j<10;j++){
    							if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&isopen_easy[i][j]==1){
    								isopen_easy[i][j]=2;    													            
    							}
								if(!inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&isopen_easy[i][j]==1){
									isopen_easy[i][j]=0;
									SetEraseMode(TRUE);
									SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
						            DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
								}    							    							
    						}    						
    					}
    					if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)&&isbomberfield==2){
							ClearWindow();
							Drawmenu();
						    isbomberfield=0;
						    ismenu=1;
						    for(i=0;i<10;i++){
						    	for(j=0;j<10;j++){
						    		isbomb_easy[i][j]=0;
						    		isopen_easy[i][j]=0;
						    		issign_easy[i][j]=0;
						    	}
						    }
						    isbegin1=0;
						}
						else{
							SetEraseMode(TRUE);
							SetPenColor("Gray");
						    StartFilledRegion(1);
						    DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    EndFilledRegion();
						    SetEraseMode(FALSE);
						    DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    DrawSmile(cx, cy+3, smiler);
						    isbomberfield=1;
						}   			
    				}
    				if(button == RIGHT_BUTTON){
    					for(i=0;i<10;i++){
    						for(j=0;j<10;j++){
    							if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==1&&minenumber!=0){
    								issign_easy[i][j]=2;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            StartFilledRegion(1);
		                            DrawBox(cx-1.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            DrawTextString(smine);
						            SetEraseMode(FALSE);
    								DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
    								DrawFlag(boxcx_easy[i][j]+boxlength/2, boxcy_easy[i][j]+boxlength/2, flagwidth, flagheight);
    								SetPenColor("Light Gray");    								
    								StartFilledRegion(1);
		                            DrawBox(cx-1.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            minenumber--;
		                            sprintf(smine, "%d", minenumber);
		                            if(minenumber==99||minenumber==9)
		                                minex+=TextStringWidth("1")/2;
		                            SetPenColor("Red");
		                            MovePen(minex, miney);
		                            DrawTextString(smine);    								
    							}
								if(!inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==1){									
    								issign_easy[i][j]=0;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
    							} 
								if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==3){
    								issign_easy[i][j]=4;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
    								SetPenColor("Black");
    								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
    								DrawTextString("?");
    							}
    							if(!inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==3){
    								issign_easy[i][j]=2;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
    								DrawFlag(boxcx_easy[i][j]+boxlength/2, boxcy_easy[i][j]+boxlength/2, flagwidth, flagheight);
    							}
								if(inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==5){
									SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            StartFilledRegion(1);
		                            DrawBox(cx-1.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            DrawTextString(smine);
						            SetEraseMode(FALSE);
    								issign_easy[i][j]=0;
    								DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
    								SetPenColor("Light Gray");    								
    								StartFilledRegion(1);
		                            DrawBox(cx-1.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            minenumber++;
		                            sprintf(smine, "%d", minenumber);
		                            if(minenumber==100||minenumber==10)
		                                minex-=TextStringWidth("1")/2;
		                            SetPenColor("Red");
		                            MovePen(minex, miney);
		                            DrawTextString(smine);
    							}
								if(!inBox(mx, my, boxcx_easy[i][j], boxcy_easy[i][j], boxcx_easy[i][j]+boxlength, boxcy_easy[i][j]+boxlength)&&issign_easy[i][j]==5){
    								issign_easy[i][j]=4;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
    								SetPenColor("Black");
    								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
    								DrawTextString("?");
    							}     							    							
    						}
    						
    					}
    				}
    				break;
    	    }
			
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){					
					if(isopen_easy[i][j]==2){
						SetEraseMode(TRUE);
						DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						SetEraseMode(FALSE);
						SetPenColor("light Gray"); 
						StartFilledRegion(1);
						DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						EndFilledRegion();
						SetPenColor("Dark Gray");
						DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
							
						if(isbomb_easy[i][j]==0){
							count=0;
							if(i-1>=0&&j-1>=0&&isbomb_easy[i-1][j-1]==1)
							count++;
							if(i-1>=0&&isbomb_easy[i-1][j]==1)
							count++;
							if(i-1>=0&&j+1<10&&isbomb_easy[i-1][j+1]==1)
							count++;
							if(j-1>=0&&isbomb_easy[i][j-1]==1)
							count++;
							if(j+1<10&&isbomb_easy[i][j+1]==1)
							count++;
							if(i+1<10&&j-1>=0&&isbomb_easy[i+1][j-1]==1)
							count++;
							if(i+1<10&&isbomb_easy[i+1][j]==1)
							count++;
							if(i+1<10&&j+1<10&&isbomb_easy[i+1][j+1]==1)
							count++;
							if(count==0){
								if(i-1>=0&&j-1>=0)
								isopen_easy[i-1][j-1]=2;
								if(i-1>=0)
								isopen_easy[i-1][j]=2;
								if(j-1>=0)
								isopen_easy[i][j-1]=2;
								if(i-1>=0&&j+1<10)
								isopen_easy[i-1][j+1]=2;
								if(j+1<10)
								isopen_easy[i][j+1]=2;
								if(i+1<10&&j-1>=0)
								isopen_easy[i+1][j-1]=2;
								if(i+1<10)
								isopen_easy[i+1][j]=2;
								if(i+1<10&&j+1<10)
								isopen_easy[i+1][j+1]=2;								
							}
							if(count==1){
								SetPenColor("Blue");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("1\0");
							}
							if(count==2){
								SetPenColor("Green");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("2\0");
							}
							if(count==3){
								SetPenColor("Red");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("3\0");
							}
							if(count==4){
								SetPenColor("Brown");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("4\0");
							}
							if(count==5){
								SetPenColor("Orange");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("5\0");
							}
							if(count==6){
								SetPenColor("Violet");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("6\0");
							}
							if(count==7){
								SetPenColor("Yellow");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("7\0");
							}
							if(count==8){
								SetPenColor("Black");
								MovePen(boxcx_easy[i][j]+0.08, boxcy_easy[i][j]+0.08);
								DrawTextString("8\0");
							}
						}
						else{
							int p, q;
							p=i;  q=j;														
						    for(i=0;i<10;i++){
						    	for(j=0;j<10;j++){
						    		if(isbomb_easy[i][j]==1){
						    		    SetEraseMode(TRUE);
						    		    DrawField(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						    		    SetEraseMode(FALSE);
						    		    SetPenColor("light Gray"); 
						                StartFilledRegion(1);
						                DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
					                  	EndFilledRegion();
					                  	SetPenColor("Dark Gray");
					                   	DrawBox(boxcx_easy[i][j], boxcy_easy[i][j], boxlength, boxlength);
						    		    DrawBomb(boxcx_easy[i][j]+boxlength/2, boxcy_easy[i][j]+boxlength/2);
						    	    }
						    	    isbomb_easy[i][j]=0;
						    	    isopen_easy[i][j]=0;
						    	    issign_easy[i][j]=0;
						    	}
						    }
							SetPenColor("Red");
							StartFilledRegion(1);
						    DrawBox(boxcx_easy[p][q], boxcy_easy[p][q], boxlength, boxlength);
						    EndFilledRegion();
						    DrawBomb(boxcx_easy[p][q]+boxlength/2, boxcy_easy[p][q]+boxlength/2);
						    isbomberfield=0;
						    isbegin1=0;
						    isfail=1; 
						    SetEraseMode(TRUE);
						    DrawSmile(cx, cy+3, smiler);
						    SetEraseMode(FALSE);
						    DrawCry(cx, cy+3, smiler);
						}
					}
					
				}
			}
			
			count=0;
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					if(isbomb_easy[i][j]==0&&isopen_easy[i][j]==2)
					 count++;
				}
			}
			if(count==80){
				SetEraseMode(TRUE);
				DrawSmile(cx, cy+3, smiler);
				SetEraseMode(FALSE);
				DrawWinFace(cx, cy+3, smiler);
				SetPenColor("Red");				
				MovePen(cx-0.3, cy+2);
				DrawTextString("You win!");
				cancelTimer(TIMER_BLINK1000);
				nt=0;
			} 
				
				    		
    	}
    	
    	if(choice==2){
    		if(isbegin2==0){
			    a=0;    			
	            srand((unsigned) time(&t));
	            for(;;){
	            	n=rand()%400;
	            	i=n/20;
	            	j=n%20;
	            	if(isbomb_normal[i][j]==0){
	            		isbomb_normal[i][j]=1;
	            		a++;
	            	}
	            	if(a==50)
	            	break;						            		            	
	            }
	            isbegin2=1;	            
    		} 
    		
    		switch (event) {
    			case BUTTON_DOWN:
    				if(button == LEFT_BUTTON) {
    					for(i=0;i<20;i++){
    						for(j=0;j<20;j++){
    							if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&isopen_normal[i][j]==0&&issign_normal[i][j]==0){
    								isopen_normal[i][j]=1;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();						            
    							}    							    							
    						}   						
    					}
						if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)){
							SetEraseMode(TRUE);
							DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
							SetEraseMode(FALSE);
						    SetPenColor("Gray");
						    StartFilledRegion(1);
						    DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    EndFilledRegion();
						    DrawSmile(cx, cy+3, smiler);
						    isbomberfield=2;
						}      					
    				}
    				if(button == RIGHT_BUTTON){
    					for(i=0;i<20;i++){
    						for(j=0;j<20;j++){
    							if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==0){
    								issign_normal[i][j]=1;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}
								if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==2){
    								issign_normal[i][j]=3;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}
								if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==4){
    								issign_normal[i][j]=5;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}     							    							
    						}   						
    					}
    				}
    				break;
    			case BUTTON_UP:
    				if(button == LEFT_BUTTON){
    					for(i=0;i<20;i++){
    						for(j=0;j<20;j++){
    							if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&isopen_normal[i][j]==1){
    								isopen_normal[i][j]=2;    													            
    							}
								if(!inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&isopen_normal[i][j]==1){
									isopen_normal[i][j]=0;
									SetEraseMode(TRUE);
									SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
						            DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
								}    							    							
    						}    						
    					}
    					if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)&&isbomberfield==2){
							ClearWindow();
							Drawmenu();
						    isbomberfield=0;
						    ismenu=1;
						    for(i=0;i<20;i++){
						    	for(j=0;j<20;j++){
						    		isbomb_normal[i][j]=0;
						    		isopen_normal[i][j]=0;
						    		issign_normal[i][j]=0;
						    	}
						    }
						    isbegin2=0;
						}
						else{
							SetEraseMode(TRUE);
							SetPenColor("Gray");
						    StartFilledRegion(1);
						    DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    EndFilledRegion();
						    SetEraseMode(FALSE);
						    DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    DrawSmile(cx, cy+3, smiler);
						    isbomberfield=1;
						}   
    				}
    				if(button == RIGHT_BUTTON){
    					for(i=0;i<20;i++){
    						for(j=0;j<20;j++){
    							if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==1&&minenumber!=0){
    								issign_normal[i][j]=2;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            StartFilledRegion(1);
		                            DrawBox(cx-2.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            DrawTextString(smine);
						            SetEraseMode(FALSE);
    								DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
    								DrawFlag(boxcx_normal[i][j]+boxlength/2, boxcy_normal[i][j]+boxlength/2, flagwidth, flagheight);
    								SetPenColor("Light Gray");    								
    								StartFilledRegion(1);
		                            DrawBox(cx-2.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            minenumber--;
		                            sprintf(smine, "%d", minenumber);
		                            if(minenumber==99||minenumber==9)
		                                minex+=TextStringWidth("1")/2;
		                            SetPenColor("Red");
		                            MovePen(minex, miney);
		                            DrawTextString(smine);
    							}
								if(!inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==1){
    								issign_normal[i][j]=0;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
    							} 
								if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==3){
    								issign_normal[i][j]=4;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
    								SetPenColor("Black");
    								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
    								DrawTextString("?");
    							}
    							if(!inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==3){
    								issign_normal[i][j]=2;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
    								DrawFlag(boxcx_normal[i][j]+boxlength/2, boxcy_normal[i][j]+boxlength/2, flagwidth, flagheight);
    							}
								if(inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==5){
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            StartFilledRegion(1);
		                            DrawBox(cx-2.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            DrawTextString(smine);
						            SetEraseMode(FALSE);
    								issign_normal[i][j]=0;
    								DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
    								SetPenColor("Light Gray");    								
    								StartFilledRegion(1);
		                            DrawBox(cx-2.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            minenumber++;
		                            sprintf(smine, "%d", minenumber);
		                            if(minenumber==100||minenumber==10)
		                                minex-=TextStringWidth("1")/2;
		                            SetPenColor("Red");
		                            MovePen(minex, miney);
		                            DrawTextString(smine);
    							}
								if(!inBox(mx, my, boxcx_normal[i][j], boxcy_normal[i][j], boxcx_normal[i][j]+boxlength, boxcy_normal[i][j]+boxlength)&&issign_normal[i][j]==5){
    								issign_normal[i][j]=4;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
    								SetPenColor("Black");
    								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
    								DrawTextString("?");
    							}     							    							
    						}
    						
    					}
    				}
    				break;
    	    }
			
			for(i=0;i<20;i++){
				for(j=0;j<20;j++){					
					if(isopen_normal[i][j]==2){
						SetEraseMode(TRUE);
						DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						SetEraseMode(FALSE);
						SetPenColor("light Gray"); 
						StartFilledRegion(1);
						DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						EndFilledRegion();
						SetPenColor("Dark Gray");
						DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
							
						if(isbomb_normal[i][j]==0){
							count=0;
							if(i-1>=0&&j-1>=0&&isbomb_normal[i-1][j-1]==1)
							count++;
							if(i-1>=0&&isbomb_normal[i-1][j]==1)
							count++;
							if(i-1>=0&&j+1<20&&isbomb_normal[i-1][j+1]==1)
							count++;
							if(j-1>=0&&isbomb_normal[i][j-1]==1)
							count++;
							if(j+1<20&&isbomb_normal[i][j+1]==1)
							count++;
							if(i+1<20&&j-1>=0&&isbomb_normal[i+1][j-1]==1)
							count++;
							if(i+1<20&&isbomb_normal[i+1][j]==1)
							count++;
							if(i+1<20&&j+1<20&&isbomb_normal[i+1][j+1]==1)
							count++;
							if(count==0){
								if(i-1>=0&&j-1>=0)
								isopen_normal[i-1][j-1]=2;
								if(i-1>=0)
								isopen_normal[i-1][j]=2;
								if(j-1>=0)
								isopen_normal[i][j-1]=2;
								if(i-1>=0&&j+1<20)
								isopen_normal[i-1][j+1]=2;
								if(j+1<20)
								isopen_normal[i][j+1]=2;
								if(i+1<20&&j-1>=0)
								isopen_normal[i+1][j-1]=2;
								if(i+1<20)
								isopen_normal[i+1][j]=2;
								if(i+1<20&&j+1<20)
								isopen_normal[i+1][j+1]=2;								
							}
							if(count==1){
								SetPenColor("Blue");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("1\0");
							}
							if(count==2){
								SetPenColor("Green");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("2\0");
							}
							if(count==3){
								SetPenColor("Red");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("3\0");
							}
							if(count==4){
								SetPenColor("Brown");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("4\0");
							}
							if(count==5){
								SetPenColor("Orange");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("5\0");
							}
							if(count==6){
								SetPenColor("Violet");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("6\0");
							}
							if(count==7){
								SetPenColor("Yellow");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("7\0");
							}
							if(count==8){
								SetPenColor("Black");
								MovePen(boxcx_normal[i][j]+0.08, boxcy_normal[i][j]+0.08);
								DrawTextString("8\0");
							}
						}
						else{
							int p,q;
							p=i;  q=j;														
						    for(i=0;i<20;i++){
						    	for(j=0;j<20;j++){
						    		if(isbomb_normal[i][j]==1){
						    		    SetEraseMode(TRUE);
						    		    DrawField(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						    		    SetEraseMode(FALSE);
						    		    SetPenColor("light Gray"); 
						                StartFilledRegion(1);
						                DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
					                  	EndFilledRegion();
					                  	SetPenColor("Dark Gray");
					                   	DrawBox(boxcx_normal[i][j], boxcy_normal[i][j], boxlength, boxlength);
						    		    DrawBomb(boxcx_normal[i][j]+boxlength/2, boxcy_normal[i][j]+boxlength/2);
						    	    }
						    	    isbomb_normal[i][j]=0;
						    	    isopen_normal[i][j]=0;
						    	    issign_normal[i][j]=0;
						    	}
						    }
							SetPenColor("Red");
							StartFilledRegion(1);
						    DrawBox(boxcx_normal[p][q], boxcy_normal[p][q], boxlength, boxlength);
						    EndFilledRegion();
						    DrawBomb(boxcx_normal[p][q]+boxlength/2, boxcy_normal[p][q]+boxlength/2);
						    isbomberfield=0;
						    isbegin2=0;
						    isfail=1; 
						    SetEraseMode(TRUE);
						    DrawSmile(cx, cy+3, smiler);
						    SetEraseMode(FALSE);
						    DrawCry(cx, cy+3, smiler);
						}
					}
					
				}
			}
			
			count=0;
			for(i=0;i<20;i++){
				for(j=0;j<20;j++){
					if(isbomb_normal[i][j]==0&&isopen_normal[i][j]==2)
					 count++;
				}
			}
			if(count==350){
				SetEraseMode(TRUE);
				DrawSmile(cx, cy+3, smiler);
				SetEraseMode(FALSE);
				DrawWinFace(cx, cy+3, smiler);
				SetPenColor("Red");
				MovePen(cx-0.3, cy+2);
				DrawTextString("You win!");
				cancelTimer(TIMER_BLINK1000);
				nt=0;
			} 
				    		
    	}
    	
    	if(choice==3){
    		if(isbegin3==0){
			    a=0;    			
	            srand((unsigned) time(&t));
	            for(;;){
	            	n=rand()%570;
	            	i=n/30;
	            	j=n%30;
	            	if(isbomb_hard[i][j]==0){
	            		isbomb_hard[i][j]=1;
	            		a++;
	            	}
	            	if(a==100)
	            	break;
						            		            	
	            }
	            isbegin3=1;	            
    		} 
    		
    		switch (event) {
    			case BUTTON_DOWN:
    				if(button == LEFT_BUTTON) {
    					for(i=0;i<19;i++){
    						for(j=0;j<30;j++){
    							if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&isopen_hard[i][j]==0&&issign_hard[i][j]==0){
    								isopen_hard[i][j]=1;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();						            
    							}    							    							
    						}   						
    					} 
						if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)){
							SetEraseMode(TRUE);
							DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
							SetEraseMode(FALSE);
						    SetPenColor("Gray");
						    StartFilledRegion(1);
						    DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    EndFilledRegion();
						    DrawSmile(cx, cy+3, smiler);
						    isbomberfield=2;
						}   					
    				}
    				if(button == RIGHT_BUTTON){
    					for(i=0;i<19;i++){
    						for(j=0;j<30;j++){
    							if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==0){
    								issign_hard[i][j]=1;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}
								if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==2){
    								issign_hard[i][j]=3;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}
								if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==4){
    								issign_hard[i][j]=5;
    								SetEraseMode(TRUE);
						            DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            SetEraseMode(FALSE);
						            SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
    							}     							    							
    						}   						
    					}
    				}
    				break;
    			case BUTTON_UP:
    				if(button == LEFT_BUTTON){
    					for(i=0;i<19;i++){
    						for(j=0;j<30;j++){
    							if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&isopen_hard[i][j]==1){
    								isopen_hard[i][j]=2;    													            
    							}
								if(!inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&isopen_hard[i][j]==1){
									isopen_hard[i][j]=0;
									SetEraseMode(TRUE);
									SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
						            DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
								}    							    							
    						}    						
    					}
    					if(inBox(mx, my, cx-smileboxlength/2, cy+3-smileboxlength/2, cx+smileboxlength/2, cy+3+smileboxlength/2)&&isbomberfield==2){
							ClearWindow();
							Drawmenu();
						    isbomberfield=0;
						    ismenu=1;
						    for(i=0;i<19;i++){
						    	for(j=0;j<30;j++){
						    		isbomb_hard[i][j]=0;
						    		isopen_hard[i][j]=0;
						    		issign_hard[i][j]=0;						    		
						    	}
						    }
							isbegin3=0;
						}
						else{
							SetEraseMode(TRUE);
							SetPenColor("Gray");
						    StartFilledRegion(1);
						    DrawBox(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    EndFilledRegion();
						    SetEraseMode(FALSE);
						    DrawField(cx-smileboxlength/2, cy+3-smileboxlength/2, smileboxlength, smileboxlength);
						    DrawSmile(cx, cy+3, smiler);
						    isbomberfield=1;
						}   
    				}
    				if(button == RIGHT_BUTTON){
    					for(i=0;i<19;i++){
    						for(j=0;j<30;j++){
    							if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==1&&minenumber!=0){
    								issign_hard[i][j]=2;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            StartFilledRegion(1);
		                            DrawBox(cx-3.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            DrawTextString(smine);
						            SetEraseMode(FALSE);
    								DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
    								DrawFlag(boxcx_hard[i][j]+boxlength/2, boxcy_hard[i][j]+boxlength/2, flagwidth, flagheight);
    								SetPenColor("Light Gray");    								
    								StartFilledRegion(1);
		                            DrawBox(cx-3.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            minenumber--;
		                            sprintf(smine, "%d", minenumber);
		                            if(minenumber==99||minenumber==9)
		                                minex+=TextStringWidth("1")/2;
		                            SetPenColor("Red");
		                            MovePen(minex, miney);
		                            DrawTextString(smine);
    							}
								if(!inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==1){
    								issign_hard[i][j]=0;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
    							} 
								if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==3){
    								issign_hard[i][j]=4;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
    								SetPenColor("Black");
    								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
    								DrawTextString("?");
    							}
    							if(!inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==3){
    								issign_hard[i][j]=2;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
    								DrawFlag(boxcx_hard[i][j]+boxlength/2, boxcy_hard[i][j]+boxlength/2, flagwidth, flagheight);
    							}
								if(inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==5){
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            StartFilledRegion(1);
		                            DrawBox(cx-3.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            DrawTextString(smine);
						            SetEraseMode(FALSE);
    								issign_hard[i][j]=0;
    								DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
    								SetPenColor("Light Gray");    								
    								StartFilledRegion(1);
		                            DrawBox(cx-3.5, cy+2.75, 0.5, 0.5);
		                            EndFilledRegion();
		                            minenumber++;
		                            sprintf(smine, "%d", minenumber);
		                            if(minenumber==100||minenumber==10)
		                                minex-=TextStringWidth("1")/2;
		                            SetPenColor("Red");
		                            MovePen(minex, miney);
		                            DrawTextString(smine);
    							}
								if(!inBox(mx, my, boxcx_hard[i][j], boxcy_hard[i][j], boxcx_hard[i][j]+boxlength, boxcy_hard[i][j]+boxlength)&&issign_hard[i][j]==5){
    								issign_hard[i][j]=4;
    								SetEraseMode(TRUE);
    								SetPenColor("Gray"); 
						            StartFilledRegion(1);
						            DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						            EndFilledRegion();
						            SetEraseMode(FALSE);
    								DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
    								SetPenColor("Black");
    								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
    								DrawTextString("?");
    							}     							    							
    						}
    						
    					}
    				}
    				
    	    }
			
			for(i=0;i<19;i++){
				for(j=0;j<30;j++){					
					if(isopen_hard[i][j]==2){
						SetEraseMode(TRUE);
						DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						SetEraseMode(FALSE);
						SetPenColor("light Gray"); 
						StartFilledRegion(1);
						DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						EndFilledRegion();
						SetPenColor("Dark Gray");
						DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
							
						if(isbomb_hard[i][j]==0){
							count=0;
							if(i-1>=0&&j-1>=0&&isbomb_hard[i-1][j-1]==1)
							count++;
							if(i-1>=0&&isbomb_hard[i-1][j]==1)
							count++;
							if(i-1>=0&&j+1<30&&isbomb_hard[i-1][j+1]==1)
							count++;
							if(j-1>=0&&isbomb_hard[i][j-1]==1)
							count++;
							if(j+1<30&&isbomb_hard[i][j+1]==1)
							count++;
							if(i+1<19&&j-1>=0&&isbomb_hard[i+1][j-1]==1)
							count++;
							if(i+1<19&&isbomb_hard[i+1][j]==1)
							count++;
							if(i+1<19&&j+1<30&&isbomb_hard[i+1][j+1]==1)
							count++;
							if(count==0){
								if(i-1>=0&&j-1>=0)
								isopen_hard[i-1][j-1]=2;
								if(i-1>=0)
								isopen_hard[i-1][j]=2;
								if(j-1>=0)
								isopen_hard[i][j-1]=2;
								if(i-1>=0&&j+1<30)
								isopen_hard[i-1][j+1]=2;
								if(j+1<30)
								isopen_hard[i][j+1]=2;
								if(i+1<19&&j-1>=0)
								isopen_hard[i+1][j-1]=2;
								if(i+1<19)
								isopen_hard[i+1][j]=2;
								if(i+1<19&&j+1<30)
								isopen_hard[i+1][j+1]=2;								
							}
							if(count==1){
								SetPenColor("Blue");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("1\0");
							}
							if(count==2){
								SetPenColor("Green");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("2\0");
							}
							if(count==3){
								SetPenColor("Red");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("3\0");
							}
							if(count==4){
								SetPenColor("Brown");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("4\0");
							}
							if(count==5){
								SetPenColor("Orange");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("5\0");
							}
							if(count==6){
								SetPenColor("Violet");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("6\0");
							}
							if(count==7){
								SetPenColor("Yellow");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("7\0");
							}
							if(count==8){
								SetPenColor("Black");
								MovePen(boxcx_hard[i][j]+0.08, boxcy_hard[i][j]+0.08);
								DrawTextString("8\0");
							}
						}
						else{
							int p, q;
							p=i;  q=j;														
						    for(i=0;i<19;i++){
						    	for(j=0;j<30;j++){
						    		if(isbomb_hard[i][j]==1){
						    		    SetEraseMode(TRUE);
						    		    DrawField(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						    		    SetEraseMode(FALSE);
						    		    SetPenColor("light Gray"); 
						                StartFilledRegion(1);
						                DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
					                  	EndFilledRegion();
					                  	SetPenColor("Dark Gray");
					                   	DrawBox(boxcx_hard[i][j], boxcy_hard[i][j], boxlength, boxlength);
						    		    DrawBomb(boxcx_hard[i][j]+boxlength/2, boxcy_hard[i][j]+boxlength/2);
						    	    }
						    	    isbomb_hard[i][j]=0;
						    	    isopen_hard[i][j]=0;
						    	    issign_hard[i][j]=0;
						    	}
						    }
							SetPenColor("Red");
							StartFilledRegion(1);
						    DrawBox(boxcx_hard[p][q], boxcy_hard[p][q], boxlength, boxlength);
						    EndFilledRegion();
						    DrawBomb(boxcx_hard[p][q]+boxlength/2, boxcy_hard[p][q]+boxlength/2);
						    isbomberfield=0;
						    isbegin3=0;	
							isfail=1; 
						    SetEraseMode(TRUE);
						    DrawSmile(cx, cy+3, smiler);
						    SetEraseMode(FALSE);
						    DrawCry(cx, cy+3, smiler);					    
						}
					}
					
				}
			}
			count=0;
			for(i=0;i<19;i++){
				for(j=0;j<30;j++){
					if(isbomb_hard[i][j]==0&&isopen_hard[i][j]==2)
					 count++;
				}
			}
			if(count==470){
				SetEraseMode(TRUE);
				DrawSmile(cx, cy+3, smiler);
				SetEraseMode(FALSE);
				DrawWinFace(cx, cy+3, smiler);
				SetPenColor("Red");
				MovePen(cx-0.3, cy+2.3);
				DrawTextString("You win!");
				cancelTimer(TIMER_BLINK1000);
				nt=0;
			} 			
				    		
    	}    	    	    	
    }       
}
 
void TimerEventProcess(int timerID)
{
	if(timerID==TIMER_BLINK1000){
	
	    switch(choice){
	      case 1:		      
		    if(nt == 9 ||nt == 99)
		       timex = timex - TextStringWidth("1")/2;
			SetEraseMode(TRUE);
			SetPenColor("Light Gray");
		    StartFilledRegion(1);
		    DrawBox(cx+1, cy+2.75, 0.5, 0.5);
		    EndFilledRegion();		  
		    MovePen(timex, timey); 		    
		    DrawTextString(stime);
		    SetEraseMode(FALSE);
		    nt++;
		    SetPenColor("Light Gray");
		    StartFilledRegion(1);
		    DrawBox(cx+1, cy+2.75, 0.5, 0.5);
		    EndFilledRegion();
		    SetPenColor("Red");
		    sprintf(stime, "%d", nt);
		    MovePen(timex, timey); 
		    DrawTextString(stime);		  
		    break;
		  case 2:		      
		    if(nt == 9 ||nt == 99)
		       timex = timex - TextStringWidth("1")/2;
			SetEraseMode(TRUE);
			SetPenColor("Light Gray");
		    StartFilledRegion(1);
		    DrawBox(cx+2, cy+2.75, 0.5, 0.5);
		    EndFilledRegion();		  
		    MovePen(timex, timey); 		    
		    DrawTextString(stime);
		    SetEraseMode(FALSE);
		    nt++;
		    SetPenColor("Light Gray");
		    StartFilledRegion(1);
		    DrawBox(cx+2, cy+2.75, 0.5, 0.5);
		    EndFilledRegion();
		    SetPenColor("Red");
		    sprintf(stime, "%d", nt);
		    MovePen(timex, timey); 
		    DrawTextString(stime);		  
		    break;	
	      case 3:		      
		    if(nt == 9 ||nt == 99)
		       timex = timex - TextStringWidth("1")/2;
			SetEraseMode(TRUE);
			SetPenColor("Light Gray");
		    StartFilledRegion(1);
		    DrawBox(cx+3, cy+2.75, 0.5, 0.5);
		    EndFilledRegion();		  
		    MovePen(timex, timey); 		    
		    DrawTextString(stime);
		    SetEraseMode(FALSE);
		    nt++;
		    SetPenColor("Light Gray");
		    StartFilledRegion(1);
		    DrawBox(cx+3, cy+2.75, 0.5, 0.5);
		    EndFilledRegion();
		    SetPenColor("Red");
		    sprintf(stime, "%d", nt);
		    MovePen(timex, timey); 
		    DrawTextString(stime);		  
		    break;  
	    }
    }
}

