#include <iostream>
#include "binary_class_M.h"

using namespace std;

int main()
{
	MyBinaryTree tt;

	tt.buildTree();
	tt.displayTree(0);
	cout << endl;
	tt.displayTree(1);
	cout << endl;
	tt.displayTree(2);
	cout << endl;
	
}