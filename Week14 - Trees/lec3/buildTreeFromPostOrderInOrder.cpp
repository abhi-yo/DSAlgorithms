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

Node *buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int &postIndex, int inorderStart, int inorderEnd)
{
    // base case
    if (inorderStart > inorderEnd)
        return NULL;

    int element = postorder[postIndex];
    postIndex--;

    Node *root = new Node(element);
    int pos = findPosition(inorder, inorderEnd + 1, element);

    root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, pos + 1, inorderEnd);
    root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, inorderStart, pos - 1);

    return root;
}

int main()
{
    int inorder[] = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    cout << "Building tree from inorder and postorder traversal" << endl;
    Node *root = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, inorderStart, inorderEnd);
    cout << "Printing level order traversal of tree" << endl;
    printLevelOrder(root);

    return 0;
}
