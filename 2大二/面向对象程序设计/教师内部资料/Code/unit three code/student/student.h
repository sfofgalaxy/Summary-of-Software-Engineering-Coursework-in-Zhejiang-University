#ifndef STUDENT_H
#define STUDENT_H

class Student{
private://data member,���ݳ�Ա
	char *name;
	short age;
	char gender[3];   //"��" or "Ů"

public:	//member function ,��Ա����
	//constructor,���캯���������ʼ������
	Student(const char* name,short age,char gender[]);
    Student();
	void print();
	char* get_name() const;
    //void destroy();
	//destructor, �����������������ٶ����Ա��ռ�õ���Դ	
	~Student();
};

#endif