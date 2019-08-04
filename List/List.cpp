#include "List.h"


/*构造*/
template <class T>
List<T> ::List()
{
	head = new ListNode <T>;
	head->next = NULL;
}

template <class T>             //由传入的数组构造链表 
List<T> ::List(T a[], int n)
{
	head = new ListNode <T>;
	ListNode<T>* node = head;
	for (int i = 0; i < n; ++i)
	{
		ListNode<T>* tmp = new ListNode<T>;
		tmp->val = a[i];
		node->next = tmp;
		node = node->next;
	}
	head = head->next;
}

/*析构*/
template <class T>
List<T> :: ~List()
{
	clear();
}

/*清空列表*/
template <class T>
void List<T> ::clear()
{
	while (head != NULL)
	{
		ListNode<T>* tmp = head;
		head = head->next;
		delete tmp;
	}
}

/*打印链表*/
template <class T>
void List<T> ::PrintList()
{
	ListNode<T>* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->val;
		if (tmp->next != NULL)
			cout << " -> ";
		tmp = tmp->next;
	}
	cout << endl;
}

/*是否空表*/
template <class T>
bool List<T> ::isEmpty()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}


/*查找*/
template <class T>
ListNode<T>* List<T> ::Findi(const int i)  //返回第i个元素的指针 
{
	ListNode<T>* tmp = head;
	int count = 1;
	while (tmp != NULL && count < i)
	{
		tmp = tmp->next;
		count++;
	}
	if (i == count)
		return tmp;
	else
		return NULL;
}

template <class T>
ListNode<T>* List<T> ::Findx(const T x)  //返回值为x的元素的指针 
{
	ListNode<T>* tmp = head;
	while (tmp != NULL)
	{
		if (x == tmp->val)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

/*长度*/
template <class T>
int List<T> ::length()   //返回线性表的长度 
{
	int length = 0;
	ListNode<T>* tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		length++;
	}
	return length;
}


/*插入*/
template<class T>
ListNode<T>* List<T> ::Insert(const int p, const T value)
{
	if (p == 1)
	{
		ListNode<T>* node = new ListNode<T>;
		node->val = value;
		node->next = head;
		return node;
	}
	ListNode<T>* node = Findi(p - 1);
	ListNode<T>* tmp = new ListNode<T>;
	tmp->val = value;
	tmp->next = node->next;
	node->next = tmp;
	return head;

}

/*删除*/
template <class T>
ListNode<T>* List<T> ::Delete(const int p)
{
	if (p == 1)
	{
		ListNode<T>* tmp = head;
		head = head->next;
		delete tmp;
		return head;
	}
	ListNode<T>* node = Findi(p - 1);
	ListNode<T>* tmp = node->next;
	node->next = tmp->next;
	delete tmp;
	return head;
}



int main() {

	cout << "初始化链表" << endl;
	cout << "---------------------------------------------------------------" << endl;
	int a[10] = { 1, 2, 3, 6, 5, 4, 2, 9, 6, 3 };
	List<int> list(a, 10);
	list.PrintList();
	while (1)
	{
		cout << "请输入您要进行的操作的序号:" << endl;
		cout << "1:打印全部元素;" << endl;
		cout << "2:查找第i个元素;" << endl;
		cout << "3:查找指定元素;" << endl;
		cout << "4:在第i个位置插入元素;" << endl;
		cout << "5:删除第i个元素;" << endl;
		cout << "6:计算链表的长度;" << endl;
		cout << "7:退出." << endl;
		cout << "---------------------------------------------------------------" << endl;

		int operation;
		cin >> operation;
		if (operation == 7)
			break;
		else if (operation == 1)
		{
			list.PrintList();
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 2)
		{
			int p = -1;
			cout << "请输入您要查询的位置:" << endl;
			cin >> p;
			cout << "第" << p << "个元素为" << list.Findi(p) << endl;
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 3)
		{
			int x = 0;
			cout << "请输入您要查找的值:" << endl;
			cin >> x;
			ListNode<int>* position = list.Findx(x);
			if (position == NULL)
				cout << "查找失败!" << endl;
			else
				cout << x << "的位置为:" << position << endl;
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 4)
		{
			int index = -1;
			int i = 0;
			cout << "请输入插入的位置和插入的数字:" << endl;
			cin >> index;
			cin >> i;
			list.Insert(index, i);
			cout << "插入后的链表为:";
			list.PrintList();
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 5)
		{
			int index = -1;
			cout << "请输入删除的位置:" << endl;
			cin >> index;
			list.Delete(index);
			cout << "删除后的链表为:";
			list.PrintList();
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 6)
		{
			cout << "链表的长度为:" << list.length() << endl;
			cout << "---------------------------------------------------------------" << endl;
		}
	}
}