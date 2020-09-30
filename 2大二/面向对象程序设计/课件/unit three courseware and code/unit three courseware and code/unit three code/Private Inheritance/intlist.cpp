#include "intlist.h"
#include <iostream.h>

intlist::~intlist()
{			
	PNODE temp;//node *temp;
	for (node *p=head; p; ){
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
		temp->next = head;
		head = temp;
	}
}


void intlist::append(int a)
{
	PNODE previous, tail, newnode;
	
	newnode = new node;
	newnode->val = a;
	newnode->next = NULL;

	if (head){
		previous = head;
		tail = head;
		while (tail->next) {
				previous = tail;
				tail = tail->next;
		}
		tail->next = newnode;
	}
	else {
		head = newnode;
	}
}

int intlist::get()
{
	if(head==0) {
	 	 cout<<"链表为空"<<endl;
	   	 return 0;
	}
	else {
		PNODE p=head;
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
