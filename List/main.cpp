#include "SingleLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include <list>

using namespace std;

/** 单向链表 测试 */
int main1()
{
	SLList<int> sllList;
	sllList.DisplayList("空");
	sllList.InsertToHead(1);
	sllList.InSertToTail(2);
	sllList.RemoveFromHead();
	sllList.RemoveFromTail();
	sllList.InSertToTail(3);
	sllList.InSertToTail(3);
	sllList.InSertToTail(10);
	sllList.InSertToTail(15);
	sllList.DisplayList("插入和删除");
	sllList.RemoveNode(15);
	sllList.RemoveNode(3);
	sllList.DisplayList("根据元素删除");
	sllList.ReverList();
	sllList.DisplayList("反转");

	SLLNode<int>* findNode = sllList.Find(3);
	if (findNode != nullptr)
	{
		findNode->info = 100;
	}
	sllList.DisplayList("寻找元素");
	return 0;
}

/** 双向链表测试 */
int main2()
{
	DLList<int> dllList;
	dllList.InsertToHead(0);
	dllList.InsertToHead(1);
	dllList.InsertToTail(2);
	dllList.InsertToTail(3);
	dllList.DisplayList(true);
	dllList.RemoveNode(2);
	dllList.RemoveNode(3);
	dllList.DisplayList();

	DLLNode<int> *fNode = dllList.Find(0);
	if (fNode != nullptr)
	{
		fNode->m_info = 100;
		dllList.DisplayList();
	}
	
	return 0;
}

/** 双向循环链表 */
int main()
{
	DCLList<int> dclList;
	dclList.InsertToHead(0);
	dclList.InsertToHead(1);
	dclList.InsertToHead(2);
	dclList.InsertToHead(3);
	dclList.InsertToHead(4);
	dclList.DisplayList();
	dclList.RemoveFromHead();
	dclList.RemoveFromHead();
	dclList.RemoveFromHead();
	dclList.RemoveFromHead();
	dclList.RemoveNode(0);

	dclList.DisplayList();

	struct my_struct
	{
	public:
		int m_info;
	};

	list<my_struct> myList;
	my_struct m1;
	myList.push_back(m1);

	myList.push_back(m1);



	return 0;
}