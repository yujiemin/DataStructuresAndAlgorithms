#include <iostream>

#include "BinaryTree.h"

int main()
{
	BinaryTree<int> binaryTree;

	binaryTree.Insert(5);
	binaryTree.Insert(6);
	binaryTree.Insert(1);
	binaryTree.Insert(3);
	binaryTree.Insert(8);

	binaryTree.PreOrder();
	cout << endl;
	binaryTree.InOrder();
	cout << endl;
	binaryTree.PostOrder();
	cout << endl;

	binaryTree.BreadthFirst();
	cout << endl;

	if (BTreeNode<int>* tempNode = binaryTree.Search(1))
	{
		std::cout << "Find the ndoe " << tempNode->m_element << std::endl;
	}
	else
	{
		std::cout << "Search Do Not Found" << std::endl;
	}

	if (BTreeNode<int>* findNode = binaryTree.RecursiveSearch(8))
	{
		std::cout << "Recursive Search Find " << findNode->m_element << std::endl;
	}
	else
	{
		std::cout << "Recursive Do Not Found " << std::endl;
	}


	queue<int> tempQueue;
	tempQueue.push(1);
	int tempValue = tempQueue.front();

	system("pause");

	return 0;
}

