#include <iostream>
using namespace std;
#include <memory.h>

class Array{
public:  
	Array(int size = 10) : size( size ), p(new int[size])  
	{
		memset(p, 0, size * sizeof ( int ) );
	}
    ~Array()
	{
		delete[] p;
	}
	
	void print()  const    // const function member
	{
		for ( int i = 0; i < size; i++ )
		      cout << p[i] << "\t";
	    cout << endl;
	}

	int& operator[]( const unsigned i ) 
	{
		if( i >= size || i < 0)
		{
			cout << "suffix is beyond the mark." << endl;
			exit(0);
		}
		else
			return p[i];   
	}
    int operator[](const unsigned i) const
	{
		if( i >= size || i < 0)
		{
			cout << "suffix is beyond the mark." << endl;
			exit(0);
		}
		else
		{
			return p[i]; // *(p+i);
		}
	}
	/*
    //bitcopy
	Array(const Array& com): size(com.size),p(com.p)
	{
	}*/
	/*
	Array(const Array& com):size(com.size),p(new int[com.size])  //调试时发生的问题p(new int[size])
	{
		memcpy(p, com.p, size*sizeof(int));
	}
	*/
	/*
	Array& operator=(const Array& right)
	{
		if (this == &right || size!=right.size)
			return *this;

		memcpy(p, right.p, size*sizeof(int));
	}*/
	
private:
	int* const p;    
	const int size;  
    //Array(const Array&);
	//Array& operator=(const Array&);
};

int main()
{
   Array a(10);
   a.print();
    
   for ( int i = 0; i < 10; i++ )
	    a[i] = i;  ///a.operator[](i)
    
   a.print(); 
   
   /*
   char *p = (char*)malloc(100);
   free(p);
   free(p);
   */
   
   Array bb(a);  //call Array(const A&);
   cout << "-----------------------" << endl;
   bb.print();
   
   system("pause");
   return 0;
}
