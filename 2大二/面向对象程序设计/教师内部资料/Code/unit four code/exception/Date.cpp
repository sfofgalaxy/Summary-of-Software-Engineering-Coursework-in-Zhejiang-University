//û���κκϷ��Լ��
/*
#include <iostream>
using namespace std;

class Date {
public:	
	Date(int nDay, int nMonth, int nYear)
	{
		year = nYear;
		month = nMonth;
		day = nDay;
	}
	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "��" << d.month << "��" << d.day << "��" << endl;
        return out;
	}


private:
	int year;
	int month;
	int day;
};

void main()
{
	Date birthday(20,13,2008);
	cout << birthday;
}*/
/*
//C���÷��������������

#include <iostream>
using namespace std;

class Date {
public:
	Date(int nDay, int nMonth, int nYear)
	{
		if ( nMonth<1 || nMonth>12 ){
			cout << "��ʼ��Date���� �·ݳ���" << endl;
			exit(0);
		}
		//���nYear����
		//���nDay����
		year = nYear;
		month = nMonth;
		day = nDay;
	}
	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "��" << d.month << "��" << d.day << "��" << endl;
        return out;
	}


private:
	int year;
	int month;
	int day;
};

void main()
{
	Date birthday(20,13,2008);
	cout << birthday;
}
*/

//C++���쳣�������
#include <iostream>
using namespace std;
class Date {
public:
	class monthError{};//����

	Date(int nDay, int nMonth, int nYear)
	{
		if (nMonth<1 || nMonth>12)  //when/where/what
			throw monthError();

		//if (dayError){
		//    dayError r;
		//    throw r;
		//}

	    day = nDay;
		month = nMonth;
		year = nYear;
	}

	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "��" << d.month << "��" << d.day << "��" << endl;
        return out;
	} 
private:
	int year;
	int month;
	int day;
};

void main()
{
	try{
       Date d(22, 13 , 2008); 
	   //...
	}
	catch(Date::monthError& e)
	{
   	    cout << "��ʼ��Date�����·ݳ���" << endl;
	}
	//catch(Date::yearError e)
	//catch(Date::yearError& e)
}
//���ź�����d����û�е�����������

/*
//�쳣�����֯����
#include <iostream>
#include <exception>
using namespace std;

class Date {
public:
	class monthError:public exception
	{
	public:
		virtual const char *what( ) const 
		{
			return "monthError";
		}

	};
	class yearError:public exception
	{
	public:
		virtual const char *what( ) const 
		{
			return "yearError";
		}

	};
	class dayError:public exception
	{
	public:
		virtual const char *what( ) const 
		{
			return "dayError";
		}

	};
	Date(int nDay,int nMonth, int nYear)
	{
		if (day <= 0){
		    dayError r;
		    throw r;
		}

		if (nMonth <1 || nMonth>12)  //when/where/what
			throw monthError();
		
		if (nYear <=0)  //when/where/what
			throw yearError();
	
		day = nDay;
		month = nMonth;
		year = nYear;
	}

	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "��" << d.month << "��" << d.day << "��" << endl;
        return out;
	} 
private:
	int year;
	int month;
	int day;
};

void main()
{
	try{
       Date d(-2, 13, 2008); 
	}
//	catch(Date::yearError& e)
//	{
//		cout << "��ʼ��Date���󣬷���" << e.what() << "�쳣!" << endl;
//	}
	catch(exception& e)
	{
		cout << "��ʼ��Date���󣬷���" << e.what() << "�쳣!" << endl;
	}
}
*/

//�ѷ��ִ������ڱ���/���ӽ׶�
/*
#include <iostream>
using namespace std;

class Date {
public:
	//��ô���������ڶ������кϷ��Լ���أ�����Ϸ����·�
	//һ�����Եİ취�ǲ���ö�����Ͷ���������
	enum Month { Jan = 1,Feb = 2,Mar = 3,Apr = 4,May = 5,Jun = 6,Jul=7,Aug = 8,Sep = 9,Oct=10,Nov = 11,Dec = 12 };

	Date(int day, Month month, int year)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "��" << d.month << "��" << d.day << "��" << endl;
        return out;
	}
   

private:
	int year;
	int month;
	int day;
};

void main()
{
	//�ź����ǣ��ⲻ�ỻ�����ٺô�����Ϊö�����Ͳ���Ҫ��ʼ����
	Date::Month m;
    Date d(22, m, 1857); // m �ǲ�ȷ����
	//���ԣ�Date ���캯�����ǵ���֤month ������ֵ��
}
*/

/*�����������ʱ��飬��Ҫ��֤�㹻�İ�ȫ�ԣ�
��͵���һ��������ʾmonth����͵ñ�ֻ֤�кϷ���month �ű�������
*/
/*
#include <iostream>
using namespace std;

class Month {
public:
	static const Month Jan() { return 1; }
	static const Month Feb() { return 2; }
	static const Month Mar() { return 3; }
	static const Month Apr() { return 4; }
	static const Month May() { return 5; }
	static const Month Jun() { return 6; }
	static const Month Jul() { return 7; }
	static const Month Aug() { return 8; }
	static const Month Sep() { return 9; }
	static const Month Oct() { return 10; }
	static const Month Nov() { return 11; }
	static const Month Dec() { return 12; }

	operator int() const // ���Ա�ת��Ϊint
	{ return monthNumber; } 
private:
	Month(int number): monthNumber(number) {}
	const int monthNumber;
};


class Date {
public:
	
	Date(int day, const Month& month, int year)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "��" << d.month << "��" << d.day << "��" << endl;
        return out;
	} 
private:
	int year;
	int month;
	int day;
};

void main()
{
    Month m(Month::Jan());//�ɱ���ʱȷ��m����ȷ��
    Date d(22, m , 1857); 
}
*/

