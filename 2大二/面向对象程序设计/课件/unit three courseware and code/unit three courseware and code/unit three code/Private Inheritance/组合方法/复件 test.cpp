#include "intlist.h"
#include "intstack.h"
#include <iostream.h>

void main()
{
	intstack b;
	b.push(1);
	b.push(2);
	b.push(3);
	cout<<b.pop()<<endl;
	cout<<b.pop()<<endl;
	cout<<b.pop()<<endl;
}
