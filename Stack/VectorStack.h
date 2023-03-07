#pragma once

#include <vector>
#include <iostream>

template <typename T>
class VStack
{
public:

	//��ȡ����
	int GetLength() const
	{
		return  m_pool.size();
	}

	//ѹջ
	void Push(const T& element)
	{
		m_pool.push_back(element);
	}

	//����ջ
	void Pop()
	{
		if (GetLength() > 0)
		{
			m_pool.pop_back();
		}
	}

	//��ȡ������Ԫ��
	T& GetTopElement()
	{
		return m_pool.back();
	}

	//���ջ
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
				std::cout << *iterate ;
			}
		}
	}

	/** ��ӡ���� */
	void DisplayNum()
	{
		std::cout << "----------------------" << std::endl;
		if (GetLength() < 1)
		{
			std::cout << "��ջΪ��" << std::endl;
		}
		else
		{
			for (auto iterate = m_pool.begin(); iterate != m_pool.end(); ++iterate)
			{
				std::cout << *iterate;
			}
		}
	}

private:
	std::vector<T> m_pool;
};