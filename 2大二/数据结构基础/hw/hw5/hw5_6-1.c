#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* details omitted */
int CheckBST ( BinTree T, int K );

BinTree BuildTree()
{
    struct TNode* _ans_tree = NULL;
    int temp_number;
    scanf("%d", &temp_number);

    if( temp_number != -1 )
    {
        _ans_tree = (BinTree)malloc(sizeof(struct TNode));
        _ans_tree->Left = _ans_tree->Right = NULL;
        _ans_tree->Key = temp_number;
        scanf("%d", &temp_number);
        while( temp_number != -1 ){
            Insert_Node(_ans_tree, temp_number);
            scanf("%d", &temp_number);
        }
        
    }

    return _ans_tree;
}

void Insert_Node(BinTree _root, int con_key)
{
    int flag = ( ( con_key < _root->Key ) ? 1 : 0 );
    switch( flag )
    {
        case 1: //means need to insert into the left bintree of the root
        {
            if( _root->Left != NULL )
            {
                Insert_Node( _root->Left, con_key );
            }
            else
            {
                BinTree _new_node = (BinTree)malloc(sizeof(struct TNode));
                _new_node->Key = con_key;
                _new_node->Left = _new_node->Right = NULL;
                _root->Left = _new_node;
            }
            break;
        }
        case 0: //means need to insert into the right bintree of the root
        {
            if( _root->Right != NULL )
            {
                Insert_Node( _root->Right, con_key );
            }
            else
            {
                BinTree _new_node = (BinTree)malloc(sizeof(struct TNode));
                _new_node->Key = con_key;
                _new_node->Left = _new_node->Right = NULL;
                _root->Right = _new_node;
            }
            break;
        }
    }
    return;
}

int main()
{
    BinTree T;
    int K, out;

    T = BuildTree();
    scanf("%d", &K);
    out = CheckBST(T, K);
    if ( out < 0 )
        printf("No.  Height = %d\n", -out);
    else
        printf("Yes.  Key = %d\n", out);

    return 0;
}

struct stack
{
	BinTree node;
	struct stack *Next;	
};


int mintraversal(BinTree T,int n)
{
	int flag1=1,flag2=1;
	if(T)
	{
		if(T->Key>=n)return 0;
		else
		{
			flag1=mintraversal(T->Left,n);
			flag2=mintraversal(T->Right,n);
			return flag1&&flag2;
		}
	}
	return 1;
}

int maxtraversal(BinTree T,int n)
{
	int flag1=1,flag2=1;
	if(T)
	{
		if(T->Key<=n)return 0;
		else
		{
			flag1=maxtraversal(T->Left,n);
			flag2=maxtraversal(T->Right,n);
			return flag1&&flag2;
		}
	}
	return 1;
}

int check(BinTree T)
{
	int flag1=1,flag2=1;
	if(T)
	{
		flag1 = check(T->Left);
		flag2 = check(T->Right);
		return flag1&&flag2&&maxtraversal(T->Right,T->Key)&&mintraversal(T->Left,T->Key);
	}
	return 1;
}


int TreeHeight(BinTree T)
{
	if(T)return (TreeHeight(T->Right)>TreeHeight(T->Left)? TreeHeight(T->Right) : TreeHeight(T->Left))+1;
	else return 0;
}

struct stack *inorder(BinTree T,struct stack *p)
{
	if(T)
	{
		p = inorder(T->Right,p);
		
		struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
		temp->Next = NULL;
		temp->node = T;
		p->Next = temp;
		p = temp;
		
		p = inorder(T->Left,p);
	}
	return p;
}

int find(BinTree T, int K)
{
	int i, Key;
	struct stack *header = (struct stack *)malloc(sizeof(struct stack));
	header->Next = NULL; 
	
	inorder(T,header);
		
	struct stack *ptr=header;
	for (i = 1; i <= K; i++)ptr = ptr->Next;
	
	Key = ptr->node->Key;
	return Key;
}

int CheckBST(BinTree T, int K)
{
	//初始化为最右端（最大值）
	if (check(T))
	{
		return find(T, K);
	}

	else
	{
		return -TreeHeight(T);
	}

}

