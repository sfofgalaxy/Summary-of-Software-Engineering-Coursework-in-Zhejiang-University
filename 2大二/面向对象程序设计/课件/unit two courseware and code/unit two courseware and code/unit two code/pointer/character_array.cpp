#include <iostream>
using namespace std;


int main()
{
	//This is technically an error Ó¦¸Ã£ºconst char* p="..."; 
    char *p = "how are you!"; 	 
	cout<< p <<endl;
	char *q = p;

    while(*q != '\0'){
		*q = *q + 1;
		q++;
	}
	cout << p << endl;

/*1	
	char *p = (char*)malloc(100);
    strcpy(p,"how are you!");	
	char* q = p;
	cout<< p <<endl;

	while(*q){
		*q = *q + 1;
		q++;
	}

	cout << p << endl;

*/

/*2
	char p[] = "how are you!";  
	cout<< p <<endl;
	char *q = p;

    while(*q != '\0'){
		*q = *q + 1;
		q++;
	}

	cout << p << endl;

   //char pc[100];
   //::strcpy(pc,"hello!");
*/
	return 0;
}


