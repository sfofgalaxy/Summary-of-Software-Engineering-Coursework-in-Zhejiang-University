#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct character{
	char ch;
	int tag;
	struct character *next;
}List;


List *FindKth(int K, List *PtrL);                 //寻找链表的第K个元素 

List *Insert(char c, int t, int i, List *Ptrl);                  //插入链表元素函数 

void Connect(List *head, List *tail);                     //拼接链表串函数 

void reverse(char c[]);                             //翻转字符串函数

void Free(List *p);                     //释放空间函数 

void Break(List *head, List *Breakpoint);                //拆分链表函数 


 
void reverse(char c[]){
	int length;
	int i = 0;
	length = strlen(c);
	for(i = 0;i <= (length-2)/2;i++){
		c[i] = c[i] + c[length  - 1 - i];
		c[length- 1 - i] = c[i] - c[length-1  -i];
		c[i] = c[i] - c[length-1   -i];
	}
}

List *Insert(char c, int t, int i, List *Ptrl){
	List *p, *s;
	if(i==1){
		s = (List *)malloc(sizeof(List));
		s->ch=c;
		s->tag=t;
		s->next = Ptrl;
		return s;
	}
	p = FindKth(i-1, Ptrl);
	if(p==NULL){
		printf("参数i错误"); 
		return NULL; 
	}
	else{
		s = (List *)malloc(sizeof(List));
		s->ch=c;
		s->tag=t;
		s->next = p->next;
		p->next = s;
		return Ptrl;
	}
}

List *FindKth(int K, List *PtrL){
	List *p = PtrL;
	int i = 1;
	while(p!=NULL&&i<K){
		p = p->next;
		i++;
	}
	if(i==K)return p;
	else return NULL;
}

void Connect(List *head, List *tail){
	List *p = head;
	if(p == NULL){
	head = tail;
	}
	else{
	
	while(p->next!=NULL)p=p->next;
	p->next = tail;
}
		
};

void Free(List *p){
	List *s;
	while(p!=NULL){
		s = p;
		p = s->next;
		free(s);
		
	}
};

void Break(List *head, List *Breakpoint){
	List *p;
	p = head;
	while(p->next!=Breakpoint){
		p = p->next;
	}
	if(p == NULL){
		printf("wrong breakpoint.");
	}
	else{
		p->next = NULL;
	}
}

