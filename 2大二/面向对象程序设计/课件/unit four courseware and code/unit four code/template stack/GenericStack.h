#ifndef STACK_H
#define STACK_H

//例：堆栈模板类的定义STACK.h

template <typename T> 
class STACK{   
private:  
	T *v;	//用T类型指针v表示栈底
	T *p;	//栈顶指示器
    const int size;	//栈体大小
public:
	STACK(int z=100); 
	void push(T a);
	T pop();
	T top() const;
	int getsize() const;
	~STACK()
	{
		delete[] v;
	}
	friend ostream& operator<< <>(ostream &out, STACK<T> & ob);
};

/*inline函数的定义放在源文件的头文件中
模板类的定义与模板类成员函数的定义都放在头文件中*/
template <typename T>
STACK<T>::STACK(int z):size(z)
{	
	p = v = new T[size];
}

template <typename T>
void STACK<T>::push(T ch)
{      
	if (p - v >= size)
    {   
		cout << "overflow!" << endl;
        exit(1);      
	}
    else
        *p++ = ch;
}


template <typename T>			  
 T STACK<T>::pop()
{     
	if (p == v)
    {	
		cout << "underflow!" << endl;
		exit(1);
	}
    else
        return *--p;
}

template <typename T>
T STACK<T>::top() const
{
	if (p == v)
    {	
		cout << "underflow!" << endl;
		exit(1);
	}
    else
        return *(p - 1);
}

template <typename T>
int STACK<T>::getsize() const
{
	return size;
}


template <typename T>
ostream& operator<< <>(ostream &out, STACK<T> &ob)
{
	while(ob.p>ob.v){
		ob.p--;
		out << *ob.p << '\t';
	}
    return out;
};

#endif