#include"hll.h"
using namespace std;

int main()
{
	cout << "����һ������A" << endl;
	HLL A;
	A.insert_head(12345);
	cout << "���� Int \"12345\" �ڵ� : " << endl;								
	A.print();
	cout << endl;

	cout << "���� Double \"88.88\" ��ͷ�ڵ� : " << endl;						
	A.insert_head(88.88);
	A.print();
	cout << endl;

	cout << "���� String\"OOP\" ��β�ڵ� : " << endl;						
	A.insert_tail("OOP");
	A.print();
	cout << endl;

	cout << "���� 2,1 ��ͷ�ڵ� and ���� 1,2 ��β�ڵ�: " << endl;						
	A.insert_head(2);
	A.insert_head(1);
	A.insert_tail(1);
	A.insert_tail(2);
	A.print();
	cout << endl;

	cout << "ɾ��ͷ�ڵ�(1) : " << endl;								
	A.delete_head();
	A.print();
	cout << endl;

	cout << "ɾ��β�ڵ�(2) : " << endl;								
	A.delete_tail();
	A.print();
	cout << endl;

	cout << "��ת����A: " << endl;					
	A.reverse();
	A.print();
	cout << endl;

	cout << "��������B����ӡ " << endl;				
	HLL B;
	B.insert_head("Linked_List");
	B.insert_tail("B");
	B.print();
	cout << endl;

	cout << "�ϲ�A��B��A��" << endl;								
	A.union_other(B);
	A.print();
	cout << endl;

	cout << "��������A��ͨ����ӡ���䳤�ȼ���Ƿ������٣�" << endl;
	A.destory();															
	A.print();
	cout << A.length() << endl;
	system("pause");
	return 0;
}