/*程序填空，不要改变与输入输出有关的语句。
有一个单向链表，头指针为L，结点的数据域是一个整数，将链表L中奇数值的结点重新组成一个新的链表NEW，
并输出新建链表。
输入输出示例：
输入：
1 2 3 4 5 6 7 -1
输出：
1 3 5 7 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud_node{
	int num;
	struct stud_node *next;
};
void Ptrint_Stu_Doc(struct stud_node *head);
void main()
{
	struct stud_node *L,*tail1,*tail2,*p1,*p2,*NEW;
	int num;
	int size=sizeof(struct stud_node);

	L=tail1=NULL;
	scanf("%d",&num);
	while(num!=-1){
		p1=(struct stud_node *)malloc(size);
		p1->num=num;
		p1->next=NULL;
		if(L==NULL)
		    L=p1;
		else
			tail1->next=p1;
		tail1=p1;
		scanf("%d",&num);
	}
	p1 = L;
	NEW = L;
	for(p2 = L;p2;p2 = p2->next){
		if(p2->num%2==0&&p2==NEW){
			NEW = p2->next;
		}
		else if(p2->num%2==0){
			p1->next = p2->next;
		}
		else {
			p1 = p2;
		}
	}
	Ptrint_Stu_Doc(NEW);
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
