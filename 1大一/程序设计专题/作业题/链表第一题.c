/*������գ���Ҫ�ı�����������йص���䡣
�������ɸ�ѧ����Ϣ������ѧ�š������ͳɼ���������ѧ��Ϊ0ʱ���������
����һ����������������һ���ɼ�ֵ�����ɼ����ڵ��ڸ�ֵ��ѧ����Ϣ�����
��ʾ��
���庯��struct stud_node *Creat_Stu_Doc()��ɴ�������
���庯��struct stud_node *DeleteDoc(struct stud_node *head,int min_score)����������min_score�Ľ��ɾ��
���庯��void Ptrint_Stu_Doc(struct stud_node *head)��ӡ����
�������ʾ����������Ϊ˵��
���룺
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
0
80
�����
2 wang 80
4 zhao 85*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud_node{
	int num;
	char name[20];
	int score;
	struct stud_node *next;
};
struct stud_node *Creat_Stu_Doc();
struct stud_node *DeleteDoc(struct stud_node *head,int min_score);
void Ptrint_Stu_Doc(struct stud_node *head);
int  main(void)
{
	struct stud_node *head;
	head = NULL;
	int min_score;
	
	head=Creat_Stu_Doc();
	scanf("%d",&min_score);
	head=DeleteDoc(head,min_score);
	Ptrint_Stu_Doc(head);
	return 0;
}
struct stud_node *Creat_Stu_Doc(){
	struct stud_node *p,*tail,*head;
	head = tail = NULL;
	p = (struct stud_node *)malloc(sizeof(struct stud_node));
	tail = p;
	head = p;
	scanf("%d",&p->num);
	while(p->num){
		scanf("%s%d",p->name,&p->score);
		p = (struct stud_node*)malloc(sizeof(struct stud_node));
		tail->next = p;
		tail = p;
		scanf("%d",&p->num);
		if(p->num==0)tail = NULL;
	}
	return head;
} 

struct stud_node *DeleteDoc(struct stud_node *head,int min_score){
	struct stud_node *p,*temp_p,*n_head;
	n_head = head;
	temp_p = head;
	for(p=head;p->next;p=p->next){
		if(p->score<min_score){
			if(p == n_head){
				n_head = p->next;
			}
			temp_p->next = p->next;
			p = temp_p ;
		}
		else {
		temp_p = p;
		}
	}
	return n_head;
}

void Ptrint_Stu_Doc(struct stud_node *head){
	struct stud_node *p;
	for(p=head;p->next;p=p->next)
		printf("%d %s %d\n",p->num,p->name,p->score);
}


