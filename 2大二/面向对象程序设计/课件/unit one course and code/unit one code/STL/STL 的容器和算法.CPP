#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

void print(int i)
{
   cout << i << ' ';
}

int  main()
{	
	{
		//int i;
		int ia[10]={12,14,54,6,3,66,45,90,10,20};
		
		vector<int> iv(ia, ia+10); //定义一个整型向量iv
		for_each(iv.begin(), iv.end(), print);  //for_each is a STL Algorithms
		cout << endl;

		sort(iv.begin(), iv.end());//sort is a STL Algorithms, sort运用于iv

		for_each(iv.begin(), iv.end(), print);
		cout << endl;

		set<int> is;
		is.insert(4);
		is.insert(3);
		is.insert(7);
		is.insert(0);
		is.insert(2);
		for_each(is.begin(), is.end(), print);
		cout << endl;
	}
	{
		int i;
		int ia[10]={12,14,54,6,3,66,45,90,10,20};
		vector<int> iv(ia, ia+10);
		for_each(iv.begin(), iv.end(), print);
		cout << endl;
		sort(iv.begin(), iv.end(), greater<int>() );
		for_each(iv.begin(), iv.end(), print);
		cout << endl;
	}
	return 0;
}
