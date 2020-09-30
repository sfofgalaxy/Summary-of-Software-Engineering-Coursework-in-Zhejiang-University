#include<stdio.h>
#include<stdlib.h>

typedef struct tree *Tree;
struct tree
{
	int value;
	Tree left;
	Tree right;
	Tree parent;
};

int height(Tree root);
Tree SingleRight(Tree ptr);
Tree SingleLeft(Tree ptr);
Tree DoubleRight(Tree ptr);
Tree DoubleLeft(Tree ptr);
Tree inspect(Tree ptr, int num);
Tree balance(Tree ptr, int num);
Tree input(Tree root);
Tree findroot(Tree root);
void output(Tree root);

int main()
{
	int N;
	Tree root = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		root = input(root);
		//准备写数据的输入，随后开始写输入后是否不平衡，进行旋转的函数
	}
	printf("%d", root->value);
	system("pause");
}

int height(Tree root)
{
	int L, R;
	if (root == NULL)return 0;
	else
	{
		L = height(root->left);
		R = height(root->right);
		return 1 + ((R > L) ? R : L);
	}
}

Tree SingleRight(Tree ptr)
{
	Tree temp;
	temp = ptr->right;
	ptr->right = temp->left;
	if(temp->left)temp->left->parent = ptr;
	temp->left = ptr;
	temp->parent = ptr->parent;
	ptr->parent = temp;
	if (temp->parent)
	{
		if (temp->value > temp->parent->value)temp->parent->right = temp;
		else temp->parent->left = temp;
	}
	return temp;
}
Tree SingleLeft(Tree ptr)
{
	Tree temp;
	temp = ptr->left;
	ptr->left = temp->right;
	if(temp->right)temp->right->parent = ptr;
	temp->right = ptr;
	temp->parent = ptr->parent;
	ptr->parent = temp;
	if (temp->parent)
	{
		if (temp->value > temp->parent->value)temp->parent->right = temp;
		else temp->parent->left = temp;
	}
	return temp;
}
Tree DoubleRight(Tree ptr)
{
	return SingleRight(SingleLeft(ptr->right)->parent);
}
Tree DoubleLeft(Tree ptr)
{
	return SingleLeft(SingleRight(ptr->left)->parent);
}


//如果没问题那就返回空指针,有问题就返回单旋转或双旋转后新树的根
Tree inspect(Tree ptr, int num)
{
	int L, R;
	ptr = ptr->parent;
	ptr = ptr->parent;
	while (ptr)
	{
		R = height(ptr->right);
		L = height(ptr->left);
		if (R - L > 1 || R - L < -1)break;
		ptr = ptr->parent;
	}
	//如果ptr为空证明没问题，返回空
	//否则证明有问题，就balance一下，返回新数的根

	if (!ptr)return NULL;
	return balance(ptr, num);
}

Tree balance(Tree ptr, int num)
{
	if (num > ptr->value)
	{
		if (num > ptr->right->value)return findroot(SingleRight(ptr));
		else return findroot(DoubleRight(ptr));
	}
	else
	{
		if (num < ptr->left->value)return findroot(SingleLeft(ptr));
		else return findroot(DoubleLeft(ptr));
	}
}

//返回input后的新根
Tree input(Tree root)
{
	int num;
	Tree ptr = root;
	scanf("%d", &num);
	if (!root)
	{
		root = (Tree)malloc(sizeof(struct tree));
		root->value = num;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		return root;
	}
	else
	{

		while (1)
		{
			if (num > ptr->value)
			{
				if (!(ptr->right))
				{
					ptr->right = (Tree)malloc(sizeof(struct tree));
					ptr->right->parent = ptr;
					ptr = ptr->right;
					ptr->value = num;
					ptr->right = NULL;
					ptr->left = NULL;
					break;
				}
				else ptr = ptr->right;
			}
			else
			{
				if (!(ptr->left))
				{
					ptr->left = (Tree)malloc(sizeof(struct tree));
					ptr->left->parent = ptr;
					ptr = ptr->left;
					ptr->value = num;
					ptr->right = NULL;
					ptr->left = NULL;
					break;
				}
				else ptr = ptr->left;
			}
		}
		if (!(ptr = inspect(ptr, num)))ptr = root;
		return ptr;
	}
}

Tree findroot(Tree root)
{
	if (root->parent != NULL)return findroot(root->parent);
	return root;
}
