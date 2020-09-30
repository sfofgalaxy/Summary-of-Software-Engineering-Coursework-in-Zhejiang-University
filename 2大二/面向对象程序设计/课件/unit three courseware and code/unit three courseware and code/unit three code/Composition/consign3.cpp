class Laundry{
private:
public: 
	void CommonWashing(){}
	void SpecialWashing(){}
};


class Hotel{
public: 
	Hotel()
	{
		delegate = new Laundry;
	} 
	Laundry* operator->()		//递引用运算符重载
	{		
		return delegate;		
	}
private: 
	Laundry *delegate;
};

void main()
{
	Hotel 浙大启真大酒店;
	浙大启真大酒店->SpecialWashing(); 
	<==>   (delegate)->SpecialWashing();
}

//⑴通过重载-〉，减少了在客户类client中复写接口的麻烦，并且当服务器类server的接口发生变化时，客户类client不受影响。
//例如，服务器类server中增加一个接口void e();客户类client对象c，就可直接使用：c->e()。
//⑵以上例子通过重载"->"，来实现转送技术或委托功能。当然，也可以对其它运算符重载来实现这一功能（比如[]），
//只不过，"->"更直观，因为"·"不能重载。


两个类之间的关系：
1)has-a关系(有一个)
2)is-implemented-in-terms-of(根据某物实现出)
class Head{
private:
        Eye  eye[2];  
		Mouth m;  
		Ear ear[2];  
		Nose n;
};
	           