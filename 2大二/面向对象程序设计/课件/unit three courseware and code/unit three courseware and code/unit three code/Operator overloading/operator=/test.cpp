#include "Array.h"
#include <iostream>
using namespace std;
#include <memory.h>

class AA{
	const int i;
	int k;
public:

};

int main()
{
   Array a(12), c;  
   /*AA m;  compile-time error:没有合适的默认构造函数可用*/
   a.print();
   for ( int i = 0; i < 12; i++ )
	    a[i] = i;    // a.operator[](i) = i;
   a.print();

   //c = a;
   const Array b(5);
   //b.print();    //compile time error
   
   for(int i=0; i<5; i++)
       cout << b[i] << ' '; //  b.operator[](i)
    
   Array bb(a);  //call Array(const A&);
   cout << "-----------------------" << endl;
   bb.print();
   a.print();
    
   system("pause");
   return 0;
}