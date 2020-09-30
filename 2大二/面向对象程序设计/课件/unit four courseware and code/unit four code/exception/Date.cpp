//没有任何合法性检查
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
		out << d.year << "年" << d.month << "月" << d.day << "日" << endl;
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
//C常用方法：加入检测代码

#include <iostream>
using namespace std;

class Date {
public:
	Date(int nDay, int nMonth, int nYear)
	{
		if ( nMonth<1 || nMonth>12 ){
			cout << "初始化Date对象， 月份出错！" << endl;
			exit(0);
		}
		//检测nYear代码
		//检测nDay代码
		year = nYear;
		month = nMonth;
		day = nDay;
	}
	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "年" << d.month << "月" << d.day << "日" << endl;
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

//C++的异常解决机制
#include <iostream>
using namespace std;
class Date {
public:
	class monthError{};//空类

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
		out << d.year << "年" << d.month << "月" << d.day << "日" << endl;
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
   	    cout << "初始化Date对象，月份出错！" << endl;
	}
	//catch(Date::yearError e)
	//catch(Date::yearError& e)
}
//但遗憾的是d对象没有调用析购函数

/*
//异常类的组织方法
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
		out << d.year << "年" << d.month << "月" << d.day << "日" << endl;
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
//		cout << "初始化Date对象，发生" << e.what() << "异常!" << endl;
//	}
	catch(exception& e)
	{
		cout << "初始化Date对象，发生" << e.what() << "异常!" << endl;
	}
}
*/

//把发现错误发生在编译/联接阶段
/*
#include <iostream>
using namespace std;

class Date {
public:
	//怎么做可以免于对它进行合法性检查呢？比如合法的月份
	//一个明显的办法是采用枚举类型而不用整数
	enum Month { Jan = 1,Feb = 2,Mar = 3,Apr = 4,May = 5,Jun = 6,Jul=7,Aug = 8,Sep = 9,Oct=10,Nov = 11,Dec = 12 };

	Date(int day, Month month, int year)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	friend ostream& operator<<(ostream& out,const Date& d)
	{
		out << d.year << "年" << d.month << "月" << d.day << "日" << endl;
        return out;
	}
   

private:
	int year;
	int month;
	int day;
};

void main()
{
	//遗憾的是，这不会换来多少好处，因为枚举类型不需要初始化：
	Date::Month m;
    Date d(22, m, 1857); // m 是不确定的
	//所以，Date 构造函数还是得验证month 参数的值。
}
*/

/*既想免除运行时检查，又要保证足够的安全性，
你就得用一个类来表示month，你就得保证只有合法的month 才被创建：
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

	operator int() const // 可以被转换为int
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
		out << d.year << "年" << d.month << "月" << d.day << "日" << endl;
        return out;
	} 
private:
	int year;
	int month;
	int day;
};

void main()
{
    Month m(Month::Jan());//由编译时确定m的正确性
    Date d(22, m , 1857); 
}
*/

