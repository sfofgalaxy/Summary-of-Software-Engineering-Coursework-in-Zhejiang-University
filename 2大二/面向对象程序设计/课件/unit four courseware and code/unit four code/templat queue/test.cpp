#include <iostream>
using namespace std;
#include "GenericQueue.h"

int main()
{	
	QUEUE<double> q(5);
    std::cout << q.empty() << std::endl;
	std::cout << q.size() << std::endl;
    q.enQueue(1.3);
    q.enQueue(2.3);
    q.enQueue(3.3);
    q.enQueue(4.3);
    std::cout << q.full() << std::endl;
	std::cout << q.size() << std::endl;

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.enQueue(5.3);
    q.enQueue(6.3);
    q.enQueue(7.3);
    std::cout << q.full() << std::endl;
	std::cout << q.size() << std::endl;

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    std::cout << q.empty() << std::endl;

	return 0;
}