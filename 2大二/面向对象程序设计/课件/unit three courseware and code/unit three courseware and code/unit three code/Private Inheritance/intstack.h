class intstack: private intlist{
public: 
	void push(int a)
    {  	
		insert(a);	//插在链头
	}
	int pop()
	{  
		return get(); //取出链头数据
	}  
	void print()  //遍历
	{
		intlist::print();
	}
};
/*
创建intstack，几乎没有任何开销，私有继承了intlist的代码
intstack c;
c.push(1);
c.pop();
*/


