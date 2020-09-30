#include <stdio.h>
#include "alloplasmicList.h"

int main()
{
	PNODE head1;
	PNODE head2;
	head1 = createNode(3);
	print(head1);
	insert(head1,INT,34);
	print(head1);
	insert(head1,CHAR,'H');
	print(head1);
//	head2 = createNode(5);
//	print(head2);
	destory(head1);
    return 0;
}