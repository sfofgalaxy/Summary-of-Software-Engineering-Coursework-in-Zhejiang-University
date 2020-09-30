#include <iostream>
using namespace std;
#include "GenericSTACK.h"

void main()
{	
	try{
		STACK<int> s(10);
		s.push(1);
		s.push(2);
		s.push(3);
		for (int i = 0; i < 10; i++)
			s.push(i);    
		int a=s.pop();
		int b=s.pop();
		int c=s.pop();

		cout<<s.getsize()<<"  "<<a<<b<<c<<endl;
	}
	catch(STACK<int>::Range& m)  //STACK<int>::Range m;
    {
		if (1==m.get())
		   cout<<"overflow£¡"<<endl;
		else if (2==m.get())
			cout << "underflow£¡" << endl;
		//
 		//char k = getchar();
    }	
	catch(...)
	{
		//...
	}
	getchar();
}