#pragma once
#include <cstddef>

/** 双向链表 */

template <typename T>
class DLLNode
{
public:

	DLLNode(const T& info, DLLNode* pre = nullptr, DLLNode* next = nullptr)
		:m_info(info), m_pre(pre), m_next(next)
	{
	}


	T m_info;
	DLLNode* m_pre;
	DLLNode* m_next;
};

template <typename T>
class DLList
{
public:
	DLList()
	{
		m_head = nullptr;
		m_tail = nullptr;
	}

	void InsertToHead(const T& info)
	{
		if (m_head == nullptr )
		{
			m_head = m_tail = new DLLNode<T>(info);
		}
		else if (m_head == m_tail)
		{
			m_head = new DLLNode<T>(info, nullptr, m_head);
			m_tail->m_pre = m_head;
		}
		else
		{
			DLLNode<T>* tempNode = m_head;
			m_head = new DLLNode<T>(info, nullptr, m_head);
			tempNode->m_pre = m_head;
		}
	}

	void InsertToTail(const T& info)
	{
		if (m_tail == nullptr)
		{
			m_head = m_tail = new DLLNode<T>(info);
		}
		else if (m_tail == m_head)
		{
			m_tail = new DLLNode<T>(info, m_tail, nullptr);
			m_head->m_next = m_tail;
		}
		else
		{
			DLLNode<T>* tempNode = m_tail;
			m_tail = new DLLNode<T>(info, m_tail, nullptr);
			tempNode->m_next = m_tail;
		}
	}

	T RemoveFromHead()
	{
		T retInfo = NULL;
		if (m_head != nullptr)
		{
			retInfo = m_head->m_info;
			if (m_head == m_tail)
			{
				delete m_head;
				m_head = m_tail = nullptr;
			}
			else
			{
				m_head = m_head->m_next;
				delete m_head->m_pre;
				m_head->m_pre = nullptr;
			}
		}
		
		return retInfo;
	}

	T RemoveFromTail()
	{
		T retInfo = NULL;
		if (m_tail != nullptr)
		{
			retInfo = m_tail->m_info;
			if (m_tail == m_head)
			{
				delete m_tail;
				m_head = m_tail = nullptr;
			}
			else
			{
				m_tail = m_tail->m_pre;
				delete m_tail->m_next;
				m_tail->m_next = nullptr;
			}
		}

		return retInfo;
	}

	T RemoveNode(const T& info, bool bReverse = false)
	{

		T retInfo = NULL;
		if (m_head != nullptr)
		{
			if (m_head == m_tail && m_head->m_info == info)
			{
				retInfo = m_head->m_info;
				delete m_head;
				m_head = m_tail = nullptr;
			}
			else if (m_head->m_info == info)
			{
				retInfo = m_head->m_info;
				DLLNode<T>* tempNode = m_head->m_next;
				delete m_head;
				m_head = tempNode;
				m_head->m_pre = nullptr;
			}
			else if (m_tail->m_info == info)
			{
				retInfo = m_tail->m_info;
				DLLNode<T>* tempNode = m_tail->m_pre;
				delete m_tail;
				m_tail = tempNode;
				m_tail->m_next = nullptr;
			}
			else
			{
				DLLNode<T>* tempNode = Find(info, bReverse);
				if (tempNode != nullptr)
				{
					retInfo = tempNode->m_info;
					
					tempNode->m_pre->m_next = tempNode->m_next;
					tempNode->m_next->m_pre = tempNode->m_pre;
					delete tempNode;
					tempNode = nullptr;
				}
			}
		}

		return retInfo;
	}

	/**
	 * \brief 查找
	 * \param info 要查找的信息
	 * \param bReverse 是否从后往前查找
	 * \return 返回查找的节点
	 */
	DLLNode<T>* Find(const T& info, bool bReverse = false)
	{
		if (!bReverse)
		{
			for (DLLNode<T>* tempNode = m_head; tempNode != nullptr; tempNode = tempNode->m_next)
			{
				if (tempNode->m_info == info)
				{
					return tempNode;
				}
			}
		}
		else
		{
			for (DLLNode<T>* retNode = m_tail; retNode != nullptr; retNode = retNode->m_pre)
			{
				if (retNode->m_info == info)
				{
					return retNode;
				}
			}
		}

		return nullptr;
	}


	/**
	 * \brief  打印链表
	 * \param bRerverse 是否从后往前打印
	 */
	void DisplayList(bool bRerverse = false)
	{
		std::cout << "--------------------" << std::endl;
		if (!bRerverse)
		{
			DLLNode<T>* tempNode = m_head;
			while (tempNode != nullptr)
			{
				std::cout << tempNode->m_info << std::endl;
				tempNode = tempNode->m_next;
			}
		}
		else
		{
			DLLNode<T>* tempNode = m_tail;
			while (tempNode != nullptr)
			{
				std::cout << tempNode->m_info << std::endl;
				tempNode = tempNode->m_pre;
			}
		}
	}

private:

	DLLNode<T>* m_head;

	DLLNode<T>* m_tail;
};