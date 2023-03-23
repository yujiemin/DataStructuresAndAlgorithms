#pragma once

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/** BinaryTree ������ */  //�ݹ� ���ջ��ԭ��

template <typename T>
class Queue: public queue<T>
{
public:
	T Dequeue()
	{
		T temp = this->front();
		this->pop();
		return temp;
	}

	void Enqueue(T element)
	{
		this->push(element);
	}
};

template <typename T>
class Stack: public stack<T>
{
public:
	void Push(const T& element)
	{
		this->push(element);
	}

	T Pop()
	{
		T temp = this->top();
		this->pop();
		return temp;
	}

};

template <typename T>
struct BTreeNode
{
	BTreeNode()
		:m_element(0), m_leftChild(nullptr), m_rightChild(nullptr)
	{
	}

	BTreeNode(const T& element, BTreeNode<T>* leftChild = nullptr, BTreeNode<T>* rightChild = nullptr)
		:m_element(element), m_leftChild(leftChild), m_rightChild(rightChild)
	{
	}

	//Ԫ��
	T m_element;

	//���ӽڵ�
	BTreeNode<T>* m_leftChild;

	//���ӽڵ�
	BTreeNode<T>* m_rightChild;
};

template <typename T>
class BinaryTree
{
public:
	/** ���캯�� */
	BinaryTree()
		:m_root(nullptr)
	{
	}

	/** ������ã�С�ķ���ߣ���ķ���� */
	void Insert(const T& element);
	/** �ݹ�ķ������� */
	void RecursiveInsert(BTreeNode<T>* node, const T& element);

	/** ���� */
	BTreeNode<T>* Search(const T& element);
	BTreeNode<T>* Search(BTreeNode<T>* node, const T& element);
	/** �ݹ���� */
	BTreeNode<T>* RecursiveSearch(const T& element);
	BTreeNode<T>* RecursiveSearch(BTreeNode<T>* node, const T& element);


	/** ��� */
	void Clear();
	void Clear(BTreeNode<T>* &node);

	/** �Ƿ�Ϊ�� */
	void IsEmpty();

	/** ������ȱ����������ܵ����󣨻����ң����У���������һ��ת�۵�ʱ�����󣨻����ң�һ����Ȼ���پ����ܵ����󣨻����ң���չ */
	/** ǰ����� :���ڵ� -> ������ ��> ������ */
	void PreOrder();
	void PreOrder(const BTreeNode<T>* node);
	/** ������� : ������ -> ���ڵ� -> ������*/
	void InOrder();
	void InOrder(const BTreeNode<T>* node);
	/** ������� : ������ -> ������ -> ���ڵ�*/
	void PostOrder();
	void PostOrder(const BTreeNode<T>* node);

	/** ǰ��������ǵݹ�ʵ�� */
	void iteratePreOrder();
	void iteratePreOrder(BTreeNode<T>* node);
	/** ����������ǵݹ�ʵ�� */
	void iterateInOrder();
	void iterateInOrder(BTreeNode<T>* node);
	/** ������� */
	void iteratePostOrder();
	void iteratePostOrder(BTreeNode<T>* node);

	/** ������ȱ���������Ͳ㣨������߲㣩��ʼ�����£��������ϣ�������ÿ���ڵ㣬��ÿһ����ϣ������ң����ߴ��ҵ��󣩷���ÿ���ڵ�*/
	/** ���ϵ��£������ҵĹ�����ȱ���ʵ�� */
	void BreadthFirst();
	void BreadthFirst(BTreeNode<T>* node);

	/** ɾ���ڵ� */


	/** ��ӡ */
	void Visit(const BTreeNode<T>* node);

private:
	/** ���ڵ� */
	BTreeNode<T>* m_root;
};

template <typename T>
void BinaryTree<T>::Insert(const T& element)
{
	BTreeNode<T>* p = m_root;
	//�ҵ�Ҫ�����ǰһ���ڵ�
	BTreeNode<T>* pre = nullptr;
	while (p != nullptr)	
	{
		pre = p;
		if (element < p->m_element)
			p = p->m_leftChild;
		else
			p = p->m_rightChild;
	}

	if (m_root == nullptr) //���ڵ�Ϊ�յ�ʱ��
	{
		m_root = new BTreeNode<T>(element);
	}
	else if (element < pre->m_element)  //charu dao 
	{
		pre->m_leftChild = new BTreeNode<T>(element);
	}
	else
	{
		pre->m_rightChild = new BTreeNode<T>(element);
	}

}

template <typename T>
void BinaryTree<T>::RecursiveInsert(BTreeNode<T>* node, const T& element)
{
	if (node == nullptr )
	{
		node = new BTreeNode<T>(element);
	}
	else if (element < node->m_element)
	{
		RecursiveInsert(node->m_leftChild);
	}
	else
	{
		RecursiveInsert(node->m_rightChild);
	}
}

template <typename T>
BTreeNode<T>* BinaryTree<T>::Search(const T& element)
{
	return Search(m_root, element);
}

template <typename T>
BTreeNode<T>* BinaryTree<T>::Search(BTreeNode<T>* node, const T& element)
{
	while (node != nullptr)
	{
		if (node->m_element == element)
		{
			return node;
		}

		if (element < node->m_element)
		{
			node = node->m_leftChild;
		}
		else
		{
			node = node->m_rightChild;
		}
	}

	return nullptr;
}

