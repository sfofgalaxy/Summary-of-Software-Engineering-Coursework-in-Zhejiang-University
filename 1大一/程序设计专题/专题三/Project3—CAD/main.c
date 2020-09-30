#include "myheadfile.h" 


/*  
���������ѡ��״̬ 
choose״̬������ƶ�ͼ�Σ��Ҽ��ı�ͼ�δ�С
line��ellipse��retangle״̬�»�ֱ�ߡ���Բ������
text״̬�µ�����ʼд����
delete״̬�����ɾ����ѡͼ��
*/ 
  
void Main()
{
    InitGraphics();//��ʼ������ 
    SetWindowTitle("CAD");
	choosey= GetWindowHeight()-0.5;
	ly = choosey-0.8;
	cy=ly-0.8;
	ry = cy-0.8;
	ty=ry-0.8;
	dy=ty-0.8;
    initialize();
    registerMouseEvent(MouseEventProcess);/*ע�������Ϣ�ص�����*/ 
    registerKeyboardEvent(KeyboardEventProcess);/*ע�������Ϣ�ص�����*/
	registerCharEvent(CharEventProcess);/*ע���ַ���Ϣ�ص�����*/
	registerTimerEvent(TimerEventProcess);/*ע�ᶨʱ����Ϣ�ص�����*/
    SetPenSize(1);
}
void DrawRectangle(double lenth,double width)//������ 
{
	DrawLine(lenth,0);
	DrawLine(0,-width);
	DrawLine(-lenth,0);
	DrawLine(0,width);
	return;
}

bool InBox(double x0, double y0, double x1, double y1, double x2, double y2){//�ж�ĳ���Ƿ������ж������� 
	return (x0 >= x1 && x0 <= x2 && y0 >= y1 && y0 <= y2)||(x0>=x2&&x0<=x1&&y0>=y1&&y0<=y2)||(x0>=x1&&x0<=x2&&y0>=y2&&y0<=y1)||(x0>=x2&&x0<=x1&&y0>=y2&&y0<=y1);
}

void initialize(void){//��ʼ������ 
	MovePen(bx,choosey);DrawRectangle(0.8,0.4);MovePen(bx+0.15,choosey-0.2);DrawTextString("Choose");
    MovePen(bx,ly);DrawRectangle(0.8,0.4);MovePen(bx+0.25,ly-0.2);DrawTextString("Line");
    MovePen(bx,cy);DrawRectangle(0.8,0.4);MovePen(bx+0.15,cy-0.2);DrawTextString("Ellipse");
    MovePen(bx,ry);DrawRectangle(0.8,0.4);MovePen(bx+0.04,ry-0.2);DrawTextString("Rectangle");
    MovePen(bx,ty);DrawRectangle(0.8,0.4);MovePen(bx+0.23,ty-0.2);DrawTextString("Text");
    MovePen(bx,dy);DrawRectangle(0.8,0.4);MovePen(bx+0.17,dy-0.2);DrawTextString("Delete");
    SetPenColor("red");
    MovePen(bx+0.15,ly-0.3);DrawLine(0.5,0); 
    MovePen(bx+0.6,cy-0.33);DrawEllipticalArc(0.2,0.06,0,360);
    MovePen(bx+0.25,ry-0.25);DrawRectangle(0.3,0.13);
    MovePen(bx+0.25,ty-0.35);DrawTextString("ABC");
    SetPenColor("black");
	MovePen(GetWindowWidth()/8,0);
	DrawLine(0,GetWindowHeight());   	
}

