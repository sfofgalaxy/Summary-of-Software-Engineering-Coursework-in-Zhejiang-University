#ifndef STACK_H
#define STACK_H

//������ջģ����Ķ���STACK.h

template <typename T> 
class STACK{   
private:  
	T *v;	//��T����ָ��v��ʾջ��
	T *p;	//ջ��ָʾ��
    const int size;	//ջ���С
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

/*inline�����Ķ������Դ�ļ���ͷ�ļ���
ģ����Ķ�����ģ�����Ա�����Ķ��嶼����ͷ�ļ���*/
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