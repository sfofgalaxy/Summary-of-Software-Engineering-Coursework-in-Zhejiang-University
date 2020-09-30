#ifndef BASETYPE_H_
#define BASETYPE_H_

class iostream;

class TYPE  
{
	TYPE *m_next;
public:
	TYPE(): m_next(0) 
	{} 
	void linkTo(TYPE *p);
	TYPE*& next();
	virtual ~TYPE(){}
	virtual void print() const = 0;
};

class INT : public TYPE
{
	int i;
public:
	INT(int ii=0): i(ii)
	{}
	void print() const;
};

class CHAR : public TYPE
{
	char ch;
public:
	CHAR(char c=0): ch(c)
	{}
	void print() const;
};
class DOUBLE : public TYPE
{
	double i;
public:
	DOUBLE(double ii=0): i(ii)
	{}
	void print() const;
};

class STRING : public TYPE
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