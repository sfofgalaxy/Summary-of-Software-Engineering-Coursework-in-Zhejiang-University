
#include <string.h>  //C���������ַ����⺯��
#include <malloc.h>
#include <iostream>
using namespace std;

int main()
{
	char name[40];//= "hello ,how are you!";
	//char name[40];
	//name = "hello ,how are you!";
	//strcpy(name,"hello,how are you!");
	cin >> name;  /*��2�����⣺���հ��ַ�ֹͣ���룻������Խ�紦��*/
	
	cout << name << endl;
	cout << sizeof(name) << strlen(name) << endl;
 
	char* p = "I am an student!";  //�����Դ���
	cout << p << endl;
	*p = 'i';   //�˴����öϵ�
    //char *p;
	//cin >> p;  //pû����ȷָ��

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
#include <string>  //C++��׼����ַ�����
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
#include <cstring>  //����namespace std�﷨�����Ժ��C���Կ⺯��
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
