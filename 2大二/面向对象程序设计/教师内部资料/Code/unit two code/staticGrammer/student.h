#ifndef STUDENT_H
#define STUDENT_H

class Student{
private://data member,���ݳ�Ա
	char* name;
	short age;
	char gender[3];   //"��" or "Ů"
	static double classFee  ; //���
public:	//member function ,��Ա����
	//constructor,���캯���������ʼ������
	Student(const char* name,short age,char gender[]);
    Student();

	 //destructor, �����������������ٶ����Ա��ռ�õ���Դ	
	~Student();

	void print() const;
	char* get_name() const;
    /*
	����if coding
	double getClassFee() const
    {
        return classFee;
    }
	void setClassFee(double money) //�����
	{
		classFee += money;
    }
	ÿ��ѧ�����ѡ������:
	 Student zhangsan("����", 22, "��");
	 zhangsan.getClassFee();
	 zhangsan.setClassFee(50);
	���⣺��������ô���ѣ�
	*/

	//if coding
    static double getClassFee()  //����
	{
        return classFee;
    }
   
	static void setClassFee(double money); //�����

	/*
	ÿ��ѧ�����ѡ������:
	 Student zhangsan("����", 22, "��");
	 zhangsan.getClassFee(); 
	 Student::getClassFee();

	 zhangsan.setClassFee(50); 
	 Student::setClassFee(50)

	 �����β���:
	 Student::getClassFee(); 
	 Student::setClassFee(500)
	*/ 
	
};


#endif