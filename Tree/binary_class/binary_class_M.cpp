// 이진트리의 순회

// 전위 순회(Preorder Traversal)	: P-L-R
// 중위 순회(Inorder Traversal)		: L-P-R
// 후위 순회(Postorder Traversal)	: L-R-P

#include <iostream>
#include "binary_class_M.h"
#define CAPACITY	15	// node의 총수

using namespace std;

 MyBinaryTree::~MyBinaryTree() {
	 delete[] root;
}
void MyBinaryTree::buildTree() {
  root = new NODE[CAPACITY + 1];  //root로 바꿔보기
	//NODE nodes[CAPACITY + 1]; // 이 구문이 class에 있으면 class에 메모리 잡힘(stack)
  //이것 쓰려면 root->nodes
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
	//root = &root[1]; //class변수에 struct 객체 주소 넣어줌
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
//순회는 바꿀 필요 없음
// 전위 순회 
void MyBinaryTree::preorder(LPNODE ptr)
{
	if (ptr)
	{
		cout << char(ptr->data) << ' ';
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

// 중위 순회
void MyBinaryTree::inorder(LPNODE ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		cout << char(ptr->data) << ' ';
		inorder(ptr->right);
	}
}

// 후위 순회
void MyBinaryTree::postorder(LPNODE ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << char(ptr->data) << ' ';
	}
}
