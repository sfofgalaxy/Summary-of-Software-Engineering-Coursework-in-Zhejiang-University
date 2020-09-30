#include <iostream>
#include <cstdlib>
using namespace std;

#include "node.h"
#include "queue.h"

int main()
{
	Queue m;
	m.enqueue(new INT(5));
	m.enqueue(new CHAR('T'));
	m.enqueue(new DOUBLE(33.2));
	m.enqueue(new STRING("hello"));
    m.print();
	return 0;
}
