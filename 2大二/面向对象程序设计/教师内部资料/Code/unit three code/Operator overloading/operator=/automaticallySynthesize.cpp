#include <iostream>
using namespace std;
#include <memory.h>
class A
{
	int i;
	const int d;
	A(const A&);
public:
	A():i(0),d(0)
	{}
	void f(A a)
	{
	}
	int g()
	{
		A a;
		f(a);
		return 1;
	}
};
int main()
{
	A m, n;  
	m = n;
	//but A k(m);
//	m.g();
	system("pause");
	return 0;
}
