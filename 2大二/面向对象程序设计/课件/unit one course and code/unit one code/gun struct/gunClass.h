#ifndef GUNCLASS_H
#define GUNCLASS_H

#define max_size 100

/*������������ǵĲ�������һ��*/
struct Gun{
       char v[max_size];//�������ʾ��ϻ Data member
       char *p;
	   void push(char ch);	//member function 
       char pop();
};

#endif