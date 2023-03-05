#pragma once
/** ��������ʵ�� */

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

	//��ͷ������
	void InsertToHead(T inInfo)
	{
		//�����ķ�ʽ
		m_head = new  SLLNode<T>(inInfo, m_head);
		if (m_tail == nullptr)
		{
			m_tail = m_head;
		}
	}

	//��β������
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
			m_tail = newNode; //��β�������Ҫ�ı�β����ֵ
		}
	}

	//��ͷ��ɾ��
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

	//��β��ɾ��
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

	//ɾ��
	void RemoveNode(T inInfo)
	{
		if (m_head != nullptr)	//û��Ԫ��
		{
			if (m_head == m_tail && m_head->info == inInfo)   //ֻ��һ��Ԫ��
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
			else//���ڵ�������Ԫ��
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

			//��߼ǵ�Ҫ���¸ı�headָ��
			m_head = pre;
		}
	}

	//����
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

	//�Ƿ�Ϊ��
	bool isEmpty() const
	{
		return m_head == nullptr;
	}

	//��ӡ����
	void DisplayList(const std::string& inName = "")
	{
		std::cout << inName << "--------------------------" << std::endl;

		if (m_head == nullptr)
		{
			std::cout << "��ǰԪ��Ϊ��" << std::endl;
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
	//ͷ��
	SLLNode<T>* m_head;

	//β��
	SLLNode<T>* m_tail;
};