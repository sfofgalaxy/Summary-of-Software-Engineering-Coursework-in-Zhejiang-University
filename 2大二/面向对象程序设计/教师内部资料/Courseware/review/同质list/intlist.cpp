#include "intlist.h"
#include <iostream.h>

intlist::~intlist()
{		
	PNODE temp;
	for (PNODE p=head; p; ){
		temp = p;
		p = p->next;
		delete temp;
	}
}


void intlist::insert(int a)
{
	PNODE temp = new node;
	temp->val = a;
	temp->next = NULL;

	if(head){//链表非空
		temp->next = head;
		head = temp;
	}
	else {
		head = temp;
	}
}


void intlist::append(int d)
{
	PNODE newnode, tail;
    newnode = new node;
    newnode->val = d;
    newnode->next = NULL;

    if (head==NULL)
	{
		head = newnode;
	}
  	else
  	{//确定链尾的位置
        tail = head;
        while(tail->next!=NULL){
             tail = tail->next;
        }
       tail->next = newnode;
  	} 
}

int intlist::get()
{
	if(head==0) {
	 	 cout<<"链表为空"<<endl;
	   	 return 0;
	}
	else {
		node *p=head;
		head=head->next;
		int r=p->val;
		delete p;
		return r;
	}	
}


void intlist::print()
{
	PNODE current;
	if (head) {
		current = head;
		while (current){
			cout << current->val << endl;
			current = current->next;
		}
	}
}

void main()
{}
