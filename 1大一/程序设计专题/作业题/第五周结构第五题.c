/*������գ���Ҫ�ı�����������йص���䡣
��д���򣬴Ӽ������� n (n<10)��������ƺͶ��۲�����ṹ�����У����Ҳ�������ж�����ߺ���͵�������ƺͶ��ۡ�
�������ʾ����������Ϊ˵��
���룺
3	(n=3)
Programming in C
21.5
Programming in VB
18.5
Programming in Delphi
25.0
�����
highest price: 25.0, Programming in Delphi 
lowest price: 18.5, Programming in VB */ 


#include <stdio.h>
int main (void)
{  
    int i, max_index, min_index, n;
    double x;
    struct book{
        char name[50];
        double price;
    }book[10];

    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++){
        gets(book[i].name);
        scanf("%lf", &x);
        getchar();
        book[i].price = x;
    }
    min_index=max_index=0;
	for(i=1;i<n;i++){
		if(book[min_index].price>book[i].price)min_index=i;
		if(book[max_index].price<book[i].price)max_index=i;
	}
    printf("highest price: %.1f, %s\n", book[max_index].price, book[max_index].name);
    printf("lowest price: %.1f, %s\n", book[min_index].price, book[min_index].name);
}


