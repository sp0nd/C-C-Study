// ����Ʈ���� ��ȸ

// ���� ��ȸ(Preorder Traversal)	: P-L-R
// ���� ��ȸ(Inorder Traversal)		: L-P-R
// ���� ��ȸ(Postorder Traversal)	: L-R-P

#include <iostream>
#include "binary_class_M.h"
#define CAPACITY	15	// node�� �Ѽ�

using namespace std;

 MyBinaryTree::~MyBinaryTree() {
	 delete[] root;
}
void MyBinaryTree::buildTree() {
  root = new NODE[CAPACITY + 1];  //root�� �ٲ㺸��
	//NODE nodes[CAPACITY + 1]; // �� ������ class�� ������ class�� �޸� ����(stack)
  //�̰� ������ root->nodes
	for (int i = 1; i <= CAPACITY; i++)
	{
		root[i].data = 'A' + i - 1;
		root[i].left = NULL;
		root[i].right = NULL;
	}
	for (int i = 2; i <= CAPACITY; i++)
	{
		if (i % 2 == 0)
		{
			root[i / 2].left = &root[i];
		}
		else
		{
			root[i / 2].right = &root[i];
		}
	}
	//root = &root[1]; //class������ struct ��ü �ּ� �־���
}
void MyBinaryTree::displayTree(int i) {
	
	if (i == 0) {
		preorder(&root[1]);
	}
	else if (i == 1) {
		inorder(&root[1]);
	}
	else if (i == 2) {
		postorder(&root[1]);
	}
}
//��ȸ�� �ٲ� �ʿ� ����
// ���� ��ȸ 
void MyBinaryTree::preorder(LPNODE ptr)
{
	if (ptr)
	{
		cout << char(ptr->data) << ' ';
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

// ���� ��ȸ
void MyBinaryTree::inorder(LPNODE ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		cout << char(ptr->data) << ' ';
		inorder(ptr->right);
	}
}

// ���� ��ȸ
void MyBinaryTree::postorder(LPNODE ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << char(ptr->data) << ' ';
	}
}
