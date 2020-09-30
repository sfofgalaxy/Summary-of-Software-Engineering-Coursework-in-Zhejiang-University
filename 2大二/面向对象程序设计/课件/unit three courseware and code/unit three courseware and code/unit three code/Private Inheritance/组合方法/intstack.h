class intlist;
class intstack{
public: 
	intstack()
	{
		p = new intlist;
	}
	void push(int a)
    {  	
		p->insert(a);	
	}
	int pop()
	{  
		return p->get();
	}  
	void print()
	{
		p->print();
	}
	~intstack()
	{
		delete p;
	}
private:
	intlist *p;
};






