#include <iostream>
using namespace std;

struct example{
	int a;
	double b;
	//example(int a=0,double b=0.0):a(a),b(b){}
}ex,*pe;

void main()
{

//���ڶ��������ת��:C��������ת�����ڴ�³,�ڳ������������ʶ��, 
//��������Ϊ������Ϊ����C���Ե��ڲ����ơ�
   char ch;
   int i = 65;
   float f = float(2.5);  //explicit type conversion ����ת��
   double db ;
 
   ch = i;//����ת��  implicit type conversion 
   db = f;//����ת��
   ch = char(db); //explicit type conversion ����ת��
 
//C++���ᳫ��д����Ŀ��������������ת�������Ƕ��˹����ǶԳ��򶼺�����ʶ��
 
   ch = static_cast<char>(i);         // int to char
   db = static_cast<double>(f);         // float to double
   f = static_cast<float>(db);          //double to float
   ch = static_cast<char>(db);

   //int *pi = (int*)i;
   //int *pi = static_cast<int*>(i);//compile-time error����ΪC�в�������������ʽת��
    
	//enum E { first=1, second=2, third=3 };
	//int ii = second; // ��ʽת��
	//E e = ii;
	//ii = 4;
	//E e = static_cast<E>(ii); // ������ʽת�� value of e is second
	
    //reinterpret_cast
	//int *pi = (int*)i;
    //int *pi = reinterpret_cast<int*>(i);
    //int j = reinterpret_cast<int>(pi);
	
	//ex = i; //error! example��int������,�����ṩ��Ӧ�Ĺ��캯��
   //ex = example(i);//���������Ͷ���ǿ��ת��Ҳ����
  

//���ڶ���ָ�������ת��
/*
	int in = 3;
	int* p_int;
	double du = 3.3;
	double* p_double;
	example* pe;

	p_double = &du;
	p_int = &in;
*/
//	p_int = p_double; //�������ָ�����Ͳ�һ����ָ�벻������ת��
//	p_double = p_int;
 //   p_int = pe;
//��pe = p_int;
/* C Style
	p_int = (int*)p_double;
	pe = (example*)p_int;//�κ����͵�ָ��֮�䶼�����໥ǿ������ת��,����ͨ�� 
	pe->a; //����ͨ��������pe�ľ�̬����ȥ����
	pe->b; //�ڴ����
	cout<<"int="<<sizeof(int)<<"	double="<<sizeof(double)<<"		example="<<sizeof(example)<<endl;
	cout<<pe->a<<endl;
	cout<<pe->b<<endl;
*/
/*C++ Style
    pe = static_cast<example*>(p_int); //�������
    p_int = static_cast<int*>(pe);
	int *q1 = new int(1);
	double* q2 = new double(1.1);
	q2 = static_cast<int*>(q1);
*/
}
