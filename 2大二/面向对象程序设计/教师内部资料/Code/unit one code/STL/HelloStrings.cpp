
#include <string.h>  //C语言早期字符串库函数
#include <malloc.h>
#include <iostream>
using namespace std;

int main()
{
	char name[40];//= "hello ,how are you!";
	//char name[40];
	//name = "hello ,how are you!";
	//strcpy(name,"hello,how are you!");
	cin >> name;  /*有2个问题：遇空白字符停止输入；不进行越界处理*/
	
	cout << name << endl;
	cout << sizeof(name) << strlen(name) << endl;
 
	char* p = "I am an student!";  //技术性错误
	cout << p << endl;
	*p = 'i';   //此处设置断点
    //char *p;
	//cin >> p;  //p没有正确指向

	char* q =  (char*)malloc(sizeof(char)*20);
	strcpy(q,"I am a student!");
	cin.getline(q,20);
	cout << q << endl;
	q++;
    *q = 'i';
	cout << strcat(name,q) << endl;

	free(q);
    return 0;
}

/*
#include <string>  //C++标准库的字符串类
#include <iostream>   
using namespace std;

int main() 
{
  string s1, s2; // Empty strings
  string s3 = "Hello, World."; // Initialized
  string s4("I am"); // Also initialized
  s2 = "Today"; // Assigning to a string
  s1 = s3 + " " + s4; // Combining strings
  s1 += " zhang san "; // Appending to a string
  cout << s1 + s2 + "!" << endl;
  return 0;
} 
*/

/*
#include <cstring>  //引进namespace std语法机制以后的C语言库函数
#include <iostream>
using namespace std;

int main()
{
	char name[20];
	strcpy(name,"hello ,how are you!aaaa");
	cout << name << endl;
	return 0;
}
*/
