#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1("Welcome");
    cout << s1.length() << endl; // Length is 7
    cout << s1.size() << endl; // Size is 7
    cout << s1.capacity() << endl; // Capacity is 15
    return 0;
}

