class point{
private:
	int x,y;
	static int counter;	 
//静态数据成员，相当于类point的全局变量，此处用来计数创建了多少个point类的点对象
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
	   void f()//类point的成员函数可以访问static data member and data member
	   {
		   x++;
		   counter++;
	   }
	   static int pointexisted(); 	   
//静态成员函数，是这个类的全局函数，
//用来访问该类私有的静态数据成员
/* 
	   ~point()
	   {
		   counter--;
	   }
*/
};
