/*
程序填空，不要改变与输入输出有关的语句。
有2个已按升序排序的单向链表，头指针分别为list1、list2，链表中每一结点的数据域是一个整数。
请编写一个函数，把2个链表拼成1个链表并对新链表升序排列后，返回新链表。编写主程序验证实现。
提示：
定义函数struct stud_node *Creat_Stu_Doc()分别创建两个链表；
定义函数void Ptrint_Stu_Doc(struct stud_node *head)打印链表；
定义函数struct stud_node *InserDoc(struct stud_node *list1,struct stud_node *list2)
完成按升序将链表list2的结点依次插入链表list1中。
输入输出示例：
输入：
1 3 5 7 -1
2 4 6 -1
输出：
1 2 3 4 5 6 7
*/ 

#include<stdio.h>
#include<stdlib.h>
struct stud_node{
	int num;
	struct stud_node *next;
};
struct stud_node *Creat_Stu_Doc();
void Ptrint_Stu_Doc(struct stud_node *head);
struct stud_node *InserDoc(struct stud_node *list1,struct stud_node *list2);
void main()
{
	struct stud_node  *list1,*list2;

	list1=Creat_Stu_Doc();
	list2=Creat_Stu_Doc();
	list1=InserDoc(list1,list2);
	Ptrint_Stu_Doc(list1);
}
struct stud_node *Creat_Stu_Doc()
{
	struct stud_node *head,*tail,*p;
	int num;
	int size=sizeof(struct stud_node);

	head=tail=NULL;
	scanf("%d",&num);
	while(num!=-1){
		p=(struct stud_node *)malloc(size);
		p->num=num;
		p->next=NULL;
		if(head==NULL)
		    head=p;
		else
			tail->next=p;
		tail=p;
		scanf("%d",&num);
	}
	return head;
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
struct stud_node *InserDoc(struct stud_node *list1,struct stud_node *list2){
	struct stud_node *ptr1,*ptr2,*temp,*n_head,*p;
	n_head = list1;
	temp = n_head;
		if(list1->num>list2->num){
			p = list2->next;
			list2->next = list1;
			list1 = list2;
			list2 = p;
			n_head = list1;
		}
	for(ptr2 = list2;ptr2;ptr2 = list2){
		for(ptr1 = n_head ;ptr1->num<=ptr2->num&&ptr1->next; ptr1 = ptr1->next){
			temp = ptr1;
		}
		if(ptr1->next){
			p = temp->next;
			temp->next = ptr2;
			list2 = ptr2->next;
			ptr2->next = p;
		}
		else if(ptr1->num<=ptr2->num){
			ptr1->next = ptr2;
			list2=ptr2->next;
		}
		else{
			p = temp->next;
			temp->next=ptr2;
			list2 = ptr2->next;
			ptr2->next = p;
		}
	}
	return n_head;
} 




