#pragma once

#include <iostream>
#include <list>

template <typename T>
class LQueue
{
public:
	/** ���캯�� */
	LQueue() = default;

	/** ��� */
	void Clear()
	{
		m_stroge.clear();
	}

	/** ����� */
	void EnQueue(const T& element)
	{
		m_stroge.push_back(element);
	}

	/** ������ */
	T DeQueue()
	{
		if (!m_stroge.empty())
		{
			T& retValue = m_stroge.front();
			m_stroge.pop_front();

			return  retValue;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
		}
		return NULL;
	}

	/** ��ȡ��һ��Ԫ�� */
	T& GetFrontElement()
	{
		return m_stroge.front();
	}

	/** ��ȡ������Ԫ�صĴ�С */
	int GetSize() const
	{
		return m_stroge.size();
	}

	/** ��ӡ */
	void Display()
	{
		std::cout << "----------------------" << std::endl;

		for (auto iterate = m_stroge.begin(); iterate != m_stroge.end(); ++iterate)
		{
			std::cout << *iterate << std::endl;
		}
	}

private:
	std::list<T> m_stroge;
};