#pragma once

/** 线索树：中序的实现 */

template <typename T>
class ThreadedNode
{
public:
	ThreadedNode(const T& element)
		:m_element(element), m_left(nullptr), m_right(nullptr)
	{
		bSuccessor = false;
	}

	ThreadedNode(const T& element, ThreadedNode<T>* left, ThreadedNode<T>* right)
		:m_element(element), m_left(left), m_right(right)
	{
		bSuccessor = false;
	}

private:

	/** 元素 */
	T m_element;

	/** 左节点 */
	ThreadedNode<T>* m_left;

	/** 右节点 */
	ThreadedNode<T>* m_right;

	unsigned int bSuccessor : 1;
};


template <typename T>
class ThreadedTree
{
public:
	ThreadedTree()
	{
		m_root = nullptr;
	}

	void Clear()
	{
		Clear(m_root);
		m_root = nullptr;
	}

	~ThreadedTree()
	{
		Clear();
	}

	/** 插入 */
	void Insert(const T& element);
	
protected:
	void Clear(ThreadedNode<T>* node);

private:
	ThreadedNode<T>* m_root;
};

template <typename T>
void ThreadedTree<T>::Insert(const T& element)
{
	if (m_root = nullptr)
	{
		m_root = new ThreadedNode<T>(element);
		return;
	}

	ThreadedNode<T>* newNode = new ThreadedNode<T>(element);
	ThreadedNode<T>* node = m_root;
	ThreadedNode<T>* prev = nullptr;

	while (node != nullptr)
	{
		prev = node;
		if (element < node->m_element)
		{
			node = node->m_left;
		}
		else if (node->bSuccessor == true)
		{
			node = node->m_right;
		}
		else
		{
			break;
		}
	}

	if (element < prev->m_element)
	{
		newNode->bSuccessor = true;
		prev->m_left = newNode;
		newNode->m_left = prev;
	}
	else if (prev->bSuccessor)
	{
		newNode->bSuccessor = true;
		newNode->m_right = prev->m_right;
		prev->m_right = newNode;
		prev->bSuccessor = false; //已经填满了 所以置为空
	}
	else
	{
		prev->m_right = newNode;
	}
}

template <typename T>
void ThreadedTree<T>::Clear(ThreadedNode<T>* node)
{
	if (node != nullptr)
	{
		Clear(node->m_left);
		if (node->bSuccessor == false)
			Clear(node->m_right);

		delete node;
	}
}




