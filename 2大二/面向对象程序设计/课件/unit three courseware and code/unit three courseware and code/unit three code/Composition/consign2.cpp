class Laundry{
private:
public: 
	void CommonWashing(){}
	void SpecialWashing(){}
};

class Hotel{
public:
	void CommonWashing(){象王.CommonWashing();}
	void SpecialWashing(){象王.SpecialWashing();}
private:
	Laundry 象王;    //member object
};

void main()
{
	Hotel 启真大酒店;
    启真大酒店.CommonWashing();
}
/*两者之间还是耦合太紧密
①仅为了重用server中的方法，而在client中定义相同的接口，显得即冗余又繁琐。
②server中的成员函数有所变动，client也要跟着变动。
*/
