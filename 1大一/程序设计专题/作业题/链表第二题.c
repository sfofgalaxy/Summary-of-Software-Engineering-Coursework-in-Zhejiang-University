/*程序填空，不要改变与输入输出有关的语句。
输入若干个正整数（输入-1为结束标志），要求按输入数据的逆序建立一个链表并输出。
提示：
定义函数struct stud_node *Creat_Stu_Doc()完成按输入数据的逆序创建链表。
输入输出示例：括号内为说明
输入：
1 2 3 4 5 6 7 -1
输出：
7 6 5 4 3 2 1*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud_node{
	int num;
	struct stud_node *next;
};
struct stud_node *Creat_Stu_Doc();
void Ptrint_Stu_Doc(struct stud_node *head);
void main()
{
	struct stud_node *head;

	head=Creat_Stu_Doc();
	Ptrint_Stu_Doc(head);
	return; 
}
struct stud_node *Creat_Stu_Doc(){
	struct stud_node *head,*p,*temp;
	int n;
	head  = (struct stud_node*)malloc(sizeof(struct stud_node));
	head->next = NULL; 
	p = head ;
	scanf("%d",&head->num);
	while(p->num!=-1){
		temp = p;
		p = (struct stud_node*)malloc(sizeof(struct stud_node));
		p->next = temp;
		scanf("%d",&p->num);
	}
	return temp;
} 
void Ptrint_Stu_Doc(struct stud_node *head)
{
	struct stud_node *ptr;
	if(head==NULL){
		printf("No Records\n");
		return;
	}
	for(ptr=head;ptr;ptr=ptr->next)
		printf("%d ",ptr->num);
	printf("\n");
}
