#pragma once
#include<string>  
#include<iostream>
#include<cstdio>
using namespace std;

class Node													//����
{
public:
	Node() {}
	virtual ~Node() {}										//����������
	Node *&next() { return Next; }							//��ȡ��һ��ָ��
	virtual void print() const = 0;							//���麯����ӡ�ڵ�
	virtual void union_other(Node *&a) const = 0;				//���麯���ϲ�����
private:
	Node *Next;												//ָ����һ�ڵ�
};

class IntNode :public Node									//�����̳���ڵ�
{
private:
	int Int_value;											
public:
	IntNode(int a);											
	~IntNode() {}											
	virtual void union_other(Node *&a) const;				
	virtual void print() const;								
};

class StringNode :public Node								//�ַ����̳���
{
private:
	char *Char_value;											
public:
	StringNode(const char *a);									
	~StringNode();											
	virtual void union_other(Node *&a) const;				
	virtual void print() const;								
};

class DoubleNode :public Node								//˫���ȸ������̳���
{
private:
	double Double_value;									
public:
	DoubleNode(double a);									
	~DoubleNode() {}										
	virtual void union_other(Node *&a) const;					
	virtual void print() const;								
};

//������
class HLL {
public:
	Node *Head;
	Node *Tail;
	int Length;
	HLL();
	~HLL();
	void print()const; //��ӡ���нڵ�
	Node * get_head(); //���������ͷָ��
	Node * get_tail(); //���������βָ��
	Node * operator [](int index); //ʹ��[]���������б�index��Ҫ�����Ľڵ��λ��
	const int length()const; //��������ĳ���
	void insert_head(int a); //��IntNode���������ǰ��
	void insert_head(double a); //��DoubleNode���������ǰ��
	void insert_head(const char * a); //��StringNode���������б��ǰ��
	void insert_tail(int a); //��IntNode��������ĺ���
	void insert_tail(double a); //��DoubleNode��������ĺ���
	void insert_tail(const char * a); //��StringNode��������ĺ���
	void delete_head(); //ɾ�������ͷ�ڵ�
	void delete_tail(); //ɾ�������β�ڵ�
	void reverse(); //��ת����
	void destory(); //��������
	void union_other(const HLL& a); //�ϲ�����
};