#ifndef STUDENT_H
#define STUDENT_H

class Student{
private://data member,数据成员
	char *name;
	short age;
	char gender[3];   //"男" or "女"

public:	//member function ,成员函数
	//constructor,构造函数，负责初始化对象
	Student(const char* name,short age,char gender[]);
    Student();
	void print();
	char* get_name() const;
    //void destroy();
	//destructor, 析构函数，负责销毁对象成员所占用的资源	
	~Student();
};

#endif