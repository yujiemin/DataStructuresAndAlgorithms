#pragma once

#include <iostream>
#include <list>

template <typename T>
class LQueue
{
public:
	/** 构造函数 */
	LQueue() = default;

	/** 清空 */
	void Clear()
	{
		m_stroge.clear();
	}

	/** 入队列 */
	void EnQueue(const T& element)
	{
		m_stroge.push_back(element);
	}

	/** 出队列 */
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

	/** 获取第一个元素 */
	T& GetFrontElement()
	{
		return m_stroge.front();
	}

	/** 获取队列中元素的大小 */
	int GetSize() const
	{
		return m_stroge.size();
	}

	/** 打印 */
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