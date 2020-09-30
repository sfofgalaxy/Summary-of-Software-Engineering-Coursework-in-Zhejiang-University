#ifndef GUNCLASS_H
#define GUNCLASS_H

#define max_size 100

/*数据与操作他们的操作放在一起*/
struct Gun{
       char v[max_size];//用数组表示弹匣 Data member
       char *p;
	   void push(char ch);	//member function 
       char pop();
};

#endif