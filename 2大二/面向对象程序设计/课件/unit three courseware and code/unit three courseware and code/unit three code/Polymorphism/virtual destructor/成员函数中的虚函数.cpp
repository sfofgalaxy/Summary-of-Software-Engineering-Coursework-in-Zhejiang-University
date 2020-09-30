#include <iostream>
using namespace std;

class BASE
{
public:
	BASE(int mm=0) : m(mm)
	{
		cout << "BASE()\n" ;
	}
	virtual ~BASE()
	{
		cout << "~BASE()\n" ;
	}
	void F1()  
	{
		F2(); //this->F2(); dynamic binding
		cout << "BASE::F1()\n" ;
	}
	virtual void F2()
	{
		cout << "BASE::F2()\n" ;
	}
private:
	int m;
};

class DERIVE : public BASE
{
public:
	DERIVE():BASE()
	{
		cout << "DERIVE()\n" ;
	}
	virtual ~DERIVE()
	{
		cout << "~DERIVE()\n" ;
	}
	virtual void F2()
	{
		cout << "DERIVE::F2()\n" ;
	}
};

int main()
{
	BASE d;
	d.F1();   //static binding
	d.F2();   //static binding
    DERIVE e;
    e.F1();   //BASE::F1()-->DERIVE::F2()
	BASE* pb = new DERIVE;
	pb->F2();  //dynamic binding
	pb->F1(); //BASE::F1()-->DERIVE::F2()
	delete pb;
	return 0;
}








