class B{};
class MyObject{
	int i;
	static int j;
	const int k;
	B b;
public:
	MyObject():k(0),b()//b()可省略
	{
		i = 0;
	}

    MyObject(int ii,int jj);

	MyObject(const MyObject&);

	void g(MyObject& m) const
	{
//		i = 0;  //complie-time error
//		f(m);    //complie-time error
		m.f(m);  //ok
	}
	void f(const MyObject& m)
	{
		m.g(m);  //ok
        i = 0;
		g(m);
	}
	
	const MyObject operator+(const MyObject&) const;
	
    static int get_j();//不能加const

	friend const MyObject operator+(const MyObject&,const MyObject&); //不能加const

//	friend istream& operator>>(istream&,MyObject&);

//	friend ostream& operator<<(ostream&,const MyObject&);


};
