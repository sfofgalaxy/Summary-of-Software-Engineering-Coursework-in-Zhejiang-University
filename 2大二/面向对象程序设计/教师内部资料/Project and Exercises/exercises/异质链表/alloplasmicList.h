/* ����
=========================== ����
ö�ٳ��������������нڵ����ݵ����� ������
=========================== ����
*/
enum TYPE{INT,DOUBLE,FLOAT,CHAR};

/* ����
=========================== ����
�����������нڵ����� ������
=========================== ����
*/
struct Node{
	enum TYPE type;
	void *data;
	struct Node *next;
};

/* ����
=========================== ����
��struct Node*������ΪPNODE ������
=========================== ����
*/
typedef struct Node* PNODE;

/* ����
=========================== ����
���ܣ�����ڵ� ����
���أ� void ����
=========================== ����
*/
void print(PNODE pHead);

/*
==========================
���ܣ�����һ������n���ڵ�������Ӽ����������ݽ����ʼ����
���أ�ָ�������ͷ��ָ��
==========================
*/   
PNODE createNode(int n);

/*
==========================
���ܣ�ɾ�����ͷ���������Ľڵ�
���أ�void
==========================
*/  
void destory(PNODE pHead);

/*
==========================
���ܣ�����ͷ�������ָ�����ͺ�����ֵ�Ľڵ�
���أ�ָ�������ͷ��ָ��
==========================
*/  
PNODE insert(PNODE &pHead, TYPE type, int data);
PNODE insert(PNODE &pHead, TYPE type, double data);
PNODE insert(PNODE &pHead, TYPE type, float data);
PNODE insert(PNODE &pHead, TYPE type, char data);