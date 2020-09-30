class counter{
private: 
	int second;   //60秒计时器
public: 
	counter():second(0){}
    counter& operator++();  //prefix
    int operator++(int);	//postfix
	counter& operator--();  //prefix
    int operator--(int);	//postfix
	void reset()
	{
		second = 0;
	}
    operator int() const  //类类型转换函数,隐含调用
	{
		return second;
	}	
};
