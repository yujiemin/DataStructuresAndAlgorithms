#pragma once

#include <vector>
#include <iostream>

template <typename T>
class VStack
{
public:

	//获取长度
	int GetLength() const
	{
		return  m_pool.size();
	}

	//压栈
	void Push(const T& element)
	{
		m_pool.push_back(element);
	}

	//弹出栈
	void Pop()
	{
		if (GetLength() > 0)
		{
			m_pool.pop_back();
		}
	}

	//获取顶部的元素
	T& GetTopElement()
	{
		return m_pool.back();
	}

	//清空栈
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
				std::cout << *iterate ;
			}
		}
	}

	/** 打印数字 */
	void DisplayNum()
	{
		std::cout << "----------------------" << std::endl;
		if (GetLength() < 1)
		{
			std::cout << "该栈为空" << std::endl;
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