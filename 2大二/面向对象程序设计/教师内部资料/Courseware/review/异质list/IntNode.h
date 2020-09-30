class IntNode : public Node
{
	int i;
public:
	IntNode(int ii=0): i(ii)
	{}
	void print() const
	{
		cout << "ÕûÊý£º" << i << endl;
	}
};
