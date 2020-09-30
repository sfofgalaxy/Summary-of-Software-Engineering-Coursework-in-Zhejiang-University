#include <iostream>
using namespace std;

static int oneData = 0;
void increase()  {  ++oneData; }
void decrease() {  --oneData; }
class A{
private:  int oneData;
public:
     A() {  
        oneData = 0; increase();
        cout << oneData << '\t' << ::oneData << endl;
    }
    A(int value) {
        oneData = value;
        for (int i=0; i<value; i++)
            increase(); 
        cout << oneData << '\t' << ::oneData << endl;
    }
    ~A() { decrease(); }
};
void main()
{  
    void f();
    f();      
    f();
}
void f()
{
    A m1, m2(2);
    static A n1, n2(2);
}
