class intstack: private intlist{
public: 
	void push(int a)
    {  	
		insert(a);	//������ͷ
	}
	int pop()
	{  
		return get(); //ȡ����ͷ����
	}  
	void print()  //����
	{
		intlist::print();
	}
};
/*
����intstack������û���κο�����˽�м̳���intlist�Ĵ���
intstack c;
c.push(1);
c.pop();
*/


