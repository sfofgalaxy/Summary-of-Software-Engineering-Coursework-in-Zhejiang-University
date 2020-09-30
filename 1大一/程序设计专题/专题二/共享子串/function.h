#ifndef _function_h
#define _function_h 
typedef struct character{
	char ch;
	int tag;
	struct character *next;
}List;


List *FindKth(int K, List *PtrL);

List *Insert(char c, int t, int i, List *Ptrl);

void Connect(List *head, List *tail);

void reverse(char c[]);

void Free(List *p);

void Break(List *head, List *Breakpoint);


#endif
