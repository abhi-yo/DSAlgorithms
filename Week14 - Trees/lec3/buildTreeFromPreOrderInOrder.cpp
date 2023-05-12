#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }

        cout << endl;
    }
}

int findPosition(int inorder[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{
    // base case
    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }
    // Step A
    int element = preorder[preIndex++];
    Node *root = new Node(element);
    int pos = findPosition(inorder, size, element);
    // Step B
    root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
    // Step C
    root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);
    return root;
}

int main()
{
    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;
    cout << "Building tree from inorder and preorder traversal" << endl;
    Node *root = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);
    cout << "Printing level order traversal of tree" << endl;
    printLevelOrder(root);
    return 0;
}
