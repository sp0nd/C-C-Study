// ����Ʈ���� ��ȸ

// ���� ��ȸ(Preorder Traversal)	: P-L-R
// ���� ��ȸ(Inorder Traversal)		: L-P-R
// ���� ��ȸ(Postorder Traversal)	: L-R-P

#include <iostream>

#define CAPACITY	15	// node�� �Ѽ�

using namespace std;

// ��� ����ü
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}NODE, * LPNODE;

// ���� ��ȸ
void preorder(LPNODE ptr)
{
	if (ptr)
	{
		cout << char(ptr->data) << ' ';
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

// ���� ��ȸ
void inorder(LPNODE ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		cout << char(ptr->data) << ' ';
		inorder(ptr->right);
	}
}

// ���� ��ȸ
void postorder(LPNODE ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << char(ptr->data) << ' ';
	}
}

int main()
{
	NODE nodes[CAPACITY + 1]; // 0��° �ε��� ���� �ʰڴ�.
	for (int i = 1; i <= CAPACITY; i++)
	{
		nodes[i].data = 'A' + i - 1;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}
	for (int i = 2; i <= CAPACITY; i++)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].left = &nodes[i];
		}
		else
		{
			nodes[i / 2].right = &nodes[i];
		}
	}
	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	cout << endl;
}