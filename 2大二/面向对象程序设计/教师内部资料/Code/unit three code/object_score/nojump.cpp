#include <iostream>;
using namespace std;

class test  {   
private:   int num;      
public:   test( );     
          int get( )  {return num;}    
          void set(int num )  { this->num = num;}   
          ~test( );   
};    
test::test( )   
{    cout << "Initalizing default" << endl;    num = 0; } 
test::~test( )  
{    cout << "Desdtructor is active" << endl;  }    

void main( )  
 {  
	  for (int i = 0; i<2; i++){
         test m; 
		 static test n;
		 m.set(m.get()+1); 
		 n.set(n.get()+1);
		 cout << m.get() << " " 
              << n.get() << endl;      
     }
 } 
