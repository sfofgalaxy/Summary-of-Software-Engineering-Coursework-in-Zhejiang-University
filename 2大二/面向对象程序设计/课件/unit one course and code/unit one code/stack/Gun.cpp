/* *
 * @copyright 2012-2013, Zhejiang University
 * @file   gun.cpp
 * @brief  实现子弹压膛和射击操作
 *
 * 版本历史：   
 * @Verson  0.1 @date 2011-02-17   hlq：新建文件
 * @Verson  0.2 @date 2012-08-11   hlq：修改了......
 *     
*/
#include <iostream>
using namespace std;

#define max_size 100  //弹匣长度
char v[max_size];	//全局变量，用数组表示弹匣，用字符表示子弹
char *p = v;		   //弹匣顶部

/**
* @brief   功能 : 子弹压膛 
* @param [in]  输入参数ch :  char表示子弹
* @return      void
* @exception   如果弹匣已满，程序终止运行。
*/
void push(char ch)	//function define
{
	if (p-v >= max_size)
	{
		cout << "弹匣已满！" << endl;
		exit(1);
	}
	*p++ = ch;//*与++优先级相同，右结合
}

/**
* @brief   功能 : 射击操作 
* @return      返回值字符。
* @exception   如果弹匣为空，则程序终止运行
*/
char pop()
{
	if (p == v)
	{
		cout << "已经没有子弹！" << endl;
		exit(1);
	}
	return *--p;
}