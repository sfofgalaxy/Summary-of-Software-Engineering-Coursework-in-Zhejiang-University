class Laundry{
private:
public: 
	void CommonWashing(){}
	void SpecialWashing(){}
};


class Hotel{
public: 
	Hotel()
	{
		delegate = new Laundry;
	} 
	Laundry* operator->()		//���������������
	{		
		return delegate;		
	}
private: 
	Laundry *delegate;
};

void main()
{
	Hotel ��������Ƶ�;
	��������Ƶ�->SpecialWashing(); 
	<==>   (delegate)->SpecialWashing();
}

//��ͨ������-�����������ڿͻ���client�и�д�ӿڵ��鷳�����ҵ���������server�Ľӿڷ����仯ʱ���ͻ���client����Ӱ�졣
//���磬��������server������һ���ӿ�void e();�ͻ���client����c���Ϳ�ֱ��ʹ�ã�c->e()��
//����������ͨ������"->"����ʵ��ת�ͼ�����ί�й��ܡ���Ȼ��Ҳ���Զ����������������ʵ����һ���ܣ�����[]����
//ֻ������"->"��ֱ�ۣ���Ϊ"��"�������ء�


������֮��Ĺ�ϵ��
1)has-a��ϵ(��һ��)
2)is-implemented-in-terms-of(����ĳ��ʵ�ֳ�)
class Head{
private:
        Eye  eye[2];  
		Mouth m;  
		Ear ear[2];  
		Nose n;
};
	           