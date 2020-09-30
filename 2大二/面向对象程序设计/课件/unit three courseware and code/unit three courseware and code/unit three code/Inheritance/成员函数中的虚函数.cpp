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
		BASE::F2();
		F2(); //this->F2();
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
	d.F1();
	d.F2();
    DERIVE e;
    e.F1();
	BASE* pb = new DERIVE;
	pb->F2();
	pb->F1();
	delete pb;
	return 0;
}








