#pragma once
#include <iostream>

/** 双向循环链表（doubly circular linked list） */

template <typename T>
class DCLLNode
{
public:
	DCLLNode(const T& info, DCLLNode* pre = nullptr, DCLLNode* next = nullptr)
		:m_info(info), m_pre(pre), m_next(next)
	{
	}

	T m_info;
	DCLLNode* m_pre;
	DCLLNode* m_next;
};

template <typename T>
class DCLList
{
public:
	DCLList()
	{
		m_first = nullptr;
	}

	void InsertToHead(const T& info)
	{
		if (m_first == nullptr)
		{
			m_first = new DCLLNode<T>(info);
			m_first->m_pre = m_first;
			m_first->m_next = m_first;
		}
		else 
		{
			m_first = new DCLLNode<T>(info, m_first->m_pre, m_first);
			m_first->m_next->m_pre = m_first;
			m_first->m_pre->m_next = m_first;
		}
	}

	void InsertToTail(const T& info)
	{
		if (m_first == nullptr)
		{
			m_first == new DCLLNode<T>(info);
			m_first->m_pre = m_first;
			m_first->m_next = m_first;
		}
		else
		{
			DCLLNode<T>* tempNode = new DCLLNode<T>(info);
			tempNode->m_pre = m_first->m_pre;
			tempNode->m_next = m_first;
			m_first->m_pre->m_next = tempNode;
			m_first->m_pre = tempNode;
		}
	}

	T RemoveFromHead()
	{
		T retInfo = NULL;
		if (m_first != nullptr)
		{
			retInfo = m_first->m_info;
			if (m_first == m_first->m_next)
			{
				delete m_first;
				m_first = nullptr;
			}
			else
			{
				DCLLNode<T>* tempNode = m_first;
				m_first->m_pre->m_next = m_first->m_next;
				m_first->m_next->m_pre = m_first->m_pre;
				m_first = m_first->m_next;
				delete tempNode;
				tempNode = nullptr;
			}
		}
		return retInfo;
	}

	T RemoveFromEnd()
	{
		T retInfo = NULL;
		if (m_first != nullptr)
		{
			if (m_first == m_first->m_next)
			{
				retInfo = m_first->m_info;
				delete m_first;
				m_first = nullptr;
			}
			else
			{
				retInfo = m_first->m_pre->m_info;
				DCLLNode<T>* tempNode = m_first->m_pre;

				m_first->m_pre->m_next = m_first;
				m_first->m_pre = m_first->m_pre->m_pre;
				delete tempNode;
			}
		}

		return  retInfo;
	}

	T RemoveNode(const T& info)
	{
		T retNode = NULL;

		DCLLNode<T>* fNode = Find(info);
		if (fNode != nullptr)
		{
			retNode = fNode->m_info;
			if (m_first == m_first->m_pre)
			{
				delete m_first;
				m_first = nullptr;
			}
			else
			{
				fNode->m_pre->m_next = fNode->m_next;
				fNode->m_next->m_pre = fNode->m_pre;
				delete fNode;
			}
		}

		return retNode;
	}

	DCLLNode<T>* Find(const T& info, bool bReverse = false)
	{

		if (m_first != nullptr)
		{
			DCLLNode<T>* tempNode = m_first;
			if (!bReverse)
			{
				do
				{
					if (tempNode->m_info == info)
					{
						return tempNode;
					}
					tempNode = tempNode->m_next;
				}
				while (tempNode != m_first);

			}
			else
			{
				tempNode = m_first->m_pre;
				do
				{
					if (tempNode->m_info == info)
					{
						return tempNode;
					}
					tempNode = tempNode->m_pre;
				}
				while (tempNode != m_first->m_pre);
			}
		}

		return nullptr;
	}

	void DisplayList(bool bRerverse = false)
	{
		std::cout << "------------------------" << std::endl;
		if (m_first == nullptr)
		{
			std::cout << "该链表中暂时没有元素" << std::endl;
		}
		else
		{
			if (!bRerverse)
			{
				DCLLNode<T>* tempNode = m_first;
				do
				{
					std::cout << tempNode->m_info << std::endl;
					tempNode = tempNode->m_next;
				} while (tempNode != m_first);
			}
			else
			{
				DCLLNode<T>* tempNode = m_first->m_pre;
				do
				{
					std::cout << tempNode->m_info << std::endl;
					tempNode = tempNode->m_pre;
				} while (tempNode != m_first->m_pre);
			}
		}
	}

public:
	DCLLNode<T>* m_first;
};