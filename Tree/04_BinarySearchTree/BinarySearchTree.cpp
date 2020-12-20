#include <stdio.h> 
#include <stdlib.h> 
#include <stack>
#include <iterator>

using namespace std;

// ���� Ž�� Ʈ��

typedef struct node {   // ��� ����ü
    int key;
    struct node* left;  // ���� �ڽ� ������
    struct node* right; // ������ �ڽ� ������
} NODE;

int cnt = 0;    // ��带 �湮�ϴ� ȸ�� ����
NODE* search(NODE* root, int key) {
    cnt++;
    if (root == NULL) return NULL;

    if (root->key == key) return root; //key�� �ڱ� �ڽ��� ��� ã�����Ƿ� ����
    else if (root->key < key) return search(root->right, key); //����Ű<ã������ Ű�� ������ Ʈ����(ū����)
    else return search(root->left, key); //�ƴϸ� ���� Ʈ����
}

NODE* newNode(int item) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(NODE* root) { //���� ��ȸ�� ���
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

NODE* insert(NODE* node, int key) {
    if (node == NULL) return newNode(key); //Ʈ���� ����ٸ� ���� ��带 ����

    if (key < node->key) node->left = insert(node->left, key); //ã��Ű<���Ű�� ����
    else if (key > node->key) node->right = insert(node->right, key); //�ݴ�� ������

    return node; //��� ������ ��ȯ
}

void appendStack(std::stack<NODE*>& st, NODE* node)
{
    st.push(node);
    if (node->left != NULL) appendStack(st, node->left);
    if (node->right != NULL) appendStack(st, node->right);
}

void deleteNodes(NODE* root)
{
    std::stack<NODE*> st;

    st.push(root);
    if (root->left != NULL) appendStack(st, root->left);
    if (root->right != NULL) appendStack(st, root->right);

    while (1)
    {
        NODE* node = st.top();
        printf("delete : %d\n", node->key);
        delete node;
        st.pop();

        if (st.size() == 0) break;
    }
}

// ���� Ž�� Ʈ�� 
int main()
{
    NODE* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 40);
    insert(root, 20);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);

    cnt = 0;    // ��� �湮 Ƚ�� �ʱ�ȭ
    search(root, 40);

    printf("ã�� �� �� �� ��ȸ?: %d\n", cnt);

    inorder(root); //���

    deleteNodes(root);

    return 0;
}