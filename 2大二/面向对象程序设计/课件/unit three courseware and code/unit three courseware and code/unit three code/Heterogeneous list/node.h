#ifndef BASENODE_H_
#define BASENODE_H_

class iostream;

class NODE  
{
	NODE *m_next;
public:
	NODE(): m_next(0) 
	{} 
	void linkTo(NODE *p);
	NODE*& next();
	virtual ~NODE(){}
	virtual void print() const = 0;
};

class INT : public NODE
{
	int i;
public:
	INT(int ii=0): i(ii)
	{}
	void print() const;
};

class CHAR : public NODE
{
	char ch;
public:
	CHAR(char c=0): ch(c)
	{}
	void print() const;
};
class DOUBLE : public NODE
{
	double i;
public:
	DOUBLE(double ii=0): i(ii)
	{}
	void print() const;
};

class STRING : public NODE
{
	char *p;
public:
	STRING(char *p) ;
	STRING()
	{
		p = 0;
	}
	~STRING()
	{	
		if(p!=0) delete[] p;	
	}
	void print() const;
};

#endif