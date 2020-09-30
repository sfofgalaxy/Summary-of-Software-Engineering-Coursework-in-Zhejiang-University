//: C13:Framis.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Local overloaded new & delete
#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>
using namespace std;

class Framis {
  enum { sz = 10 };
  char c[sz]; // To take up space, not used
  static unsigned char pool[];
  static bool alloc_map[];
public:	   
	enum { psize = 100 };  // frami allowed
	Framis() 
	{ 
		  cout << "Framis()\n"; 
	}
	~Framis() 
	{ 
		cout << "~Framis() ... "; 
	}
	void* operator new(size_t) throw(bad_alloc);
	void operator delete(void*);
};

unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

// Size is ignored -- assume a Framis object
void*  Framis::operator new(size_t) throw(bad_alloc) 
{
  for(int i = 0; i < psize; i++)
    if(!alloc_map[i]) {
      cout << "using block " << i << " ... ";
      alloc_map[i] = true; // Mark it used
      return pool + (i * sizeof(Framis));
    }
  cout << "out of memory" << endl;
  throw bad_alloc();
}

void Framis::operator delete(void* m) 
{
  if(!m) return; // Check for null pointer
  // Assume it was created in the pool
  // Calculate which block number it is:
  unsigned long block = (unsigned long)m
    - (unsigned long)pool;
  block /= sizeof(Framis);
  cout << "freeing block " << block << endl;
  // Mark it free:
  alloc_map[block] = false;
}

void main() 
{
  Framis* f[Framis::psize];
  try {
    for(int i = 0; i < Framis::psize; i++)
      f[i] = new Framis;
    new Framis; // Out of memory
  } catch(bad_alloc) {
    cout << "Out of memory!" << endl;
  }
  delete f[10];
  f[10] = 0;
  // Use released memory:
  Framis* x = new Framis;
  delete x;
  for(int j = 0; j < Framis::psize; j++)
    delete f[j]; // Delete f[10] OK
} ///:~
