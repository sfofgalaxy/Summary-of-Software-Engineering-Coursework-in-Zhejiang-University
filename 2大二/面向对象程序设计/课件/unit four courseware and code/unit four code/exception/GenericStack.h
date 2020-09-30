//例：堆栈类模板的定义STACK.h

template <typename T> 
class STACK{   
private:  
	T *v;	//用T类型指针v表示栈底
	T *p;	//栈高指示器
    const int size;	//栈体大小
public:
	inline STACK(int z=100);
	void push(T a);
	inline T pop();
	inline T top() const;
	inline int getsize() const;
	virtual ~STACK()
	{
		delete[] v;
		cout << "call ~STACK()!" << endl;
	}
	/*嵌套类的定义*/
	class Range{
	private:
		int level;
	public:
		Range(int i=0):level(i)
		{
			cout << "构造一个异常对象：Range(int ii)" << endl;
		}
		virtual ~Range()
		{
			cout << "销毁一个异常对象：~Range()" << endl;
		}
		Range(const Range& r)
        {
			level = r.level;
			cout << "复制一个异常对象: Rangle(const Range* r)" << endl;
		}
		int get() const
		{
			return level;
		}
	};  //嵌套类
};


template <typename T>
inline STACK<T>::STACK(int z):size(z)
{	
	p = v = new T[size];
}


template <typename T>
void STACK<T>::push(T ch)
{      
/*
	if (p-v >= size)  
	{
	    cout << "overflow!" << endl;     
		exit(1);
	}
*/
	if (p-v >= size)  //cout<<"overflow!"<<endl;     exit(1); 
    {  
		throw Range(1);//when/where/what The return optimization
		//Range e(1);
		//throw e;	
	}
    else
        *p++ = ch;
}


template <typename T>
inline T STACK<T>::pop()
{     
	if(p == v){
		Range r(2);
		throw r;
	}   	
    else
        return *--p;
}

template <typename T>
inline T STACK<T>::top() const
{
	if(p == v)
        throw Range(2);   
    else
        return *(p-1);
}

template <typename T>
inline int STACK<T>::getsize() const
{
	return size;
}
