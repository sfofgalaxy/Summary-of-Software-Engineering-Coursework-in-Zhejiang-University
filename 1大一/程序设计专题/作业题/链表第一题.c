/*程序填空，不要改变与输入输出有关的语句。
输入若干个学生信息（包括学号、姓名和成绩），输入学号为0时输入结束，
建立一个单向链表，再输入一个成绩值，将成绩大于等于该值的学生信息输出。
提示：
定义函数struct stud_node *Creat_Stu_Doc()完成创建链表
定义函数struct stud_node *DeleteDoc(struct stud_node *head,int min_score)将分数低于min_score的结点删除
定义函数void Ptrint_Stu_Doc(struct stud_node *head)打印链表
输入输出示例：括号内为说明
输入：
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
0
80
输出：
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


