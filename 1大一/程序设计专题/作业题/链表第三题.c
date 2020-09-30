/*������գ���Ҫ�ı�����������йص���䡣
�������ɸ�������������-1Ϊ������־����������һ���������������е�ż��ֵ���ɾ���������
���庯��struct stud_node *DeleteDoc(struct stud_node *head)ɾ��������ż��ֵ��㡣
�������ʾ����������Ϊ˵��
���룺
1 2 3 4 5 6 7 -1
�����
1 3 5 7
*/

#include<stdio.h>
#include<stdlib.h>
struct stud_node{
	int num;
	struct stud_node *next;
};
struct stud_node *Creat_Stu_Doc();
struct stud_node *DeleteDoc(struct stud_node *head);
void Ptrint_Stu_Doc(struct stud_node *head);
void main()
{
	struct stud_node *head;

	head=Creat_Stu_Doc();
	head=DeleteDoc(head);
	Ptrint_Stu_Doc(head);
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
struct stud_node *DeleteDoc(struct stud_node *head){
	struct stud_node* ptr,*p,*n_head;
	p = head;
	n_head=head;
	for(ptr=head;ptr;ptr=ptr->next){
		if(ptr->num%2==0){
			if(ptr==n_head){
				n_head = ptr->next;
				p = n_head;
			}
			else{
				p->next = ptr->next;
				p = ptr->next;
			}
		}
		else{
			p = ptr;
		}
	}
	return n_head;
}


