#pragma once
#include <iostream>
using namespace std;

/** BinaryTree 二叉树 */  //递归 理解栈的原理

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

	//元素
	T m_element;

	//左子节点
	BTreeNode<T>* m_leftChild;

	//右子节点
	BTreeNode<T>* m_rightChild;
};

template <typename T>
class BinaryTree
{
public:
	/** 构造函数 */
	BinaryTree()
		:m_root(nullptr)
	{
	}

	/** 插入放置：小的放左边，大的放左边 */
	void Insert(const T& element);

	/** 前序遍历 :根节点 -> 左子树 —> 右子树 */
	void PreOrder();
	void PreOrder(const BTreeNode<T>* node);

	/** 中序遍历 : 左子树 -> 根节点 -> 右子树*/
	void InOrder();
	void InOrder(const BTreeNode<T>* node);

	/** 后序遍历 : 左子树 -> 右子树 -> 根节点*/
	void PostOrder();
	void PostOrder(const BTreeNode<T>* node);


	/** 打印 */
	void Visit(const BTreeNode<T>* node);

private:
	/** 根节点 */
	BTreeNode<T>* m_root;
};

template <typename T>
void BinaryTree<T>::Insert(const T& element)
{
	BTreeNode<T>* p = m_root;
	//找到要插入的前一个节点
	BTreeNode<T>* pre = nullptr;
	while (p != nullptr)	
	{
		pre = p;
		if (element < p->m_element)
			p = p->m_leftChild;
		else
			p = p->m_rightChild;
	}

	if (m_root == nullptr) //根节点为空的时候
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
void BinaryTree<T>::Visit(const BTreeNode<T>* node)
{
	cout << node->m_element << " ";
}

