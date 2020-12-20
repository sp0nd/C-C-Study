#include <iostream>
#include "LinkedBinaryTree.h"

using namespace std;

// Tree �����
void makeTree(LinkedBinaryTree& tree)
{
	tree.addRoot();

	Position root = tree.root();

	tree.expandExternal(root);

	tree.expandExternal(root.left());
	tree.expandExternal(root.right());
}

int main()
{
	LinkedBinaryTree tree;

	makeTree(tree);

	// ���� ��ȸ
	PositionList pl1 = tree.positions(0);
	cout << "Preorder Traversal" << endl;
	for (auto list : pl1)
	{
		cout << *list << " ";
	}
	cout << endl;

	// ���� ��ȸ
	PositionList pl2 = tree.positions(1);
	cout << "Inorder Traversal" << endl;
	for (auto list : pl2)
	{
		cout << *list << " ";
	}
	cout << endl;

	// ���� ��ȸ
	PositionList pl3 = tree.positions(2);
	cout << "Postorder Traversal" << endl;
	for (auto list : pl3)
	{
		cout << *list << " ";
	}
	cout << endl;

	return 1;
}