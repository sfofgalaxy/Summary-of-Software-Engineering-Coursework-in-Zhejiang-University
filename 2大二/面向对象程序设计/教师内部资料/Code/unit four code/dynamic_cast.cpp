#include <iostream>
using namespace std;
  
class CBasic 
{ 
public: 
	virtual ~CBasic(){}  // must be virtual 
}; 
  
class CDerived : public CBasic 
{  
}; 
  
int main() 
{ 
	try{
		CBasic b; 
		CDerived d; 
      
		CBasic * pB1 = &b; 
		CBasic * pB2 = &d;  //upcasting
  
		//dynamic cast failed, so pD1 is null. 
		CDerived * pD1 = dynamic_cast<CDerived * > (pB1);    
                  
		//dynamic cast succeeded, so pD2 points to d object                                         
		CDerived * pD2 = dynamic_cast<CDerived * > (pB2);    
      
		//dynamci cast failed, so throw an exception.             
		CDerived & rD1 = dynamic_cast<CDerived &> (*pB1);    
  
		//dynamic cast succeeded, so rD2 references to CDerived object. 
		CDerived & rD2 = dynamic_cast<CDerived &> (*pB2);    
	}
	catch(std::bad_cast)
	{
		cout << "dynamci cast failed!!!!" << endl;
	}
//	catch(...)
//	{
//		cout << "dynamci cast failed!" << endl;
//	}
	return 0; 
} 

