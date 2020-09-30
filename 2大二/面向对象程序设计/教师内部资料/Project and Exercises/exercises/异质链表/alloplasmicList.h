/* 　　
=========================== 　　
枚举出异质链表中所有节点数据的类型 　　　
=========================== 　　
*/
enum TYPE{INT,DOUBLE,FLOAT,CHAR};

/* 　　
=========================== 　　
定义质链表中节点类型 　　　
=========================== 　　
*/
struct Node{
	enum TYPE type;
	void *data;
	struct Node *next;
};

/* 　　
=========================== 　　
把struct Node*重命名为PNODE 　　　
=========================== 　　
*/
typedef struct Node* PNODE;

/* 　　
=========================== 　　
功能：输出节点 　　
返回： void 　　
=========================== 　　
*/
void print(PNODE pHead);

/*
==========================
功能：创建一个具有n个节点的链表，从键盘输入数据将其初始化，
返回：指向链表表头的指针
==========================
*/   
PNODE createNode(int n);

/*
==========================
功能：删除并释放整个链表的节点
返回：void
==========================
*/  
void destory(PNODE pHead);

/*
==========================
功能：在链头插入具有指定类型和数据值的节点
返回：指向链表表头的指针
==========================
*/  
PNODE insert(PNODE &pHead, TYPE type, int data);
PNODE insert(PNODE &pHead, TYPE type, double data);
PNODE insert(PNODE &pHead, TYPE type, float data);
PNODE insert(PNODE &pHead, TYPE type, char data);