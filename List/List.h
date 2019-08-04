#pragma once
#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
	T val;
	ListNode* next;
	ListNode(const T x) : val(x), next(NULL) {}
	ListNode(const T x, const ListNode<T>* nextNode = NULL) : val(x), next(nextNode) {}
	ListNode() : val(), next(NULL) {}
};


template <class T>
class List
{
private:
	ListNode<T>* head;

public:
	/*构造*/		List();
	List(T a[], int n);
	/*析构*/		~List();
	/*清空列表*/	void clear();
	/*是否空表*/	bool isEmpty();
	/*打印链表*/ 	void PrintList();

	/*查找*/		ListNode<T>* Findi(const int i);   //返回第i个元素的指针 
	ListNode<T>* Findx(const T x);    //返回值为x的元素的指针 
	/*长度*/		int length(); //返回线性表的长度 

	/*插入*/		ListNode<T>* Insert(const int p, const T value); //在位置p插入一个元素value 
	/*删除*/		ListNode<T>* Delete(const int p);  //删除位置p上的元素 
};