//: C12:AutomaticTypeConversion.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Type conversion constructor


//���캯������ת��
class One {
public:	
	One() {}
	friend class Two;
};

class Two {
public:
	Two(){}
	Two(double d){}     //automatic type conversion double->Two  explicit
    Two(const One&) {}  //automatic type conversio One->Two
};

/*
Two c(2.3);  //double->Two
One a;
Two b(a);  //One->Two
*/
void f(Two) {}

void main() {
  One one;
  f(one); // Wants a Two, has a One
  f(1.1);
/*When the compiler sees f( ) called with a One object, it looks at 
  the declaration for f( ) and notices it wants a Two.
  Then it looks to see if there��s any way to get a Two from a One, 
  and it finds the constructor Two::Two(One),which it quietly calls.
  The resulting Two object is handed to f(Two(one));*/
} 
//ͨ�����캯���Զ�����ת���������˶�������f()���ذ汾���鷳��Ȼ�������������˹��캯���ĵ��� .
//������ǿ���׷��f()�����ĵ���Ч�ʣ���Ӧ�ñ��⡣


/*
//��ֹ���캯����������ת��
class One {
public:	
	One() {}
};

class Two {
public:
	Two(){}
    explicit Two(const One&) {} 
    //Preventing constructor conversion:There are times when automatic type conversion 
    //via the constructor can cause problems. To turn it off, 
};

void f(Two) {}

void main() {
  One one;
  //f(one); //error,no auto conversion allowed.
  f(Two(one)); 
}

*/
