#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define maxnamelen 10
#define end -1

struct node{
    char name[maxnamelen];
    int age;
    int height;
    int weight;
    struct node *next;
};
typedef struct node Friend;
typedef struct list{
    Friend *First;
    int count;
}List;

Friend* ReadContent();//��ios��ȡ�����
Friend* Readfilecontent(FILE *p);//���ļ���ȡ�����
void insert(List *p,Friend *q);//������ڲ���ͨѶ��
void Readfile(FILE *p,List *q);//��ȡ�ļ������������
void Sort(List *p,int key,int type);//����ѡ���������N��ȷ����С
void deletefriend(List *p,int position);//������ɾ������
void FREE(List *p);//�ͷſռ�
void ownprint(FILE *p,List *q);//��ͨѶ�ʸ�ʽ��������ļ�
void printresult(List *p);

int main(){
    FILE *fp;
    List* AddressList;
    int a,b,d;
    char c;

    AddressList = (List *)malloc(sizeof(List));
    AddressList->First=NULL;
    AddressList->count=0;

    while(1){
    printf("Please choose what you\'d like to do(Enter -1 to quit)\n");
    printf("1.Add some Friend\n2.Readfile and sort it\n(please enter 1 or 2)\n");
    scanf("%d",&a);
    if(a==-1){
        break;
    }

    switch(a){
        case 1:
        fp = fopen("AddressList.txt","a");
        loop:
        printf("��������ϵ����Ϣ������+�Լ������룬����=�Խ������룬����-��ɾ����һ������\n");
        c=getchar();
        second:
        if((c=getchar())=='='){
        	ownprint(fp,AddressList);//��������������뵽�ļ�������
            break;
        }
        else if(c=='-'){
            deletefriend(AddressList,end);//ɾ������
        }
        else if(c=='+'){
            insert(AddressList,ReadContent());//����һ������
        }
        else{
        	goto second;
		}
        goto loop;

        
        case 2:
        fp = fopen("AddressList.txt","r");
        Readfile(fp,AddressList);
        Err:
        printf("Please choose a key word to sort:\n");
        printf("1.age\n2.height\n3.weight\n");
        scanf("%d",&b);
        switch(b){
            case 1:printf("Please choose mode:\n1 for old to young and 2 for young to old\n");
            scanf("%d",&d);if(d==1)Sort(AddressList,1,1);
            else if(d==2)Sort(AddressList,1,2);else goto Err;break;

            case 2:printf("Please choose mode:\n1 for high to short and 2 for short to high\n");
            scanf("%d",&d);if(d==1)Sort(AddressList,2,1);
            else if(d==2)Sort(AddressList,2,2);else goto Err;break;

            case 3:printf("Please choose mode:\n1 for heavy to light and 2 for light to heavy\n");
            scanf("%d",&d);if(d==1)Sort(AddressList,3,1);
            else if(d==2)Sort(AddressList,3,2);else goto Err;break;

            default:goto Err;
        }
        printresult(AddressList);break;
        default:printf("Illigal input");continue;
    }
    /*if(AddressList->First!=NULL){
    FREE(AddressList);
    }*/
    FREE(AddressList);
    }

    free(AddressList);
}

void Readfile(FILE *p,List *q)//��ȡ�ļ������������
{
    char a,b;
    while(1){
    if((a = fgetc(p))=='\n'){//��fgetc���ж��ļ��Ƿ��н�β
        if((b=fgetc(p))==EOF)break;//�����ļ�β�ͽ���ѭ��
        else{
            ungetc(b,p);
            insert(q,Readfilecontent(p));//���ǽ�β��Ż��ַ�����ӡ��
        }
    }
    ungetc(a,p);
    insert(q,Readfilecontent(p));//��������ֱ�Ӵ�ӡ
    }
}

Friend *Readfilecontent(FILE *p){
    Friend *m=(Friend*)malloc(sizeof(Friend));//��������տռ�
    fscanf(p,"%s%d%d%d",m->name,&m->age,&m->height,&m->weight);//fsccanf
    m->next=NULL;//���һ�������
    return m;
}//���

Friend* ReadContent(){
    Friend *p=(Friend*)malloc(sizeof(Friend));//����ռ�
    char s[maxnamelen];
    printf("Please Enter your friend's name:");
    scanf("%s",p->name);
    printf("Please Enter your friend's age:");
    scanf("%d",&p->age);
    printf("Please Enter your friend's height:");
    scanf("%d",&p->height);
    printf("Please Enter your friend's weight:");
    scanf("%d",&p->weight); 
    p->next=NULL;              //�Ĵ�scanf
    return p;


}//���

void insert(List *p,Friend *q){
        Friend *m;
        m=p->First;
        if(m==NULL){
            p->First=q;
        p->count++;
        }
        else{
        while(m->next!=NULL){
        m=m->next;
        }
        m->next=q;
        p->count++;
        }
}//���

void deletefriend(List *p,int position){
    Friend *m,*n,*q;//m���洢��ǰ�ġ�n�洢Ҫ�ҵġ�
    n=NULL;
    int count=1;
    //Ѱ�ҵ�position��friend
    if(position>p->count||p==NULL){
        printf("it dose not exist");
    }
    else if(position==1){//�����һ��ֱ��ɾ��
        q=p->First;
        p->First=p->First->next;
        p->count--;
    }
    else if(position==end){//ֱ��Ѱ����һ����NULL��ָ��
        m=p->First;
        while(m->next!=NULL){
        n=m;
        m=m->next;
        }
        if(n==NULL){
            p->First==NULL;
            p->count--;
            q=m;
        }
        else{
        n->next=NULL;
        q=m;
        p->count--;
        }
    }
    else{//�������һ��ֱ���Ҹ�����count����
        m=p->First;
        while(count<position){
        n=m;
        m=m->next;
        count++;
        } 
        n->next=m->next;
        q=m;
        p->count--;
    }
    free(q);//��q�������Ҫɾ���Ľڵ�Ȼ��ɾ����
}//���

