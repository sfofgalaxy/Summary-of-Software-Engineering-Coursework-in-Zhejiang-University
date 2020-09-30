/* Create an integer array class  with two data members:
1)const pointer  p that points to the beginning of the array;            
  const int size  that indicates the size of the array.
2)when accessing the array , The compiler can perform subscript bounds checking��
*/

#ifndef _ARRAY_H
#define _ARRAY_H

class Array{
public:  
	Array(int size = 10);
    ~Array();
    /*void print() ;*/
	void print() const;   // const function member 
	int get_size() const;	
	int& operator[]( const unsigned i );
    int operator[](const unsigned i) const;
	
	/* bitcopy
	Array::Array(const Array& com):size(com.size),p(com.p)
	{
	}*/
    /*
	Array(const Array& com):size(com.size),p(new int[com.size])  //����ʱ����������p(new int[size])
	{
		memcpy(p, com.p, size*sizeof(int));
	}*/
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
	    if (this == &rhs) return *this;  //�������Ҹ�ֵ����
		delete[] p;
		size = rhs.size;
		p = new int[size*sizeof(int)];
		::memcpy(p, rhs.p, size*sizeof(int));
		return *this;
	}*/
	//w = w; ��ֻ��Ч�ʵ�����
	
private:
    int* const p;    //ָ�볣��
	const int size;
    //Array(const Array&);
	//Array& operator=(const Array&);
};

#endif