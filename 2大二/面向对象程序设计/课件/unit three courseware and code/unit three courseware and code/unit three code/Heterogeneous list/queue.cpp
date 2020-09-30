// queue.cpp -- Queue and Customer methods
#include "queue.h"
#include "node.h"
 
// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = 0; 
	items = 0;
}
Queue::~Queue()
{
	NODE * temp;
	while (front != 0) // while queue is not yet empty
	{
		temp = front; // save address of front item
		front = front->next();// reset pointer to next item
		delete temp; // delete former front
	}
}
bool Queue::isempty() const
{
	return items == 0;
}
bool Queue::isfull() const
{
	return items == qsize;
}
int Queue::count() const
{
	return items;
}
// Add item to queue
bool Queue::enqueue( NODE *item)
{
	if (isfull()) return false;
	item->next() = 0;
	items++;
	if (front == 0) // if queue is empty,
		front = item; // place item at front
	else
		rear->linkTo(item);// else place at rear
		rear = item; // have rear point to new node
	return true;
}
// Place front item into item variable and remove from queue

NODE * Queue::dequeue()
{
	NODE * temp = front; // save location of first item
	front = front->next(); // reset front to next item
	items--;
	if (items == 0)
		rear = 0;
    return temp;
}

void Queue::print() const
{
	NODE * temp = front; 
	while (temp)
	{
		temp->print();
	    temp = temp->next(); 
	}
}