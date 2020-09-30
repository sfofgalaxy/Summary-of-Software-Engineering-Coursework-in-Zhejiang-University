#include"hll.h"
using namespace std;

int main()
{
	cout << "创建一个链表A" << endl;
	HLL A;
	A.insert_head(12345);
	cout << "插入 Int \"12345\" 节点 : " << endl;								
	A.print();
	cout << endl;

	cout << "插入 Double \"88.88\" 到头节点 : " << endl;						
	A.insert_head(88.88);
	A.print();
	cout << endl;

	cout << "插入 String\"OOP\" 到尾节点 : " << endl;						
	A.insert_tail("OOP");
	A.print();
	cout << endl;

	cout << "插入 2,1 到头节点 and 插入 1,2 到尾节点: " << endl;						
	A.insert_head(2);
	A.insert_head(1);
	A.insert_tail(1);
	A.insert_tail(2);
	A.print();
	cout << endl;

	cout << "删除头节点(1) : " << endl;								
	A.delete_head();
	A.print();
	cout << endl;

	cout << "删除尾节点(2) : " << endl;								
	A.delete_tail();
	A.print();
	cout << endl;

	cout << "反转链表A: " << endl;					
	A.reverse();
	A.print();
	cout << endl;

	cout << "创建链表B并打印 " << endl;				
	HLL B;
	B.insert_head("Linked_List");
	B.insert_tail("B");
	B.print();
	cout << endl;

	cout << "合并A和B到A中" << endl;								
	A.union_other(B);
	A.print();
	cout << endl;

	cout << "销毁链表A并通过打印及其长度检查是否已销毁：" << endl;
	A.destory();															
	A.print();
	cout << A.length() << endl;
	system("pause");
	return 0;
}