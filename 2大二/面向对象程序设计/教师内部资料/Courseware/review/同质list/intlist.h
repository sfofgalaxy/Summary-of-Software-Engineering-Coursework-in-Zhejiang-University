//enum bool{false,true};

struct node
{
	 int val;
	 node *next;
};
typedef struct node* PNODE;

class intlist{
private: 
	PNODE head;
	int size;
public:   
	intlist() : head(0),size(0)
	{	}

	~intlist();
	void insert(int); 		//������ͷ
	void append(int);		//������β
	int get();				//ȡ����ͷ����
	void print();			//����
};





