/*
������գ���Ҫ�ı�����������йص���䡣
��2���Ѱ���������ĵ�������ͷָ��ֱ�Ϊlist1��list2��������ÿһ������������һ��������
���дһ����������2������ƴ��1���������������������к󣬷�����������д��������֤ʵ�֡�
��ʾ��
���庯��struct stud_node *Creat_Stu_Doc()�ֱ𴴽���������
���庯��void Ptrint_Stu_Doc(struct stud_node *head)��ӡ����
���庯��struct stud_node *InserDoc(struct stud_node *list1,struct stud_node *list2)
��ɰ���������list2�Ľ�����β�������list1�С�
�������ʾ����
���룺
1 3 5 7 -1
2 4 6 -1
�����
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




