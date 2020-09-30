#ifndef STUDENT_H
#define STUDENT_H

class Student{
private://data member,数据成员
	char* name;
	short age;
	char gender[3];   //"男" or "女"
	static double classFee  ; //班费
public:	//member function ,成员函数
	//constructor,构造函数，负责初始化对象
	Student(const char* name,short age,char gender[]);
    Student();

	 //destructor, 析构函数，负责销毁对象成员所占用的资源	
	~Student();

	void print() const;
	char* get_name() const;
    /*
	查班费if coding
	double getClassFee() const
    {
        return classFee;
    }
	void setClassFee(double money) //交班费
	{
		classFee += money;
    }
	每个学生查班费、交班费:
	 Student zhangsan("张三", 22, "男");
	 zhangsan.getClassFee();
	 zhangsan.setClassFee(50);
	问题：班主任怎么查班费？
	*/

	//if coding
    static double getClassFee()  //查班费
	{
        return classFee;
    }
   
	static void setClassFee(double money); //交班费

	/*
	每个学生查班费、交班费:
	 Student zhangsan("张三", 22, "男");
	 zhangsan.getClassFee(); 
	 Student::getClassFee();

	 zhangsan.setClassFee(50); 
	 Student::setClassFee(50)

	 班主任查班费:
	 Student::getClassFee(); 
	 Student::setClassFee(500)
	*/ 
	
};


#endif