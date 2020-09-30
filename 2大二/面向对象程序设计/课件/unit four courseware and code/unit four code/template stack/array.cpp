#include "iostream"
#include <memory.h>
#include <process.h>
using namespace std;

template <typename T>
class array{  
public:  
	array(int size1=10):size(size1),p(new T[size1])
	{ 
		memset(p, 0, size*sizeof(T));
		cout << "I am in array(int size1)." << endl;
	}
	~array() 
	{  
		delete[] p;  
		cout << "I am in ~array()." << endl;
	}
	T& operator[](int i) 	
	{   
		if(i<0 || i>=size) 
		{
		   cout<<"下标越界！"<<endl;
		   exit(1);  
		}
		return p[i];
	}
	T operator[](int i) const	
	{   
		if(i<0 || i>=size) 
		{
		   cout<<"下标越界！"<<endl;
		   exit(1);  
		}
		return p[i];
	}
	int getsize() const
	{
		return size;
	}
	friend istream& operator>>(istream& in,array<T>& ob);	
	friend ostream& operator<<(ostream& out,const array<T>& ob);
private:  
	T *p;
    int size;
	array(const array&);
	array& operator=(const array&);
};

istream& operator>>(istream& in, array<int>& ob)
{
   for(int i=0; i<ob.getsize(); i++)
	   in >> ob[i];

   return in;   
}

istream& operator>>(istream& in, array<double>& ob)
{
   for(int i=0; i<ob.getsize(); i++)
	   in >> ob[i];

   return in;   
}

ostream& operator<<(ostream& out, const array<int>& ob)
{
	for (int i=0; i<ob.getsize(); i++)
		out << ob[i] << ","; 

	out << endl;
	return out;
}

void main()
{
	array<int> a(10),c;
 	for(int i=0;i < a.getsize();i++)
		a[i] = i;	 

	cout << a << endl;
	cout << c << endl;
	system("pause");
 }