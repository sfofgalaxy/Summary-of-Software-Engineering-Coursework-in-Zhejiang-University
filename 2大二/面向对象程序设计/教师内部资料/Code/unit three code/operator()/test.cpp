#include "matrix.h"
#include <iostream>
using namespace std;
int main()
{	
	
	Matrix m1(2,3);	
	Matrix m2(2,3);
	cout << m1;
	cout << m2;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			m1(i,j) = i+j;
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout << m1(i,j) << "\t";
		}
		cout << endl;
	}
	return 0;
}