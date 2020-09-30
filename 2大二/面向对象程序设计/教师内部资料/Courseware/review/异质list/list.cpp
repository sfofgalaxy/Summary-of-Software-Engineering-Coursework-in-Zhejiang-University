#include "Node.h"
#include "List.h"

List::~List()
{
	Node *p = head;
	Node *q;
	while (p)
	{
		q = p;
		delete q;
		p = p->next();
	}
}

void List::print() const
{
	Node *p = head;
	while (p)
	{
		p->print();
		p = p->next();
	}
}