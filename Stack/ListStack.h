#pragma once

#include <list>
#include <iostream>

template <typename T>
class LStack
{
public:
	/** 获取长度 */
	int GetLength() const
	{
		return m_pool.size();
	}

	/** 压栈 */
	void Push(const T& element)
	{
		m_pool.push_back(element);
	}

	/** 出栈 */
	void Pop()
	{
		m_pool.pop_back();
	}

	/** 获取栈顶元素 */
	T& GetTopElement()
	{
		return m_pool.back();
	}

	/** 清空 */
	void Clear()
	{
		m_pool.clear();
	}

	/** 打印 */
	void Display()
	{
		std::cout << "----------------------" << std::endl;
		if (GetLength() < 1)
		{
			std::cout << "该栈为空" << std::endl;
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
