#pragma once

#include <list>
#include <iostream>

template <typename T>
class LStack
{
public:
	/** ��ȡ���� */
	int GetLength() const
	{
		return m_pool.size();
	}

	/** ѹջ */
	void Push(const T& element)
	{
		m_pool.push_back(element);
	}

	/** ��ջ */
	void Pop()
	{
		m_pool.pop_back();
	}

	/** ��ȡջ��Ԫ�� */
	T& GetTopElement()
	{
		return m_pool.back();
	}

	/** ��� */
	void Clear()
	{
		m_pool.clear();
	}

	/** ��ӡ */
	void Display()
	{
		std::cout << "----------------------" << std::endl;
		if (GetLength() < 1)
		{
			std::cout << "��ջΪ��" << std::endl;
		}
		else
		{
			for (auto iterate = m_pool.rbegin(); iterate != m_pool.rend(); ++iterate)
			{
				std::cout << *iterate << std::endl;
			}
		}

	}

private:
	std::list<T> m_pool;
};
