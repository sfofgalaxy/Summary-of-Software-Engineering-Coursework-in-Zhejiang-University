#include <iostream>

class bird{
private:
	int a[100];
public:
	void print()
	{
		std::cout << "I am a bird, My size is " << sizeof(bird) << std::endl;
	}
};

class rock{
private:
	int b[1000];
public:
	void print()
	{
		std::cout << "I am a rock, My size is " << sizeof(rock) << std::endl;
	}
};

int main()
{
	bird b;
	rock r;
	b.print();
	r.print();

	bird* pb = &b;
	rock* pr = &r;
	void* pv;

	//pr = pb; //in C++: complie-time error
	pv = pb;   //ok
	//pr = pv;   //in C++: complie-time error
	//but In C&&C++
	pr = (rock*) pb;//强制类型转换
	//pr = static_cast<rock*>(pb);//compile-time error，推荐使用
	int *pi;
	double *pd;
	//pd = (double*)(pi);
	//pd = static_cast<double*>(pi);

	return 0;

}


