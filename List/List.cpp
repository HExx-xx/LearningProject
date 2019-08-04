#include "List.h"


/*����*/
template <class T>
List<T> ::List()
{
	head = new ListNode <T>;
	head->next = NULL;
}

template <class T>             //�ɴ�������鹹������ 
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

/*����*/
template <class T>
List<T> :: ~List()
{
	clear();
}

/*����б�*/
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

/*��ӡ����*/
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

/*�Ƿ�ձ�*/
template <class T>
bool List<T> ::isEmpty()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}


/*����*/
template <class T>
ListNode<T>* List<T> ::Findi(const int i)  //���ص�i��Ԫ�ص�ָ�� 
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
ListNode<T>* List<T> ::Findx(const T x)  //����ֵΪx��Ԫ�ص�ָ�� 
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

/*����*/
template <class T>
int List<T> ::length()   //�������Ա�ĳ��� 
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


/*����*/
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

/*ɾ��*/
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

	cout << "��ʼ������" << endl;
	cout << "---------------------------------------------------------------" << endl;
	int a[10] = { 1, 2, 3, 6, 5, 4, 2, 9, 6, 3 };
	List<int> list(a, 10);
	list.PrintList();
	while (1)
	{
		cout << "��������Ҫ���еĲ��������:" << endl;
		cout << "1:��ӡȫ��Ԫ��;" << endl;
		cout << "2:���ҵ�i��Ԫ��;" << endl;
		cout << "3:����ָ��Ԫ��;" << endl;
		cout << "4:�ڵ�i��λ�ò���Ԫ��;" << endl;
		cout << "5:ɾ����i��Ԫ��;" << endl;
		cout << "6:��������ĳ���;" << endl;
		cout << "7:�˳�." << endl;
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
			cout << "��������Ҫ��ѯ��λ��:" << endl;
			cin >> p;
			cout << "��" << p << "��Ԫ��Ϊ" << list.Findi(p) << endl;
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 3)
		{
			int x = 0;
			cout << "��������Ҫ���ҵ�ֵ:" << endl;
			cin >> x;
			ListNode<int>* position = list.Findx(x);
			if (position == NULL)
				cout << "����ʧ��!" << endl;
			else
				cout << x << "��λ��Ϊ:" << position << endl;
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 4)
		{
			int index = -1;
			int i = 0;
			cout << "����������λ�úͲ��������:" << endl;
			cin >> index;
			cin >> i;
			list.Insert(index, i);
			cout << "����������Ϊ:";
			list.PrintList();
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 5)
		{
			int index = -1;
			cout << "������ɾ����λ��:" << endl;
			cin >> index;
			list.Delete(index);
			cout << "ɾ���������Ϊ:";
			list.PrintList();
			cout << "---------------------------------------------------------------" << endl;
		}
		else if (operation == 6)
		{
			cout << "����ĳ���Ϊ:" << list.length() << endl;
			cout << "---------------------------------------------------------------" << endl;
		}
	}
}