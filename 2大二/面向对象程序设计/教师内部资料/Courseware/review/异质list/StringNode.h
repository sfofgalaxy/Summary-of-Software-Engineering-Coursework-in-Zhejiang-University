class StringNode : public Node
{
	char *p;
public:
	StringNode(char *p) 
	{	
		  this->p = new char[strlen(p)+1]; 
		  strcpy(this->p, p);
	}
	StringNode()
	{
		p = NULL;
	}
	~StringNode()
	{	
		if(p!=NULL)
			delete[] p;	
	}
	void print() const
	{
		cout << "×Ö·û´®£º" << p << endl;
	}
};
