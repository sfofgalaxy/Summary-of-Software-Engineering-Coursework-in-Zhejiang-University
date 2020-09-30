// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
class NODE;
class Queue
{
private:
	enum {Q_SIZE = 10};
	NODE *front; // pointer to front of Queue
	NODE *rear; // pointer to rear of Queue
	int items; // current number of items in Queue
	const int qsize; // maximum number of items in Queue
	// preemptive definitions to prevent public copying
	Queue(const Queue & q) : qsize(0) { }
	Queue & operator=(const Queue & q) { return *this;}
public:
	Queue(int qs = Q_SIZE); // create queue with a qs limit
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int count() const;
	bool enqueue( NODE *item); // add item to end
	NODE* dequeue(); // remove item from front
	void print() const;
};
#endif