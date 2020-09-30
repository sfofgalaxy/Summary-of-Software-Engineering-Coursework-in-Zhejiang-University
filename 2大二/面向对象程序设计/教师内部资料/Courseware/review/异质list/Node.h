class Node  
{
	Node *m_next;
public:
	Node() : m_next(0) 
	{} 
	void linkTo(Node *p)
	{	
		m_next = p;	
	}
	Node *next()
	{	
		return m_next;	
	}
	virtual ~Node(){}
	virtual void print() const = 0;
};
