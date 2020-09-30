#ifndef MYCLASS_H
#define MYCLASS_H

//class B; //前置声明
class B{};
class MyObject{
	int i;
	static int j;
	const int k;
	B b;
public:
	MyObject():k(0),b()//b()可省略
	{i=0;}

    MyObject(int ii,int jj);

	MyObject(const MyObject&);

	void g(MyObject& m) const
	{
//		i = 0;  //complie-time error
//		m.f(m);    //complie-time error
	}
	/*
	void f(const MyObject& n)
	{
		n.g(n);  //ok
        i = 0;
		g(n);
	}*/
	
	const MyObject operator+(const MyObject&) const;
	
    static int get_j();//不能是const static member function

	friend const MyObject operator+(const MyObject&,const MyObject&); //不能是const global function

//	friend istream& operator>>(istream&,MyObject&);

//	friend ostream& operator<<(ostream&,const MyObject&);


};

#endif
