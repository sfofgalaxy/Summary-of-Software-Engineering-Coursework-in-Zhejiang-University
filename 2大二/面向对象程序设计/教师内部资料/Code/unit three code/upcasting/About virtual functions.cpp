
//�麯����ʹ��
#include <iostream>
using namespace std;

class parent{
public: 
		virtual void f(int a=10)
		{	
			cout<<"Here is parent "<<a<<endl;
		}
		void g()
		{	cout << "Here is void parent::g()" << endl;
		}
};
class child:public parent{
public:
	virtual void f(int a=20);
};

void child::f(int a)
{	
	cout<<"Here is child "<<a<<endl;
}

 void g( parent* p)
 {
	 p->f(3);
 }

int main()
{	
	parent father,*pointer;
	child son;

	pointer = &father;
	pointer -> f();//dynamic binding������parent::f(int)
	pointer = &son; //upcasting
	pointer -> f();//dynamic binding������child::f(int)
	/*���ǣ�����pointer�ľ�̬������parent*������������õ�ȱʡ����ֵ�Ǵ�parent����ȡ�õģ�������child�࣡*/

	parent& p = father;//dynamic binding������parent::f(int)
	p.f(2);
	parent& q = son;//���������������������
	q.f(3);	      //dynamic binding ����child::f(int)
   
	son.f(2);//static binding	or early binding ����child::f(int)
	return 0;
}


/*
#include <iostream>
using namespace std;
class parent{
public: 
	virtual void f(int a)
	{	
		cout<<"Here is parent "<<a<<endl;
	}
};
class child:public parent{
public:
	
	virtual int  f(float a)  //�����ͬ�������������治һ��
	{	
		cout<<"Here is child "<<a<<endl;
		return 0;
	}
//	virtual int f(int a)//���������������ͬ��������ֻ�Ƿ������Ͳ�һ������������Ϊ���ж����ԡ�
//   {return 0;}
};

virtual�������ã�child::f(float)��parent::f(int)�����غ�����ʹ�û���ָ�벻�ܽ��ж�̬����
ʹ��ʱע�⣺Name Hiding


int main()
{
	parent father,*pointer;
	child son;
	pointer = &father;
	pointer ->f(0); //��̬binding  ����parent::f(int)

	pointer = &son; //upcasting
	pointer ->f(1.0); //ʹ������ת��int(1.0),�ٵ���parent::f(int)
    

	child *pointer1 = &son;
	pointer1->f(1.0); // ����child::f(1.0)
	pointer1->f(1);// ����child::f( float(1) )  name hiding��������
	pointer1->parent::f(1);
	
	son.f(1.0);  //����child::f(1.0)
	son.f(1);  //����child::f( float(1) )  ��������
	
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
class parent{
public: 
	virtual void f(int a)
	{	
		cout<<"Here is parent "<<a<<endl;
	}
};
class child:public parent{
public:
	virtual int f(int a)//���������������ͬ��������ֻ�Ƿ������Ͳ�һ������������Ϊ���ж����ԡ�
   {
	   return 0;
	}
};

int main()
{
	return 0;
}
*/