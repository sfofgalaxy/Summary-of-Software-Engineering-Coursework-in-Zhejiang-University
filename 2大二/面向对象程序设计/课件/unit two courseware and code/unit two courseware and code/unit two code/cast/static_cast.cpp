#include <iostream>
using namespace std;

int main()
{
	signed char s_ch = '\xFF';
	int i;
    i = s_ch;
	cout << "i=" << i << endl;
	i = static_cast<unsigned char>(s_ch);
	cout << "i=" << i << endl;
    return 0;
}