class Laundry{
private:
public: 
	void CommonWashing(){}
	void SpecialWashing(){}
};

class Hotel{
public:
	void CommonWashing(){����.CommonWashing();}
	void SpecialWashing(){����.SpecialWashing();}
private:
	Laundry ����;    //member object
};

void main()
{
	Hotel �����Ƶ�;
    �����Ƶ�.CommonWashing();
}
/*����֮�仹�����̫����
�ٽ�Ϊ������server�еķ���������client�ж�����ͬ�Ľӿڣ��Եü������ַ�����
��server�еĳ�Ա���������䶯��clientҲҪ���ű䶯��
*/
