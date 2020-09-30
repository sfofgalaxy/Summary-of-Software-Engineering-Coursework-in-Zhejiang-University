#include "iostream"
#include <memory.h>
#include <process.h>
using namespace std;

class array{  
public:  
	array(int size1=10):size(size1),p(new int[size1])
	{ 
		memset(p, 0, size*sizeof(int));
		cout << "I am in array(int size1)." << endl;
	}
	~array() 
	{  
		delete[] p;  
		cout << "I am in ~array()." << endl;
	}
	int& operator[](int i) 	
	{   
		if(i<0 || i>=size) 
		{
		   cout<<"�±�Խ�磡"<<endl;
		   exit(1);  
		}
		return p[i];
	}
	int operator[](int i) const	
	{   
		if(i<0 || i>=size) 
		{
		   cout<<"�±�Խ�磡"<<endl;
		   exit(1);  
		}
		return p[i];
	}
	int getsize() const
	{
		return size;
	}
	
	array& operator=(const array& rhs) 	
	{
	    if (this == &rhs) return *this;  //�������Ҹ�ֵ����
		delete[] p;
		size = rhs.size;
		p = new int[size*sizeof(int)];
		memcpy(p, rhs.p, size*sizeof(int));
		return *this;
	}
	//w = w; ��ֻ��Ч�ʵ�����
	
	friend istream& operator>>(istream& in,array& ob);	//int_array a(10); cin>>a;��Ϊ��һ��������cin�������س���Ա����
	friend ostream& operator<<(ostream& out,const array& ob);
private:  
	int * p;
    int size;
	array(const array&);
	//array& operator=(const array&);
};

istream& operator>>(istream& in, array& ob)
{
   for(int i=0; i<ob.getsize(); i++)
	   in >> ob[i];

   return in;   //Ϊ����cin>>ob1>>ob2;������in����
}

ostream& operator<<(ostream& out, const array& ob)
{
	for (int i=0; i<ob.getsize(); i++)
		out << ob[i] << ","; //because ob is a const,so ob.operator[](i) must be const function

	out << endl;
	return out;
}

class A{
private:
	const int i;
public:
	A(int i = 0):i(i)
	{}
};
void fun()
{
	A a(1), b;
	A c(a);
	//b = a;
}
void main()
{
	array a(10),c;
 	for(int i=0;i < a.getsize();i++)
		a[i] = i;	 

	cout << a << endl;
	c = a;  //bitcopy
	cout << c << endl;
	system("pause");
 }

/*
array& Array::operator=(const array& rhs) 	
{
   size = rhs.size;
   p = rhs.p;
   return *this;
}
*/