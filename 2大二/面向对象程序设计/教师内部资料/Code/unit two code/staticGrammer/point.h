class point{
private:
	int x,y;
	static int counter;	 
//��̬���ݳ�Ա���൱����point��ȫ�ֱ������˴��������������˶��ٸ�point��ĵ����
public:point(int x1,int y1)
	   {
		   x = x1;
		   y = y1;
		   counter++;
	   }
	   
	   int x_coord()
	   {
		   return x;				          
	   }		
	   int y_coord()
	   {
		   return y;
	   }
	   void f()//��point�ĳ�Ա�������Է���static data member and data member
	   {
		   x++;
		   counter++;
	   }
	   static int pointexisted(); 	   
//��̬��Ա��������������ȫ�ֺ�����
//�������ʸ���˽�еľ�̬���ݳ�Ա
/* 
	   ~point()
	   {
		   counter--;
	   }
*/
};
