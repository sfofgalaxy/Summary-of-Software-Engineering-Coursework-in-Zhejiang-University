class counter{
private: 
	int second;   //60���ʱ��
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
    operator int() const  //������ת������,��������
	{
		return second;
	}	
};
