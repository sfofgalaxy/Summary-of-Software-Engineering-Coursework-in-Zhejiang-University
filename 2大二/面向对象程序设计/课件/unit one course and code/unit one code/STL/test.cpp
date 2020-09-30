#include<iostream>
#include<stdlib.h>
using namespace std;
class Student
{private:
    int num;
	int score;
public:
	void setdata()
	{cin >> num;
	cin >> score;
	}
    void display()
	{cout << "num=" << num << endl;
	cout << "score=" << score << endl;
	};
};
Student stud1,stud2;
int main()
{
	stud1.setdata();
	stud2.setdata();
	stud1.display();
	stud2.display();
	//fflush(stdin);//C方法，清空输入缓冲区
	cin.sync();//C++就用这个吧
	getchar();
	return 0;
}
