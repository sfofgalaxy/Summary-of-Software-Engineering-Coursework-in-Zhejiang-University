/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� n��3<n��10���������� n ��ѧ������Ϣ������ѧ�š�������3�ſγ̵ĳɼ�������ܷ����ѧ�����������ܷ֡�
�������ʾ����������Ϊ˵��
���룺
5	(n=5)
1 ��� 78  83  75
2 ���� 76  80  77
3 ��ǿ 87  83  76
4 �ŷ� 92  88  78
5 ���� 76  81  75
����� 
�ܷ���ߵ�ѧ����: �ŷ㣬258��
*/

#include <stdio.h>
int main (void)
{  
    int i, j, k, max_index, n;
    struct student{
        int number;
        char name[20];
        int score[3];
        int sum;
    }stu[10];

    scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d%s%d%d%d",&stu[i].number,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
	}
	max_index=0;
	for(i=1;i<n;i++)if(stu[i].sum>stu[max_index].sum)max_index=i;
    printf("�ܷ���ߵ�ѧ����: %s��%d��\n", stu[max_index].name, stu[max_index].sum);
}

