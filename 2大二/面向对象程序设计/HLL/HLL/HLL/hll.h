#pragma once
#include<string>  
#include<iostream>
#include<cstdio>
using namespace std;

class Node													//基类
{
public:
	Node() {}
	virtual ~Node() {}										//虚析构函数
	Node *&next() { return Next; }							//获取下一个指针
	virtual void print() const = 0;							//纯虚函数打印节点
	virtual void union_other(Node *&a) const = 0;				//纯虚函数合并链表
private:
	Node *Next;												//指向下一节点
};

class IntNode :public Node									//整数继承类节点
{
private:
	int Int_value;											
public:
	IntNode(int a);											
	~IntNode() {}											
	virtual void union_other(Node *&a) const;				
	virtual void print() const;								
};

class StringNode :public Node								//字符串继承类
{
private:
	char *Char_value;											
public:
	StringNode(const char *a);									
	~StringNode();											
	virtual void union_other(Node *&a) const;				
	virtual void print() const;								
};

class DoubleNode :public Node								//双精度浮点数继承类
{
private:
	double Double_value;									
public:
	DoubleNode(double a);									
	~DoubleNode() {}										
	virtual void union_other(Node *&a) const;					
	virtual void print() const;								
};

//链表类
class HLL {
public:
	Node *Head;
	Node *Tail;
	int Length;
	HLL();
	~HLL();
	void print()const; //打印所有节点
	Node * get_head(); //返回链表的头指针
	Node * get_tail(); //返回链表的尾指针
	Node * operator [](int index); //使用[]控制链接列表index是要操作的节点的位置
	const int length()const; //返回链表的长度
	void insert_head(int a); //将IntNode插入链表的前面
	void insert_head(double a); //将DoubleNode插入链表的前面
	void insert_head(const char * a); //将StringNode插入链接列表的前面
	void insert_tail(int a); //将IntNode插入链表的后面
	void insert_tail(double a); //将DoubleNode插入链表的后面
	void insert_tail(const char * a); //将StringNode插入链表的后面
	void delete_head(); //删除链表的头节点
	void delete_tail(); //删除链表的尾节点
	void reverse(); //反转链表
	void destory(); //销毁链表
	void union_other(const HLL& a); //合并链表
};