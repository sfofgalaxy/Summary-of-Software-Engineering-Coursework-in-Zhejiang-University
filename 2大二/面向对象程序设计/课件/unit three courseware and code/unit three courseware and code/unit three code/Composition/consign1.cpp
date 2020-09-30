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
	Hotel 启真大酒店("象王");
    启真大酒店.partner.CommonWashing();
}

问题： 客户端与服务器端耦合太紧密，程序员在使用客户端类的同时必须非常了解服务器类
//组合对象缺少了组件对象就不能正常发挥其功能
//解决方法：改变嵌入对象的访问权限private（更具一般性），对用户来讲，使服务器端的功能变成客户端的
