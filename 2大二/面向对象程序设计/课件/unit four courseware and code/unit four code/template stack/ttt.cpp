#include<iostream>
using namespace std;
template <typename T>
class Test
{
private:
   T num;
public:
   Test( T n)
   {
       num=n;
   }
   T get() const
   {
	   return num;
   }
   friend ostream& operator<< <>(ostream &out,const Test<T> &);
};

template <typename T>
ostream& operator<< <>(ostream &out,const Test<T> &obj)
{
    //out<<obj.num;
	out << obj.get();
    return out;
}


int main()
{
 Test<int> t(414);
 cout<<t;
 return 0;
}


