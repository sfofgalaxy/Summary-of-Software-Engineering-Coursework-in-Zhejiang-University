class Node;
class List
{
private:
	Node *head;
public:
	List():head(0)  //�κ�һ���඼��Ҫ���ʵ�constrator
	{}

	void insert(Node* p)
	{
		if (head==0)
			head = p;
		else
			p->linkTo(head);
	}

    void print() const;

	~List();
};
