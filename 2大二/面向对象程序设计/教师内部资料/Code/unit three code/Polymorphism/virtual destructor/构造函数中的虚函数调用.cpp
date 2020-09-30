#include <iostream>
using namespace std;

class BASE
{
public:
	BASE( int mm = 1 ) : m(mm)		
	{
		F1();
	}
	virtual void F1()			
	{
		m *= 20;
	}
	virtual void PRINT()	
	{
		cout << "BASE::m=" << m << endl ;
	}
	//virtual ~BASE(){}
private:
	int m;
};

class DERIVE : public BASE
{
public:
	DERIVE() : m(2)		
	{ 	
		F1();
	}
	virtual void F1()			
	{
		m  *= 30 ;
	}
	virtual void PRINT()			
	{  
		//F1();
		cout << "DERIVE::m=" << m << endl ;
	}
private:
	int m;
};

int main()
{//BASE(1) DERIVE()
	BASE* pb = new DERIVE ;			
	pb->PRINT();			
	delete pb;
	return 0;
}


