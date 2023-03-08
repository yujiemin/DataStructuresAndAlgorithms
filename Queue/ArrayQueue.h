#pragma once
#include <iostream>
#include <string.h>
/** ʹ������ʵ�ֶ��� */

/** �Ƚ��Գ�  FIFO */
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

	/** ��� */
	void Clear()
	{
		memset(m_stroge, 0, sizeof(T) * Size);
		m_firstIndex = -1;
		m_endIndex = -1;
		m_size = 0;
	}

	/** ����У��뵽��β */
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

	/** ������ */
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

			//�������û��Ԫ�صĻ� ��Ҫ���
			if (m_size == 0)
			{
				m_firstIndex = -1;
				m_endIndex = -1;
			}
		}

		return  retValue;
	} 

	/** ��ȡ����ͷ��Ԫ�� */
	T& FirstElement()
	{
		T retValue = NULL;
		if (m_size > 0)
		{
			retValue = m_stroge[m_firstIndex];
		}

		return retValue;
	}

	/** ��ȡ����Ԫ�صĸ��� */
	int GetSize() const
	{
		return  m_size;
	}

	/** �����Ƿ���Ա */
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
			std::cout << "�ö���Ϊ��" << std::endl;
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
	/** ����ͷ��Index */
	int m_firstIndex;

	/** ����β��index */
	int m_endIndex;

	/** ����Ԫ�صĳ��� */
	int m_size;

	//����Ԫ�أ����洢Size��Ԫ�أ�
	T m_stroge[Size];
};