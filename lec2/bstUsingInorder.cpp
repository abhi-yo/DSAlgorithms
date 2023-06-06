#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *bstUsingInorder(int inorder[], int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);
    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);
    return root;
}

void inorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int inorder[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(inorder) / sizeof(int);

    Node *root = bstUsingInorder(inorder, 0, n - 1);

    inorderPrint(root);
    cout << endl;
    return 0;
}