void MouseEventProcess(int x, int y, int button, int event){
	static int i,j;
	double mx, my;//��ǰ���λ�� 
 	mx = ScaleXInches(x);/*pixels --> inches*/
 	my = ScaleYInches(y);/*pixels --> inches*/
	switch(event){
		case BUTTON_DOWN:
			if(istext){//��text��һ��������� 
				string s;
				s = SubString(text[textnum],0,location-1);
				MovePen(pic[picnum-1].x1+TextStringWidth(s),pic[picnum-1].y1);
				SetEraseMode(TRUE);
				DrawTextString("_");
				SetEraseMode(FALSE);
				textnum++;
				cancelTimer(TIMER_BLINK);
			}
			if(ischoose&&InBox(mx,my,GetWindowWidth()/8,0,GetWindowWidth(),GetWindowHeight())){//ѡ��ͼ�� 
				omx = mx;
				omy = my;
				for(i=0;i<picnum;i++){
					switch(pic[i].type){
						case 1:
							if(pic[i].x1==pic[i].x2){
								if(InBox(mx,my,pic[i].x1-0.1,pic[i].x1+0.1,pic[i].y1,pic[i].y2)){
									temp=pic[i];
								}
								break;
							}
							if(f(mx,pic[i].x1,pic[i].y1,pic[i].x2,pic[i].y2)-my<=0.15&&f(mx,pic[i].x1,pic[i].y1,pic[i].x2,pic[i].y2)-my>=-0.15&&((mx<=pic[i].x2&&mx>=pic[i].x1)||(mx<=pic[i].x1&&mx>=pic[i].x2))){
								temp = pic[i];
								break;
							}
							break;
						case 2:
							if(InBox(mx,my,pic[i].x1,pic[i].y2,pic[i].x2,pic[i].y1)){
								temp = pic[i];
							}
							break;
						case 3:
							if(InBox(mx,my,pic[i].x1,pic[i].y2,pic[i].x2,pic[i].y1))temp = pic[i];
							break;
						case 4:
							if(InBox(mx,my,pic[i].x1-0.1,pic[i].y1-0.1,pic[i].x2+0.1,pic[i].y1+0.1))temp = pic[i];
							break;
						default:
							break; 
					}
					if(temp.type!=0&&button==LEFT_BUTTON){
						ismove = TRUE;
						ischange = FALSE; 
						break;
					}
					else if(temp.type!=0&&button==RIGHT_BUTTON){
						ismove = FALSE;
						ischange = TRUE;
						break;
					}
				}
			}
			if(isdelete&&InBox(mx,my,GetWindowWidth()/8,0,GetWindowWidth(),GetWindowHeight())&&button==LEFT_BUTTON){//ѡ��ͼ�� 
				for(i=0;i<picnum;i++){
					switch(pic[i].type){
						case 1:
							if(pic[i].x1==pic[i].x2){
								if(InBox(mx,my,pic[i].x1-0.1,pic[i].x1+0.1,pic[i].y1,pic[i].y2)){
									SetEraseMode(TRUE);
									MovePen(pic[i].x1,pic[i].y1);
									DrawLine(pic[i].x2-pic[i].x1,pic[i].y2-pic[i].y1);
									temp=pic[i];
								}
								break;
							}
							if(f(mx,pic[i].x1,pic[i].y1,pic[i].x2,pic[i].y2)-my<=0.15&&f(mx,pic[i].x1,pic[i].y1,pic[i].x2,pic[i].y2)-my>=-0.15&&((mx<=pic[i].x2&&mx>=pic[i].x1)||(mx<=pic[i].x1&&mx>=pic[i].x2))){
								SetEraseMode(TRUE);
								MovePen(pic[i].x1,pic[i].y1);
								DrawLine(pic[i].x2-pic[i].x1,pic[i].y2-pic[i].y1);
								temp=pic[i];
								break;
							}
							break;
						case 2:
							if(InBox(mx,my,pic[i].x1,pic[i].y2,pic[i].x2,pic[i].y1)){
								SetEraseMode(TRUE);
								if(pic[i].x2>=pic[i].x1)MovePen(pic[i].x2,(pic[i].y1+pic[i].y2)/2);
								else MovePen(pic[i].x1,(pic[i].y1+pic[i].y2)/2);
								DrawEllipticalArc(fabs(pic[i].x2-pic[i].x1)/2,fabs(pic[i].y2-pic[i].y1)/2,0,360);
								temp = pic[i];
								break;
							}
							break;
						case 3:
							if(InBox(mx,my,pic[i].x1,pic[i].y2,pic[i].x2,pic[i].y1)){
								SetEraseMode(TRUE);
								MovePen(pic[i].x1,pic[i].y1);
								DrawRectangle(pic[i].x2-pic[i].x1,pic[i].y1-pic[i].y2);
								temp = pic[i];
							}
							break;
						case 4:
							if(InBox(mx,my,pic[i].x1-0.1,pic[i].y1-0.1,pic[i].x2+0.1,pic[i].y1+0.1)){
								SetEraseMode(TRUE);
								MovePen(pic[i].x1,pic[i].y1);
								DrawTextString(text[pic[i].num]);
								temp = pic[i];
						}
							break;
						default:
							break; 
					}
					if(temp.type!=0&&button==LEFT_BUTTON){
						SetEraseMode(FALSE);
						pic[i].type=pic[i].x1=pic[i].x2=pic[i].y1=pic[i].y2=0;
						break;
					}
				}
			} 
			if(button==LEFT_BUTTON){/*ѡ��ť*/ 
				if(InBox(mx,my,bx,choosey-0.4,bx+0.8,choosey)){
					SetEraseMode(TRUE);
					MovePen(bx-0.2,choosey-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ly-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,cy-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ry-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ty-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,dy-0.2);
					DrawTextString("��");
					SetEraseMode(FALSE);
					MovePen(bx-0.2,choosey-0.2);
					DrawTextString("��");
					ischoose = TRUE;
					isdelete = FALSE;
					isline = FALSE;
					iscircle = FALSE;
					isrectangle = FALSE;
					istext = FALSE;
					isdraw = FALSE;
				}
				else if(InBox(mx,my,bx,ly-0.4,bx+0.8,ly)){/*ѡ����*/
					SetEraseMode(TRUE);
					MovePen(bx-0.2,choosey-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ly-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,cy-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ry-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ty-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,dy-0.2);
					DrawTextString("��");
					SetEraseMode(FALSE);
					MovePen(bx-0.2,ly-0.2);
					DrawTextString("��"); 
					ischoose = FALSE;
					isline = TRUE;
					iscircle = FALSE;
					isdelete = FALSE;
					isrectangle = FALSE;
					istext = FALSE;
					isdraw = FALSE;
				}
				else if(InBox(mx,my,bx,cy-0.4,bx+0.8,cy)){/*ѡ����Բ*/ 
					SetEraseMode(TRUE);
					MovePen(bx-0.2,choosey-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ly-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,cy-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ry-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ty-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,dy-0.2);
					DrawTextString("��");
					SetEraseMode(FALSE);
					MovePen(bx-0.2,cy-0.2);
					DrawTextString("��");
					ischoose = FALSE;
					isline = FALSE;
					iscircle = TRUE;
					isdelete = FALSE;
					isrectangle = FALSE;
					istext = FALSE;
					isdraw = FALSE;
				}
				else if(InBox(mx,my,bx,ry-0.4,bx+0.8,ry)){/*ѡ�񻭾���*/ 
					SetEraseMode(TRUE);
					MovePen(bx-0.2,choosey-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ly-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,cy-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ry-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ty-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,dy-0.2);
					DrawTextString("��");
					SetEraseMode(FALSE);
					MovePen(bx-0.2,ry-0.2);
					DrawTextString("��");
					ischoose = FALSE;
					isline = FALSE;
					iscircle = FALSE;
					isdelete = FALSE;
					isrectangle = TRUE;
					istext = FALSE;
					isdraw = FALSE;
				}
				else if(InBox(mx,my,bx,ty-0.4,bx+0.8,ty)){/*ѡ���ı�*/ 
					SetEraseMode(TRUE);
					MovePen(bx-0.2,choosey-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ly-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,cy-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ry-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ty-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,dy-0.2);
					DrawTextString("��");
					SetEraseMode(FALSE);
					MovePen(bx-0.2,ty-0.2);
					DrawTextString("��");
					ischoose = FALSE;
					isline = FALSE;
					iscircle = FALSE;
					isrectangle = FALSE;
					isdelete = FALSE;
					istext = TRUE;
					isdraw = FALSE;
				}
				else if(InBox(mx,my,bx,dy-0.4,bx+0.8,dy)){/*ɾ��ͼ��*/ 
					SetEraseMode(TRUE);
					MovePen(bx-0.2,choosey-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ly-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,cy-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ry-0.2);
					DrawTextString("��");
					MovePen(bx-0.2,ty-0.2);
					DrawTextString("��");
					SetEraseMode(FALSE); 
					MovePen(bx-0.2,dy-0.2);
					DrawTextString("��");
					isdelete = TRUE; 
					ischoose = FALSE;
					isline = FALSE;
					iscircle = FALSE;
					isrectangle = FALSE;
					istext = FALSE;
					isdraw = FALSE;
				}
				else if(InBox(mx,my,GetWindowWidth()/8,0,GetWindowWidth(),GetWindowHeight())){/*ѡ��ͼ��or��ͼ��*/ 
					if(isline||iscircle||istext||isrectangle){
						textlen = location = 0;
						isdraw = TRUE;
						startx = omx = mx;
						starty = omy = my;
					}
				}
			}
			break;
		case BUTTON_DOUBLECLICK:
			break; 
		case BUTTON_UP:
			if(ischoose)initialize();
			temp.type = 0;
			if((!istext)){
				ischange =  FALSE;
				ismove = FALSE;
				isdraw = FALSE;
				for(j=0;j<picnum;j++){//ʵ��������������ʱ�ѱ�������ͼ�λָ� 
					switch(pic[j].type){
						case 1:
							MovePen(pic[j].x1,pic[j].y1);
							DrawLine(pic[j].x2-pic[j].x1,pic[j].y2-pic[j].y1);
							break;
						case 2:
							if(pic[j].x2>=pic[j].x1)MovePen(pic[j].x2,(pic[j].y1+pic[j].y2)/2);
							else MovePen(pic[j].x1,(pic[j].y1+pic[j].y2)/2);
							DrawEllipticalArc(fabs(pic[j].x2-pic[j].x1)/2,fabs(pic[j].y1-pic[j].y2)/2,0,360);
							break;
						case 3:
							MovePen(pic[j].x1,pic[j].y1);
							DrawRectangle(pic[j].x2-pic[j].x1,pic[j].y1-pic[j].y2); 
							break;
						case 4:
							MovePen(pic[j].x1,pic[j].y1);
							DrawTextString(text[pic[j].num]);
							break;
						default:
							break;
					}
				}
				if(button==LEFT_BUTTON&&(isline||iscircle||isrectangle)&&InBox(mx,my,GetWindowWidth()/8,0,GetWindowWidth(),GetWindowHeight())){//������̧��ʱ��¼ͼ������ 
					pic[picnum].x1=startx;
					pic[picnum].y1=starty;
					pic[picnum].x2=mx;
					pic[picnum].y2=my;
					pic[picnum].num=picnum;
					if(isline)pic[picnum].type=1;
					else if(iscircle)pic[picnum].type=2;
					else if(isrectangle)pic[picnum].type=3;
					picnum++;	
				}
				break;	
			}
			else if(button==LEFT_BUTTON&&istext){//���̧��ʱ��ʼд�ı� 
				MovePen(startx,starty);
				pic[picnum].x1=startx;
				pic[picnum].y1=pic[picnum].y2=starty;
				pic[picnum].num=textnum;
				pic[picnum].type=4;
				picnum++;
				MovePen(startx,starty); 
				startTimer(TIMER_BLINK, mseconds);
			}
		case MOUSEMOVE:
			if(!InBox(mx,my,GetWindowWidth()/8,0,GetWindowWidth(),GetWindowHeight()))return;
			if(ismove){/*�ƶ���ѡͼ*/ 
				if(temp.type==0)return;
				SetEraseMode(TRUE);
				switch(pic[i].type){
						case 1:
							MovePen(pic[i].x1,pic[i].y1);
							DrawLine(pic[i].x2-pic[i].x1,pic[i].y2-pic[i].y1);
							SetEraseMode(FALSE);
							pic[i].x1 += mx-omx;
							pic[i].x2 += mx-omx;
							pic[i].y1 += my-omy;
							pic[i].y2 += my-omy;
							omx = mx;
							omy = my;
							MovePen(pic[i].x1,pic[i].y1);
							DrawLine(pic[i].x2-pic[i].x1,pic[i].y2-pic[i].y1);
							break;
						case 2:
							if(pic[i].x2>=pic[i].x1)MovePen(pic[i].x2,(pic[i].y1+pic[i].y2)/2);
							else MovePen(pic[i].x1,(pic[i].y1+pic[i].y2)/2);
							DrawEllipticalArc(fabs(pic[i].x2-pic[i].x1)/2,fabs(pic[i].y2-pic[i].y1)/2,0,360);
							SetEraseMode(FALSE);
							pic[i].x1 += mx-omx;
							pic[i].x2 += mx-omx;
							pic[i].y1 += my-omy;
							pic[i].y2 += my-omy;
							omx = mx;
							omy = my;
							if(pic[i].x2>=pic[i].x1)MovePen(pic[i].x2,(pic[i].y1+pic[i].y2)/2);
							else MovePen(pic[i].x1,(pic[i].y1+pic[i].y2)/2);
							DrawEllipticalArc(fabs(pic[i].x2-pic[i].x1)/2,fabs(pic[i].y2-pic[i].y1)/2,0,360); 
							break;
						case 3:
							MovePen(pic[i].x1,pic[i].y1);
							DrawRectangle(pic[i].x2-pic[i].x1,pic[i].y1-pic[i].y2);
							SetEraseMode(FALSE);
							pic[i].x1 += mx-omx;
							pic[i].x2 += mx-omx;
							pic[i].y1 += my-omy;
							pic[i].y2 += my-omy;
							omx = mx;
							omy = my;
							MovePen(pic[i].x1,pic[i].y1);
					 		DrawRectangle(pic[i].x2-pic[i].x1,pic[i].y1-pic[i].y2);
							break;
						case 4:
							MovePen(pic[i].x1,pic[i].y1);
							DrawTextString(text[pic[i].num]);
							SetEraseMode(FALSE);
							pic[i].x1 += mx-omx;
							pic[i].x2 += mx-omx;
							pic[i].y1 += my-omy;
							pic[i].y2 += my-omy;
							omx = mx;
							omy = my;
							MovePen(pic[i].x1,pic[i].y1);
							DrawTextString(text[pic[i].num]);
							break;
						default:
							break;
					}
			}
			else if(isline&&isdraw){//��껭�� 
				SetEraseMode(TRUE);
              	MovePen(startx,starty);
              	DrawLine(omx-startx,omy-starty);
              	MovePen(startx,starty);
              	SetEraseMode(FALSE);
                DrawLine(mx-startx,my-starty);  
               	omx = mx;
        		omy = my;
			}
			else if(iscircle&&isdraw){//��껭��Բ 
				MovePen(omx,(starty+omy)/2);
				SetEraseMode(TRUE);
				if(omx>startx)MovePen(omx,(starty+omy)/2);
				else MovePen(startx,(starty+omy)/2);
				DrawEllipticalArc(fabs(omx-startx)/2,fabs(starty-omy)/2,0,360);
				SetEraseMode(FALSE);
				if(mx>startx)MovePen(mx,(starty+my)/2);
				else MovePen(startx,(starty+my)/2);
				DrawEllipticalArc(fabs(mx-startx)/2,fabs(starty-my)/2,0,360);
				omx = mx;
				omy = my;
			} 
			else if(isrectangle&&isdraw){//��껭���� 
				SetEraseMode(TRUE);
              	MovePen(startx,starty);
              	DrawRectangle(omx-startx,starty-omy);
              	MovePen(startx,starty);
              	SetEraseMode(FALSE);
              	DrawRectangle(mx-startx,starty-my);
              	omx = mx;
              	omy = my;
			}
			else if(ischange){//�ı��С 
				if(temp.type==0)return;
				SetEraseMode(TRUE);
				switch(pic[i].type){
					case 1:
						MovePen(pic[i].x1,pic[i].y1);
						DrawLine(pic[i].x2-pic[i].x1,pic[i].y2-pic[i].y1);
						SetEraseMode(FALSE);
						pic[i].x2 += mx-omx;
						pic[i].y2 += my-omy;
						omx = mx;
						omy = my;
						MovePen(pic[i].x1,pic[i].y1);
						DrawLine(pic[i].x2-pic[i].x1,pic[i].y2-pic[i].y1);
						break;
					case 2:
						if(pic[i].x2>=pic[i].x1)MovePen(pic[i].x2,(pic[i].y1+pic[i].y2)/2);
						else MovePen(pic[i].x1,(pic[i].y1+pic[i].y2)/2);
						DrawEllipticalArc(fabs(pic[i].x2-pic[i].x1)/2,fabs(pic[i].y2-pic[i].y1)/2,0,360);
						SetEraseMode(FALSE);
						pic[i].x2 += mx-omx;
						pic[i].y2 += my-omy;
						omx = mx;
						omy = my;
						if(pic[i].x2>=pic[i].x1)MovePen(pic[i].x2,(pic[i].y1+pic[i].y2)/2);
						else MovePen(pic[i].x1,(pic[i].y1+pic[i].y2)/2);
						DrawEllipticalArc(fabs(pic[i].x2-pic[i].x1)/2,fabs(pic[i].y2-pic[i].y1)/2,0,360); 
						break;
					case 3:
						MovePen(pic[i].x1,pic[i].y1);
						DrawRectangle(pic[i].x2-pic[i].x1,pic[i].y1-pic[i].y2);
						SetEraseMode(FALSE);
						pic[i].x2 += mx-omx;
						pic[i].y2 += my-omy;
						omx = mx;
						omy = my;
						MovePen(pic[i].x1,pic[i].y1);
				 		DrawRectangle(pic[i].x2-pic[i].x1,pic[i].y1-pic[i].y2);
						break;
					default:
						SetEraseMode(FALSE);
						break;
				}
				break;
			}
			break;
		default:
			break; 
	}
}


