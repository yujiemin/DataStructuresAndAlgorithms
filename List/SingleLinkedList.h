#pragma once
/** 单向链表实现 */

#include <cassert>
#include <iostream>

template <typename T>
class SLLNode
{
public:
	SLLNode()
	{
		info = 0;
		next = nullptr;
	}

	SLLNode(T inInfo, SLLNode* inNext = nullptr)
	{
		info = inInfo;
		next = inNext;

	}

	T info;
	SLLNode* next;
};

template <typename T>
class SLList
{
public:
	SLList()
	{
		m_head = nullptr;
		m_tail = nullptr;
	}

	~SLList()
	{
		SLLNode<T>* tempNode = nullptr;
		while (m_head != nullptr)
		{
			tempNode = m_head->next;
			delete m_head;
			m_head = tempNode;
		}
		m_head = m_tail = nullptr;
	}

	//从头部插入
	void InsertToHead(T inInfo)
	{
		//更简洁的方式
		m_head = new  SLLNode<T>(inInfo, m_head);
		if (m_tail == nullptr)
		{
			m_tail = m_head;
		}
	}

	//从尾部插入
	void InSertToTail(T inInfo)
	{
		if (m_head == nullptr)
		{
			m_head = new SLLNode<T>(inInfo);
			m_tail = m_head;
		}
		else
		{
			SLLNode<T>* newNode = new SLLNode<T>(inInfo);
			m_tail->next = newNode;
			m_tail = newNode; //从尾部插入就要改变尾部的值
		}
	}

	//从头部删除
	T RemoveFromHead()
	{
		assert(m_head != nullptr);

		SLLNode<T>* tempNode = m_head->next;
		delete m_head;
		m_head = tempNode;

		if (m_head == nullptr)
		{
			m_head = m_tail = nullptr;
		}

		return tempNode->info;
	}

	//从尾部删除
	T RemoveFromTail()
	{

		assert(m_head != nullptr);
		T retValue = m_tail->info;

		if (m_head == m_tail)
		{
			delete m_tail;
			m_head = m_tail = nullptr;
		}
		else
		{
			SLLNode<T>* tempNode = m_head;
			for (;tempNode->next != m_tail; tempNode = tempNode->next);
			delete m_tail;
			m_tail = tempNode;
		}

		return retValue;
	}

	//删除
	void RemoveNode(T inInfo)
	{
		if (m_head != nullptr)	//没有元素
		{
			if (m_head == m_tail && m_head->info == inInfo)   //只有一个元素
			{
				delete m_head;
				m_head = m_tail = nullptr;
			}
			else if (m_head->info == inInfo)
			{
				SLLNode<T>* tempNode = m_head;
				m_head = m_head->next;
				delete tempNode;
			}
			else//大于等于两个元素
			{
				SLLNode<T>* tempNode = m_head;
				for (; tempNode != nullptr && tempNode->next != nullptr; tempNode = tempNode->next)
				{
					if (tempNode->next->info == inInfo)
					{
						tempNode->next = tempNode->next->next;
						delete tempNode->next;
						break;
					}
				}
			}
		}
	}

	void ReverList()
	{
		if (m_head != nullptr && m_head != m_tail)
		{
			SLLNode<T>* current = m_head;
			SLLNode<T>* next = nullptr;
			SLLNode<T>* pre = nullptr;

			while (current != nullptr)
			{
				next = current->next;
				current->next = pre;
				pre = current;
				current = next;
			}

			//这边记得要重新改变head指向
			m_head = pre;
		}
	}

	//查找
	SLLNode<T>* Find(T inInfo)
	{
		for (SLLNode<T>* tempNode = m_head; tempNode != nullptr; tempNode = tempNode->next)
		{
			if (tempNode->info == inInfo)
			{
				return tempNode;
			}
		}
		return nullptr;
	}

	//是否为空
	bool isEmpty() const
	{
		return m_head == nullptr;
	}

	//打印链表
	void DisplayList(const std::string& inName = "")
	{
		std::cout << inName << "--------------------------" << std::endl;

		if (m_head == nullptr)
		{
			std::cout << "当前元素为空" << std::endl;
		}
		else
		{
			SLLNode<T>* tempNode = m_head;
			while (tempNode != nullptr)
			{
				std::cout << tempNode->info << std::endl;
				tempNode = tempNode->next;
			}
		}
	}

private:
	//头部
	SLLNode<T>* m_head;

	//尾部
	SLLNode<T>* m_tail;
};