void FREE(List *p){
    Friend *m,*n;
    m=p->First;
    while(m!=NULL){
        n=m;
        m=m->next;
        free(n);
    }
    p->First=NULL;
}//���

void ownprint(FILE *p,List *q){
    Friend *m;
    m=q->First;
    while(m!=NULL){
        fprintf(p,"%s %d %d %d\n",m->name,m->age,m->height,m->weight);
        m=m->next;
    }
    fclose(p);
}//���

void printresult(List *p){
    int a,b,i;
    Friend *m,*n;
    Err1:
    printf("What kind of result do you want?\n");
    printf("1 for certain student and 2 for several students from the head\n");
    scanf("%d",&a);
    switch(a){
        case 1:printf("which one do you want? Please enter a number\n");
        scanf("%d",&b);
        if(p->count<b){printf("Illegal input\n");goto Err1;}
        else{
            i=1;m=p->First;
            while(i<b){
                m=m->next;
                i++;
            }
            printf("%s %d %d %d\n",m->name,m->age,m->height,m->weight);
        }
        break;
        case 2:printf("which one do you want? Please enter a number\n");
        scanf("%d",&b);
        if(p->count<b){printf("Illegal input\n");goto Err1;}
        else{
            i=1;m=p->First;
            while(i<=b){
                printf("%s %d %d %d\n",m->name,m->age,m->height,m->weight);
                m=m->next;
                i++;
            }
        }
        break;
        default:goto Err1;
    }
}

void Sort(List *p,int key,int type){
    Friend *n,*q,*l,*head,*target,*intern;//����type��ѡ����һ������
    int count,flag,m;
    switch(key){
        case 1:
        switch(type){
            case 1:
            count=0;
            m=1;
            head=p->First;
            target=NULL;
            while(m<p->count){
                count=0;
                n=head;
                while(n->next!=target){
                    q=n;
                    l=q->next;
                    if((q->age)<(l->age)){
                        q->next=l->next;
                        l->next=q;
                        if(count==0)head=l;
                        n=l;
                        if(count>0){
                            intern->next=n;
                        }
                    }
                    intern=n;
                    n=n->next;
                    count++;
                }
                target=n;
                m++;
            }
            break;
           
            case 2:
            count=0;
            m=1;
            head=p->First;
            target=NULL;
            while(m<p->count){
                count=0;
                n=head;
                while(n->next!=target){
                    q=n;
                    l=q->next;
                    if((q->age)>(l->age)){
                        q->next=l->next;
                        l->next=q;
                        if(count==0)head=l;
                        n=l;
                        if(count>0){
                            intern->next=n;
                        }
                    }
                    intern=n;
                    n=n->next;
                    count++;
                }
                target=n;
                m++;
            }
        }
        break;
        case 2:
        switch(type){
            case 1:
            count=0;
            m=1;
            head=p->First;
            target=NULL;
            while(m<p->count){
                count=0;
                n=head;
                while(n->next!=target){
                    q=n;
                    l=q->next;
                    if((q->height)<(l->height)){
                        q->next=l->next;
                        l->next=q;
                        if(count==0)head=l;
                        n=l;
                        if(count>0){
                            intern->next=n;
                        }
                    }
                    intern=n;
                    n=n->next;
                    count++;
                }
                target=n;
                m++;
            }
            break;
           
            case 2:
            count=0;
            m=1;
            head=p->First;
            target=NULL;
            while(m<p->count){
                count=0;
                n=head;
                while(n->next!=target){
                    q=n;
                    l=q->next;
                    if((q->height)>(l->height)){
                        q->next=l->next;
                        l->next=q;
                        if(count==0)head=l;
                        n=l;
                        if(count>0){
                            intern->next=n;
                        }
                    }
                    intern=n;
                    n=n->next;
                    count++;
                }
                target=n;
                m++;
            }
        }
        break;
        case 3:
        switch(type){
            case 1:
            count=0;
            m=1;
            head=p->First;
            target=NULL;
            while(m<p->count){
                count=0;
                n=head;
                while(n->next!=target){
                    q=n;
                    l=q->next;
                    if((q->weight)<(l->weight)){
                        q->next=l->next;
                        l->next=q;
                        if(count==0)head=l;
                        n=l;
                        if(count>0){
                            intern->next=n;
                        }
                    }
                    intern=n;
                    n=n->next;
                    count++;
                }
                target=n;
                m++;
            }
            break;
           
            case 2:
            count=0;
            m=1;
            head=p->First;
            target=NULL;
            while(m<p->count){
                count=0;
                n=head;
                while(n->next!=target){
                    q=n;
                    l=q->next;
                    if((q->weight)>(l->weight)){
                        q->next=l->next;
                        l->next=q;
                        if(count==0)head=l;
                        n=l;
                        if(count>0){
                            intern->next=n;
                        }
                    }
                    intern=n;
                    n=n->next;
                    count++;
                }
                target=n;
                m++;
            }
        }
        break;
    }
            
       
    //key1���䡣1��2С
    //type2��ߡ�1��2С
    //type3���ء�1��2С
    p->First=head;
}
        
            
