// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
class TYPE;
class Queue
{
private:
	enum {Q_SIZE = 10};
	TYPE *front; // pointer to front of Queue
	TYPE *rear; // pointer to rear of Queue
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
	int queuecount() const;
	bool enqueue( TYPE *item); // add item to end
	TYPE* dequeue(); // remove item from front
	void print() const;
};
#endif