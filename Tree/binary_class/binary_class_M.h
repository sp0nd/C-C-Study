#include <iostream>
#define CAPACITY	15
using namespace std;

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}NODE, * LPNODE;

class MyBinaryTree {
	LPNODE root;
	//NODE nodes[CAPACITY + 1];
	void preorder(LPNODE ptr);
	void inorder(LPNODE ptr);
	void postorder(LPNODE ptr);
public :
	MyBinaryTree() : root(NULL) {}
	~MyBinaryTree();
	void buildTree();
	void displayTree(int);
};