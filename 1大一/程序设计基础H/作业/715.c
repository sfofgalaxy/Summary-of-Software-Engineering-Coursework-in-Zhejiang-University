#include<stdio.h>
void main()
{
	int ri,looptimes;
	int month;
	char *month_name[]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
	
	scanf("%d",&looptimes);
	for(ri=1;ri<=looptimes;ri++){
		scanf("%d",&month);
		switch(month){
			case 1:printf("%s\n",month_name[1]);break;
			case 2:printf("%s\n",month_name[2]);break;
			case 3:printf("%s\n",month_name[3]);break;
			case 4:printf("%s\n",month_name[4]);break;
			case 5:printf("%s\n",month_name[5]);break;
			case 6:printf("%s\n",month_name[6]);break;
			case 7:printf("%s\n",month_name[7]);break;
			case 8:printf("%s\n",month_name[8]);break;
			case 9:printf("%s\n",month_name[9]);break;
			case 10:printf("%s\n",month_name[10]);break;
			case 11:printf("%s\n",month_name[11]);break;
			case 12:printf("%s\n",month_name[12]);break;
			default:printf("Wrong input!\n");break; 
		}
	}
}
 