template <typename T>
BTreeNode<T>* BinaryTree<T>::RecursiveSearch(const T& element)
{
	return  RecursiveSearch(m_root, element);
}

template <typename T>
BTreeNode<T>* BinaryTree<T>::RecursiveSearch(BTreeNode<T>* node, const T& element)
{
	if (node != nullptr)
	{
		if (element == node->m_element)
		{
			return node;
		}

		if (element < node->m_element)
		{
			return RecursiveSearch(node->m_leftChild, element);
		}
		else
		{
			return RecursiveSearch(node->m_rightChild, element);
		}
	}
	else
	{
		return nullptr;
	}
}

template <typename T>
void BinaryTree<T>::Clear()
{
	Clear(m_root);
}

template <typename T>
void BinaryTree<T>::Clear(BTreeNode<T>* &node)
{
	if (node != nullptr)
	{
		Clear(node->m_leftChild);
		Clear(node->m_rightChild);
		delete node;
	}

	node = nullptr;
}

template <typename T>
void BinaryTree<T>::IsEmpty()
{
	return m_root == nullptr;
}

template <typename T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(m_root);
}

template <typename T>
void BinaryTree<T>::PreOrder(const BTreeNode<T>* node)
{
	if (node != nullptr)
	{
		Visit(node);
		PreOrder(node->m_leftChild);
		PreOrder(node->m_rightChild);
	}
}

template <typename T>
void BinaryTree<T>::InOrder()
{
	InOrder(m_root);
}

template <typename T>
void BinaryTree<T>::InOrder(const BTreeNode<T>* node)
{
	if (node != nullptr)
	{
		InOrder(node->m_leftChild);
		Visit(node);
		InOrder(node->m_rightChild);
	}
}

template <typename T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(m_root);
}

template <typename T>
void BinaryTree<T>::PostOrder(const BTreeNode<T>* node)
{
	if (node != nullptr)
	{
		PostOrder(node->m_leftChild);
		PostOrder(node->m_rightChild);
		Visit(node);
	}
}

template <typename T>
void BinaryTree<T>::iteratePreOrder()
{
	iteratePreOrder(m_root);
}

template <typename T>
void BinaryTree<T>::iteratePreOrder(BTreeNode<T>* node)
{
	if (node != nullptr)
	{
		Stack<BTreeNode<T>*> bTreeStack;
		bTreeStack.Push(node);
		while (!bTreeStack.empty())
		{
			node = bTreeStack.Pop();

			Visit(node);
			if (node->m_rightChild != nullptr)
			{
				bTreeStack.Push(node->m_rightChild);
			}

			if (node->m_leftChild != nullptr)
			{
				bTreeStack.Push(node->m_leftChild);
			}
		}

	}
}

template <typename T>
void BinaryTree<T>::iterateInOrder()
{
	iterateInOrder(m_root);
}

template <typename T>
void BinaryTree<T>::iterateInOrder(BTreeNode<T>* node)
{
	Stack<BTreeNode<T>*> travStack;

	while (node != nullptr)
	{
		while (node != nullptr)
		{
			if (node->m_rightChild != nullptr)
			{
				travStack.Push(node->m_rightChild);
			}

			travStack.Push(node);
			node = node->m_leftChild;
		}

		node = travStack.Pop();
		while (!travStack.empty() && node->m_rightChild == nullptr)
		{
			Visit(node);
			node = travStack.Pop();
		}
		Visit(node);

		if (!travStack.empty())
		{
			node = travStack.Pop();
		}
		else
		{
			node = nullptr;
		}

	}
}

template <typename T>
void BinaryTree<T>::iteratePostOrder()
{
	iteratePostOrder(m_root);
}

template <typename T>
void BinaryTree<T>::iteratePostOrder(BTreeNode<T>* node)
{
	Stack<BTreeNode<T>*> travStack;
	travStack.Push(node);
	// while (!travStack.empty())
	// {
	// 	//���߳��ֺ��ӽڵ㶼�����ʹ�
	// 	while (node->m_leftChild != nullptr || node->m_rightChild != nullptr)
	// 	{
	// 		if (node->m_rightChild != nullptr)
	// 		{
	// 			travStack.Push(node->m_rightChild);
	// 		}
	//
	// 		if (node->m_leftChild != nullptr)
	// 		{
	// 			travStack.Push(node->m_leftChild);
	// 		}
	// 		node = node->m_leftChild;
	// 	}
	//
	// 	node = travStack.Pop();
	// }
}

template <typename T>
void BinaryTree<T>::BreadthFirst()
{
	BreadthFirst(m_root);
}


/** ���ϵ��� ������ �����ö��еķ�ʽʵ��*/
template <typename T>
void BinaryTree<T>::BreadthFirst(BTreeNode<T>* node)
{
	BTreeNode<T> *p = node;
	if (p != nullptr)
	{
		Queue<BTreeNode<T>*> queue;
		queue.Enqueue(p);

		while (!queue.empty())
		{
			node = queue.Dequeue();
			Visit(node);
			if (node->m_leftChild)
			{
				queue.Enqueue(node->m_leftChild);
			}

			if (node->m_rightChild)
			{
				queue.Enqueue(node->m_rightChild);
			}
		}
	}

}

template <typename T>
void BinaryTree<T>::Visit(const BTreeNode<T>* node)
{
	cout << node->m_element << " ";
}

