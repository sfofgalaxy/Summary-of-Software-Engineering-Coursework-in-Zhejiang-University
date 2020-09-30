/* Create an integer array class  with two data members:
1)const pointer  p that points to the beginning of the array;            
  const int size  that indicates the size of the array.
2)when accessing the array , The compiler can perform subscript bounds checking。
*/

#ifndef _ARRAY_H
#define _ARRAY_H

class Array{
public:  
	Array(int size = 10);
    ~Array();
   	int getSize() const;	
	void print();
	//void print() const;
	int& operator[]( const unsigned i );
    int operator[](const unsigned i) const;

	/*bitcopy*/
	/*
    Array& Array::operator=(const Array& rhs):size(rhs.size),p(rhs.p) 	
    {
        return *this;
    }
   */
    /*
	Array& operator=(const Array& rhs) 	
	{
	    if (this == &rhs) return *this;  //进行自我赋值处理
		delete[] p;
		size = rhs.size;
		p = new int[size*sizeof(int)];
		::memcpy(p, rhs.p, size*sizeof(int));
		return *this;
	}*/
	//w = w; 不只是效率的问题
	friend istream& operator>>(istream& in,Array& ob);	
	friend ostream& operator<<(ostream& out,const Array& ob);

private:
    int* const p;    //constant pointer
	const int size;
    //Array(const Array&);
	//Array& operator=(const Array&);
};

#endif