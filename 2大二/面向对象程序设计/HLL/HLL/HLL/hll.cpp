#include "hll.h"

HLL::HLL()
{
	Head = Tail = NULL;												//initialize the list
	Length = 0;
}

HLL::~HLL()
{
	destory();
}

void HLL::print() const
{
	Node *Temp = Head;
	if (!Temp)
		cout << "Empty HLL!" << endl;
	else
	{
		while (Temp)
		{
			Temp->print();											//call virtual function
			Temp = Temp->next();
		}
	}
}

Node * HLL::get_head()
{
	return Head;													//return Head
}

Node * HLL::get_tail()
{
	return Tail;													//return Tail
}

Node * HLL::operator[](int index)
{
	int count = 0;
	Node *Temp = Head;
	while (Temp)														//find the index poision's node
	{
		if (count == index)
			break;
		Temp = Temp->next();
		count++;
	}
	return Temp;													//return the node's pointer
}

const int HLL::length() const
{
	return Length;													//return the length
}

void HLL::insert_head(int a)										//insert Int node into head (function overload)
{
	Node *Temp = new IntNode(a);
	Temp->next() = Head;
	Head = Temp;
	if (!Tail)
		Tail = Temp;
	Length++;
}

void HLL::insert_head(double a)									//insert Double node into head (function overload)
{
	Node *Temp = new DoubleNode(a);
	Temp->next() = Head;
	Head = Temp;
	if (!Tail)
		Tail = Temp;
	Length++;
}

void HLL::insert_head(const char * a)									//insert String node into head (function overload)
{
	Node *Temp = new StringNode(a);
	Temp->next() = Head;
	Head = Temp;
	if (!Tail)
		Tail = Temp;
	Length++;
}

void HLL::insert_tail(int a)										//insert Int node into tail(function overload)
{
	Node *Temp = new IntNode(a);
	Temp->next() = NULL;
	if (Tail)														//find the tail node
		Tail->next() = Temp;
	Tail = Temp;
	if (!Head)
		Head = Temp;
	Length++;
}

void HLL::insert_tail(double a)									//insert Double node into head (function overload)
{
	Node *Temp = new DoubleNode(a);
	Temp->next() = NULL;
	if (Tail)
		Tail->next() = Temp;
	Tail = Temp;
	if (!Head)
		Head = Temp;
	Length++;
}

void HLL::insert_tail(const char * a)									//insert String node into head (function overload)
{
	Node *Temp = new StringNode(a);
	Temp->next() = NULL;
	if (Tail)
		Tail->next() = Temp;
	Tail = Temp;
	if (!Head)
		Head = Temp;
	Length++;
}


void HLL::delete_head()											//Delete the head node (function overload)
{
	if (!Head)
	{
		cout << "The list is empty!" << endl;
		return;
	}
	Node *Temp = Head;
	Head = Temp->next();
	delete Temp;
	Length--;
}

void HLL::delete_tail()											//Delete the tail node (function overload)
{
	if (!Tail)
	{
		cout << "The list is empty!" << endl;
		return;
	}
	Node *Temp = Head;
	if (1 == Length)
	{
		delete Tail;
		Head = Tail = NULL;
	}
	else
	{
		while (Temp->next()->next())
			Temp = Temp->next();
		delete Temp->next();
		Temp->next() = NULL;
		Tail = Temp;
	}
	Length--;
}


void HLL::reverse()												//Reverse the linked list
{
	if (1 >= Length)
		return;
	Node *FTemp = Head;
	Node *NTemp = Head->next();
	while (NTemp)
	{
		FTemp->next() = NTemp->next();
		NTemp->next() = Head;
		Head = NTemp;
		NTemp = FTemp->next();
	}
	Tail = FTemp;
}

void HLL::destory()												//Destory the linked list
{
	Node *Temp = Head;
	Node *T;
	while (Temp)
	{
		T = Temp;
		Temp = Temp->next();
		delete T;
	}
	Head = Tail = NULL;
	Length = 0;
}

void HLL::union_other(const HLL& a)									//Union two linked list
{
	Node *TTemp = Tail;
	Node *FTemp = a.Head;
	while (FTemp)
	{
		FTemp->union_other(TTemp);
		FTemp = FTemp->next();
		TTemp = TTemp->next();
	}
}


IntNode::IntNode(int a)												//IntNode class
{
	Int_value = a;
}

void IntNode::union_other(Node *& a) const								//IntNode union
{
	a->next() = new IntNode(Int_value);
	a->next()->next() = NULL;
}

void IntNode::print() const											//IntNode print
{
	cout << Int_value << endl;
}

DoubleNode::DoubleNode(double a)									//DoubleNode class
{
	Double_value = a;
}

void DoubleNode::union_other(Node *& a) const							//DoubleNode union
{
	a->next() = new DoubleNode(Double_value);
	a->next()->next() = NULL;
}

void DoubleNode::print() const										//Double print
{
	printf("%lf\n", Double_value);
}

StringNode::StringNode(const char * a)									//StringNode class
{
	Char_value = new char[strlen(a) + 1];
	strcpy(Char_value, a);
}

StringNode::~StringNode()											//virtual StringNode destructor function to release the space applicated in heap
{
	delete Char_value;
}

void StringNode::union_other(Node *& a) const							//StringNode union
{
	a->next() = new StringNode(Char_value);
	a->next()->next() = NULL;
}

void StringNode::print() const										//StringNode print
{
	cout << Char_value << endl;
}
