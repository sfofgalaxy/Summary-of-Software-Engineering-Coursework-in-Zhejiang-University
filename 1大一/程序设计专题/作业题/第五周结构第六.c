/*
������գ���Ҫ�ı�����������йص���䡣
����n(n<10)�����ѵ���Ϣ���������������ա��绰���룬��������Ӵ�С��˳���������ͨѶ¼��
�������ʾ����������Ϊ˵��
���룺
3	(n=3)
zhang  19850403  13912345678
wang  19821020  0571-88018448
qian  19840619  13609876543
�����
wang 19821020 0571-88018448
qian 19840619 13609876543
zhang 19850403 13912345678*/


#include <stdio.h>
int main (void)
{  
    int i, index, j, n;
    struct address_list{
        char name[20];
        long birthday;
        char phone[20];
    }temp, friends[10];

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%s%ld%s", friends[i].name, &friends[i].birthday, friends[i].phone);
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(friends[j].birthday>friends[j+1].birthday){
				temp=friends[j];
				friends[j]=friends[j+1];
				friends[j+1]=temp;
			}
    for(i = 0; i < n; i++)
        printf("%s %ld %s\n", friends[i].name, friends[i].birthday, friends[i].phone);
}


