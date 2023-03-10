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

	system("pause");

	return 0;
}

