class Laundry{
private:
public: 
	void CommonWashing(){}
	void SpecialWashing(){}
};

class Hotel{
public:
	Laundry partner;    //member object
public:
};

void main()
{
	Hotel �����Ƶ�("����");
    �����Ƶ�.partner.CommonWashing();
}

���⣺ �ͻ���������������̫���ܣ�����Ա��ʹ�ÿͻ������ͬʱ����ǳ��˽��������
//��϶���ȱ�����������Ͳ������������书��
//����������ı�Ƕ�����ķ���Ȩ��private������һ���ԣ������û�������ʹ�������˵Ĺ��ܱ�ɿͻ��˵�
