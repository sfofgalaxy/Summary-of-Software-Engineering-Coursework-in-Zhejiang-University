#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"function.h"
/*
typedef struct character{
	char ch;
	int tag;
	struct character *next;
}List;



List *FindKth(int K, List *PtrL);

List *Insert(char c, int t, int i, List *Ptrl);

void Connect(List *head, List *tail);

void reverse(char c[]);

void Free(List *p);

void Break(List *head, List *Breakpoint)

*/

int main(int argc, char** argv) {
	int size;
	int i = 0;//���ڽ��ַ���������� 
	int j = 0;
	int k = 0;
	char a[20] = "";        //���ڼ�¼��������� 
	char b[20] = "";
	
	struct character *head1, *head2, *CommonPart;
	head1 = head2 = CommonPart = NULL;
	
	
    printf("�����һ������:");
 
    scanf("%s",a);	
	
	printf("����ڶ�������:");
	scanf("%s",b);
		
	reverse(a);
	reverse(b);
//	if(a[i]==b[i])printf("aaa");
	while(1){
	if(a[i]==b[i]){
	
		CommonPart = Insert(a[i],-1,1,CommonPart);                 //���ڼ�¼����Ĳ��� 
		i++;
		}
	else break;
	}
		
	k = j = i;
	while(a[j]!='\0'){
		head1 = Insert(a[j],0,1,head1);                            //�ֱ��¼�������ʶ��еĲ��֡� 
		j++;
	}
	while(b[k]!='\0'){
		head2 = Insert(b[k],0,1,head2);
		k++;
	} 
	
	Connect(head1, CommonPart);                                        //ƴ�ӹ����Ӵ��ͷǹ����� 
	Connect(head2, CommonPart);
	if(CommonPart == NULL){
		printf("they do not have common part.");
	} 
	
	else{
	
	printf("The First Character of Common Part is %c.\n",CommonPart->ch);
	printf("It is no.%d character in the first word.\n",j - i + 1);
	printf("It is no.%d character in the second word.\n",k - i + 1);
	}
	
	
	Break(head2,CommonPart);                                  //�������Ӵ���ֳ�������ͬ�Ĳ��� 
	Free(head1);                                             //�ͷ�����Ŀռ� 
	Free(head2);                    
	

	

	
	
}

/*
void reverse(char c[]){
	int length;
	int i = 0;
	length = strlen(c);
	for(i = 0;i <= (length-1)/2;i++){
		c[i] = c[i] + c[length - i];
		c[length - i] = c[i] - c[length -i];
		c[i] = c[i] - c[length -i];
	}
}

List *Insert(char c, int t, int i, List *Ptrl){
	List *p, *s;
	if(i==1){
		s = (List *)malloc(sizeof(List));
		s->ch=c;
		s->tag=t;
		s->next = Ptrl;
		return s;
	}
	p = FindKth(i-1, Ptrl);
	if(p==NULL){
		printf("����i����"); 
		return NULL; 
	}
	else{
		s = (List *)malloc(sizeof(List));
		s->ch=c;
		s->tag=t;
		s->next = p->next;
		p->next = s;
		return Ptrl;
	}
}

List *FindKth(int K, List *PtrL){
	List *p = PtrL;
	int i = 1;
	while(p!=NULL&&i<K){
		p = p->next;
		i++;
	}
	if(i==K)return p;
	else return NULL;
}

void Connect(List *head, List *tail){
	List *p = head;
	if(p == NULL){
	head = tail;
	}
	else{
	
	while(p->next!=NULL)p=p->next;
	p->next = tail;
}
		
};

void Free(List *p){
	List *s;
	while(p!=NULL){
		s = p;
		p = s->next;
		free(s);
		
	}
};
*/
