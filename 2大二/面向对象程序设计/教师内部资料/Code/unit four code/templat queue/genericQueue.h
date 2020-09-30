#ifndef QUEUE_H
#define QUEUE_H

//例：队列模板类的定义GenericQUEUE.h

template<typename T>
class QUEUE {
private:
    int capacity;         // capacity of the QUEUE
    T *data;              // dynamically allocated array of doubles
    int front;            // head of the QUEUE
    int rear;             // tail of the QUEUE
public:
    QUEUE(int maxsize);
    ~QUEUE();
    bool empty();
    bool full();
    void enQueue(T a);     	// append a double value to the tail of QUEUE
    T deQueue();		    // delete the head element of the QUEUE
	int size() const;
};

template<typename T> QUEUE<T>::QUEUE(int maxsize)
{
    capacity = maxsize;
    data = new T[capacity];
    front = rear = 0;
    std::cout << "QUEUE initialized" << std::endl;
}
template<typename T> QUEUE<T>::~QUEUE()
{
    delete[] data;
    std::cout << "QUEUE destroyed" << std::endl;
}
template<typename T> bool QUEUE<T>::empty()
{
    return front == rear;
}
template<typename T> bool QUEUE<T>::full()
{
    return front == ((rear + 1) % capacity);
}

//The dynamic array data will be a circular QUEUE
template<typename T> void QUEUE<T>::enQueue(T a)
{
  if(full())
  {
     std::cerr << "\nThe QUEUE is full!" << std::endl;
     exit(0);
  }
  else
  {
     data[rear] = a;
     rear = ((rear + 1) % capacity);
  }
}

template<typename T> T QUEUE<T>::deQueue()
{
  if(empty())
  {
     std::cerr << "\nThe QUEUE is empty!" << std::endl;
     exit(0);
  }
  T top = data[front];
  front = ((front + 1) % capacity);
  return top;
}

template<typename T> int QUEUE<T>::size() const
{
	return (rear-front+capacity)%capacity;
}

#endif
