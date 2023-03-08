#pragma once
#include <iostream>
#include <string.h>
/** 使用数组实现队列 */

/** 先进显出  FIFO */
template <typename T, int Size = 100>
class AQueue
{
public:
	AQueue()
	{
		m_firstIndex = -1;
		m_endIndex = -1;
		m_size = 0;
		memset(m_stroge, 0, sizeof(m_stroge));
	}

	/** 清空 */
	void Clear()
	{
		memset(m_stroge, 0, sizeof(T) * Size);
		m_firstIndex = -1;
		m_endIndex = -1;
		m_size = 0;
	}

	/** 入队列，入到队尾 */
	void EnQueue(const T& element)
	{
		if (!IsFull())
		{
			m_endIndex += 1;
			if (m_endIndex >= Size)
			{
				m_endIndex = 0;
			}

			m_stroge[m_endIndex] = element;
			m_size += 1;

			if (m_size == 1)
			{
				m_firstIndex = m_endIndex;
			}
		}
	}

	/** 出队列 */
	T DeQueue()
	{
		T retValue = NULL;
		if (m_size > 0)
		{
			retValue = m_stroge[m_firstIndex];
			m_firstIndex += 1;
			if (m_firstIndex >= Size)
			{
				m_firstIndex = 0;
			}

			m_size--;

			//如果其中没有元素的话 就要清空
			if (m_size == 0)
			{
				m_firstIndex = -1;
				m_endIndex = -1;
			}
		}

		return  retValue;
	} 

	/** 获取队列头的元素 */
	T& FirstElement()
	{
		T retValue = NULL;
		if (m_size > 0)
		{
			retValue = m_stroge[m_firstIndex];
		}

		return retValue;
	}

	/** 获取队列元素的个数 */
	int GetSize() const
	{
		return  m_size;
	}

	/** 队列是否满员 */
	bool IsFull() const
	{	
		return m_size == Size;
	}

	void Display()
	{
		std::cout << "-----------------" << std::endl;
		if (m_size > 0)
		{

			int tempIndex = m_firstIndex;
			while (tempIndex != m_endIndex)
			{

				std::cout << m_stroge[tempIndex] << std::endl;
				tempIndex += 1;
				if (tempIndex >= Size)
				{
					tempIndex = 0;
				}
			}
			std::cout << m_stroge[m_endIndex] << std::endl;

		}
		else
		{
			std::cout << "该队列为空" << std::endl;
		}

		std::cout << "sizeof = " << sizeof(m_stroge) << "=" << sizeof(T) * Size << std::endl;
	}

	void DisplayAll()
	{
		std::cout << "display all -------------" << std::endl;

		for (int i = 0; i < Size; ++i)
		{
			std::cout << m_stroge[i];
		}
	}

public:
	/** 队列头的Index */
	int m_firstIndex;

	/** 队列尾的index */
	int m_endIndex;

	/** 队列元素的长度 */
	int m_size;

	//队列元素（最多存储Size个元素）
	T m_stroge[Size];
};