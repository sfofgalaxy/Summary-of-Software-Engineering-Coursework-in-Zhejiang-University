#include "intlist.h"
#include <iostream.h>

intlist::~intlist()
{		
	node *temp;
	for (node *p=head; p; ){
		temp = p;
		p = p->next;
		delete temp;
	}
}


void intlist::insert(int a)
{
	node *temp = new node;
	temp->val = a;
	if(head){//链表非空
		temp->next = head;
		head = temp;
	}
	else {
		temp->next = 0;
		head = temp;
	}
	size++;
}


void intlist::append(int a)
{
	node *previous,*current,*newnode;
	newnode = new node;
	newnode->val = a;
	newnode->next = 0;

	if (head){
		previous = head;
		current = head->next;
		while (current) {
			previous = current;
			current = current->next;
		}
		previous->next = newnode;
	}
	else {
		head = newnode;
	}
    size++;

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
		size--;
		return r;
	}	
}


void intlist::print()
{
	node *current;
	if (head) {
		current = head;
		while (current){
			cout << current->val << endl;
			current = current->next;
		}
	}
}
