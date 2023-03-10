#pragma once
#include <iostream>
using namespace std;

/** BinaryTree ������ */  //�ݹ� ���ջ��ԭ��

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

	/** ǰ����� :���ڵ� -> ������ ��> ������ */
	void PreOrder();
	void PreOrder(const BTreeNode<T>* node);

	/** ������� : ������ -> ���ڵ� -> ������*/
	void InOrder();
	void InOrder(const BTreeNode<T>* node);

	/** ������� : ������ -> ������ -> ���ڵ�*/
	void PostOrder();
	void PostOrder(const BTreeNode<T>* node);


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

