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
	/*����*/		List();
	List(T a[], int n);
	/*����*/		~List();
	/*����б�*/	void clear();
	/*�Ƿ�ձ�*/	bool isEmpty();
	/*��ӡ����*/ 	void PrintList();

	/*����*/		ListNode<T>* Findi(const int i);   //���ص�i��Ԫ�ص�ָ�� 
	ListNode<T>* Findx(const T x);    //����ֵΪx��Ԫ�ص�ָ�� 
	/*����*/		int length(); //�������Ա�ĳ��� 

	/*����*/		ListNode<T>* Insert(const int p, const T value); //��λ��p����һ��Ԫ��value 
	/*ɾ��*/		ListNode<T>* Delete(const int p);  //ɾ��λ��p�ϵ�Ԫ�� 
};