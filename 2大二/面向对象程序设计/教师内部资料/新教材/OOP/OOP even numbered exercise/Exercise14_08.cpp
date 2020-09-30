#include <iostream>
#include <complex>
using namespace std;

int main(){
  double a, b;
  cout << "Enter a complex number: ";
  cin >> a >> b;

  complex<double> c(a, b), z;

  for (int i = 0; i < 60; i++) 
  {
    z = z * z + c;
	if (abs(z) > 2) 
	{
	  cout << c << " is not in the Mandelbrot set" << endl;
	  return 0;
	}
  }

  cout << c << " is in the Mandelbrot set" << endl;
  return 0;
}