void KeyboardEventProcess(int key,int event)//�����ı�֧������ɾ���������Ҽ� 
{
	if(!istext)return; 
	switch(event){
		case KEY_DOWN:
			switch(key){
				case VK_BACK: 
					{
						if(location<=0)return;//�жϵ�ǰλ�� 
						//�Ȳ������ 
						SetEraseMode(TRUE);
						DrawTextString("_");
						SetEraseMode(FALSE);
						MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
						//ɾ�� 
						int i; 
						string s1,s2;
						s1 = SubString(text[textnum],location,textlen);
						s2 = SubString(text[textnum],location-1,textlen);
						SetEraseMode(TRUE);
						str[0] = text[textnum][--location];
						MovePen(GetCurrentX()-TextStringWidth(str),GetCurrentY());
						DrawTextString(s2);
						SetEraseMode(FALSE);
						MovePen(GetCurrentX()-TextStringWidth(s2),GetCurrentY());
						DrawTextString(s1);
						MovePen(GetCurrentX()-TextStringWidth(s1),GetCurrentY());
						DrawTextString("_");
						MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
						isBlink = TRUE;
						//��¼ɾ������ַ��� 
						for(i=location;i<textlen;i++)text[textnum][i]=text[textnum][i+1];
						textlen--; 
						pic[picnum-1].x2=startx+TextStringWidth(text[textnum]);
						break;
					}
				case VK_DELETE://��back������ͬ 
					{
						if(location>=textlen)return;
						int i; 
						string s1,s2; 
						location++;
						s1 = SubString(text[textnum],location,textlen);
						s2 = SubString(text[textnum],location-1,textlen);
						SetEraseMode(TRUE);
						str[0] = text[textnum][--location];
						DrawTextString(s2);
						SetEraseMode(FALSE);
						MovePen(GetCurrentX()-TextStringWidth(s2),GetCurrentY());
						DrawTextString(s1);
						MovePen(GetCurrentX()-TextStringWidth(s1),GetCurrentY());
						for(i=location;i<textlen;i++)text[textnum][i]=text[textnum][i+1];
						textlen--; 
						pic[picnum-1].x2=startx+TextStringWidth(text[textnum]);
						break;
					}
				case VK_LEFT:
					if(location==0)return;
					string s;
					location--;
					str[0]=text[textnum][location];
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
					str[0] = text[textnum][location];
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

void CharEventProcess(char c)//�ı����� 
{
	if(textlen>=99||GetCurrentX()>GetWindowWidth()||c==VK_DELETE||c==VK_BACK||!istext)return;
	switch(c){
		int i;
		case '\r':
			return;
		default:{
			str[0] = c;
			//�Ȳ������ 
			SetEraseMode(TRUE);
			DrawTextString("_");
			MovePen(GetCurrentX()-TextStringWidth("_"),GetCurrentY());
			SetEraseMode(FALSE);
			
			//д���ַ� 
			string s;
			s = SubString(text[textnum],location,textlen);
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
			
			//��¼�µ��ַ��� 
			for(i=textlen;i>location;i--)text[textnum][i]=text[textnum][i-1];
			text[textnum][location] = c;
			location++;
			textlen++;
			pic[picnum-1].x2=startx+TextStringWidth(text[textnum]);
			break;		
		}	
	}
}

void TimerEventProcess(int timerID){//���ƹ����˸ 
		switch (timerID) {
	   		case TIMER_BLINK: /*�����˸��ʱ��*/
				SetEraseMode(!isBlink);
				DrawTextString("_");/*��ǰλ�û����ַ�������*/
				MovePen(GetCurrentX()-TextStringWidth("_"), GetCurrentY());
				isBlink = !isBlink;/*������ʾ/���ع��*/
				break;
			default:
				break;
		}
} 
double f(double x0,double x1,double y1,double x2,double y2){//����ֱ�߷��̵������� 
	return ((y2-y1)*(x0-x1)/(x2-x1)+y1);
	
}
