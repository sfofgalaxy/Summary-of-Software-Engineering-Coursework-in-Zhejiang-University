/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� repeat (0<repeat<10)���� repeat ���������㣺
����һ��ʱ����ֵ������������ n�������ʱ���ٹ� n ����ʱ��ֵ��ʱ��ı�ʾ��ʽΪʱ:��:�룬
���� 24 ʱ�� 0 ʱ���¿�ʼ��ʱ��
�������ʾ����������Ϊ˵��
���룺
3	   (repeat=3)
0:0:1
59	   (����n=59)
11:59:40   
30	   (����n=30)
23:59:40   
301	   (����n=301)
�����
time: 0:1:0	   (0:0:01����59�����ʱ��)   
time: 12:0:10	   (11:59:40����30�����ʱ��)
time: 0:4:41	   (23:59:40����301�����ʱ��)
*/

#include<stdio.h>
int main(void)
{
	int repeat,i;
	int n,m;
	struct {
		int hour;
		int minute;
		int second;
	}time[10];
	scanf("%d",&repeat);
	for(i=0;i<repeat;i++){
		scanf("%d:%d:%d",&time[i].hour,&time[i].minute,&time[i].second);
		scanf("%d",&n);
		m=time[i].hour*3600+time[i].minute*60+time[i].second;
		m+=n;
		if(m/3600<24){
			time[i].hour=m/3600;
			time[i].minute=(m-m/3600*3600)/60;
			time[i].second=m-m/3600*3600-(m-m/3600*3600)/60*60;
		}
		else {
			m-=24*3600;
			time[i].hour=m/3600;
			time[i].minute=(m-m/3600*3600)/60;
			time[i].second=m-m/3600*3600-(m-m/3600*3600)/60*60;
		}
		printf("time: %d:%d:%d\n",time[i].hour,time[i].minute,time[i].second);
	}
	
} 
